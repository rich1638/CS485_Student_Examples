//***************************************************************************
// File name:  SalaryVisitor.h
// Author:     Ryan Estes and Jacob Richardson
// Date:       3/24/2017
// Class:      CS485
// Assignment: Visitor Pattern Example
// Purpose:    Demonstrate how the Visitor Pattern is implemented
//***************************************************************************
#pragma once

#include "IEmployeeVisitor.h"
#include <iostream>
class SalaryVisitor : public IEmployeeVisitor
{
public:

	SalaryVisitor();

	virtual void visit(Worker &rcWorker);
	virtual void visit(Manager &rcTheMan);

};
