
#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm( std::string new_target ): Form("ShrubberyCreation", 145, 137), _target(new_target) {

  return ;
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & var ): Form(var.getName(), var.getSigGrade(), var.getExeGrade()), _target(var.getTarget()) {
  *this = var;
  return ;
  
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

}

std::string   ShrubberyCreationForm::getTarget(void){
  return this->_target;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &tmp) {
  if (this == &tmp)
    return *this;
  
  this->_target = tmp.getTarget();
  Form::operator=(tmp); 
  
  return *this;
}


std::ostream &operator<<(std::ostream& os, const ShrubberyCreationForm &tmp) {

  (void) tmp;
  os << std::endl << static_cast<Form>(tmp) << "Signned: " << tmp->getSigned()  << std::endl;
  return (os);
  
}


void ShrubberyCreationForm::execute(Bureaucrat &tmp){

  Form::execute(tmp)
  
  std::fstream file;
  file.open(tmp.getName() + "_shrubbery", std::ios::out )
  file << printTree()
  file.close()
}


std::ostream &printBranch(std::string prefix, int nodeNum, int depth, std::ostream &os) {
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

