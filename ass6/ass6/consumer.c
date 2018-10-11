//CONSUMER.C
#include<stdio.h>
#include<stdlib.h>

void  consumer() {
	
	char turn = '0';
	char charData;
	FILE *tFile; //pointer to TURN.txt
	FILE *dFile; //pointer to DATA.txt

	// consumer waits for its turn
	while(turn == '0'){
		(tFile = fopen("TURN.txt","rt")) == NULL;
		turn = fgetc(tFile);
		fclose(tFile);
	}

	dFile = fopen("DATA.txt", "rt");
	while ((charData = getc(dFile)) != EOF){
		fclose(dFile);
		printf("%c", charData);
		
		turn = '0'; //turns changed from consumer to producer
		tFile = fopen("TURN.txt", "wt");
		fprintf(tFile, "%c", turn);
		fclose(tFile);

		while(turn == '0'){ //consumer waits for turn again
			(tFile = fopen("TURN.txt","rt")) == NULL;
			turn = fgetc(tFile);
			fclose(tFile);
		}
		
		dFile = fopen("DATA.txt", "rt");
	}
	fclose(dFile);
}

