//
//  Stack.h
//  Data_Structure
//
//  Created by Erick González on 9/14/18.
//  Copyright © 2018 Erick González. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
template<typename T>
class Stack(){
public:
    
    void pop();
    void push();
    bool isEmpty();
    T top();
private:
    T dato;
};




#endif /* Stack_h */
