// Function: FUN_004a34a0 @ 004a34a0
// Size (bytes): 179


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004a34a0(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (param_2 == '\0') {
    if (0 < *(int *)(param_1 + 0xc)) {
      iVar3 = 0;
      do {
        iVar1 = *(int *)(param_1 + 0x10) + iVar3;
        if ((*(int *)(*(int *)(param_1 + 0x10) + 0x48 + iVar3) != -1) &&
           (*(int *)(iVar1 + 100) != 0)) {
          if ((*(int *)(iVar1 + 0x70) < 1) || (**(float **)(iVar1 + 0x74) != _DAT_0059e928)) {
            if (*(char *)(iVar1 + 2) == '\0') goto LAB_004a353d;
            FUN_0054c1a0();
          }
          else if (*(char *)(iVar1 + 2) == '\0') {
            FUN_0054c1a0();
          }
          else {
LAB_004a353d:
            FUN_0054c190();
          }
        }
        iVar2 = iVar2 + 1;
        iVar3 = iVar3 + 0x78;
      } while (iVar2 < *(int *)(param_1 + 0xc));
    }
  }
  else if (0 < *(int *)(param_1 + 0xc)) {
    iVar3 = 0;
    do {
      if ((*(int *)(*(int *)(param_1 + 0x10) + 0x48 + iVar3) != -1) &&
         (*(int *)(*(int *)(param_1 + 0x10) + iVar3 + 100) != 0)) {
        FUN_0054c190();
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x78;
    } while (iVar2 < *(int *)(param_1 + 0xc));
    return;
  }
  return;
}


