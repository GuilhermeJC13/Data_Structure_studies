typedef struct pilha Pilha;

Pilha* criaPilha(char valor);
int ehVazioPilha(Pilha* PrimeiroTermo);
int inserePilha(Pilha** primeiroTermo, char valor);
int existePilha(Pilha* primeiroTermo, char valor);
void printaPilha(Pilha* primeiroTermo, char* mensagem);
void limpaPilha(Pilha** primeiroTermo);
char removerPilha(Pilha** primeiroTermo);