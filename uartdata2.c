// 2022/3/22
// LA data log transfer
//----------------
// time, dat, clk
//0.05976 ms,1,1
//0.0598 ms,1,0
//0.05984 ms,1,1

#include <stdio.h>

char outfilename[200];

main()
{	
char s[100];
char dat,clk;
int i;
int hasdata;
char preck;
int takedata;

FILE *infile=fopen("20220330-2.txt","r"); // LA log data

FILE *outfile;
	printf("read LA log file \n\r");
	if( infile==NULL) {
		printf(" cannot open LA log file!!");
	        return -1;
	        }
        printf("output filename:   ");
        scanf("%s",outfilename);	        
        if((outfile=fopen(outfilename,"w"))==NULL){
        	printf(" cannot open output file %s",outfilename);
        	return -1;
        }
preck=0; 
takedata=0; 
 while (!feof(infile)){
 	fscanf(infile,"%s",s);
	for(i=0,hasdata=0;i<100; i++){
		if(s[i]=='m') {
			dat=s[i+3];
			clk=s[i+5];
			hasdata=1;
			if(preck=='1' && clk=='0') takedata=1;
			preck=clk;			
			break;
		}
	}
	// print all message!!
	if(hasdata)
		fprintf(outfile,"%d:%c %c\r",takedata,dat,clk);
	// print data only
	//if(hasdata & takedata)
	//	fprintf(outfile,"%c\r",dat);
	
    takedata=0;
        		
}        
        
fclose(infile);
fclose(outfile);       
}