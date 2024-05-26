#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
/**
* Determine if the string s starts with the string prefix.
* @param s - the string to see if it starts with prefix
* @param prefix - the prefix to test
* @returns true if the strings begins with the prefix.
*/
int startsWith(const char s[], const char prefix[]) {
    int sz = strlen(prefix);
    if (strlen(s) < sz) return 0; // Check if s is shorter than prefix

    return strncmp(s, prefix, sz) == 0; // Use strncmp to compare prefix directly in s
}

/**
* Determine if the string s ends with the string suffix.
* @param s - the string to see if it ends with suffix
* @param suffix - the suffix to test
* @returns true if the strings ends with the suffix.
*/
int endsWith(const char s[], const char suffix[])
{
int sz = strlen(suffix);
int slen = strlen(s);
return 0 == strcmp(s + slen - sz, suffix);
}
int main(void)
{
char s1[] = { "upended" };
char prefix[] = { "up" };
char suffix[] = { "ed" };
printf("%s does %s start with %s\n",
s1, startsWith(s1, prefix) ? "" : " not", prefix);
printf("%s does %s end with %s\n",
s1, endsWith(s1, suffix) ? "" : " not", suffix);
return 0;
}