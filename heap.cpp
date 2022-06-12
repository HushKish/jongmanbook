#include <iostream>
#include <vector>
using namespace std;
void pushheap(vector <int>& heap,int n){
    heap.push_back(n);
    int idx = heap.size() - 1;
    while(heap[idx] > heap[(idx-1)/2] && idx > 0){
        swap(heap[idx], heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}
//최대원소 삭제 후 힙유지
void popheap(vector <int>& heap){
    heap[0] = heap.back();
    heap.pop_back();
    // int idx = 0;
    // while(heap[idx] < max(heap[idx*2+1] , heap[idx*2+2])){
    //     if(heap[idx*2+1] < heap[idx*2+2]){
    //         swap(heap[idx],heap[idx*2+2]);
    //         idx = idx*2+2;
    //     }
    //     else{  
    //         swap(heap[idx],heap[idx*2+1]);
    //         idx = idx*2+1;
    //     }
    //     //swap실행
    // }
    int here = 0;
    while(1){
        int left = here*2 + 1, right = here*2 + 2;
        if(left >= size) break; /* 왼쪽 자식노드가 없으면 오른쪽 자식노드도 없기에 바로 break
        언제 반복을 종료하는가 -> here의 자식노드는 어떤것이 가능할까 ( 없음 ,1개(왼쪽),2개 ) 없을 때 종료해야함*/
        int next = here;
        if(heap[next] < heap[left]) next = left;
        if(right < heap.size() && heap[next] < heap[right]) next = right;//오른쪽 노드가 있는지는 보장이 안되기 때문에 여기서 추가로 조건 걸어줘야함
        if(next == here) break; // 스왑할 필요가 없을 때(이경우를 내가 빠트림 그냥 else if로 같은 경우는 뭐 이렇게 하면 되겠지라고 정확히 짚고가지 않음)
        swap(heap[here], heap[next]);
        here = next;
    }
} 