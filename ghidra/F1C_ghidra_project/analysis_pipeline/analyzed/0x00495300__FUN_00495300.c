// Function: FUN_00495300 @ 00495300
// Size (bytes): 315


void __fastcall FUN_00495300(undefined4 *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  *param_1 = &PTR_FUN_005ac998;
  FUN_00499580();
  FUN_00499580();
  FUN_00499580();
  iVar3 = param_1[0x62b];
  while (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 4);
    FUN_00499620(1);
  }
  param_1[0x62b] = 0;
  param_1[0x62c] = 0;
  param_1[0x62d] = 0;
  param_1[0x62e] = 0;
  FUN_0049a190();
  FUN_004b0170();
  FUN_0049a2f0();
  puVar4 = param_1 + 0x58b;
  iVar3 = 4;
  do {
    piVar2 = puVar4 + -3;
    puVar4 = puVar4 + -3;
    if (*piVar2 != 0) {
      FUN_00587bcf(*piVar2);
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (param_1[0x556] != 0) {
    FUN_00587bcf(param_1[0x556]);
  }
  iVar3 = param_1[0x3c];
  while (iVar3 != 0) {
    iVar3 = *(int *)(iVar3 + 4);
    FUN_004995e0(1);
  }
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  if (param_1[0xf] != 0) {
    FUN_00587bcf(param_1[0xf]);
  }
  piVar2 = (int *)param_1[1];
  while (piVar2 != (int *)0x0) {
    piVar1 = (int *)piVar2[1];
    if (((char)piVar2[3] != '\0') && ((undefined4 *)*piVar2 != (undefined4 *)0x0)) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
    FUN_00587bcf(piVar2);
    piVar2 = piVar1;
  }
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return;
}


