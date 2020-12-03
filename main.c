#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
char* global_args[100];
char ** parse_args(char * line){
	char **args=global_args;
	char *p=line;
	int i=0;
	args[i]=strsep(&p," ");
	while(args[i]){
		i++;
		args[i]=strsep(&p," ");
	}
	return args;
}

int main() {
	char command[]="ls -l -a";
	char **args=parse_args(command);
	execvp(args[0],args);
	return 0;
}