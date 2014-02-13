#ifndef HEADER_PARSER
#define HEADER_PARSER

#include <stdio.h>

extern "C" {
	#include "type.h"
	#include "node.h"
	#include "tree.h"
	#include "y.tab.h"
	extern int wakeparse();
	extern void wake_scan_string(const char* string);
	extern Node* parsetree;
	extern FILE *wakein;
}

class Parser {
	public:
		 bool parse(FILE* input);
		 bool parse(const char* input);
		 void print();
		 Node* getParseTree();
		 ~Parser();
};

#endif
