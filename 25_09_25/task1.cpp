#include <iostream>
#include <string>
#include <vector>
#include <limits> 

struct EnrollmentRecord {
    int unique_identifier;
    std::string full_name;    
    std::string contact_email; 
};

int main() {
    int continue_entry = 1;
    
    while (continue_entry != 2) {
        int record_count; 
        std::cout << "Input the total number of student records to process: ";
        
        if (!(std::cin >> record_count)) {
            std::cerr << "Invalid input. Exiting.\n";
            return 1;
        }

        std::vector<EnrollmentRecord> student_list;
        student_list.reserve(record_count); 

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "\n--- BEGIN DATA ENTRY ---\n";
        for (int i = 0; i < record_count; ++i) { 
            EnrollmentRecord current_student; 
            
            std::cout << "\nRecord #" << i + 1 << " Information:\n";
            
            std::cout << "  Enter Full Name: ";
            std::getline(std::cin, current_student.full_name); 
            
            std::cout << "  Enter ID Number: ";
            
            std::cin >> current_student.unique_identifier;
            
            std::cout << "  Enter Contact Email: ";
            
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cin >> current_student.contact_email;

            student_list.push_back(current_student);
            
         
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        
        std::cout << "\n--- VERIFYING RECORDS ---\n";
       
        int index = 0;
        for (const auto& student_rec : student_list) {
            std::cout << "\nRecord #" << ++index << " Summary:\n";
            std::cout << "  Name:  " << student_rec.full_name << "\n";
            std::cout << "  ID:    " << student_rec.unique_identifier << "\n";
            std::cout << "  Email: " << student_rec.contact_email << "\n";
        }

      
        std::cout << "\nOperation Complete. Would you like to process another batch?\n";
        std::cout << "  (1 to continue, 2 to exit): ";
        std::cin >> continue_entry;
      
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "\nApplication closing. Goodbye!\n";
    return 0;
}