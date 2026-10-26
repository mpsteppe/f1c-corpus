// Function: FUN_00560eb0 @ 00560eb0
// Size (bytes): 91


void __thiscall FUN_00560eb0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_2 + 0x30) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x30) + 0x34) = *(undefined4 *)(param_2 + 0x34);
  }
  if (*(int *)(param_2 + 0x34) != 0) {
    *(undefined4 *)(*(int *)(param_2 + 0x34) + 0x30) = *(undefined4 *)(param_2 + 0x30);
  }
  iVar1 = *(int *)(param_1 + 0x2c);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x2c) = param_2;
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
  *(uint *)(param_2 + 0x24) = *(uint *)(param_2 + 0x24) | 4;
  return;
}


