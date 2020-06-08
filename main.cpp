//
// Created by lemme on 6/7/20.
//


#include "node.h"
#include "btree.h"
#include<vector>
#include<iostream>
#include<stdlib.h>
int main(){
    tree::btree<int,int> tree;
//    int key_list[] = {2,5,234,5432,23,35,25,35,3,53};
//
//    std::cout<<tree.insert_node(1,2)<<std::endl;
//    for(int i=0;i<10;i++){
//        std::cout<<tree.insert_node(key_list[i],key_list[i])<<std::endl;
//    }
//    std::vector<int> list = tree.inordervector();
//    for(int i=0;i<list.size();i++){
//        std::cout<<list[i]<<std::endl;
//    }
//    std::cout<<tree.size()<<std::endl;
//    std::cout<<tree.get_value(5)<<std::endl;
//    std::cout<<tree.delete_node(5)<<std::endl;
//    std::cout<<tree.delete_node(1)<<std::endl;
    int size = 20000;
    tree.insert_node(1,1);
    for(int i=0;i<size;i++){
        int x = rand();
        tree.insert_node(x,x);
    }
    std::vector<int> value_list = tree.inordervector();
    for(int i=0;i<value_list.size();i++){
        std::cout<<value_list[i]<<std::endl;
    }
    int k = tree.size();
    std::cout<<k<<std::endl;
    tree.~btree();
    return 0;
}