// Function: FUN_0041efe0 @ 0041efe0
// Size (bytes): 87


int __fastcall FUN_0041efe0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar2 = 0;
  iVar1 = FUN_004c2850();
  if (iVar1 != 0) {
    iVar3 = 0;
    FUN_004c2850();
    iVar1 = FUN_004c11d0();
    if (0 < iVar1) {
      piVar4 = (int *)(param_1 + 0x18);
      do {
        if (*piVar4 == param_2) {
          iVar2 = iVar2 + 1;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 1;
        FUN_004c2850();
        iVar1 = FUN_004c11d0();
      } while (iVar3 < iVar1);
    }
  }
  return iVar2;
}


