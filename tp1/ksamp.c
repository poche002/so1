/*
 * ksamp.c
 * 
 * Copyright 2014 poche002 <poche002@poche002-Compaq-Mini-CQ10-100>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define BUFFSIZE 256

int main(int argc, char **argv)
{
	char model[11] = "model name"; 
	FILE *fd; 
	char buffer[BUFFSIZE+1]; 
	if((fd = fopen("/proc/cpuinfo","r"))!=NULL){
		while(!feof(fd)){
			fgets(buffer, BUFFSIZE+1, fd); 
			if(strstr(buffer, model)){
				printf("%s", buffer);
			}
		}
		fclose(fd);
	}else{
		printf("El archivo no existe\n");
	}
	char str1[10], str2[10], str3[30];
	
	if((fd = fopen("/proc/version","r"))!=NULL){ 
		fscanf(fd, "%s %s %s", str1, str2, str3); 
		printf("%s %s %s\n", str1, str2, str3); 
		fclose(fd);
	}else{
		printf("El archivo no existe\n");
	}
	
	return 0;
}

