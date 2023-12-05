#include "CGI.h"

char* CGI_GET(char* key) {
	char* queryPtr = CGI_GETENV((char*)"QUERY_STRING");
	if (queryPtr == nullptr) {
		return nullptr;
	}
	char* query = queryPtr;
	return query_in_request(query, key);
}

char* CGI_POST(char* key) {
	char* queryPtr = CGI_GETENV((char*)"CONTENT_LENGTH");
	int len = 0;
	if (queryPtr != NULL && (len = atoi(queryPtr)) != 0) {
		char* post_data = (char*)malloc(len * sizeof(char));
		fgets(post_data, len + 1, stdin);
		return query_in_request(post_data, key);
	}
	return nullptr;
}

char* CGI_GETENV(char* varName) {
	char* pValue;
	size_t len;
	errno_t err = _dupenv_s(&pValue, &len, varName);
	if (err != 0)
		return nullptr;
	return pValue;
}

char* CGI_FILEPATH(){
	char* filePath = CGI_GETENV((char*)"SCRIPT_FILENAME");
	if(filePath == nullptr)
		return nullptr;
	int index = find_char_last_index_of(filePath, '/');
	return substr(filePath, 0, index);
}


char* query_in_request(char* data, char* key) {
	/*char* temp = (char*)realloc(key, (strlen(key) + 2) * sizeof(char));
	if (temp == nullptr)
	return nullptr;
	key = temp;
	strcat_s((char*)key, (strlen(key) + 2), "=");*/
	char* find = strstr(data, key);
	if (find == nullptr)
		return nullptr;
	int keyLength = strlen(key);

	// ?query=phanchanh&key=hhhhdds
	int find_idx = find_char_index_of(find, '&');
	int end_idx = (find_idx == -1) ? strlen(find) - 1 : (find_idx == 0) ? find_idx : find_idx - 1;

	char* value = substr(find, strlen(key), end_idx);
	return value;
}

int find_char_index_of(char* str, char c){
	if(str == nullptr)
		return -1;
	for(int i = 0; str[i] != '\0'; i++){
		if(str[i] == c)
			return i;
	}
	return -1;
}

int find_char_last_index_of(char* str, char c){
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] == c)
			return i;
	}
	return -1;
}

char* substr(char* str, int start, int end) {
	if (start < 0 || end >strlen(str) - 1 || start > end)
		return nullptr;
	char* newStr = (char*)malloc(((end - start) + 2) * sizeof(char));
	int count = 0;
	for (int i = start; i <= end; i++) {
		newStr[count] = str[i];
		count++;
	}
	newStr[count] = '\0';
	return newStr;
}

char* file_get_contents(char* fileName){
	if(fileName == nullptr)
		return nullptr;
	FILE* file;
	errno_t err = fopen_s(&file, fileName, "r");
	if(err != 0 || file == nullptr)
		return nullptr;
	char* str = nullptr;
	char* read = (char*)malloc(300 * sizeof(char));
	while (!feof(file)){
		fgets(read, 300, file);
		str = strcat_ext(str, read);
	}
	return str;
}

char* strcat_ext(char* str1, char* str2){
	char* newStr = nullptr;
	if(str1 == nullptr){
		if(str2 == nullptr)
			return nullptr;
		newStr = (char*)malloc((strlen(str2) + 1)* sizeof(char));
		int i;
		for(i = 0; str2[i] != '\0'; i++){
			newStr[i] = str2[i];
		}
		newStr[i] = '\0';
		return newStr;
	}
	newStr = (char*)malloc((strlen(str1) + strlen(str2) + 1) * sizeof(char));
	int index;
	for(int i = 0; str1[i] != '\0'; i++){
		newStr[i] = str1[i];
		index = i;
	}
	for(int i = 0; str2[i] != '\0'; i++){
		newStr[++index] = str2[i];
	}
	newStr[++index] = '\0';
	return newStr;
}