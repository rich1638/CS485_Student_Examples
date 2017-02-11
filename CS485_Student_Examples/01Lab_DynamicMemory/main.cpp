//***************************************************************************
// File name:  main.cpp
// Author:     Chadd Williams
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Lab
// Purpose:    Practice using raw pointers
//***************************************************************************

#define MEM_DEBUG
#include "mem_debug.h"

#include <iostream>
#include "PacString.h"

int main ()
{
  _CrtSetDbgFlag (_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  PacString s1 = "Hello!";

  std::cout << "s1:" << s1 << std::endl;

  PacString s2 ("World");
  std::cout << "s2: " << s2 << std::endl;

  PacString s3;

  s3 = s1 + s2;

  std::cout << "s3: " << s3 << std::endl;

  s3 += (s3 + "!!");

  std::cout << "s3: " << s3 << std::endl;



  // TODO:
  PacString *pcDynString;

  // dynamically allocate the PacString object using
  // pcDynString.
	pcDynString = new PacString();
  // Assign "CS485" to pcDynString.
	*pcDynString = "CS485";
  // Display pcDynString.
	std::cout << *pcDynString << std::endl;

  // concatenate " is the best!" on to
  // pcDynString
	*pcDynString += " is the best!";

  // Display pcDynString.
	std::cout << *pcDynString;

  // deallocate the object pcDynString 
	delete pcDynString;

  return EXIT_SUCCESS;
}


