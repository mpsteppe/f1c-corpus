// Function: FUN_0049f170 @ 0049f170
// Size (bytes): 71


void __thiscall FUN_0049f170(int param_1,char param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_007c54e8;
  do {
    if (param_2 == '\0') {
      iVar2 = *(int *)(param_1 + 4) + 1;
      *(int *)(param_1 + 4) = iVar2;
      if (4 < iVar2) {
        *(undefined4 *)(param_1 + 4) = 0;
      }
    }
    else {
      iVar2 = *(int *)(param_1 + 4) + -1;
      *(int *)(param_1 + 4) = iVar2;
      if (iVar2 < 0) {
        *(undefined4 *)(param_1 + 4) = 4;
      }
    }
  } while (*(int *)(iVar1 + 0x32f4 + *(int *)(param_1 + 4) * 0x40) < 2);
  return;
}


