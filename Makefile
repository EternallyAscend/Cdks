OUTPUT_FOLDER = output
BINARY_NAME = cdks
BINARY_PATH = ./$(OUTPUT_FOLDER)/$(BINARY_NAME)

CC = gcc

test:
	make compile run
compile:
	$(shell if [ ! -d $(OUTPUT_FOLDER) ]; then mkdir $(OUTPUT_FOLDER); fi)
	$(CC) -o $(BINARY_PATH) main.c algorithm/compare/* dataStructure/linear/* dataStructure/nonlinear/*
run:
ifeq ($(OS),Windows_NT)
	-$(BINARY_PATH).exe
else
	-$(BINARY_PATH)
	# UNAME_S := $(shell uname -s)
	# ifeq ($(UNAME_S),Linux)
	# 	-$(BINARY_PATH)
	# endif
	# ifeq ($(UNAME_S),Darwin)
	# 	-$(BINARY_PATH)
	# endif
	# UNAME_P := $(shell uname -p)
endif
.PHONY: clean
clean:
	-rm -r -f $(OUTPUT_FOLDER)
