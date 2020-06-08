//
// Created by lemme on 6/7/20.
//
#include "node.h"
#include "btree.h"
#include<iostream>
#include <vector>
namespace tree{

    template<typename k,typename v>
    btree<k,v>::btree(){
        this->root = nullptr;
    }

    template<typename k,typename v>
    btree<k,v>::~btree(){
        std::vector<node<k,v>*> list = this->__inordervector(this->root);
        for(int i=0;i<list.size();i++){
            list[i]->~node();
        }
    }

    template<typename k,typename v>
    void btree<k,v>::set_root(node<k, v> *n) {
        this->root = n;
        if(n!= nullptr)
            n->set_parent(nullptr);
    }

    template<typename k,typename v>
    bool btree<k,v>::insert_node(k new_key,v value){
        if(this->root == nullptr){
            node<k,v>* new_node = new struct node<k,v>(new_key,value);
            this->root = new_node;
            return true;
        }
        else{
            node<k,v>* n = this->root;
            while(true){
                if(n->get_key()<new_key){
                    if(n->get_right()==nullptr){
                        node<k,v>* new_node = new struct node<k,v>(new_key,value);
                        n->set_right(new_node);
                        return true;
                    }
                    else{
                        n = n->get_right();
                        continue;
                    }
                }
                else if(n->get_key()>new_key){
                    if(n->get_left()==nullptr){
                        node<k,v>* new_node = new struct node<k,v>(new_key,value);
                        n->set_left(new_node);
                        return true;
                    }
                    else{
                        n = n->get_left();
                        continue;
                    }
                }
                else{
                    return false;
                }
            }
        }
        return false;
    }

    template<typename k,typename v>
    node<k,v>* btree<k,v>::get_node(k key){
        if(this->root==nullptr){
            return nullptr;
        }
        else{
            node<k,v>* n = root;
            while(true){
                if(n == nullptr){
                    return nullptr;
                }
                else if(n->get_key() == key){
                    return n;
                }
                else if(n->get_key()<key){
                    n = n->get_left();
                }
                else if(n->get_key()>key){
                    n = n->get_right();
                }
            }
        }
        return nullptr;
    }

    template<typename k,typename v>
    std::vector<v> btree<k,v>::inordervector(){
//    return this->__inordervector(this->root);
        std::vector<node<k,v>*> node_list;
        std::vector<v> ret_list;
        node<k,v>* n = this->root;
        while(n!= nullptr){
            node_list.push_back(n);
            n=n->get_left();
        }

        while(node_list.size()>0){
            n = node_list.back();
            node_list.pop_back();
            ret_list.push_back(n->get_value());
            n = n->get_right();
            while(n!= nullptr){
                node_list.push_back(n);
                n=n->get_left();
            }
        }

        return ret_list;
    }

    template<typename k,typename v>
    std::vector<node<k,v>*> btree<k,v>::__inordervector(node<k,v>* n){
        if(n == nullptr){
            std::vector<node<k,v>*> list;
            return list;
        }
        std::vector<node<k,v>*> list = __inordervector(n->get_left());
        list.push_back(n);
        std::vector<node<k,v>*> list2 = __inordervector(n->get_right());
        for(int i=0;i<list2.size();i++){
            list.push_back(list2[i]);
        }
        return list;
    }

    template<typename k,typename v>
    int btree<k,v>::size() {
        int i=0;
        std::vector<node<k,v>*> list;
        node<k,v>* n = this->root;
        if(this->root != nullptr)
            list.push_back(this->root);
        while(list.size()>0){
            ++i;
            n = list.back();
            list.pop_back();
            if(n->get_left()!= nullptr){
                list.push_back(n->get_left());
            }
            if(n->get_right()!= nullptr){
                list.push_back(n->get_right());
            }
        }
        return i;
    }

    template <typename k,typename v>
    v btree<k,v>::get_value(k key) {
        node<k,v>* n = this->get_node(key);
        if(n!= nullptr)
            return n->get_value();
    }

    template <typename k,typename v>
    v btree<k,v>::delete_node(k key) {
        node<k,v>* n = this->get_node(key);
        if(n != nullptr) {

            auto set_child_of_parent = [](node<k, v> *n1, node<k, v> *n2) {
                if (n1->is_left()) {
                    n1->get_parent()->set_left(n2);
                } else if (n1->is_right()) {
                    n1->get_parent()->set_right(n2);
                }
            };

            if(n == this->root){
                if (n->get_left() == nullptr) {
                    this->set_root(n->get_right());
                } else if (n->get_right() == nullptr) {
                    this->set_root(n->get_left());
                } else {
                    node<k, v> *max_node_less_than = n->get_left();
                    if (max_node_less_than->get_right() == nullptr) {
                        max_node_less_than->set_right(n->get_right());
                        this->set_root(n->get_left());
                    } else {
                        while (max_node_less_than->get_right() != nullptr) {
                            max_node_less_than = max_node_less_than->get_right();
                        }
                        set_child_of_parent(max_node_less_than, max_node_less_than->get_left());
                        max_node_less_than->set_right(n->get_right());
                        max_node_less_than->set_left(n->get_left());
                        this->set_root(max_node_less_than);
                    }
                }
                n->~node<k,v>();
            }
            else{

                if (n->get_left() == nullptr) {
                    set_child_of_parent(n, n->get_right());
                } else if (n->get_right() == nullptr) {
                    set_child_of_parent(n, n->get_left());
                } else {
                    node<k, v> *max_node_less_than = n->get_left();
                    if (max_node_less_than->get_right() == nullptr) {
                        max_node_less_than->set_right(n->get_right());
                        set_child_of_parent(n, n->get_left());
                    } else {
                        while (max_node_less_than->get_right() != nullptr) {
                            max_node_less_than = max_node_less_than->get_right();
                        }
                        set_child_of_parent(max_node_less_than, max_node_less_than->get_left());
                        max_node_less_than->set_right(n->get_right());
                        max_node_less_than->set_left(n->get_left());
                        set_child_of_parent(n, max_node_less_than);
                    }
                }
            }
            return n->get_value();
        }
    }

    template class btree<int,int>;

}
