#ifndef __MY_HASH_HPP__
#define __MY_HASH_HPP__

#include <iostream>
#include<stdio.h>
#include<pthread.h>

typedef struct _Book Book;
typedef struct _Book{
    char title[50];
    char author[50];
    char subject[100];
    int bookId;
    void printBook();

    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(const std::istream&, Book&);
}Book;


#ifndef Box_H
#define Box_H
class Box {
    private:
        double length;
        double breath;
        double height;
    public:
        double getLength();
        double getBreath();
        double getHeight();
        void setLength(float f);
        void setBreath(float f);
        void setHeight(float f);
        void print();
};

#endif

#endif
