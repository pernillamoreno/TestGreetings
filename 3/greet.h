#ifndef GREET_H
#define GREET_H

#include <cstddef>

// Definition of the Greet interface
struct Greet {
    // Virtual destructor to ensure destruct of derived objects
    virtual ~Greet() = default;

    // virtual function for greeting
    virtual const std::string& greet(const std::string& name) const = 0;
};

// Implementation the simple greeting 
class SimpleGreet : public Greet {
public:
    //implement greetfunc for shout greet 
    const std::string& greet(const std::string& name) const override {
        // Define a static string default greeting
        static const std::string emptyGreeting = "Hello, my friend.";
        static std::string greeting; // Static variable to hold the greeting

        // Check if the name is empty
        if (name.empty()) {
            greeting = emptyGreeting; // Assign 
            return greeting; // Return greeting
        }

        // Construct concatenating "Hello, " with the input name
        greeting = "Hello, " + name;
        return greeting; // Return the greeting
    }
};

class ShoutNameGreet : Greet {
     public:
       const std::string& greet(const std::string& name) const override {

         static std::string greeting;
 
        /*When i pass ::isupper as an argument to std::all_of, 
        you're telling std::all_of to use the ::isupper function 
        to check each character in the range defined by name.begin() and name.end().
        i dont need this part: [](unsigned char c){ return std::isupper(c);} . If i will check for digits i would need it*/
          if (std::all_of(name.begin(), name.end(), [](unsigned char c){ return std::isupper(c);})){
            greeting = "HELLO " + name + "!";
            
        } 
          return greeting; // Return the greeting  
     }        

};
class MultiNamesGreet : public Greet {
public:
    // Implementation of the greet function 
    const std::string& greet(const std::string& name) const override {
        static std::string greeting; // Static variable to hold the greeting


      /*getline reads data isstringstream object iss. Reads char (char stored in storedStrings)chto it 
      comes to stop and then a comma. */
        std::vector<std::string> names;
        std::istringstream iss(name);
        std::string storedStrings;
        while (std::getline(iss,storedStrings, ',')) {
            names.push_back(storedStrings);
        }

        // Check the number of names and construct the greeting after that
        if (names.size() == 1) {
            
            greeting = "Hello, " + name;
        } else if (names.size() == 2) {
            greeting = "Hello, " + names[0] + " and " + names[1] + ".";
        } else {
            // For more than two names, use Oxford comma and "and"
            /*lt loops up to the second-to-last element (names.size() - 1) 
            to avoid adding an extra comma after the last name. */
            greeting = "Hello, ";
            for (size_t i = 0; i < names.size() - 1; ++i) {
                greeting += names[i] + ", ";
            }
            greeting += "and " + names.back() + ".";
        }

        return greeting; // Return the greeting
    }
};

       
#endif 