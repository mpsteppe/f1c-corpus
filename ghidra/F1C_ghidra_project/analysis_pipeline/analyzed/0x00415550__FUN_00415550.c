// Function: FUN_00415550 @ 00415550
// Size (bytes): 120


int __thiscall FUN_00415550(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = -1;
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0x1c);
    iVar3 = 0;
    if (0 < iVar1) {
      while( true ) {
        iVar2 = iVar3;
        if ((-1 < iVar2) && (iVar2 < *(int *)(param_1 + 0x1c))) {
          iVar4 = iVar2;
          for (iVar3 = *(int *)(param_1 + 0x10); (0 < iVar4 && (iVar3 != 0));
              iVar3 = *(int *)(iVar3 + 4)) {
            iVar4 = iVar4 + -1;
          }
        }
        iVar3 = FUN_00566810();
        if (iVar3 != 0) break;
        iVar3 = iVar2 + 1;
        if (iVar1 <= iVar2 + 1) {
          return -1;
        }
      }
    }
  }
  return iVar2;
}


