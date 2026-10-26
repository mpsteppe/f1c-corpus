// Function: FUN_00406ba0 @ 00406ba0
// Size (bytes): 251


void __fastcall FUN_00406ba0(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  *param_1 = &PTR_FUN_0059e530;
  FUN_00406e50();
  iVar4 = param_1[0xe];
  while (iVar4 != 0) {
    iVar1 = *(int *)(iVar4 + 4);
    FUN_004081e0();
    FUN_00587bcf(iVar4);
    iVar4 = iVar1;
  }
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  param_1[0x11] = 0;
  piVar3 = (int *)param_1[10];
  while (piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (*piVar3 != 0)) {
      FUN_00404f70(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar2;
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  piVar3 = (int *)param_1[6];
  while (piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar2;
  }
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  piVar3 = (int *)param_1[2];
  while (piVar3 != (int *)0x0) {
    piVar2 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && ((undefined4 *)*piVar3 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar3)(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar2;
  }
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  *param_1 = &PTR_LAB_0059e598;
  return;
}


