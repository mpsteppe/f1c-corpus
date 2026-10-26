// Function: FUN_00583570 @ 00583570
// Size (bytes): 119


void __fastcall FUN_00583570(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  
  piVar4 = (int *)*param_1;
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (piVar2 = (int *)*piVar4, piVar2 != (int *)0x0)) {
      iVar3 = *piVar2;
      if (iVar3 != 0) {
        FUN_0058a5f7(iVar3,0x103c,*(undefined4 *)(iVar3 + -4),FUN_0047aa60);
        FUN_00587bcf(iVar3 + -4);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  return;
}


