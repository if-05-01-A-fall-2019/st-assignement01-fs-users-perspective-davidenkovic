//
// Created by david on 12.03.2020.
//

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("Error\n");
    return 0;
  }
  char* firstParameter = argv[1];
  char* secoundParameter = argv[2];
  int fd = open(firstParameter,O_RDONLY);
  char buffer[sizeof(fd) + 1];
  read(fd,&buffer,sizeof(fd) + 1);
  int cpFile = open(secoundParameter,O_WRONLY | O_CREAT);
  printf("%s\n",buffer);
  write(cpFile,&buffer,sizeof(fd) + 1 );
  close(fd);
}
