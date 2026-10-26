// Function: FUN_00558dc0 @ 00558dc0
// Size (bytes): 72


void __thiscall FUN_00558dc0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x4c) == 1) && (*(char *)(param_1 + 0x20) < '\0')) {
    FUN_00558d10(0);
    iVar1 = *(int *)(*(int *)(param_1 + 0x50) + 0x20);
    if (iVar1 != 0) {
      *(undefined4 *)
       ((*(int *)(param_2 * 0x80 + 4 + *(int *)(param_1 + 0x34)) * *(int *)(param_1 + 0x24) +
        param_3) * 0x40 + 0x18 + iVar1) = param_4;
    }
  }
  return;
}


