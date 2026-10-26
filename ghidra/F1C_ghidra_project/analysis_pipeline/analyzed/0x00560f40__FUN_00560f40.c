// Function: FUN_00560f40 @ 00560f40
// Size (bytes): 126


void __thiscall FUN_00560f40(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x30) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x34) = *(undefined4 *)(param_2 + 0x34);
  }
  if (*(int *)(param_2 + 0x34) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x34) + 0x30) = *(undefined4 *)(param_2 + 0x30);
  }
  if (*(int *)(param_1 + 0x2c) == param_2) {
    iVar1 = *(int *)(param_2 + 0x34);
    *(int *)(param_1 + 0x2c) = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x30) = 0;
    }
  }
  if (DAT_008b8f28 != 0) {
    iVar1 = *(int *)(DAT_008b8f28 + 0x15c);
    iVar2 = 0;
    if (iVar1 == 0) {
      *(int *)(DAT_008b8f28 + 0x15c) = param_2;
    }
    else {
      iVar2 = iVar1;
      for (iVar1 = *(int *)(iVar1 + 0x34); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x34)) {
        iVar2 = iVar1;
      }
      *(int *)(iVar2 + 0x34) = param_2;
    }
    *(int *)(param_2 + 0x30) = iVar2;
    *(undefined4 *)(param_2 + 0x34) = 0;
  }
  *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) & 0xfffffffb;
  return;
}


