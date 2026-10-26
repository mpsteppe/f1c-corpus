// Function: FUN_00595924 @ 00595924
// Size (bytes): 124


undefined4 FUN_00595924(uint param_1,HANDLE param_2)

{
  undefined4 *puVar1;
  int iVar2;
  DWORD nStdHandle;
  
  if (param_1 < DAT_008d4a20) {
    iVar2 = (param_1 & 0x1f) * 0x24;
    if (*(int *)((&DAT_008d4920)[(int)param_1 >> 5] + iVar2) == -1) {
      if (DAT_005e65b4 == 1) {
        if (param_1 == 0) {
          nStdHandle = 0xfffffff6;
        }
        else if (param_1 == 1) {
          nStdHandle = 0xfffffff5;
        }
        else {
          if (param_1 != 2) goto LAB_0059597d;
          nStdHandle = 0xfffffff4;
        }
        SetStdHandle(nStdHandle,param_2);
      }
LAB_0059597d:
      *(HANDLE *)((&DAT_008d4920)[(int)param_1 >> 5] + iVar2) = param_2;
      return 0;
    }
  }
  puVar1 = (undefined4 *)FUN_0058afcf();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0058afd8();
  *puVar1 = 0;
  return 0xffffffff;
}


