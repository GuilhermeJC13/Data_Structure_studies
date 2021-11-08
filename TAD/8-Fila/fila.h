typedef struct fila Fila;

Fila* criaFila(char valor);
int ehVazioFila(Fila* PrimeiroTermo);
int insereFila(Fila** primeiroTermo, char valor);
int existeFila(Fila* primeiroTermo, char valor);
void printaFila(Fila* primeiroTermo, char* mensagem);
void limpaFila(Fila** primeiroTermo);
char removerFila(Fila** primeiroTermo);