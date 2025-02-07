#ifndef MY_GRAPH_H_
#define MY_GRAPH_H_

#include<iostream>

template<class T>
class edge {
private:
	/* data */
public:
	edge(/* args */) {}
	~edge() {}
};

template <typename T>
class vertexIterator {
private:
	T /* data */
public:
	vertexIterator(T /* args */);
};


//���� graph
template<class T>
class graph {
public:
	virtual ~graph() {}
	
	// ADT ����
	virtual int NumberOfVertives() const = 0;
	virtual int NumberOfEdges() const = 0;
	virtual bool ExistEdge(int, int) const = 0;
	virtual void InsertEdge(edge<T>) = 0;
	virtual void EraseEdge(int, int) = 0;
	virtual int degree(int) const = 0;
	virtual int InDegree(int) const = 0;
	virtual int OutDegree(int) const = 0;

	//��������
	virtual bool directed() const = 0;	//���ҽ���������ͼʱ������ֵΪtrue
	virtual bool weighted() const = 0;	//���ҽ����Ǽ�Ȩͼʱ������ֵΪtrue
	virtual vertexIterator<T>* iterator(int) = 0;	//����ָ����������ڶ���
};

//adjacencyGraph
//adjacencyWeiGraph
//adjacencyDiGraph
//adjacencyWeiDiGraph
template <typename T>
class adjacencyWeiDiGraph : public graph<T> {
protected:
	int n_;
	int e_;
	T** a;
	T noEdge;
public:
	adjacencyWeiDiGraph(int NumberOfVertices = 0, T theNoEdge = 0) {
		
	}
};


//linkedGraph
//linkedWeiGraph
//linkedDiGraph
//linkedWeiDiGraph

//arrayGraph
//arrayWeiGraph
//arrayDiGraph
//arrayWeiDiGraph
#endif