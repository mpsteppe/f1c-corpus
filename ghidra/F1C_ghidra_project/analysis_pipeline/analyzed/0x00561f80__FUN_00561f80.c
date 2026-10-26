// Function: FUN_00561f80 @ 00561f80
// Size (bytes): 100


void __fastcall FUN_00561f80(SOCKET *param_1)

{
  SOCKET s;
  
  if (param_1 == (SOCKET *)0x0) {
    param_1 = (SOCKET *)PTR_DAT_005e4dfc;
  }
  if ((*param_1 != 0xffffffff) && (param_1[0x39] != 0)) {
    closesocket(*param_1);
  }
  s = param_1[1];
  if ((s != 0xffffffff) && (s != *param_1)) {
    closesocket(s);
  }
  param_1[1] = 0xffffffff;
  *param_1 = 0xffffffff;
  param_1[0x36] = 0;
  if (param_1 != &DAT_005e4cf8) {
    FUN_0058aa6f(param_1);
  }
  WSACleanup();
  return;
}


