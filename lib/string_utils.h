#ifndef STRING_UTILS_H
#define STRING_UTILS_H 
/**
* Modifies the string in place to remove all white space. 
* If the string was allocated dynamically, the caller must be careful to not 
* overwrite the original pointer with the return value as then memory will be lost.
*/
char* trim(char* str);
#endif
