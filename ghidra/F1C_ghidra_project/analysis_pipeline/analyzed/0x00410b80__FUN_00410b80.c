// Function: FUN_00410b80 @ 00410b80
// Size (bytes): 60


int __thiscall FUN_00410b80(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    piVar2 = (int *)(*(int *)(param_1 + 0x44) + 0xd0);
    do {
      if (*piVar2 == param_2) {
        return *(int *)(param_1 + 0x40) + iVar1 * 0x24;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 0xc6;
    } while (iVar1 < *(int *)(param_1 + 0x3c));
  }
  return 0;
}


