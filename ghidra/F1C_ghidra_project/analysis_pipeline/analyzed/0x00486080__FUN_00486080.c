// Function: FUN_00486080 @ 00486080
// Size (bytes): 286


void __fastcall FUN_00486080(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  
  iVar5 = *(int *)(param_1 + 0xcc);
  while (iVar5 != 0) {
    iVar1 = *(int *)(iVar5 + 0x18);
    FUN_0049a5a0();
    FUN_00587bcf(iVar5);
    iVar5 = iVar1;
  }
  iVar5 = *(int *)(param_1 + 0xd0);
  while (iVar5 != 0) {
    iVar1 = *(int *)(iVar5 + 0x18);
    FUN_0049a5a0();
    FUN_00587bcf(iVar5);
    iVar5 = iVar1;
  }
  iVar5 = *(int *)(param_1 + 0xd4);
  while (iVar5 != 0) {
    iVar1 = *(int *)(iVar5 + 0x18);
    FUN_0049a5a0();
    FUN_00587bcf(iVar5);
    iVar5 = iVar1;
  }
  iVar5 = *(int *)(param_1 + 0xd8);
  while (iVar5 != 0) {
    iVar1 = *(int *)(iVar5 + 0x18);
    FUN_0049a5a0();
    FUN_00587bcf(iVar5);
    iVar5 = iVar1;
  }
  puVar2 = *(undefined4 **)(param_1 + 0x90);
  while (puVar2 != (undefined4 *)0x0) {
    uVar7 = FUN_00486320();
    *(undefined4 *)(param_1 + 0x90) = uVar7;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    puVar2 = *(undefined4 **)(param_1 + 0x90);
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  piVar6 = *(int **)(param_1 + 0x54);
  while (piVar6 != (int *)0x0) {
    piVar3 = (int *)piVar6[1];
    if (((char)piVar6[2] != '\0') && (piVar4 = (int *)*piVar6, piVar4 != (int *)0x0)) {
      if (*piVar4 != 0) {
        FUN_00587bcf(*piVar4);
      }
      FUN_00587bcf(piVar4);
    }
    FUN_00587bcf(piVar6);
    piVar6 = piVar3;
  }
  *(undefined4 *)(param_1 + 0x54) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x60) = 0;
  return;
}


