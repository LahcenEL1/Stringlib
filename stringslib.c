

#include "stringslib.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>




size_t str_length(const char *str) {
	size_t compteur=0;  
	if (str == NULL) {
		return 0;
	}
	while(str[compteur]!= '\0'){
	
		compteur++;
	}
  return compteur;
}

int str_compare(const char *str1, const char *str2) { 
	int i;
	while(str1[i]!='\0' || str2[i]!='\0'){
		if(str1[i]<str2[i]){
		return -1;
		}else if(str1[i]>str2[i]){
		return 1;
		}
		i++;
	}	
	if(str1[i]=='\0' && str2[i]!='\0'){
		return -1;
	} else if (str1[i]!='\0' && str2[i]=='\0'){
		return 1;
	}

  return 0;
}

const char *str_search(const char *haystack, const char *needle) {
int i=0;
int j;
	while(haystack[i] != '\0'){
		j=0;
		while(needle[j]!='\0' && haystack[i]==needle[j]){
		 	i++;j++;
		 }
		 if(needle[j]=='\0'){
		 	return &haystack[i-j];
		 } else {
		 	i++;
		 }
		 
	}
	
  return NULL;
}


const char *str_search_first_char(const char *haystack, char needle) {
	int i=0;
	while(haystack[i] !='\0'){
		if(haystack[i] == needle){
		return &haystack[i];
		}
	i++;
	}
  return NULL;
}

const char *str_search_last_char(const char *haystack, char needle) {
	int i=0;
	char *c=NULL;

	while(haystack[i] !='\0'){
		if (haystack[i] == needle){
			c = &haystack[i];
		}
		i++;
	}

  return c;
}


size_t str_prefix_accept(const char *str, const char *chars) {
int i=0;
int j=0;
size_t compteur =0;
while(str[i]!='\0'){
	j=0;
	while(chars[j]!=str[i] && chars[j]!='\0')
		j++;
	if(str[i]==chars[j])
		compteur++;
	else
		return compteur;
	i++;
}

  return compteur;


}

size_t str_prefix_reject(const char *str, const char *chars) {
int i=0;
int j=0;
size_t compteur =0;
while(str[i]!='\0'){
	j=0;
	while(chars[j]!=str[i] && chars[j]!='\0')
		j++;
	if(str[i]==chars[j])
		return compteur;
	else
		compteur++;
	i++;
}
  return compteur;
}

int str_to_integer(const char *str) {

	int nombre=0;

	int i =0;
	while(str[i] != '\0' && str[i]>='0' && str[i]<= '9'){

			nombre = nombre*10 + (str[i]-'0'); 
		i++;
	}

	return nombre;

}


int str_to_integer_ex(const char *str, const char **endptr, int base) {
	int i=0;
	int res=0;
	int n;

	while(str[i]!='\0'){
		
		if(str[i]>='0' && str[i]<='9'){
			n=str[i]-'0';
		} else if(str[i]>='a' && str[i]<='z'){ //
			n=(str[i]-'a')+10;
		} else if(str[i]>='A' && str[i] <= 'Z'){
			n=(str[i]-'A')+10;

		} else {
			if(endptr!=NULL){
				*endptr=&str[i];
			}
			return res;
		}
		if(n>=base){
			if(endptr!=NULL){
				*endptr=&str[i];
			}
			return res;
		} else {

			res=res*base + n;
		}
		i++;

	}
  return res;


}



void str_from_integer(char *dest, size_t size, int n) {
int i=1;
int j=0;
int m=n;
while(m/10>0){
	i*=10;
	m/=10;
}

m=n;

while(i>0 && j<size-1){ 


	dest[j]='0'+m/i;
	m=m-i*(m/i);
	i/=10;
	j++;
	
}
dest[j]='\0';

}

void str_copy(char *dest, size_t size, const char *str) {

int i=0;

while(i<size-1 && str[i]!='\0'){
	dest[i]=str[i];
	i++;
}
dest[i] = '\0';
}


char *str_duplicate(const char *str) {

	int l = str_length(str);
	char *s = malloc((l+1)*sizeof(char));
	for (int i=0;i<l;i++){
		s[i] = str[i];
	}
	s[l]='\0';
  return s;
  return NULL;
}

void str_concat_string(char *dest, size_t size, const char *str) {
int l=str_length(dest);

int i=0;
while(l<size-1 && str[i]!='\0'){
	dest[l] = str[i];
	l++; i++;
}
dest[l]='\0';

}

void str_concat_char(char *dest, size_t size, char c) {
int l=str_length(dest);

if(l<size-1){
	dest[l]=c;
	l++;
	dest[l]='\0';
}


}

void str_concat_integer(char *dest, size_t size, int n) { 
int l = str_length(dest);
char *s = malloc((size-l+1)*sizeof(char));
str_from_integer(s,size-l,n);
str_concat_string(dest,size,s);
free(s);


}

void str_concat_array(char *dest, size_t size, const char *args[], char separator) {
int i=0;

	while(args[i]!=NULL && dest[size-1]!='\0'){ 
		
		str_concat_char(dest,size,separator);
		str_concat_string(dest,size,args[i]);
		i++;
		
	}

}
char *str_join_string(const char *str1, const char *str2, char separator) {
int l1 = str_length(str1);
int l2 = str_length(str2);
int size=l1+l2+2;
char *s = malloc(size*sizeof(char));
str_concat_string(s,size,str1);
str_concat_char(s,size,separator);
str_concat_string(s,size,str2);
return s;
  

}



char *str_join_array(const char *args[], char separator) {

/*
//CA FAIT UNE FUITE MEMOIRE DU COUP JE L'AI PAS MIS 

if(args[0]==NULL){
	char *s = malloc(sizeof(char));
	s[0]='\0';
	return s;
}
int i=0;
int l=0;
while(args[i]!=NULL){
	l+=str_length(args[i]);
	l++;
	i++;
}
l++;

i=0;
char *s=malloc(l*sizeof(char));
for(i=0;i<l;i++){ 
	s[i]='X';
}
s[0]='\0';

str_concat_array(s,l,args,separator);
i=0;
s++;
char *s2 = malloc((l-1)*sizeof(char));
str_copy(s2,l-1,s);



return s2;
*/
return NULL;


}



