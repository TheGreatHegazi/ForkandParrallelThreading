#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
void producer();
void consumer();

int main(){
	
	//Creates a pointer to TURN.txt
	FILE *tFile = fopen ("TURN.txt" , "wt");
	
	fprintf(tFile, "%c", '0'); //'0' - producer gets first turn 
	fclose(tFile);
	
	//creates a clone of the program
	int pid = fork();

	if(pid == -1){
		exit(1);
	}
	else if (pid == 0) { //in child program
		producer();
	} 
	else if(pid != 0) { //in parent program
		consumer();
	}

	exit(0);
}

