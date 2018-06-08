
#include <stdio.h>
#include <string.h>
int output2 (const char* str){
	if(str && strlen(str)){
		printf("depend output2:'%s'",str);
	}else{
		printf("depend output2 str is null");
	}
	return 0;
}