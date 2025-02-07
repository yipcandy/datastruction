#include "arraylist.h"

template<class T>
void ChangeLength1D(T*& a, int oldLength, int newLength) {
    if (newLength < 0)
        throw illegalParameterValue("new length must be >= 0");
    
    T* temp = new T[newLength];
    int number = min(oldLength, newLength);
    copy(a, a + number, temp);
    delete = a;
    a = temp;
}


//class ArrayList
//构造函数
template<class T>
ArrayList<T>::ArrayList(int initialCapacity) {
    if (initialCapacity < 1) {
        ostringstream s;
        s << "Initial capacity = " << initialCapacity << " Must be > 0";
        throw illegalParameterValue(s.str());
    }
    arrayLength = initialCapacity;
    element = new T[arrayLength];
    listSize = 0;
}
//复制构造函数
template<class T>
ArrayList<T>::ArrayList(const ArrayList<T>& theList) {
    arrayLength = theList.arrayLength;
    listSize = theList.listSize;
    element = new T[arrayLength];
    copy(theList.element, theList.element + listSize, element);
}

//基本方法
template<class T>
void ArrayList<T>::CheckIndex(int theIndex) const {
    if (theIndex < 0 || theIndex >= listSize) {
        ostringstream s;
        s << "index = " << theIndex << " size = " << listSize;
        throw illegalIndex(s.str());
    }
}
template<class T>
T& ArrayList<T>::get(int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
}
template<class T>
int ArrayList<T>::IndexOf(const T& theElement) const {
    //?
    int theIndex = (int) (find(element, element + listSize, theElement) - element);

    if (theIndex == listSize)
        return -1;
    else
        return theIndex;
}
template<class T>
void ArrayList<T>::erase(int theIndex) {
    CheckIndex(theIndex);
    copy(element + theIndex + 1, element + listSize, element + theIndex);

    element[--listSize].~T(); 
}