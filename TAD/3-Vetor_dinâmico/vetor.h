typedef struct vetor Vetor;

Vetor * cria_vetor(int dimensao);
int insere_vetor(Vetor* vetor, float valor);
int tamanho_vetor(Vetor* vetor);
int acessa_vetor(Vetor* vetor, int posicao, float *valor);
void libera_vetor(Vetor* vetor);