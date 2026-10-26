// Function: FUN_004496d0 @ 004496d0
// Size (bytes): 46


int __fastcall FUN_004496d0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    iVar2 = 0;
    if (iVar1 != 1 && -1 < iVar1 + -1) {
      iVar1 = 0;
      do {
        *(int *)(iVar1 + 0x1c + param_1[2]) = iVar1 + 0x20 + param_1[2];
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0x20;
      } while (iVar2 < *param_1 + -1);
    }
    return param_1[2];
  }
  return 0;
}


