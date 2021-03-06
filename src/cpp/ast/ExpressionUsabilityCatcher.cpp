/**************************************************
 * Source Code for the Original Compiler for the
 * Programming Language Wake
 *
 * ExpressionUsabilityCatcher.cpp
 *
 * Licensed under the MIT license
 * See LICENSE.TXT for details
 *
 * Author: Michael Fairhurst
 * Revised By:
 *
 **************************************************/


#include "ast/ExpressionUsabilityCatcher.h"

Type* wake::ast::ExpressionUsabilityCatcher::typeCheck(bool forceArrayIdentifier) {
	Type* t = child->typeCheck(forceArrayIdentifier);

	if(t == NULL) {
		return new Type(TYPE_UNUSABLE);
	}

	if(t->type == TYPE_UNUSABLE) {
		errors->addError(new SemanticError(USE_OF_ASSIGNMENT_VALUE, "", node));
		t->type = TYPE_MATCHALL;
	}

	return t;
}
