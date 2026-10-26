// Function: FUN_00414420 @ 00414420
// Size (bytes): 87


void __fastcall FUN_00414420(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00414fe0();
  piVar3 = param_1 + 0x17;
  iVar2 = 2;
  do {
    piVar1 = piVar3 + -5;
    piVar3 = piVar3 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  piVar3 = param_1 + 0xd;
  iVar2 = 2;
  do {
    piVar1 = piVar3 + -5;
    piVar3 = piVar3 + -5;
    if (*piVar1 != 0) {
      FUN_00587bcf(*piVar1);
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  if (*param_1 != 0) {
    FUN_00587bcf(*param_1);
  }
  return;
}


