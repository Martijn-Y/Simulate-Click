#include<stdio.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#include<iostream>
using namespace std;
void panduan(int i){
	if(i>4000){
		printf("����������С��4000������\n");
		scanf("%d",&i);
		panduan(i);
	}else{
		return;
	} 
}
int main(){
    int i,res;
    printf("������ÿ������Ƶ�ʣ�����С��4000��\n");
    scanf("%d",&i);
    panduan(i);
    res=1000/i;//
	printf("���Ҽ�ִ�У���Esc���˳���");
    while(1){
        if(KEY_DOWN(VK_RBUTTON)){
            while(1){
                mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);
                if(GetAsyncKeyState(VK_ESCAPE))return 0;
                Sleep(res);
            }
        }
    }
    return 0;
}

