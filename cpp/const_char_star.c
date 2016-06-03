/*
 * http://stackoverflow.com/questions/4949254/const-char-const-versus-const-char
 *
 * The latter prevents you from modifying the_string inside print_string. It would actually be appropriate here, but perhaps the verbosity put off the developer.
 *
 * char* the_string : I can change the char to which the_string points, and I can modify the char at which it points.
 *
 * const char* the_string : I can change the char to which the_string points, but I cannot modify the char at which it points.
 *
 * char* const the_string : I cannot change the char to which the_string points, but I can modify the char at which it points.
 *
 * const char* const the_string : I cannot change the char to which the_string points, nor can I modify the char at which it points.
 *
 */
#include <stdio.h>

int main()
{
	const char * p = "hello";
	printf("%p\n", p);

	char *const c = "hello";
	printf("%p\n", c);

	p = "test";
//	c = "test";		// not valid for Pointer c is const and cannot be changed where it point
	printf("%p\n", p);
}
