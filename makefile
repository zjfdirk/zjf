CC = gcc 
CFLGAS = -Wall -g -O0

SRC = linkflight.c test.c
APP = test

$(APP):$(SRC)
	    $(CC) $(CFLGAS) -o $@ $^

clean:
	    $(RM) $(APP) 




















