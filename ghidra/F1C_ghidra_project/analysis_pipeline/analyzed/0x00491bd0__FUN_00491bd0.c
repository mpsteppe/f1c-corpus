// Function: FUN_00491bd0 @ 00491bd0
// Size (bytes): 153


void __fastcall FUN_00491bd0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = *(int **)(*param_1 + 0xc);
  *(int **)(*param_1 + 0x14) = piVar1;
  if (piVar1 != (int *)0x0) {
    for (iVar2 = *piVar1; iVar2 != 0; iVar2 = **(int **)(iVar2 + 0x14)) {
      FUN_00490aa0();
      iVar2 = *param_1;
      if (*(int *)(iVar2 + 0x14) != 0) {
        *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(*(int *)(iVar2 + 0x14) + 4);
      }
      if (*(int **)(iVar2 + 0x14) == (int *)0x0) break;
    }
  }
  iVar2 = *param_1;
  piVar1 = *(int **)(iVar2 + 0xc);
  while (piVar1 != (int *)0x0) {
    piVar3 = (int *)piVar1[1];
    if (((char)piVar1[2] != '\0') && (*piVar1 != 0)) {
      FUN_00587bcf(*piVar1);
    }
    FUN_00587bcf(piVar1);
    piVar1 = piVar3;
  }
  *(undefined4 *)(iVar2 + 0xc) = 0;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0x14) = 0;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  return;
}


