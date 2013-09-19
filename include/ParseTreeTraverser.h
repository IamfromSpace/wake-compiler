#ifndef HEADER_PARSE_TREE_TRAVERSER
#define HEADER_PARSE_TREE_TRAVERSER

#include <string>
#include <vector>
#include "ObjectSymbolTable.h"
#include "SemanticErrorPrinter.h"
extern "C" {
	#include "type.h"
	#include "node.h"
	#include "tree.h"
}

using namespace std;

class ParseTreeTraverser {

	public:
		void traverse(Node* tree);
		vector<SemanticError*>* getErrors();
		void printErrors(SemanticErrorPrinter& p);
		~ParseTreeTraverser();

	private:
		void secondPass(Node* tree);
		vector<SemanticError*> errors;

		ObjectSymbolTable objectsymtable;
		string errorcontext;
		string traversingclass_name;
		PropertySymbolTable* traversingclass_data;

};

#endif
