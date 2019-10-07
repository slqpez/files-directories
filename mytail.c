#include <stdio.h>
#include <stdlib.h>

void tail(FILE*, int);

void main(int argc, char* argv[]){
  if(argc != 3){
    printf("Cantidad de parametros incompletos\n");
    exit(1);
  }
  int n = 0;
  if((*argv[1]) == '-'){
  	n = atoi(argv[1]+1);
  }else{
	printf("Debe ingresar los parametros correctamente\n");
	exit(1);
  }
  FILE* fp;
  fp = fopen(argv[2], "rb");
  if(fp == NULL){
    printf("Error \n");
    exit(1);
  }
  fflush(fp);
  tail(fp, n);
  fclose(fp);
}

void tail(FILE* in, int n){
    int count = 0;
    unsigned long long pos;
    char str[2*100];
    if (fseek(in, 0, SEEK_END))
        perror("fseek() fallo");
    else{
        pos = ftell(in);
        while (pos){
            if (fseek(in, --pos, SEEK_SET) != -1){
                if (fgetc(in) == '\n'){
			if (count++ == n)
                        break;
		}
                    
		
            }
            else
                perror("fseek() fallo");
        }
	if(pos == 0)
		rewind(in);
        while (fgets(str, sizeof(str), in)){
            printf("%s", str);
	}
		
    }
}