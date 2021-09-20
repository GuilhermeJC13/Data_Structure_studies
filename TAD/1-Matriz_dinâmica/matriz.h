
typedef struct matriz Matriz;

Matriz* cria_matriz(int numero_linhas, int numero_colunas);
void libera_matriz(Matriz * matriz);
int acessa_matriz(Matriz * matriz, int linha, int coluna, float *valor);
int atribui_matriz(Matriz * matriz, int linha, int coluna, float valor);
int numero_linhas(Matriz * matriz);
int numero_colunas(Matriz * matriz);


