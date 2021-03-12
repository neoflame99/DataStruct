#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <assert.h>

using namespace std;


template <class T> class tree
{
public:
    tree():parent(nullptr){}
    tree(const tree<T>& t);
    tree<T>& operator=(tree<T>&& t);
    tree<T>* parent;
    vector<tree<T>*> children_vec;
    vector<T> contents;


    // methods
public:
    void append_child(tree<T>& child);
    void append_child(tree<T>* pt_child);
    void remove_child(tree<T>& child);
    void remove_child(tree<T>* pt_child);
    void remove_lastChild();
    void rm_all_descendants();
    void move_to(tree<T>* new_parent);
    void traverse( int depth=0);

    void add_content(T dat);
    bool del_content(int pos);
    void pop_content();

};

template <class T> tree<T>::tree(const tree<T>& t){
    parent = t.parent;
    children_vec = t.children_vec;
    contents = t.contents;
}
template <class T> tree<T>& tree<T>::operator=(tree<T>&& t){
    swap(parent, t.parent);
    swap(children_vec, t.children_vec);
    swap(contents, t.contents);
    return *this;
}

template <class T> void tree<T>::append_child(tree<T>& child){
    child.parent = this;
    this->children_vec.push_back(&child);
}
template <class T> void tree<T>::append_child(tree<T>* pt_child){
    pt_child->parent = this;
    this->children_vec.push_back(pt_child);
}
template <class T> void tree<T>::remove_child(tree<T>& child){
    child.parent = nullptr;
    for(int i=0; i < children_vec.size() ; i++ ){
        if( children_vec[i] == &child ){
            child.rm_all_descendants();
            children_vec.erase(children_vec.begin()+i);
        }
    }
}
template <class T> void tree<T>::remove_child(tree<T>* pt_child){
    pt_child->parent = nullptr;
    for(int i=0; i < children_vec.size() ; i++ ){
        if( children_vec[i] == pt_child ){
            pt_child->rm_all_descendants();
            children_vec.erase(children_vec.begin()+i);
        }
    }
}
template <class T> void tree<T>::remove_lastChild(){
    tree<T>* p_ch = children_vec[children_vec.size()-1];
    p_ch->rm_all_descendants();
    children_vec.pop_back();
}
template <class T> void tree<T>::rm_all_descendants(){
    if( children_vec.empty() ){
        parent = nullptr;
        return ;
    }else {
        size_t sz = children_vec.size();
        for( int i=sz-1; i >=0 ; --i){
            tree<T>* p_ch = children_vec[i];
            p_ch->rm_all_descendants();
            children_vec.pop_back();
        }
        assert ( children_vec.empty() );
        parent = nullptr;
    }
}
template <class T> void tree<T>::move_to(tree<T>* new_parent){
    //-- erase this record from ex_parent. it doesn't mean to remove this object and its descendants.
    tree<T>* ex_parent = parent;
    for(int i=0; i < ex_parent->children_vec.size(); ++i){
        if( ex_parent->children_vec[i] == this )
            ex_parent->children_vec.erase(ex_parent->children_vec.begin()+i);
    }
    //-- add this record to new parent
    if( new_parent == nullptr){
        parent = nullptr;
    }else{
        parent = new_parent;
        parent->children_vec.push_back(this);
    }
}
template <class T> void tree<T>::traverse( int depth ){
    for(int i=0; i < depth ; ++i )
        cout << '\t';
    for(int i=0; i < contents.size() ; ++i )
        cout << contents[i];
    cout << endl;
    if( children_vec.empty() ){
        return ;
    }else {
        size_t sz = children_vec.size();
        for( int i=0; i < sz ; ++i){
            tree<T>* p_ch = children_vec[i];
            p_ch->traverse(depth+1);
        }
    }
}

template <class T> void tree<T>::add_content(T dat){
    contents.push_back(dat);
}
template <class T> bool tree<T>::del_content(int pos){
    if( contents.size() <= pos || pos < 0){
        fprintf(stderr,"You are trying to delete a contents out of bounds. No any content is deleted!\n");
        return false;
    }else{
        contents.erase(contents.begin()+pos);
    }
    return true;
}
template <class T> void tree<T>::pop_content(){
    contents.pop_back();
}


#endif // TREE_H
