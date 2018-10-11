#include<stdio.h>
#include<stdlib.h>

void producer(){
	
	char turn;
	char charData;
	FILE *myData = fopen("mydata.txt", "rt");
	FILE *dFile;
	FILE *tFile;

	while(!feof(myData)){
		while((tFile = fopen("TURN.txt","rt")) == NULL);	
		turn = fgetc(tFile); //gets char from turnFile
		if (turn == '0'){
			dFile = fopen("DATA.txt", "wt");
			charData = fgetc(myData);
			fputc(charData, dFile);
		
			tFile = fopen("TURN.txt", "wt");
			fputc('1', tFile); //changes turn
			fclose(dFile);
		}
	
		fclose(tFile);	
	}
	
	fclose(myData);

}
