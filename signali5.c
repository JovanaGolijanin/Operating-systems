#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define RED_PORUKA 10001
#define MAX_PORUKA 10
struct poruka
{
	 long tip;
	 char tekst[MAX_PORUKA];
};
int main()
{
	 int pid;
	 int redid;
	 int broj = 0;
	 struct poruka bafer;

	 //Kreiramo novi proces
	 pid = fork();

	 if (pid < 0)
	 {
		 printf("Doslo je do greske prilikom kreiranja novog procesa\n");
		 exit(1);
	 }
	 if (pid == 0)
	 {
		 //Izvrsava pbroj);roces dete
		 if (execl("zadatak5b", "zadatak5b", NULL) < 0)
		 {
		 	printf("Doslo je do greske prilikom ucitavanja izvrsne datoteke\n");
		 }

		 exit(1);
	 }

	 //Kod koji izvrsava samo proces roditelj
	 //Pribavlja se referenca na red poruka. Red se kreira ukoliko ne postoji
	 redid = msgget(RED_PORUKA, IPC_CREAT | 0666);
	 if (redid < 0)
	 {
		 printf("Doslo je do greske prilikom kreiranja novog procesa\n");
		 exit(1);
	 }
	 //primaju se poruke iz reda poruka sve dok ne stigne poruka -1
	 do
		 {
		 if (msgrcv(redid, &bafer, MAX_PORUKA, 0, 0) < -1)
		 {
			 printf("Doslo je do greske prilikom prijema poruke\n");
			 exit(1);
		 }
		 broj = atoi(bafer.tekst);
		 printf("%d\n", broj);
	 }
	 while( broj > -1);

	 wait(NULL);
	 msgctl(redid, IPC_RMID, 0);
	 return 0;
}