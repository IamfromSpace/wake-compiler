/**************************************************
 * Source Code for the Original Compiler for the
 * Programming Language Wake
 *
 * Foreach.h
 *
 * Licensed under the MIT license
 * See LICENSE.TXT for details
 *
 * Author: Michael Fairhurst
 * Revised By:
 *
 **************************************************/

#ifndef HEADER_AST_FOREACH
#define HEADER_AST_FOREACH

#include "ast/StatementNode.h"
#include "ast/ExpressionNode.h"
#include "tree.h"
#include "ScopeSymbolTable.h"
#include "ErrorTracker.h"

namespace wake {

	namespace ast {

		class Foreach : public StatementNode {

			public:
				Foreach(ExpressionNode* iterable, StatementNode* body, Node* node, ScopeSymbolTable* scopesymtable, ErrorTracker* errors)
					: iterable(iterable), body(body), node(node), scopesymtable(scopesymtable), errors(errors) {};

				virtual void typeCheck();

				virtual Type getIterationType(Type* iterableType);

			private:
				ExpressionNode* iterable;
				StatementNode* body;
				Node* node;
				ScopeSymbolTable* scopesymtable;
				ErrorTracker* errors;

		};

	}

}

#endif