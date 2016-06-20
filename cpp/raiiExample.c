#include <stdio.h>

// https://www.ibm.com/developerworks/community/blogs/karsten/entry/raii_with_c_libraries?lang=en
// 《C 和 指针》2.5 小节

#define RAII_VARIABLE(vartype,varname,initval,dtor) \
	    void _dtor_ ## varname (vartype * v) { dtor(*v); } \
    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)

void free_test(void *in){
	printf("%s\n", in);
	free(in);
}

void raiiExample(){
	RAII_VARIABLE(char*, name, (char *)malloc(32), free_test);
	strcpy(name, "RAII EXAMPLE");
}

int main(){
	raiiExample();

}
