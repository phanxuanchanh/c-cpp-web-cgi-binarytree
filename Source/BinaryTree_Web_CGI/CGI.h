#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* CGI_GET(char* key);
char* CGI_POST(char* key);
char* CGI_GETENV(char* varName);
char* CGI_FILEPATH();

char* query_in_request(char* data, char* key);
char* substr(char* str, int start, int end);
int find_char_index_of(char* str, char c);
int find_char_last_index_of(char* str, char c);
char* strcat_ext(char* str1, char* str2);

char* file_get_contents(char* fileName);