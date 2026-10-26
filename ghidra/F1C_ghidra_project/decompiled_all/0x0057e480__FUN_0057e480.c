// Function: FUN_0057e480 @ 0057e480
// Strings:  [HotPacket_over_Winsock, <HotPacket::Winsock>, <HotPacket::Winsock>]


undefined4 __fastcall FUN_0057e480(int param_1)

{
  int iVar1;
  WNDCLASSA *pWVar2;
  WNDCLASSA local_28;
  
  if (DAT_008d3e28 == (HWND)0x0) {
    pWVar2 = &local_28;
    for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
      pWVar2->style = 0;
      pWVar2 = (WNDCLASSA *)&pWVar2->lpfnWndProc;
    }
    local_28.hInstance = *(HINSTANCE *)(param_1 + 0x774);
    local_28.style = 3;
    local_28.lpfnWndProc = (WNDPROC)&LAB_0057aea0;
    local_28.lpszMenuName = (LPCSTR)0x0;
    local_28.lpszClassName = PTR_s_<HotPacket_Winsock>_005e5374;
    RegisterClassA(&local_28);
    DAT_008d3e28 = CreateWindowExA(0,PTR_s_<HotPacket_Winsock>_005e5374,
                                   PTR_s_HotPacket_over_Winsock_005e5378,0x8000000,-0x80000000,
                                   -0x80000000,1,1,(HWND)0x0,(HMENU)0x0,
                                   *(HINSTANCE *)(param_1 + 0x774),(LPVOID)0x0);
    if (DAT_008d3e28 == (HWND)0x0) {
      return 0;
    }
  }
  return 1;
}


