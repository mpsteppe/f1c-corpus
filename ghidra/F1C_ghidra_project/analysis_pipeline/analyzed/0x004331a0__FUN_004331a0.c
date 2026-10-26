// Function: FUN_004331a0 @ 004331a0
// Size (bytes): 231


void __fastcall FUN_004331a0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  FUN_00566650(&DAT_005ea438);
  FUN_00566650(&DAT_005ea438);
  FUN_00566650(&DAT_005ea438);
  *(undefined1 *)(param_1 + 0x18) = 0;
  piVar4 = *(int **)(param_1 + 0x1c);
  while (piVar4 != (int *)0x0) {
    piVar1 = (int *)piVar4[1];
    if (((char)piVar4[2] != '\0') && (piVar2 = (int *)*piVar4, piVar2 != (int *)0x0)) {
      FUN_00432cc0();
      if (piVar2[5] != 0) {
        FUN_00587bcf(piVar2[5]);
      }
      if (piVar2[2] != 0) {
        FUN_00587bcf(piVar2[2]);
      }
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar4);
    piVar4 = piVar1;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined1 *)(param_1 + 0x2c) = 0;
  puVar5 = *(undefined4 **)(param_1 + 0x30);
  while (puVar5 != (undefined4 *)0x0) {
    puVar3 = (undefined4 *)puVar5[1];
    if (*(char *)(puVar5 + 2) != '\0') {
      FUN_00587bcf(*puVar5);
    }
    FUN_00587bcf(puVar5);
    puVar5 = puVar3;
  }
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  return;
}


