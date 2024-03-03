/* Desarrollado para Flex versión 2.5.4a */

/*
UTN - FRBA
Sintaxis y Semántica de los Lenguajes - 2022
Trabajo Práctico Integrador 
Analizador léxico, sintáctico y semántico de C

Implementar en C un programa que realice el análisis léxico, sintáctico y semántico de un archivo fuente del lenguaje C generando su respectivo reporte sobre el análisis realizado.
El mismo será un modelo simplificado (tomar una GIC reducida) que solamente realizará determinadas validaciones semánticas.

Las validaciones semánticas serán:
- Al menos un control de tipos de datos en alguna operación binaria (a elección de cada grupo) -> Utilizar TS si operamos con variables
- Control de doble declaración de variables (se consideran que todas las variables están en el mismo ámbito para simplificar la validación) -> Utilizar TS
- Control de cantidad y tipos de parámetros en la invocación a funciones -> Utilizar TS

Las validaciones sintácticas (TP 4):
- Sentencias (todos los tipos: compuesta, If, While, Salto, For, Expresión, etc)
- Declaraciones de variables (puede agregar variables tipo puntero y tipo arreglo) de forma correcta almacenando en TS.
- Declaraciones de funciones de forma correcta almacenando en TS.
- Expresiones (que están incluidas dentro de las sentencias).

El programa deberá reportar un informe en pantalla con
- Lista de variables declaradas indicando el tipo de cada una. (Utilizar TS)
- Lista de funciones declaradas indicando el tipo de parámetro que devuelve y cantidad y tipos de parámetros que recibe. (Utilizar TS)
- Error léxicos encontrados (si los hay) - (Implementar en Flex, archivo.L)
- Errores sintácticos encontrados (si los hay) (Implementar en Bison, utilizar token error)
- Errores semánticos encontrados (si los hay) (Implementar Rutinas Semánticas con TS).

El criterio para el manejo de errores es el siguiente:
- Ante un error léxico, capturar la secuencia de caracteres no reconocida (pueden utilizar una última regla con comodín), en este caso, no le llegará ningún token al analizador sintáctico.
	Pero puede suceder que un error léxico, desencadene un error sintáctico en caso de que el Parser no reciba los tokens adecuados para la GIC implementada.
- Ante un error sintáctico, utilizar el token “error” para capturar el error y almacenar la información que consideren importante para registrar el mismo.
	Luego seguir procesando a partir de donde encuentran un punto y coma ‘;’ , o bien un salto de línea ‘\n’.
- Ante un error semántico, no es necesario salvar el error dado que la gramática independiente de contexto seguirá operando sin problemas.
	Pero deben implementar dentro de las rutinas semánticas la impresión de algún mensaje en pantalla, o bien, almacenar los errores encontrados en una lista para imprimirlo al final del análisis en el reporte.

La entrega de este trabajo práctico es obligatoria y será en conjunto con defensa del mismo los días lunes 31 de octubre (K2001) y martes 1 de noviembre (K2052).
Deben estar presentes con micrófono y cámara todos los integrantes del grupo. La defensa tendrá una duración aproximada de 15 minutos en los cuales todos los integrantes deberán responder preguntas referidas al trabajo práctico integrador.
*/

/* Inicio de la sección de definiciones */
    /* Cualquier texto sangrado o encerrado entre '%{' y '%}' (estos últimos dos sin sangrar en líneas ocupadas únicamente por ellos) se copia íntegramente al archivo de salida del analizador léxico (scanner) generado */
    /* Los comentarios (sólo hay de múltiples líneas) sin sangría también se copian literalmente a la salida */

%{
#include "bibliotecas.h"
#include "semantica.h"
#include "TPI.tab.h"

extern enum Booleano bandera_podria_usarse_un_nombre_de_typedef;
extern Descripcion* erroresLexicos;
int cantidadErroresLexicos = 0;
%}
    /* */
%pointer
    /* Con esta opción la función de análisis int yylex(void); se comporta como si en la sección de usuario existiera la función int yywrap(void) return 1; la cual devuelve verdadero (no-cero), haciendo que una vez que la función de análisis int yylex(void) reciba una indicación de EOF desde YY_INPUT, asuma que no hay nada más para analizar de yyin y finalice (haciendo un return 0;) */
%option noyywrap

    /* Condiciones de arranque inclusivas */
/* %s */
    /* Condiciones de arranque exclusivas */
%x constanteEnteraDecimal constanteEnteraHexaUOctal constanteReal constanteCaracter literalCadena verSiSigueOtroLiteralCadena concatenacionDeLiteralesCadena comentarioDeMultiplesLineas tokenNoReconocido

    /* */
signo [+-]
digito [0-9]
digitoNoCero [1-9]
digitoOctal [0-7]
digitoHexa [0-9a-fA-F]
noDigito [_a-zA-Z]
parteExponente [eE]{signo}?{digito}+
secuenciaEscapeHexa \\x{digitoHexa}{1,2}
secuenciaEscapeOctal \\{digitoOctal}{1,3}
secuenciaEscapeSimple \\[abfnrtv\\?'"]

/* Fin de la sección de definiciones */

/* Inicio de la sección de reglas */
    /* Cualquier texto sangrado o encerrado entre '%{' y '%}' (estos últimos dos sin sangrar en líneas ocupadas únicamente por ellos) se copia íntegramente al archivo de salida del analizador léxico (scanner) generado */
        /* Esto podría utilizarse para declarar variables que son locales a la rutina de análisis léxico y (después de las declaraciones) al código que debe ejecutarse siempre que se entra a la rutina de análisis léxico */
    /* Dentro de esta sección NO pueden hacerse comentarios sin sangría, ya que estos no se copian literalmente a la salida */
%%
    char* buffer;
    char banderaConcatenacionEntreLiteralesCadena;

    reinicializarUbicacion();

    debug_banderas_flex_printf("Flex: Bandera podria usarse un nombre de typedef: %d\n", bandera_podria_usarse_un_nombre_de_typedef);

    /* Constantes */
        /* Entera decimal */
{digitoNoCero}{digito}* { yylloc.last_column += yyleng; iniciarCadena(&buffer, yytext); BEGIN(constanteEnteraDecimal); }
        /* Entera octal */
0{digitoOctal}* { yylloc.last_column += yyleng; iniciarCadena(&buffer, yytext); BEGIN(constanteEnteraHexaUOctal); }
        /* Entera hexadecimal */
0[xX]{digitoHexa}+ { yylloc.last_column += yyleng; iniciarCadena(&buffer, yytext); BEGIN(constanteEnteraHexaUOctal); }
        /* Real */
((({digito}*"."{digito}+)|({digito}+".")){parteExponente}?)|({digito}+{parteExponente}) { yylloc.last_column += yyleng; iniciarCadena(&buffer, yytext); BEGIN(constanteReal); }

<constanteEnteraDecimal>{
    [uU][lL]|[lL][uU] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            yylval.unsigned_long_type = conversion;
            return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [uU] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            if(conversion <= UINT_MAX)
            {
                yylval.unsigned_int_type = (unsigned int) conversion;
                return CONSTANTE_ENTERA_UNSIGNED_INT_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [lL] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            if(conversion <= LONG_MAX)
            {
                yylval.long_type = (long) conversion;
                return CONSTANTE_ENTERA_LONG_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;   
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [^uUlL] {
        yyless(0);
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera sin sufijo: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            free(buffer);
            if(conversion <= INT_MAX)
            {
                yylval.int_type = (int) conversion;
                return CONSTANTE_ENTERA_INT_TYPE;
            }
            else if(conversion <= LONG_MAX)
            {
                yylval.long_type = (long) conversion;
                return CONSTANTE_ENTERA_LONG_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera sin sufijo: %s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    <<EOF>> {
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera sin sufijo: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            free(buffer);
            if(conversion <= INT_MAX)
            {
                yylval.int_type = (int) conversion;
                return CONSTANTE_ENTERA_INT_TYPE;
            }
            else if(conversion <= LONG_MAX)
            {
                yylval.long_type = (long) conversion;
                return CONSTANTE_ENTERA_LONG_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera sin sufijo: %s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
}

<constanteEnteraHexaUOctal>{
    [uU][lL]|[lL][uU] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            yylval.unsigned_long_type = conversion;
            return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [uU] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            if(conversion <= UINT_MAX)
            {
                yylval.unsigned_int_type = (unsigned int) conversion;
                return CONSTANTE_ENTERA_UNSIGNED_INT_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [lL] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            if(conversion <= LONG_MAX)
            {
                yylval.long_type = (long) conversion;
                return CONSTANTE_ENTERA_LONG_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;   
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [^uUlL] {
        yyless(0);
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera sin sufijo: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            free(buffer);
            if(conversion <= INT_MAX)
            {
                yylval.int_type = (int) conversion;
                return CONSTANTE_ENTERA_INT_TYPE;
            }
            else if(conversion <= UINT_MAX)
            {
                yylval.long_type = (unsigned int) conversion;
                return CONSTANTE_ENTERA_UNSIGNED_INT_TYPE;
            }
            else if(conversion <= LONG_MAX)
            {
                yylval.long_type = (long) conversion;
                return CONSTANTE_ENTERA_LONG_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera sin sufijo: %s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    <<EOF>> {
        BEGIN(INITIAL);
        errno = 0; unsigned long conversion = strtoul(buffer, NULL, 0);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante entera sin sufijo: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            free(buffer);
            if(conversion <= INT_MAX)
            {
                yylval.int_type = (int) conversion;
                return CONSTANTE_ENTERA_INT_TYPE;
            }
            else if(conversion <= UINT_MAX)
            {
                yylval.long_type = (unsigned int) conversion;
                return CONSTANTE_ENTERA_UNSIGNED_INT_TYPE;
            }
            else if(conversion <= LONG_MAX)
            {
                yylval.long_type = (long) conversion;
                return CONSTANTE_ENTERA_LONG_TYPE;
            }
            else
            {
                yylval.unsigned_long_type = conversion;
                return CONSTANTE_ENTERA_UNSIGNED_LONG_TYPE;
            }
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante entera sin sufijo: %s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
}

<constanteReal>{
    [fF] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; float conversion = strtof(buffer, NULL);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante real con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            yylval.float_type = conversion;
            return CONSTANTE_REAL_FLOAT_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante real con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [lL] {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        errno = 0; long double conversion = strtold(buffer, NULL);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante real con sufijo: %s%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext);
            free(buffer);
            yylval.long_double_type = conversion;
            return CONSTANTE_REAL_LONG_DOUBLE_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante real con sufijo: %s%s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, yytext, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    [^fFlL] {
        yyless(0);
        BEGIN(INITIAL);
        errno = 0; double conversion = strtod(buffer, NULL);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante real sin sufijo: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            free(buffer);
            yylval.double_type = conversion;
            return CONSTANTE_REAL_DOUBLE_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante real sin sufijo: %s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
    <<EOF>> {
        BEGIN(INITIAL);
        errno = 0; double conversion = strtod(buffer, NULL);
        if(errno == 0)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante real sin sufijo: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            free(buffer);
            yylval.double_type = conversion;
            return CONSTANTE_REAL_DOUBLE_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante real sin sufijo: %s: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer, strerror(errno));
            free(buffer);
            cantidadErroresLexicos++;
        }
    }
}
        /* Caracter */
' { yylloc.last_column += yyleng; BEGIN(constanteCaracter); }
<constanteCaracter>{
    {secuenciaEscapeHexa}' {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        yytext[yyleng - 1] = '\0';
        int conversion = (int) (signed char) strtol(yytext + 2, NULL, 16);
        debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante caracter con secuencia de escape hexadecimal: '%s' \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        yylval.int_type = conversion;
        return CONSTANTE_ENTERA_INT_TYPE;
    }
    {secuenciaEscapeOctal}' {
        yylloc.last_column += yyleng;
        BEGIN(INITIAL);
        yytext[yyleng - 1] = '\0';
        int conversion = (int) strtol(yytext + 1, NULL, 8);
        if(conversion <= 255)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante caracter con secuencia de escape octal: '%s' \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
            yylval.int_type = (int) (signed char) conversion;
            return CONSTANTE_ENTERA_INT_TYPE;
        }
        else
        {
            error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante caracter con secuencia de escape octal fuera de rango (0-255): '%s' \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
            cantidadErroresLexicos++;
        }
    }
    {secuenciaEscapeSimple}' {
        yylloc.last_column += yyleng;
        debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante caracter con secuencia de escape simple: '%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        BEGIN(INITIAL);
        switch(yytext[1])
        {
            case 'a': yylval.int_type = '\a'; break;
            case 'b': yylval.int_type = '\b'; break;
            case 'e': yylval.int_type = '\e'; break;
            case 'f': yylval.int_type = '\f'; break;
            case 'n': yylval.int_type = '\n'; break;
            case 'r': yylval.int_type = '\r'; break;
            case 't': yylval.int_type = '\t'; break;
            case 'v': yylval.int_type = '\v'; break;
            case '\\': yylval.int_type = '\\'; break;
            case '\?': yylval.int_type = '\?'; break;
            case '\'': yylval.int_type = '\''; break;
            case '\"': yylval.int_type = '\"'; break;
        }
        return CONSTANTE_ENTERA_INT_TYPE;
    }
    [^\\'\n]' {
        yylloc.last_column += yyleng;
        debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: constante caracter simple: '%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        BEGIN(INITIAL);
        yylval.int_type = (int) yytext[0];
        return CONSTANTE_ENTERA_INT_TYPE;
    }
    [^'\n]*' {
        yylloc.last_column += yyleng;
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: constante caracter invalida: '%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
    [^'\n]+ {
        yylloc.last_column += yyleng;
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: falta el caracter ' de cierre de la constante caracter: '%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
    \n {
        yyless(0);
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: falta el caracter ' de cierre de la constante caracter: ' \n", archivo_yyin, yylloc.first_line, yylloc.first_column);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
    <<EOF>> {
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: falta el caracter ' de cierre de la constante caracter: ' \n", archivo_yyin, yylloc.first_line, yylloc.first_column);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
}
    /* Literales cadena */
\" { yylloc.last_column += yyleng; banderaConcatenacionEntreLiteralesCadena = FALSE; BEGIN(literalCadena); }
<literalCadena>{
    ({secuenciaEscapeHexa}|{secuenciaEscapeOctal}|{secuenciaEscapeSimple}|[^\"\n\\])*\" {
        yylloc.last_column += yyleng;
        if(!banderaConcatenacionEntreLiteralesCadena) iniciarCadenaHasta(&buffer, yytext, yyleng - 1);
        else
        {
            concatenarCadenaHasta(&buffer, yytext, yyleng - 1);
            banderaConcatenacionEntreLiteralesCadena = FALSE;
        }
        BEGIN(verSiSigueOtroLiteralCadena);
    }
    [^\"\n]*\" {
        yylloc.last_column += yyleng;
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: literal cadena invalido: \"%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        if(banderaConcatenacionEntreLiteralesCadena) free(buffer);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
    [^\"\n]+ {
        yylloc.last_column += yyleng;
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: falta el caracter \" de cierre del literal cadena: \"%s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext);
        if(banderaConcatenacionEntreLiteralesCadena) free(buffer);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
    \n {
        yyless(0);
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: falta el caracter \" de cierre del literal cadena: \" \n", archivo_yyin, yylloc.first_line, yylloc.first_column);
        if(banderaConcatenacionEntreLiteralesCadena) free(buffer);
        BEGIN(INITIAL);
        cantidadErroresLexicos++; 
    }
    <<EOF>> {
        error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: falta el caracter \" de cierre del literal cadena: \" \n", archivo_yyin, yylloc.first_line, yylloc.first_column);
        if(banderaConcatenacionEntreLiteralesCadena) free(buffer);
        BEGIN(INITIAL);
        cantidadErroresLexicos++;
    }
}
<verSiSigueOtroLiteralCadena>{
    [ \t\n]*\" { yyless(0); BEGIN(concatenacionDeLiteralesCadena); }
    . { yyless(0); debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: literal cadena: \"%s\" \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); BEGIN(INITIAL); yylval.char_pointer_type = buffer; return LITERAL_CADENA; }
    <<EOF>> { debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: literal cadena: \"%s\" \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); BEGIN(INITIAL); yylval.char_pointer_type = buffer; return LITERAL_CADENA; }
}
<concatenacionDeLiteralesCadena>{
    \" { yylloc.last_column += yyleng; banderaConcatenacionEntreLiteralesCadena = TRUE; BEGIN(literalCadena); }
    [ \t]+ { yylloc.last_column += yyleng; }
    \n+ { yylloc.last_line += yyleng; yylloc.last_column = INICIO_CONTEO_COLUMNA; }
}
    /* Palabras reservadas */
typedef  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return TYPEDEF_TOKEN; }
extern   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return EXTERN_TOKEN; }
static   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return STATIC_TOKEN; }
auto     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return AUTO_TOKEN; }
register { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return REGISTER_TOKEN; }

void     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return VOID_TOKEN; }
char     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return CHAR_TOKEN; }
short    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return SHORT_TOKEN; }
int      { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return INT_TOKEN; }
long     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return LONG_TOKEN; }
float    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return FLOAT_TOKEN; }
double   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DOUBLE_TOKEN; }
signed   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return SIGNED_TOKEN; }
unsigned { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return UNSIGNED_TOKEN; }

const    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return CONST_TOKEN; }
volatile { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return VOLATILE_TOKEN; }

struct   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return STRUCT_TOKEN; }
union    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return UNION_TOKEN; }

enum     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return ENUM_TOKEN; }

if       { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return IF_TOKEN; }
else     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return ELSE_TOKEN; }
switch   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return SWITCH_TOKEN; }

while    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return WHILE_TOKEN; }
do       { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DO_TOKEN; }
for      { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return FOR_TOKEN; }

case     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return CASE_TOKEN; }
default  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DEFAULT_TOKEN; }

goto     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return GOTO_TOKEN; }
continue { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return CONTINUE_TOKEN; }
break    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return BREAK_TOKEN; }
return   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return RETURN_TOKEN; }

sizeof   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocida: palabra reservada: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return SIZEOF_TOKEN; }

    /* Identificadores */
{noDigito}({noDigito}|{digito})* {
    yylloc.last_column += yyleng;
    BEGIN(INITIAL);
    iniciarCadena(&buffer, yytext);
    yylval.char_pointer_type = buffer;
    if(bandera_podria_usarse_un_nombre_de_typedef)
    {
        bandera_podria_usarse_un_nombre_de_typedef = FALSE;
        Simbolo* resultadoBusqueda = buscarSimbolo(buffer, BUSQUEDA_OBJETO_FUNCION_TYPEDEF_Y_ENUMERADOR);
        if(resultadoBusqueda != NULL && (resultadoBusqueda -> tipoSimbolo) == TYPEDEF)
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: identificador (token NOMBRE_DE_TYPEDEF): %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            return NOMBRE_DE_TYPEDEF;
        }
        else
        {
            debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: identificador (token IDENTIFICADOR): %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
            return IDENTIFICADOR;
        }
    }
    else
    {
        debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: identificador (token IDENTIFICADOR): %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer);
        return IDENTIFICADOR;
    }
}

    /* Caracteres de puntuación/operadores de C */
"..." { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return ELIPSIS_TOKEN; }
"+="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return MAS_IGUAL_TOKEN; }
"-="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return MENOS_IGUAL_TOKEN; }
"*="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return POR_IGUAL_TOKEN; } 
"/="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DIVIDIDO_IGUAL_TOKEN; }
"%="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return MOD_IGUAL_TOKEN; }
&=    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return AND_IGUAL_TOKEN; }
"|="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return OR_IGUAL_TOKEN; }
"^="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return XOR_IGUAL_TOKEN; }
"<<=" { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return ASIGNACION_CON_DESPLAZAMIENTO_IZQUIERDA_TOKEN; }
>>=   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return ASIGNACION_CON_DESPLAZAMIENTO_DERECHA_TOKEN; }
"||"  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return OR_TOKEN; }
&&    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return AND_TOKEN; }
==    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return IGUALDAD_TOKEN; }
"!="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DIFERENCIA_TOKEN; }
"<="  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return MENOR_O_IGUAL_TOKEN; }
>=    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return MAYOR_O_IGUAL_TOKEN; }
"<<"  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DESPLAZAMIENTO_IZQUIERDA_TOKEN; }
>>    { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DESPLAZAMIENTO_DERECHA_TOKEN; }
"->"  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return MIEMBRO_DE_ESTRUCTURA_CON_DESREFERENCIACION_TOKEN; }
"++"  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return INCREMENTO_TOKEN; }
"--"  { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return DECREMENTO_TOKEN; }
"["   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('['); } 
"]"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return(']'); } 
"("   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('('); }
")"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return(')'); }
"{"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('{'); } 
"}"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('}'); } 
"."   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('.'); }
&     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('&'); }
"*"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('*'); }
"+"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('+'); } 
"-"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('-'); }
~     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('~'); }
"!"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('!'); }
"/"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('/'); } 
"%"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('%'); } 
"<"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('<'); }
>     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('>'); } 
"^"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('^'); } 
"|"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('|'); } 
=     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('='); } 
"?"   { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return('?'); }
:     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return(':'); } 
;     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return(';'); } 
,     { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: caracter de puntuacion/operador de C: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); return(','); }

    /* Comentarios */
        /* Comentarios de una línea */
"//"[^\n]+ { yylloc.last_column += yyleng; debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: comentario de una linea: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, yytext); reinicializarUbicacion(); }
        /* Comentarios de múltiples líneas */
"/*" { yylloc.last_column += yyleng; iniciarCadena(&buffer, yytext); BEGIN(comentarioDeMultiplesLineas); }
<comentarioDeMultiplesLineas>{
    [^*\n]+ { yylloc.last_column += yyleng; concatenarCadena(&buffer, yytext); }
    \*+ { yylloc.last_column += yyleng; concatenarCadena(&buffer, yytext); }
    \n+ { yylloc.last_line += yyleng; yylloc.last_column = INICIO_CONTEO_COLUMNA; concatenarCadena(&buffer, yytext); }
    "*/" { yylloc.last_column += yyleng; concatenarCadena(&buffer, yytext); debug_reconocidos_flex_printf("Flex: %s:%d:%d: Reconocido: comentario de multiples lineas: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); free(buffer); reinicializarUbicacion(); BEGIN(INITIAL); }
    <<EOF>> { error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico (para el preprocesamiento): comentario multilinea sin terminar: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); free(buffer); BEGIN(INITIAL); cantidadErroresLexicos++; }
}
    /* Tokens no reconocidos */
[^ \t\n] { yylloc.last_column += yyleng; iniciarCadena(&buffer, yytext); BEGIN(tokenNoReconocido);}
<tokenNoReconocido>{
    <<EOF>> { error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: token no reconocido: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); free(buffer); BEGIN(INITIAL); cantidadErroresLexicos++; }
    " "|\t|\n { yyless(0); error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: token no reconocido: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); free(buffer); BEGIN(INITIAL); cantidadErroresLexicos++; }
    [^ \t\n]+ { yylloc.last_column += yyleng; concatenarCadena(&buffer, yytext); error_lexico_fprintf(stderr, "Flex: %s:%d:%d: Error lexico: token no reconocido: %s \n", archivo_yyin, yylloc.first_line, yylloc.first_column, buffer); free(buffer); BEGIN(INITIAL); cantidadErroresLexicos++; }
}

    /* Espacios y tabulaciones */
[ \t]+ { yylloc.first_column = yylloc.last_column += yyleng; }

    /* Saltos de línea */
\n+ { yylloc.first_line = yylloc.last_line += yyleng; yylloc.first_column = yylloc.last_column = INICIO_CONTEO_COLUMNA; }

    /* EOF */
<<EOF>> { debug_reconocidos_flex_printf("Flex: %s:%d:%d: EOF alcanzado \n", archivo_yyin, yylloc.first_line, yylloc.first_column); return 0; }

%%
/* Fin de la sección de reglas */

/* Inicio de la sección de código de usuario (se utiliza para rutinas de complemento que llaman al analizador léxico o son llamadas por este; la presencia de esta sección es opcional) */
    /* Toda esta sección simplemente se copia íntegramente al archivo de salida del analizador léxico (scanner) generado */

/* Fin de la sección de código de usuario */