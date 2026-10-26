// Function: FUN_004d82a0 @ 004d82a0
// Size (bytes): 36


void __fastcall FUN_004d82a0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x10);
  iVar2 = 0x19;
  do {
    if (*piVar1 != 0) {
      FUN_004d7e30();
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


