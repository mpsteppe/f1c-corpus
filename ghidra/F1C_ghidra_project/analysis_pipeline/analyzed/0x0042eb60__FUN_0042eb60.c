// Function: FUN_0042eb60 @ 0042eb60
// Size (bytes): 92


void __thiscall FUN_0042eb60(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_2 * 0x40;
  iVar1 = *(int *)(param_1 + iVar2 + 0xbc4);
  if (param_3 < 1) {
    *(undefined4 *)(param_1 + iVar2 + 0xbc4) = 0;
  }
  else if (param_3 < *(int *)(param_1 + iVar2 + 0xbc0)) {
    *(int *)(param_1 + iVar2 + 0xbc4) = param_3;
  }
  else {
    *(int *)(param_1 + iVar2 + 0xbc4) = *(int *)(param_1 + iVar2 + 0xbc0) + -1;
  }
  FUN_0042e530(4,param_2);
  if (*(int *)(param_1 + iVar2 + 0xbc4) != iVar1) {
    param_1[0x19a4] = 1;
    *param_1 = 1;
  }
  return;
}


