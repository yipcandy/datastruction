#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_

//���� LinearList
template <class T>
class LinearList {
protected:
    virtual         ~LinearList() {};
    virtual bool    empty() const = 0;
    virtual int     size() const = 0;
    virtual T&      get(int index) const = 0;
    virtual int     IndexOf(const T& element) const = 0;
    virtual void    erase(int index) = 0;
    virtual void    insert(int index, const T& element) = 0;
    virtual void    output(ostream& out) const = 0;
};

//���м̳� ArrayList
template <class T>
class ArrayList : public LinearList<T> {
public:
            ArrayList(int initCap = 10);
            ArrayList(const ArrayList<T>&);
            ~ArrayList() { delete [] element; }

    //ADT����
    bool    empty() const { return listSize == 0; }
    int     size() const { return listSize; }
    T&      get(int theIndex) const;
    int     IndexOf(const T& theElement) const;
    void    erase(int theIndex);
    void    insert(int theIndex, const T& theElement);
    void    output(ostream& out) const;

    //��������
    int     capacity() const { return arrayLength; }

private:
    void    CheckIndex(int theIndex) const;   //������ theIndex ��Ч, ���׳��쳣
    T*      element;
    int     arrayLength;    //һά���������
    int     listSize;   //���Ա��Ԫ�ظ���
};


#endif