// Function: FUN_005419d0 @ 005419d0
// Size (bytes): 157


void __thiscall FUN_005419d0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_2 + 0x1b4) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x1b4) + 0x1b8) = *(undefined4 *)(param_2 + 0x1b8);
  }
  if (*(int *)(param_2 + 0x1b8) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x1b8) + 0x1b4) = *(undefined4 *)(param_2 + 0x1b4);
  }
  if (param_2 == *(int *)(DAT_008b8f28 + 0xf8)) {
    *(undefined4 *)(DAT_008b8f28 + 0xf8) = *(undefined4 *)(param_2 + 0x1b8);
  }
  iVar1 = *(int *)(param_1 + 0x1b0);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x1b0) = param_2;
  }
  else {
    iVar2 = iVar1;
    for (iVar1 = *(int *)(iVar1 + 0x1b8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1b8)) {
      iVar2 = iVar1;
    }
    *(int *)(iVar2 + 0x1b8) = param_2;
  }
  *(int *)(param_2 + 0x1b4) = iVar2;
  *(undefined4 *)(param_2 + 0x1b8) = 0;
  *(int *)(param_2 + 0x1ac) = param_1;
  return;
}


