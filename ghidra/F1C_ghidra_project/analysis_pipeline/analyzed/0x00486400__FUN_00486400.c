// Function: FUN_00486400 @ 00486400
// Size (bytes): 89


int __thiscall FUN_00486400(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x90);
  if (iVar2 != 0) {
    iVar1 = iVar2;
    if (iVar2 == param_2) {
      *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(iVar2 + 0x8c);
LAB_00486445:
      *(undefined4 *)(iVar2 + 0x8c) = 0;
      *(int *)(param_1 + 0x94) = *(int *)(param_1 + 0x94) + -1;
      return iVar2;
    }
    do {
      iVar2 = *(int *)(iVar1 + 0x8c);
      if (iVar2 == param_2) {
        *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(iVar2 + 0x8c);
        goto LAB_00486445;
      }
      iVar1 = iVar2;
    } while (iVar2 != 0);
  }
  return 0;
}


