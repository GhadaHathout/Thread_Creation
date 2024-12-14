#include <stdio.h>
#include <pthread.h>

/* Variable globale partagée */
int sum = 0;

void * function0(void *arg){

int i;
	for(i = 0; i < 100000; i++)
		sum += 1;

}

void * function1(void *arg){

int i;
	for(i = 0; i < 100000; i++)
		sum += 1;

}

int main(int argc, char **argv){

	/* Un tableau de deux threads */
	pthread_t threads[2];
	/* Création des deux threads */
	pthread_create(&threads[0], NULL, &function0, NULL);
	pthread_create(&threads[1], NULL, &function1, NULL);
	/* Attendre les deux threads de terminer */
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	/* Afficher la somme finale, =200000 ?? */
	printf("Sum=%d\n", sum)
	return 0;

}
