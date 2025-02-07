#include "mybstree.h"

//constructor ans destructor
template <class T>
BSTree<T>::BSTree()
    :root_(nullptr) {}
template <class T>
BSTree<T>::~BSTree() {
    destroy();
}



//operation
template<class T>
BSTNode<T>* BSTree<T>::insert(BSTNode<T>* tree,BSTNode<T>* add) {
    BSTNode<T>* pare = nullptr;
    BSTNode<T>* ptr = tree;

    while (ptr != nullptr) {
        pare = ptr;
        if (add->value_ < ptr->value_)
            ptr = ptr->left_;
        else
            ptr = ptr->right_;
    }

    ptr->parent_ = pare;
    if (pare == nullptr)
        tree = add;
    else if (ptr->value_ < pare->value_)
        pare->left_ = ptr;
    else
        pare->right_ = ptr;
    return ptr;
}
template<class T>
bool BSTree<T>::insert(T key) {
    BSTNode<T>* add = nullptr;
    //保证待插入元素不重复
    if (search(key) || (add = new BSTNode<T>(key, nullptr, nullptr, nullptr)) == nullptr)
        return false;
    insert(root_,add);
    return true;
}

template<class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* tree,BSTNode<T>* minus) {

}
template<class T>
bool BSTree<T>::remove(T key) {

}

template<class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* tree,T key) const {
    while (tree != nullptr && tree->value_ != key) {
        if (key < tree->value_)
            tree = tree->left_;
        else
            tree = tree->right_;
    }
    return tree;
}
template<class T>
bool BSTree<T>::search(T key) {
    return search(root_, key) != nullptr;
}

template<class T>
BSTNode<T>* BSTree<T>::getMin(BSTNode<T>* tree) const {
    if (tree == nullptr)
        return nullptr;

    if (tree->left_ != nullptr)
        tree = tree->left_;
    return tree;
}
template<class T>
T BSTree<T>::getMin() {
    BSTNode<T>* p = getMin(root_);
    if (p == nullptr)
        return (T)nullptr;
    return p->value_;
}

template<class T>
BSTNode<T>* BSTree<T>::getMax(BSTNode<T>* tree) const {
    if (tree == nullptr)
        return nullptr;

    if (tree->right_ != nullptr)
        tree = tree->right;
    return tree;
}
template<class T>
T BSTree<T>::getMax() {
    BSTree<T>* p = getMax(root_);
    if (p == nullptr)
        return (T)nullptr;

    return p->value_;
}



//
template<class T>   //大于该节点的最小节点
BSTNode<T>* BSTree<T>::successor(BSTNode<T>* tree) {
    if (tree->right_ != nullptr)
        getMin(tree->right_);
}
template<class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T>* tree) {

}



//traversal
template <class T>
void BSTree<T>::preOrder(BSTNode<T>* tree) const {
    if (tree != nullptr) {
        cout << tree->value_ << " ";
        preOrder(tree->left_);
        preOrder(tree->right_);
    }
    return;
}
template <class T>
void BSTree<T>::preOrder() {
    preOrder(root_);
    return;
}

template<class T>
void BSTree<T>::inOrder(BSTNode<T>* tree) const {
    if (tree != nullptr) {
        inOrder(tree->left_);
        cout << tree->value_ << ' ';
        inOrder(tree->right_);
    }
    return;
}
template<class T>
void BSTree<T>::inOrder() {
    inOrder(root_);
    return;
}

template<class T>
void BSTree<T>::postOrder(BSTNode<T>* tree)const {
    if (tree != nullptr) {
        postOrder(tree->left_);
        postOrder(tree->right_);
        cout << tree->value_ << ' ';
    }
    return;
}
template<class T>
void BSTree<T>::postOrder() {
    postOrder(root_);
    return;
}

template<class T>
void BSTree<T>::levelOrder(BSTNode<T>* tree) const {
    queue<BSTNode<T>*> que;
    if (tree == nullptr)
        return (T)nullptr;

    que.push(tree);
    while (!que.empty()) {
        cout << que.front() << ' ';
        if (que.front()->left_ != nullptr)
            que.push(que.front()->left_);
        if (que.front()->right_ != nullptr)
            que.push(que.front()->right_);
        que.pop();
    }
    return;
}
template<class T>
void BSTree<T>::levelOrder() {
    levelOrdre(root_);
}

template<class T>
void BSTree<T>::destroy(BSTNode<T>* tree) {
    if (tree == nullptr)
        return;
    if (tree->left_ != nullptr)
        return destroy(tree->left_);
    if(tree->right_ != nullptr)
        return destroy(tree->right_);
    delete tree;
    return;
}
template<class T>
void BSTree<T>::destroy() {
    destroy(root_);
    return;
}