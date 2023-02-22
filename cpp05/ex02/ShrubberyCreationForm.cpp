
#include "ShrubberyCreationForm.hpp"

std::ostream &printTree(int depth, std::ostream &os);

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


std::ostream &operator<<(std::ostream &os, const ShrubberyCreationForm &form) {
    os << "Form Name: " << form.getName() << ", Sign Grade: " << form.getSigGrade() << ", Execute Grade: " << form.getExeGrade() << ", Signed: " << form.getSigned();
    return os;
}


void printBranches(int numSpaces, int numBranches, std::ostream& os) {
    for (int i = 0; i < numBranches; i++) {
        os << std::string(numSpaces, ' ') << "#";
        os << std::string(i, 'o') << "#";
        os << std::string(numBranches - i - 1, 'o') << "#";
        os << std::endl;
        numSpaces--;
    }
}

void printTrunk(int numSpaces, int trunkHeight, std::ostream& os) {
    for (int i = 0; i < trunkHeight; i++) {
        os << std::string(numSpaces, ' ') << "#";
        os << std::string(trunkHeight - 1, '|') << "#";
        os << std::endl;
    }
}

std::ostream& printChristmasTree(int treeHeight, int trunkHeight, std::ostream& os) {
    int numBranches = 1;
    int numSpaces = treeHeight - 1;

    for (int i = 0; i < treeHeight - trunkHeight; i++) {
        printBranches(numSpaces, numBranches, os);
        numSpaces--;
        numBranches++;
    }

    printTrunk(treeHeight - trunkHeight, trunkHeight, os);

    return os;
}

void ShrubberyCreationForm::execute(Bureaucrat const &var) const{

  Form::execute(var);
  
  std::fstream file;
  file.open(var.getName() + "_shrubbery", std::ios::out );
  std::random_device rd; // obtener una semilla aleatoria del sistema
  std::mt19937 gen(rd()); // generar números aleatorios con la semilla
  std::uniform_int_distribution<> distrib(0, 1); // distribución uniforme en el rango 0-1

  if (distrib(gen) == 0){
    printChristmasTree(5, 2, file);
  }
  else if (distrib(gen) == 1){
    printChristmasTree(6, 3, file);
  }
  else{
    printChristmasTree(16, 8, file);
  }
  file.close();
}

