// Function: FUN_00485eb0 @ 00485eb0
// Size (bytes): 337


void __fastcall FUN_00485eb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  
  *param_1 = &PTR_FUN_005ab8c0;
  FUN_00486080();
  if (param_1[0x30] != 0) {
    FUN_00587bcf(param_1[0x30]);
  }
  if (param_1[0x2e] != 0) {
    FUN_00587bcf(param_1[0x2e]);
  }
  if (param_1[0x2c] != 0) {
    FUN_00587bcf(param_1[0x2c]);
  }
  if (param_1[0x2a] != 0) {
    FUN_00587bcf(param_1[0x2a]);
  }
  if (param_1[0x28] != 0) {
    FUN_00587bcf(param_1[0x28]);
  }
  puVar6 = (undefined4 *)param_1[0x1c];
  while (puVar6 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar6[1];
    if (*(char *)(puVar6 + 2) != '\0') {
      FUN_00587bcf(*puVar6);
    }
    FUN_00587bcf(puVar6);
    puVar6 = puVar1;
  }
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  piVar5 = (int *)param_1[0x15];
  while (piVar5 != (int *)0x0) {
    piVar2 = (int *)piVar5[1];
    if (((char)piVar5[2] != '\0') && (iVar3 = *piVar5, iVar3 != 0)) {
      FUN_00414370();
      FUN_00587bcf(iVar3);
    }
    FUN_00587bcf(piVar5);
    piVar5 = piVar2;
  }
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  piVar5 = (int *)param_1[0x11];
  while (piVar5 != (int *)0x0) {
    piVar2 = (int *)piVar5[1];
    if (((char)piVar5[2] != '\0') && (piVar4 = (int *)*piVar5, piVar4 != (int *)0x0)) {
      if (*piVar4 != 0) {
        FUN_00587bcf(*piVar4);
      }
      FUN_00587bcf(piVar4);
    }
    FUN_00587bcf(piVar5);
    piVar5 = piVar2;
  }
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  FUN_0049a990();
  return;
}


