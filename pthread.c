#include <stdio.h>
#include <pthread.h>

/* Variable globale partagée */
int sum = 0;
pthread_mutex_t mutex;


void * function0(void *arg){
	
	int i;
	for(i = 0; i < 100000; i++)
	//while(1)
	{	pthread_mutex_lock(&mutex);
		printf("This is thread 1\n");
		sum += 1;
		pthread_mutex_unlock(&mutex);
	}
}

void * function1(void *arg){

	int i;
	for(i = 0; i < 100000; i++)
	//while(1)
	{	pthread_mutex_lock(&mutex);
		printf("	This is thread 2\n");
		sum += 1;
		pthread_mutex_unlock(&mutex);
	}
}

int main(int argc, char **argv){
	
	/* Initialiser la mutex */
	pthread_mutex_init(&mutex, NULL);

	/* Un tableau de deux threads */
	pthread_t threads[2];
	
	/* Création des deux threads */
	pthread_create(&threads[0], NULL, &function0, NULL);
	pthread_create(&threads[1], NULL, &function1, NULL);
	
	/* Attendre les deux threads de terminer */
	pthread_join(threads[0], NULL);
	pthread_join(threads[1], NULL);
	
	/* Afficher la somme finale, =200000 ?? */
	printf("Sum=%d\n", sum);
	
	return 0;

}
