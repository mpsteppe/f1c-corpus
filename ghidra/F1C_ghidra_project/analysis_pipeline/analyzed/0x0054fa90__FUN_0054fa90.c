// Function: FUN_0054fa90 @ 0054fa90
// Size (bytes): 67


undefined4 __thiscall FUN_0054fa90(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(param_1 + 0x1e0);
  if (((iVar1 != 0) && (param_2 < *(int *)(iVar1 + 4))) &&
     ((*(byte *)(param_2 * 0x74 + *(int *)(iVar1 + 8)) & 1) != 0)) {
    puVar3 = (undefined4 *)(param_2 * 0x74 + *(int *)(iVar1 + 8) + 0x34);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_3 = *puVar3;
      puVar3 = puVar3 + 1;
      param_3 = param_3 + 1;
    }
    return 1;
  }
  return 0;
}


