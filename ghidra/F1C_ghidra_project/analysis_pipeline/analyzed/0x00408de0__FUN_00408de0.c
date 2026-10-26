// Function: FUN_00408de0 @ 00408de0
// Size (bytes): 59


void __thiscall FUN_00408de0(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00541ca0(param_2);
    if ((param_2 == 0) && (iVar1 = *(int *)(param_1 + 0xc), iVar1 != 0)) {
      FUN_00543440(0,0,*(undefined4 *)(iVar1 + 0x1c),*(undefined4 *)(iVar1 + 0x20),&DAT_00686b75);
    }
  }
  return;
}


