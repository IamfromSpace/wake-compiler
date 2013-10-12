#ifndef HEADER_SCOPE_SYMBOL_TABLE
#define HEADER_SCOPE_SYMBOL_TABLE

#include <string>
#include <vector>
#include <map>

extern "C" {
	#include "type.h"
}

#include "AddressAllocator.h"

using namespace std;

class ScopeSymbolTable {

	public:
		ScopeSymbolTable() {
			scopes.push_back(vector<string>());
		}

		void add(string name, Type* type);
		void add(Type* type);
		Type* get(string name);
		Type* get(Type* type);
		string getAddress(Type* type);
		string getAddress(string name);
		void pushScope();
		void popScope();

	private:
		AddressAllocator allocator;
		string getNameForType(Type* type);
		map<string, pair<Type*, string> > table;
		vector<vector<string> > scopes;
};

#endif