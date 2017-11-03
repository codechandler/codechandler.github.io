/***********************************************************************
* Header:
*    Queue
* Summary:
*    This class contains the notion of a stack: a container
*    that follows First In First Out behavior and
*    expands as more items are put inside.
*
*    This will contain the class definition of:
*        Queue         : A class that holds and uses FIFO behavior
* Author
*    Nathan Bench, Jed Billman, Justin Chandler, Jeremy Chandler
************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <cassert>
#include <new>

/************************************************
 * QUEUE
 * A class that holds stuff
 ***********************************************/
template <class T>
class Queue
{
public:
   // default constructor : empty and kinda useless
   Queue() : m_numPush(0), m_numPop(0), m_capacity(0), m_data(NULL) {}

   // copy constructor : copy it
   Queue(const Queue<T> & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Queue(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Queue()        { if (!empty()) delete [] m_data; }
   
   // is the container currently empty
   bool empty() const  
   {
      return size() == 0;
   }

   // remove all the items from the container
   void clear()        { m_numPush = m_numPop = 0;                 }

   // how many items can the stack currently contain?
   int capacity() const { return m_capacity;             }
   
   // how many items are currently in the container?
   int size() const    { return (m_numPush - m_numPop);              }   // cite: BYUI PDF page 83

   // add an item to the back of the queue
   void push(const T & t) throw (const char *);

   // Removes an item from the front of the queue
   void pop() throw (const char *);

   // Returns the item currently at the front of the queue
   T & front()     throw (const char *);
   //T front() const throw (const char *);
   
   // Returns the item currently at the front of the queue
   T & back()     throw (const char *);
   //T back() const throw (const char *);
   
   // assignment operator '='
   Queue<T> & operator = (const Queue <T> & rhs);
   
private:
   T * m_data;          // dynamically allocated array of T
   int m_numPush,       // cite: BYUI PDF page 82
       m_numPop,
       m_capacity;      // how many items can I put on the Queue before full?
   int head;
   int tail;
   int num_items;
   
   // private methods
   int iHead() const { return m_numPop % m_capacity;}           // cite: BYUI PDF page 82
   int iTail() const { return (m_numPush - 1) % m_capacity; }    // cite: BYUI PDF page 82
   // increase capacity
   void resize(int newCap);
};

/*******************************************
 * QUEUE :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Queue <T> :: Queue(const Queue <T> & rhs) throw (const char *)
{
   assert(rhs.m_capacity >= 0);
   
   // resize array to the rhs
   if (m_capacity < rhs.size())
   {
      try
      {
		   // insure the indices are beginning at 0
		   m_numPop = 0;
		   m_numPush = 0;   
   
         T * temp = new T[rhs.size()];
         
         // delete data
         if(m_data)
         delete [] m_data;

		 m_capacity = rhs.m_capacity;

		 for (int i = 0; i < rhs.m_capacity; i++)
			 temp[i] = rhs.m_data[i];

         // assign new data
         m_data = temp;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for queue";
      }
   }
   
   // IF there is data to copy
   if (rhs.size() > 0)
   {      
      // copy over data
      assert(rhs.m_capacity > 0);
      for (int i = rhs.m_numPop; i < rhs.m_numPush; i++)
      {
         push(rhs.m_data[i % rhs.m_capacity]);
      }
   }

}

/**********************************************
 * QUEUE : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Queue <T> :: Queue(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (m_capacity == 0)
   {
      m_numPop = m_numPush = 0;
      m_data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      m_data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // SET member variables
   m_capacity = capacity;
   m_numPush = m_numPop = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < m_capacity; i++)
      m_data[i] = T();
}

/***************************************************
* QUEUE :: PUSH
* Adds an item to the back of the queue
**************************************************/
template<class T>
void Queue<T>::push(const T & t) throw (const char *)
{
	if (size() == capacity())
	{
		resize(capacity() * 2);
	}
   
   m_numPush++;
	m_data[iTail()] = t;
}

/***************************************************
* QUEUE :: POP
* Removes an item from the front of the queue
**************************************************/
template<class T>
void Queue<T>::pop() throw(const char *)
{
	if (empty())
		throw "ERROR: attempting to pop from an empty Queue";
	m_numPop++;
}

/***************************************************
* QUEUE :: FRONT
* Returns the item currently at the front of the queue by reference
**************************************************/
template<class T>
T & Queue<T> :: front() throw(const char *)
{
	// if empty
	if (empty())
		throw "ERROR: attempting to access an item in an empty queue";
	return m_data[iHead()];
}
/***************************************************
* QUEUE :: FRONT C
* Returns the item currently at the front of the queue by const value
**************************************************/
/*template<class T>
T Queue<T> :: front() const throw(const char *)
{
	// if empty
	if (empty())
		throw "ERROR: attempting to access an item in an empty queue";
	return m_data[iHead()];      
}*/

/***************************************************
* QUEUE :: BACK
* Returns the item currently at the back of the queue by reference
**************************************************/
template<class T>
T & Queue<T> :: back()     throw (const char *)
{
   if (empty())
		throw "ERROR: attempting to access an item in an empty queue";
	return m_data[iTail()]; 
}
   
/***************************************************
* QUEUE :: BACK C
* Returns the item currently at the back of the queue by const value
**************************************************/
/*template<class T>
T Queue<T> :: back() const throw (const char *)
{
   if (empty())
		throw "ERROR: attempting to access an item in an empty queue";
	return m_data[iTail()]; 
}*/

/***************************************************
 * QUEUE :: =
 * Overload assignment operator
 **************************************************/
 template <class T>
Queue<T> & Queue <T> :: operator = (const Queue <T> & rhs)
{
   // don't copy yourself
   if (this != &rhs)
   {
      m_numPush = m_numPop = 0;
      
      // resize array to the rhs
      if (m_capacity < rhs.size())
         resize (rhs.size());
      
      // copy over data
      for (int i = rhs.m_numPop; i < rhs.m_numPush; i++)
      {
         push(rhs.m_data[i % rhs.m_capacity]);
      }
      
      return *this;
   } // IF rhs != THIS
}
   
/***************************************************
* QUEUE :: RESIZE
* Allocate memory for m_data
**************************************************/
template<class T>
void Queue<T>::resize(int newCap)
{
   if (newCap == 0)
      newCap = 1;

   try
   {
      T *temp = new T[newCap];
      
      int index = 0;
      assert(newCap > 0);
      for (int i = m_numPop; i < m_numPush; i++)
      {
         temp[index] = m_data[i % m_capacity];
         index++;
      }
      
      m_capacity = newCap;
      
      // out with the old
      delete [] m_data;
      
      // in with the new
      m_data = temp;
      
      // reset Pop & Push counts
      m_numPop = 0;
      m_numPush = index - 1;         

   }
   catch(std::bad_alloc)
   {
      throw "ERROR: Unable to allocate a new buffer for queue";
   }

}

#endif // QUEUE_H
