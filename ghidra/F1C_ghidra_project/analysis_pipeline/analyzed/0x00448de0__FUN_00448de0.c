// Function: FUN_00448de0 @ 00448de0
// Size (bytes): 60


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00448de0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  do {
    piVar2 = (int *)(param_1 + 0x4c);
    iVar1 = 4;
    *(double *)(param_1 + 0x10) =
         (*(double *)(param_1 + 4) + *(double *)(param_1 + 0x10)) * _DAT_0059e880;
    do {
      if (*piVar2 != 0) {
        FUN_00448de0();
      }
      piVar2 = piVar2 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    param_1 = *(int *)(param_1 + 0x5c);
  } while (param_1 != 0);
  return;
}


