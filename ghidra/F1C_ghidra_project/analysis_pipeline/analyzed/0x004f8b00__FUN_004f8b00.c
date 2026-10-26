// Function: FUN_004f8b00 @ 004f8b00
// Size (bytes): 68


void __fastcall FUN_004f8b00(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 3;
  iVar2 = FUN_004f8c00(piVar1);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    param_1[2] = param_1[2] + -0x8000;
    param_1[1] = param_1[1] + -0x8000;
    *piVar1 = *piVar1 + -0x8000;
  }
  return;
}


