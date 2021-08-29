#include<stdio.h>
#include<windows.h>
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
#include<iostream>
using namespace std;
void panduan(int i){
	if(i>4000){
		printf("请重新输入小于4000的数字\n");
		scanf("%d",&i);
		panduan(i);
	}else{
		return;
	} 
}
int main(){
    int i,res;
    printf("请输入每秒点击的频率（建议小于4000）\n");
    scanf("%d",&i);
    panduan(i);
    res=1000/i;//
	printf("按右键执行（按Esc可退出）");
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

