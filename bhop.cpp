#include <Windows.h>

DWORD pid;
DWORD Jump = 0x243E71E4;
DWORD On_ground = 0x243E9FE4;

int on_ground;
int jump_on = 5;
int jump_off = 4;

int main(){
	
	HWND hwnd = FindWindowA(0, ("Counter-Strike Source"));
	GetWindowThreadProcessId(hwnd, &pid);
	HANDLE pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
    

    for(;;)
    {

    
    ReadProcessMemory(pHandle, (void*)On_ground, &on_ground, sizeof(int), 0);
    
    if (GetAsyncKeyState(VK_SPACE) && on_ground == 1){
    
        WriteProcessMemory(pHandle, (LPVOID)Jump, &jump_on, sizeof(int), 0);
                  
    }
    
    else{ 
        WriteProcessMemory(pHandle, (LPVOID)Jump, &jump_off, sizeof(int), 0);
    }  
    
    }
    
    return 0;
    
}
