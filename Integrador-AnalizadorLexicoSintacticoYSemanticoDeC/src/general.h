#define archivo_yyin "archivo.c"
#define INICIO_CONTEO_LINEA 1
#define INICIO_CONTEO_COLUMNA 1

#define DEPURAR_RECONOCIDOS_FLEX 0
#define DEPURAR_BANDERAS_FLEX 0
#define DEPURAR_REDUCCIONES_BISON 0
#define DEPURAR_BANDERAS_BISON 0

#define debug_reconocidos_flex_printf(formato, ...) \
    do { if (DEPURAR_RECONOCIDOS_FLEX) fprintf(stderr, "\t\t\t" formato "\n", __VA_ARGS__); } while (0)

#define debug_banderas_flex_printf(formato, ...) \
    do { if (DEPURAR_BANDERAS_FLEX) fprintf(stderr, "\n" "\t\t\t\t" formato, __VA_ARGS__); } while (0)

#define debug_reducciones_bison_printf(formato, ...) \
    do { if (DEPURAR_REDUCCIONES_BISON) fprintf(stderr, "\t" formato, __VA_ARGS__); } while (0)

#define debug_banderas_bison_printf(formato, ...) \
    do { if (DEPURAR_BANDERAS_BISON) fprintf(stderr, "\t\t" formato, __VA_ARGS__); } while (0)

typedef enum Booleano
{
    FALSE,
	TRUE
} Booleano;

void pausa(void);
void verSiHuboUnFalloDeAsignacionDeMemoriaDinamica(void*);
void errorCritico(char*);
void inicializarUbicacion(void);
void reinicializarUbicacion(void);
void iniciarCadena(char**, char*);
void iniciarCadenaHasta(char**, char*, size_t);
void concatenarCadena(char**, char*);
void concatenarCadenaHasta(char**, char*, size_t);