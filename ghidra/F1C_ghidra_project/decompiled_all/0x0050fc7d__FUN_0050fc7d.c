// Function: FUN_0050fc7d @ 0050fc7d
// Strings:  [Software\Microsoft\Direct3D, DisableMMX]


int FUN_0050fc7d(void)

{
  LSTATUS LVar1;
  int iVar2;
  int local_14;
  DWORD local_10 [2];
  HKEY local_8;
  
  LVar1 = RegOpenKeyA((HKEY)0x80000002,"Software\\Microsoft\\Direct3D",&local_8);
  if (LVar1 == 0) {
    local_10[1] = 4;
    LVar1 = RegQueryValueExA(local_8,"DisableMMX",(LPDWORD)0x0,local_10,(LPBYTE)&local_14,
                             local_10 + 1);
    if (((LVar1 == 0) && (local_10[0] == 4)) && (local_14 != 0)) {
      RegCloseKey(local_8);
      DAT_005d7994 = 0;
      return 0;
    }
    RegCloseKey(local_8);
  }
  if (DAT_005d7994 < 0) {
    DAT_005d7994 = 0;
    iVar2 = FUN_0050fc58();
    if (iVar2 != 0) {
      DAT_005d7994 = 1;
    }
  }
  return DAT_005d7994;
}


