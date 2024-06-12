#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default Robotomy", 72, 45, "Default Robotomy Target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other.getName(), other.getRequiredExecute(), other.getRequiredSign(), other.getTarget())
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("Robotomy Request Form", 72, 45, target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
        this->_signed = other.getSigned();
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    (void)executor;
    //std::cout << executor.getName() << " is making some drilling noises" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->getTarget() << CYAN <<" has been robotomized successfully!" << RESET <<std::endl;
    else
        std::cout << this->getTarget() << CYAN << "'s robotomy failed!" << RESET << std::endl;
}