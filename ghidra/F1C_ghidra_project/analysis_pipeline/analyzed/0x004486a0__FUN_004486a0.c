// Function: FUN_004486a0 @ 004486a0
// Size (bytes): 59


int __fastcall FUN_004486a0(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 1;
  piVar3 = (int *)(param_1 + 0x4c);
  iVar2 = 4;
  do {
    if (*piVar3 != 0) {
      iVar1 = FUN_004486a0();
      iVar4 = iVar4 + iVar1;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*(int *)(param_1 + 0x5c) != 0) {
    iVar2 = FUN_004486a0();
    iVar4 = iVar4 + iVar2;
  }
  return iVar4;
}


