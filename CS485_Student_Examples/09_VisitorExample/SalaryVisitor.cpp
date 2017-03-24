#include "SalaryVisitor.h"

SalaryVisitor::SalaryVisitor()
{
}

void SalaryVisitor::visit(Worker & rcWorker)
{
	if (rcWorker.getSalary() % 2 == 1)
		std::cout << rcWorker.getSalary() << std::endl;
}

void SalaryVisitor::visit(Manager & rcTheMan)
{
	if (rcTheMan.getSalary() % 2 == 0)
		std::cout << rcTheMan.getSalary() << std::endl;
}
