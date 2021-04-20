#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
#include "Date.h"
#include "Time.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;


template <class T>
class Vector
{
public:
    Vector();
   ~Vector();


   bool is_Vector_Empty() const;


        /***************************************************************************
         *@brief    : get_Current_Maximum_Size
         *@brief    : gets storage vectors current maximum size
         *
         *
         *@param    :
         *@return   : m_Current_Max_Size (const int)
         ****************************************************************************/

    int get_Current_Maximum_Size() const;



        /***************************************************************************
         *@brief    : get_Current_Vector_Size
         *@brief    : gets the current size of the storage vector
         *
         *
         *@param    :
         *@return   : m_Current_Size (const int)
         ****************************************************************************/

    int get_Current_Vector_Size() const;



        /***************************************************************************
        *@brief    : get_Vector_Item
        *@brief    : gets an item from storage vector
        *
        *
        *@param    : item_Number (int)
        *@return   : (const T)
        ****************************************************************************/


    T get_Vector_Item(int item_Number) const;


        /***************************************************************************
         *@brief    : add_Item
         *@brief    : adds an item to the current storage_Vector
         *             if the current size of storage_Vector is less than the current maximum size of storage_Vector add an item
         *             else make storage_Vectors current_Maximum_Size double and then add the item to storage_Vector
         *
         *
         *@param    : const T& item
         *@return   : storage_Vector[item_Number] (Template T)
         ****************************************************************************/

    void add_Item(const T& add_Item);



        /***************************************************************************
         *@brief    : remove_Item
         *@brief    : removes an item from the vector if the item is there
         *
         *
         *@param    : const T& item
         *@return   : void
         ****************************************************************************/

	void remove_Item(const T& remove_Item);
        
        //requires the following 
        //constructor
        //destructor
         /// assignment opperator
        ///  Overloads the assignment operator

    

    ~Vector();
    /************************************************************************************************************************************************************************************
     *@brief    :variables
     *************************************************************************************************************************************************************************************/

private:
    T*  storage_Vector;
    int m_Current_Size;
    int m_Current_Maximum_Size;

}

/**********************************************************************************************************************
    End of Vector Template below is vector function deffinitions
    is_Vector_Empty()
    get_Current_Maximum_Size()
    get_Current_Vector_Size()



 ***********************************************************************************************************************/

    /************************************************************************************************************************************************************************************
     *@brief    :Implementations of the vector functions
     *************************************************************************************************************************************************************************************/


template <class T>
Vector<T>::Vector()
{
    m_Current_Maximum_Size = 1;
    m_Current_Size         = 0;
}

    /************************************************************************************************************************************************************************************
     *@brief    :Destructor of the vector functions
     *************************************************************************************************************************************************************************************/

template <class T>
Vector<T>::~Vector()
{
    delete[] storage_Vector;
}



    /************************************************************************************************************************************************************************************
     *@brief    :get_Current_Size function implementation
     *************************************************************************************************************************************************************************************/

template <class T>
int Vector<T>::get_Current_Size() const
{
    return m_Current_Size;
}



    /************************************************************************************************************************************************************************************
     *@brief    : gets the current maximum size of the vector
     *************************************************************************************************************************************************************************************/

template <class T>
int Vector<T>::get_Current_Maximum_Size() const
{
    return m_Current_Maximum_Size;
}






/********************************************************************************************
 @brief add_Item  function definition
 @brief adds an item to the vector if the current

 ********************************************************************************************/


template<class T>
void Vector<T>::add_Item(const T& item)
{
    ///if current location is less than max_Size add a item to the current vector
    if (m_Current_Size < m_Current_Maximum_Size)
    {
        storage_Vector[m_Current_Size] = item;

        m_Current_Size++;
    }


    /// if the current size is greater than max size double the current size of the vector
    else
    {
        ///double the size of the vector
        m_Current_Maximum_Size  = m_Current_Maximum_Size * 2;

        ///assign the large storage vec with twice capacity of storage vector
        T* large_Storage_Vector = new T[m_Current_Maximum_Size];


        for (int item_Number = 0; item_Number < m_Current_Size; item_Number++)
        {
            large_Storage_Vector[item_Number] = storage_Vector[item_Number];
        }


        storage_Vector = large_Storage_Vector;
        storage_Vector[m_Current_Size] = item;


        m_Current_Size++;
    }
}


/********************************************************************************************
 @brief remove_Item  function definition
 @brief searches for an item and then removes it from vector

 ********************************************************************************************/


template<class T>
void Vector<T>::remove_Item(const T& item)
{
    for (int item_Number = 0; item_Number < m_Current_Size; item_Number++)
    {
        if (item == storage_Vector[item_Number])
        {
            for (int j = item_Number; j < m_Current_Size - 1; j++)
            {
                storage_Vector[j] = storage_Vector[j + 1];
            }

            m_Current_Size--;
        }
    }
}

#endif // VECTOR_H_INCLUDED
