
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ): Form("ShrubberyCreation", 145, 137), _target(target) {

  return ;
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

std::string   ShrubberyCreationForm::getTarget(void) const{
  return this->_target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &tmp) {
  if (this == &tmp)
    return *this;
  
  this->_target = tmp.getTarget();
  Form::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream &os, const Form &form) {
    os << "Form Name: " << form.getName() << ", Sign Grade: " << form.getSigGrade() << ", Execute Grade: " << form.getExeGrade() << ", Signed: " << form.getSigned();
    return os;
}

std::ostream &printBranch(std::string prefix, int nodeNum, int depth) {
    std::ostream os;
    
    if (depth == 0) {
        return os;
    }

    std::string branch = prefix + (nodeNum % 2 == 0 ? "| " : "  ");
    os << branch << "Node " << nodeNum << std::endl;

    printBranch(branch + "+-", nodeNum * 2, depth - 1, os);

    printBranch(branch + "`-", nodeNum * 2 + 1, depth - 1, os);

    return os;
}

std::ostream &printTree(int depth, std::ostream &os) {
    std::string trunk = "|-";
    os << "Root" << std::endl;

    printBranch(trunk, 2, depth, os);

    printBranch(trunk, 3, depth, os);
    return os;
}

void ShrubberyCreationForm::execute(Bureaucrat const &var) const{

  Form::execute(var);
  
  std::fstream file;
  file.open(var.getName() + "_shrubbery", std::ios::out );
  if (rand() == 1)
    file << printTree("", 2);
  else if (rand() == 1) 
    file << printTree("", 3);
  else
    file << printTree("", 4);
  file.close();
}

