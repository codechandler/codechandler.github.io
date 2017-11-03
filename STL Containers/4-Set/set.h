/***********************************************************************
* Header:
*    Set
* Summary:
*    This class contains the notion of a set: a container
*    that holds exactly one of each item (no duplicates)
*
*    This will contain the class definition of:
*        Set         : A class that holds stuff
*        SetIterator : An interator through Set
* Author
*    Nathan Bench, Jed Billman, Justin Chandler, Jeremy Chandler
************************************************************************/

#ifndef SET_H
#define SET_H

#include <cassert>

// forward declaration for SetIterator
template <class T>
class SetIterator;

// forward declaration for SetConstIterator
template <class T>
class SetConstIterator;

/************************************************
 * SET
 * A class that holds stuff
 ***********************************************/
template <class T>
class Set
{
public:
   // default constructor : empty and kinda useless
   Set() : numItems(0), max(0), data(NULL) {}

   // copy constructor : copy it
   Set(const Set & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Set(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Set()        { if (max) delete [] data; }
   
   // standard container methods
   bool empty() const   { return numItems == 0;         } 
   void clear()         { numItems = 0;                 }
   int capacity() const { return max;                   }
   int size() const     { return numItems;              }

   // SET specific methods
   void insert(const T & t) throw (const char *);
   void erase(SetIterator <T> & it);
   SetIterator <T> find(const T & t);
   
   // operators
   Set <T> & operator = (const Set <T> & rhs);
   Set <T> operator || (const Set <T> & rhs);   // union
   Set <T> operator && (const Set <T> & rhs);   // intersection
   Set <T> operator - (const Set <T> & rhs);
   
   // iterators
   SetIterator <T> begin() { return SetIterator<T>(data); }
   SetIterator <T> end() { return SetIterator<T>(data + numItems);}
   
   SetConstIterator <T> cbegin() const { return SetConstIterator<T>(data); }
   SetConstIterator <T> cend() const   { return SetConstIterator<T>(data + numItems); }
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Set?
   int max;           // how many items can I put on the Set before full?
   
   int findInsertIndex(const T & t);
   int findIndex(const T & t);
   void addToEnd(const T & t);
   void resize(int newCap) throw (const char *);
   // for debugging
   void display()
   {
      for (int i = 0; i < numItems; i++)
      {
         std::cout << "i: " << i << "\tvalue: " << data[i] << std::endl;
      }
   }
   
};

/**************************************************
 * SET ITERATOR
 * An iterator through Set
 *************************************************/
template <class T>
class SetIterator
{
  public:
   // default constructor
  SetIterator() : p(NULL) {}

   // initialize to direct p to some item
  SetIterator(T * p) : p(p) {}

   // copy constructor
   SetIterator(const SetIterator & rhs) { *this = rhs; }

   // assignment operator
   SetIterator & operator = (const SetIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const SetIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * ()
   {
      return *p;
   }

   // prefix increment
   SetIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   SetIterator <T> operator++(int postfix)
   {
      SetIterator tmp(*this);
      p++;
      return tmp;
   }
   
   SetIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }
   
  private:
   T * p;
};

/**************************************************
 * SET CONST ITERATOR
 * An iterator through Set
 *************************************************/
template <class T>
class SetConstIterator
{
  public:
   // default constructor
  SetConstIterator() : p(NULL) {}

   // initialize to direct p to some item
  SetConstIterator(T * p) : p(p) {}

   // copy constructor
   SetConstIterator(const SetConstIterator & rhs) { *this = rhs; }

   // assignment operator
   SetConstIterator & operator = (const SetConstIterator & rhs)
   {
      this->p = rhs.p;
      return *this;
   }

   // not equals operator
   bool operator != (const SetConstIterator & rhs) const
   {
      return rhs.p != this->p;
   }

   // dereference operator
   T & operator * () const
   {
      return *p;
   }

   // prefix increment
   SetConstIterator <T> & operator ++ ()
   {
      p++;
      return *this;
   }

   // postfix increment
   SetConstIterator <T> operator++(int postfix)
   {
      SetConstIterator tmp(*this);
      p++;
      return tmp;
   }
   
   SetConstIterator <T> & operator -- ()
   {
      p--;
      return *this;
   }
   
  private:
   T * p;
};

/*******************************************
 * SET :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Set <T> :: Set(const Set <T> & rhs) throw (const char *)
{
   assert(rhs.max >= 0);
      
   // do nothing if there is nothing to do
   if (rhs.max == 0)
   {
      max = numItems = 0;
      data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[rhs.max];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }
   
   // copy over the capacity and size
   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.max);
   max = rhs.max;
   numItems = rhs.numItems;

   // copy the items over one at a time using the assignment operator
   for (int i = 0; i < numItems; i++)
      data[i] = rhs.data[i];

   // the rest needs to be filled with the default value for T
   for (int i = numItems; i < max; i++)
      data[i] = T();
}

/**********************************************
 * SET : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "capacity"
 **********************************************/
template <class T>
Set <T> :: Set(int capacity) throw (const char *)
{
   assert(capacity >= 0);
   
   // do nothing if there is nothing to do
   if (max == 0)
   {
      this->max = this->numItems = 0;
      this->data = NULL;
      return;
   }

   // attempt to allocate
   try
   {
      data = new T[capacity];
   }
   catch (std::bad_alloc)
   {
      throw "ERROR: Unable to allocate buffer";
   }

      
   // copy over the stuff
   this->max = capacity;
   this->numItems = 0;

   // initialize the container by calling the default constructor
   for (int i = 0; i < max; i++)
      data[i] = T();
}

/***************************************************
 * SET :: INSERT
 * Sort an item then insert into container
 **************************************************/
template <class T>
void Set <T> :: insert(const T & t) throw (const char *)
{
   if (data == NULL)
   {
      resize(max);
      data[numItems++] = t;
      return;
   }
   
   if (findIndex(t) != -1)
      return;
   
   int iInsert = findInsertIndex(t);
   //std::cout << "iInsert: " << iInsert << std::endl;
   
   if (max == 0 || max == numItems)
   {
      resize(max);
   }
   
   if (t != data[iInsert])
   {
      // shift the array
      if (numItems)
      for (int i = numItems - 1; i >= iInsert; i--)
      {
         //std::cout << "i: " << i << std::endl;        
            data[i + 1] = data[i];
      }
      
      
      data[iInsert] = t;
      numItems++;
   }
}

/***************************************************
 * SET :: FIND INSERT INDEX
 * Return an int if t is found, or return end.
 * CITE: Brother Jones DB05
 **************************************************/
template <class T>
 int Set <T> :: findInsertIndex(const T & t)
{
   int iBegin = 0;
   int iEnd = numItems - 1;
   while(iBegin <= iEnd)
   {
      int iMid = (iBegin + iEnd) / 2;
      
      if (t < data[iMid])
         iEnd = iMid - 1;
      
      if (t > data[iMid])
         iBegin = iMid + 1;
   }
   
   // t not found
   return iBegin;
}

/***************************************************
 * SET :: ADD TO END
 * Add to the end of the array
 * CITE: CS235 PDF Page 124
 **************************************************/
template <class T>
 void Set <T> :: addToEnd(const T & t)
{
   if (max == numItems)
      resize(max * 2);
   
   data[numItems++] = t;
}

/***************************************************
 * SET :: ERASE
 * Return an iterator if t is found, or return end.
 * CITE: CS235 PDF Page 124
 **************************************************/
template <class T>
 void Set <T> :: erase(SetIterator <T> & it)
{
   T t = *it;
   int iErase = findIndex(t);
   if (iErase == -1)
      return;
   assert(iErase < numItems && iErase >= 0);
   

      // start at the index and shift the upper array onto it
      assert(iErase != -1);
      for (int i = iErase; i < (numItems - 1); i++)
         data[i] = data[i + 1]; 
      numItems--;            
}

/***************************************************
 * SET :: FIND INDEX
 * Return an int if t is found, or return end.
 * CITE: Brother Jones DB05
 **************************************************/
template <class T>
 int Set <T> :: findIndex(const T & t)
{
   int iBegin = 0;
   int iEnd = numItems - 1;
   while(iBegin <= iEnd)
   {
      int iMid = (iBegin + iEnd) / 2;
      //std::cout << "data[mid] == " << data[iMid] << "\tT == " << t << std::endl;
      if (t == data[iMid])
         return iMid;
      
      if (t < data[iMid])
         iEnd = iMid - 1;
      
      if (t > data[iMid])
         iBegin = iMid + 1;
   }
   
   // t not found
   return -1;
}

/***************************************************
 * SET :: FIND
 * Return an iterator if t is found, or return end.
 * CITE: Brother Jones DB05
 **************************************************/
template <class T>
SetIterator <T> Set <T> :: find(const T & t)
{
   int i = findIndex(t);
  
   if (i == -1)
      return end();
   else
      return SetIterator<T>(data + i);
}

/***************************************************
 * SET :: =
 * Overload assignment operator
 **************************************************/
template <class T>
Set<T> & Set <T> :: operator = (const Set <T> & rhs)
{
   // don't copy yourself
   if (this != &rhs)
   {
      // clean up data
      if (data)
         delete [] data;
      
      // assign each member variable to right-hand-side
      max = rhs.max;
      numItems = rhs.numItems;
      
      // allocate new array
      try
      {
         data = new T[max];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Set";
      }
      // copy over values from rhs
      for (int i = 0; i < rhs.numItems; i++)
      {
         data[i] = rhs.data[i];
      }
      
      return *this;
   }
}

/***************************************************
 * SET :: UNION
 * Overload || operator
 **************************************************/
template <class T>
Set <T> Set <T> :: operator || (const Set <T> & rhs)
{
   Set <T> setReturn;
   int iThis = 0;
   int iRhs = 0;
   
   while (iThis < numItems || iRhs < rhs.numItems)
   {
      if (iThis == numItems)
         setReturn.addToEnd(rhs.data[iRhs++]);
      else if (iRhs == rhs.numItems)
         setReturn.addToEnd(data[iThis++]);
      else if (data[iThis] == rhs.data[iRhs])
      {
         setReturn.addToEnd(data[iThis]);
         iThis++;
         iRhs++;
      }
      else if (data[iThis] < rhs.data[iRhs])
         setReturn.addToEnd(data[iThis++]);
      else
         setReturn.addToEnd(rhs.data[iRhs++]);
   }
   return setReturn;
}

/***************************************************
 * SET :: INTERSECTION
 * Overload && operator
 **************************************************/
template <class T>
Set <T> Set <T> :: operator && (const Set <T> & rhs)
{
   Set <T> setReturn;
   int iThis = 0;
   int iRhs = 0;
   
   while (iThis < numItems || iRhs < rhs.numItems)
   {
      if (iThis == numItems)
         return setReturn;
      else if (iRhs == rhs.numItems)
         return setReturn;
      else if (data[iThis] == rhs.data[iRhs])
      {
         setReturn.addToEnd(data[iThis]);
         iThis++;
         iRhs++;
      }
      else if (data[iThis] < rhs.data[iRhs])
         iThis++;
      else
         iRhs++;
   }   
}

/***************************************************
 * SET :: DIFFERENCE
 * Overload - operator
 **************************************************/
template <class T>
Set <T> Set <T> :: operator - (const Set <T> & rhs)
{
   Set <T> setReturn;
   int iThis = 0;
   int iRhs = 0;
   
   while (iThis < numItems || iRhs < rhs.numItems)
   {
      if (iThis == numItems)
         return setReturn;
      else if (iRhs == rhs.numItems)
         setReturn.addToEnd(data[iThis++]);
      else if (data[iThis] == rhs.data[iRhs])
      {
         // skip equal values
         iThis++;
         iRhs++;
      }
      else if (data[iThis] < rhs.data[iRhs])
         setReturn.addToEnd(data[iThis++]);
      else
          iRhs++;
   }
   return setReturn;
}

/***************************************************
 * SET :: RESIZE
 * Overload && operator
 **************************************************/
template <class T>
void Set <T> :: resize(int newCap) throw (const char *)
{
   // IF capacity == 0
   if (max == 0)
   {
      max = 1;
      try
      {
         data = new T[max];
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: unable to allocate a new buffer for Set";
      }
   }
   
   // IF max capacity AND numItems is not less than 0
   if (max == numItems && numItems > 0)
   {
      max *= 2;
      try
      {
         T* tempArray = new T[max];
         
         // copy
         for (int i = 0; i < numItems; i++)
         {
            tempArray[i] = data[i];
         }

         // free memory
         delete[] data;

         // point to tempArray
         data = tempArray;
      }
      catch (std::bad_alloc)
      {
         throw "ERROR: Unable to allocate a new buffer for Set";
      }
   }
}

#endif // SET_H

