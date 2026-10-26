// Function: FUN_004918d0 @ 004918d0
// Size (bytes): 140


undefined4 __thiscall
FUN_004918d0(int *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  if ((0 < param_4) && (0 < param_5)) {
    cVar1 = FUN_004f9b20();
    if (cVar1 == '\0') {
      FUN_00490ee0(*(int *)(*param_1 + 4) * 0x10 + *(int *)(*param_1 + 8),param_2,param_3,param_4,
                   param_5);
      return 1;
    }
    iVar2 = *(int *)*param_1;
    if (0 < iVar2) {
      iVar3 = 0;
      do {
        FUN_00490ee0(*(int *)(*param_1 + 8) + iVar3,param_2,param_3,param_4,param_5);
        iVar3 = iVar3 + 0x10;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    return 1;
  }
  return 0;
}


