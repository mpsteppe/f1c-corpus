// Function: FUN_004f6d60 @ 004f6d60
// Size (bytes): 37


void __fastcall FUN_004f6d60(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)param_1[0x10];
  *param_1 = 0;
  iVar1 = 0;
  do {
    if (*piVar2 == 0) {
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
    *param_1 = *param_1 + 1;
  } while (iVar1 < 5);
  return;
}


