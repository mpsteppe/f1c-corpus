// Function: FUN_0055bd20 @ 0055bd20
// Size (bytes): 160


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0055bd20(int param_1,int param_2,int param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x120);
  iVar2 = 0;
  while( true ) {
    if (iVar1 == 0) {
      return 0xffffffff;
    }
    if ((((*(int *)(iVar1 + 8) == param_2) && (*(int *)(iVar1 + 0xc) == param_3)) &&
        (*(int *)(iVar1 + 0x14) == param_4)) &&
       ((param_6 == 0 || (*(int *)(iVar1 + 0x18) == param_6)))) break;
    iVar1 = *(int *)(iVar1 + 0x20);
    iVar2 = iVar2 + 1;
  }
  *(int *)(param_1 + 0x118) = iVar2;
  _DAT_008b8dec = param_5 & 1;
  DAT_008b8dd4 = param_2;
  DAT_008b8dd8 = param_3;
  DAT_008b8de4 = param_4;
  iVar1 = FUN_0053e070(param_1,DAT_008b8f0c,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  FUN_0055c440(1);
  return 0;
}


