// **************************************************************************
//  File       [sort_tool.cpp]
//  Author     [Yu-Hao Ho]
//  Synopsis   [The implementation of the SortTool Class]
//  Modify     [2015/03/02 Yu-Hao Ho]
// **************************************************************************

#include "sort_tool.h"
#include<iostream>
#include<limits.h>
#include<math.h>
// Constructor
SortTool::SortTool() {}

// Insertsion sort method
void SortTool::InsertionSort(vector<int>& data) {
   for (int j=1; j<data.size(); j++){
        int key = data[j];
        int i = j - 1;
        while(i>=0 && data[i]>key){
            data[i+1] = data[i];
            i = i - 1;
        }
        data[i+1] = key;
   }
}

// Merge sort method
void SortTool::MergeSort(vector<int>& data){
    SortSubVector(data, 0, data.size() - 1);
}

// Sort subvector
void SortTool::SortSubVector(vector<int>& data, int low, int high) {
    if (low<high){
        int medium = (high + low)/2;
        SortSubVector(data, low, medium);
        SortSubVector(data, medium+1, high);
        Merge(data, low, medium, medium+1, high);  
    }
}

// Merge
void SortTool::Merge(vector<int>& data, int low, int middle1, int middle2, int high) {
    int n1 = middle1 - low + 1;
    int n2 = high - middle1;
    int L[n1 + 1];
    int R[n2 + 1];
    for(int k=0; k<n1; k++){
        L[k] = data[low + k];
    }
    for(int k=0; k<n2; k++){
        R[k] = data[middle2 + k];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int i = 0;
    int j = 0;
    for(int k=low; k<=high; k++){
        if(L[i] <= R[j]){
            data[k] = L[i];
            i = i + 1;
        }
        else{
            data[k] = R[j];
            j = j + 1;
        }
    }
}

// Heap sort method
void SortTool::HeapSort(vector<int>& data) {
    // Build Max-Heap
    Build_Max_Heap(data);
    // 1. Swap data[0] which is max value and data[i] so that the max value will be in correct location
    // 2. Do max-heapify for data[0]
    for (int i = data.size() - 1; i >= 1; i--) {
        swap(data[0],data[i]);
        heapSize--;
        Max_Heapify(data,0);
    }
}

//Max heapify
void SortTool::Max_Heapify(vector<int>& data, int root) {
    int left = 2*root;
    int right = 2*root+1;
    int largest;
    if(left < heapSize && data[left] > data[root]){
        largest = left;
    }
    else{
        largest = root;
    }
    if(right < heapSize && data[right] > data[largest]){
        largest = right;
    }
    if(largest != root){
        swap(data[root], data[largest]);
        Max_Heapify(data, largest);
    }

}

//Build max heap
void SortTool::Build_Max_Heap(vector<int>& data) {
    heapSize = data.size(); // initialize heap size
    for(int i= ceil(heapSize/2); i>=0; i--){
        Max_Heapify(data, i);
    }
}
