// Function: FUN_00563230 @ 00563230
// Size (bytes): 33


int __fastcall FUN_00563230(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x6c)) {
    piVar2 = (int *)(*(int *)(param_1 + 8) + 4);
    do {
      if (*piVar2 == param_2) {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
      piVar2 = piVar2 + 7;
    } while (iVar1 < *(int *)(param_1 + 0x6c));
  }
  return -1;
}


