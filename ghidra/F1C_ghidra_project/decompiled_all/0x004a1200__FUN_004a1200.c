// Function: FUN_004a1200 @ 004a1200
// Strings:  [F1 Challenge 99-02, CUBEApp, %s v%0.3f, CUBERealtime, CUBERealtime]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004a1200(int param_1,int param_2)

{
  ATOM AVar1;
  HWND hWnd;
  undefined4 uVar2;
  tagRECT local_70;
  RECT local_60;
  CHAR local_50 [80];
  
  hWnd = GetDesktopWindow();
  _DAT_007ce270 = 0x30;
  _DAT_007ce284 = DAT_007ce2a0;
  _DAT_007ce298 = s_CUBERealtime_005cd0a4;
  _DAT_007ce278 = &LAB_004a1560;
  _DAT_007ce274 = 0x40;
  _DAT_007ce288 = LoadIconA(DAT_007ce2a0,(LPCSTR)0x65);
  _DAT_007ce29c = 0;
  _DAT_007ce28c = 0;
  _DAT_007ce294 = 0;
  _DAT_007ce27c = 0;
  _DAT_007ce280 = 0;
  _DAT_007ce290 = GetStockObject(5);
  FUN_0058815f(local_50,s__s_v_0_3f_005cd098,s_F1_Challenge_99_02_005c6620,(double)_DAT_007c56b0);
  if (DAT_005ec4a4 == '\0') {
    _DAT_007ce288 = LoadIconA((HINSTANCE)0x0,(LPCSTR)0x7f00);
    AVar1 = RegisterClassExA((WNDCLASSEXA *)&DAT_007ce270);
    if (AVar1 == 0) {
      return 1;
    }
    DAT_007ce2dc = CreateWindowExA(8,s_CUBERealtime_005cd0a4,local_50,0x80000000,0,0,param_1,param_2
                                   ,(HWND)0x0,(HMENU)0x0,DAT_007ce2a0,(LPVOID)0x0);
    local_60.left = 0;
    local_60.right = param_1;
    local_60.top = 0;
    local_60.bottom = param_2;
    DAT_007ce2e0 = DAT_007ce2dc;
    ClipCursor(&local_60);
    ShowWindow(DAT_007ce2dc,1);
    DAT_007ce2e4 = 1;
    return 0;
  }
  _DAT_007ce2a8 = 0x30;
  _DAT_007ce2bc = DAT_007ce2a0;
  _DAT_007ce2d0 = s_CUBEApp_005cd090;
  _DAT_007ce2b0 = &LAB_004a1560;
  _DAT_007ce2ac = 0;
  _DAT_007ce2c0 = LoadIconA(DAT_007ce2a0,(LPCSTR)0x65);
  _DAT_007ce2d4 = 0;
  _DAT_007ce2c4 = 0;
  _DAT_007ce2cc = 0;
  _DAT_007ce2b4 = 0;
  _DAT_007ce2b8 = 0;
  _DAT_007ce2c8 = GetStockObject(5);
  AVar1 = RegisterClassExA((WNDCLASSEXA *)&DAT_007ce2a8);
  if (AVar1 == 0) {
    return 1;
  }
  GetClientRect(hWnd,&local_70);
  uVar2 = FUN_0059db88();
  return uVar2;
}


