
#include <stdio.h>
#include <string.h>
int output (const char* str){
	if(str && strlen(str)){
		printf("depend output:'%s'",str);
	}else{
		printf("depend output str is null");
	}
	return 0;
}