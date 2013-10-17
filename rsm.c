/*Copyright (C) <2013>  <Tyler Morgan>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void printHelpMessage(){
  printf("Incorrect number of arguments\n");
  printf("usage: rsm add ruby /path/to/ruby/bin\n");
  return;
}

int addNewSource(char *destination, char *source_path){
  printf("Adding %s as %s\n", source_path, destination);

  char destination_path[255];
  strncpy(destination_path, getenv("HOME"), 255);
  strncat(destination_path, "/.rsm/bin/", 255);
  strncat(destination_path, destination, 255);

  if(symlink(source_path, destination_path) == 0){
    printf("added\n");
    return 1;
  }else{
    printf("could not add to %s\n", destination_path);
    perror("symlink() error");
    return -1;
  }
}

int main(int argc, char *argv[]){
  if(argc <= 1){
    printHelpMessage();
    return 0;
  }

  if(!strcmp(argv[1], "add") && argc == 4){
    addNewSource(argv[2], argv[3]);
  }

  return 0;
}
