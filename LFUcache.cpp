#include <iostream>
#include <list>

using namespace std;

class LFUCache {
    private:
        list<int> NameList;
        list<int> CountList;
        list<int>::iterator iter1 = NameList.begin();
        list<int>::iterator iter2 = CountList.begin();
    public:
        LFUCache(int length);
        void put(int key, int value);
        int get(int key);
        void showlist();
    //IMPLEMENT MEMBERS HERE
};
//IMPLEMENT YOUR FUNCTIONS HERE
LFUCache::LFUCache(int length){
    for (int i=0; i<length; ++i){
        NameList.push_front(0);
        CountList.push_front(0); 
    }
}
void LFUCache:: showlist(){
    for (iter1=NameList.begin(); iter1!=NameList.end(); ++iter1){
        cout <<*iter1<<" ";
    }
    cout<<""<<endl;

    for (iter2=CountList.begin(); iter2!=CountList.end(); ++iter2){
        cout <<*iter2<<" ";
    }
    cout<<""<<endl;
}
void LFUCache:: put(int key, int value){
    int minValue = 523;
    int minIndex =0;
    int index =0;
    iter1 = NameList.begin();
    iter2 = CountList.begin();
    //숫자가 있을 때, count 올리기
    for (iter1=NameList.begin(); iter1!=NameList.end(); ++iter1){
        if (key == *iter1){
            while (index>0){
                iter2++;
                index--;
            }
            *iter2 = value+1;
            return;
        }
        index++;
    }
    //빈 배열이 있을 때 채우기
    index = 0;
    for (iter1=NameList.begin(); iter1!=NameList.end(); ++iter1){
        if (0 == *iter1){
            *iter1 = key;
            while (index>0){
                iter2++;
                index--;
            }   
            *iter2 = value;
            return;
        }
        index++;
    }
    //가장 작은 count를 지우고 업데이트하기 - 가장 작은 count 찾기
    index = 0;
    int times = 0;
    for (iter2=CountList.begin(); iter2!=CountList.end(); ++iter2){
        if (minValue>=*iter2){
            minValue = *iter2;
            ++times;
        }
    }
    showlist();
    cout<<minValue<<endl;
    cout<<times<<endl;
    //가장 작은 count를 지우고 업데이트하기 - 업데이트 하기
    iter1 = NameList.begin();
    for (iter2=CountList.begin(); iter2!=CountList.end(); ++iter2){
        if (*iter2 == minValue){
            --times;
            if (times ==0)
            {
                *iter2 = value;
                while (index>0){
                    ++iter1;
                    index--;
                }
                *iter1 = key;
                showlist(); 
                return;
            }        
        }
        index++;
    }
}
int LFUCache:: get(int key){
    int index = 0;
    iter2 = CountList.begin();
    for (iter1=NameList.begin(); iter1!=NameList.end(); ++iter1){
        if (key == *iter1){
            while (index>0){
                iter2++;
                index--;
            }
            *iter2 = *iter2+1; 
            return *iter2-1;
        }
        ++index;
    }
    return -1;
}
//---------------------------------
int main() {
    // LFU 캐시 테스트
    LFUCache cache(3); // 캐시 크기: 2

    // put(key, value) 메소드 예시
    cache.put(1, 1);
    cache.put(2, 2);
    cout << cache.get(1) << endl; // 1을 출력해야 함
    cache.put(3, 3); // 2를 제거함
    cout << cache.get(2) << endl; // -1을 출력해야 함 (2는 캐시에서 제거됐음)
    cout << cache.get(3) << endl; // 3을 출력해야 함

    return 0;
}