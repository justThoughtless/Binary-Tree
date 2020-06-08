//
// Created by lemme on 6/7/20.
//

#include "node.h"
#include<iostream>
namespace tree{

    template<typename k,typename v>
    node<k,v>::node()
    {
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    template<typename k,typename v>
    node<k,v>::node(k key,v value){
        this->Key = key;
        this->Value = value;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }

    template<typename k,typename v>
    node<k,v>::~node(){
        std::cout<<"node_deleted"<<std::endl;
    }

    template<typename k,typename v>
    k node<k,v>::get_key() {
        return this->Key;
    }

    template <typename k,typename v>
    v node<k,v>::get_value() {
        return this->Value;
    }

    template<typename k,typename v>
    node<k,v>* node<k,v>::get_parent(){
        return this->parent;
    }

    template<typename k,typename v>
    node<k,v>* node<k,v>::get_left(){
        return this->left;
    }

    template<typename k,typename v>
    node<k,v>* node<k,v>::get_right(){
        return this->right;
    }

    template<typename k,typename v>
    void node<k,v>::set_parent(node* n){
        this->parent = n;
    }

    template<typename k,typename v>
    void node<k,v>::set_left(node<k,v>* n){
        this->left = n;
        n->set_parent(this);
    }

    template<typename k,typename v>
    void node<k,v>::set_right(node<k,v>* n){
        this->right = n;
        n->set_parent(this);
    }

    template<typename k,typename v>
    bool node<k,v>::is_left() {
        if(this->parent->left == this){
            return true;
        }
        else{
            return false;
        }
    }

    template<typename k,typename v>
    bool node<k,v>::is_right() {
        if(this->parent->right == this){
            return true;
        }
        else{
            return false;
        }
    }
    template struct node<int,int>;
}
