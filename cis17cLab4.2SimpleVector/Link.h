/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Linked from first principles
 */

#ifndef LINK_H
#define LINK_H

template <typename T>
struct Link
{
    T data;     //Some type of data
    Link *lnkNext; //Next Link in the chain
    
};

#endif /* LINK_H */

