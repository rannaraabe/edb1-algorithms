#ifndef SEARCHING_H
#define SEARCHING_H
using value_type = unsigned long ;

const value_type * lsearch( const value_type *, const value_type *, value_type );

const value_type * binarySearch( const value_type *, const value_type *, value_type );

const value_type * ternarySearch( const value_type* first, const value_type* last, const value_type value );

const value_type * fibonacciSearch( const value_type* first, const value_type* last, value_type value );

const value_type * jumpSearch( const value_type* first, const value_type* last, value_type value );

const value_type * rbinarySearch( const value_type *, const value_type *, value_type );

const value_type * rternarySearch( const value_type* first, const value_type* last, const value_type value );

#endif
