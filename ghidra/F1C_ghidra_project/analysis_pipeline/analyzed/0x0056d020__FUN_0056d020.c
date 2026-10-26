// Function: FUN_0056d020 @ 0056d020
// Size (bytes): 407


void __fastcall FUN_0056d020(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  double *pdVar4;
  
  FUN_00435e00(*(int *)(param_1 + 8) + 0x18,*(int *)(param_1 + 8) + 0x48);
  FUN_00435e00(*(int *)(param_1 + 8) + 0x30,*(int *)(param_1 + 8) + 0x60);
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 8);
  iVar3 = *(int *)(param_1 + 0xc);
  pdVar4 = (double *)(iVar2 + 0x48);
  *(double *)(iVar1 + 0x18) =
       *(double *)(iVar3 + 0x1c) * *pdVar4 +
       *(double *)(iVar3 + 0x34) * *(double *)(iVar2 + 0x50) +
       *(double *)(iVar3 + 0x4c) * *(double *)(iVar2 + 0x58);
  *(double *)(iVar1 + 0x20) =
       *(double *)(iVar3 + 0x3c) * *(double *)(iVar2 + 0x50) +
       *(double *)(iVar3 + 0x54) * *(double *)(iVar2 + 0x58) + *(double *)(iVar3 + 0x24) * *pdVar4;
  *(double *)(iVar1 + 0x28) =
       *(double *)(iVar3 + 0x44) * *(double *)(iVar2 + 0x50) +
       *(double *)(iVar3 + 0x5c) * *(double *)(iVar2 + 0x58) + *(double *)(iVar3 + 0x2c) * *pdVar4;
  pdVar4 = *(double **)(param_1 + 0x10);
  pdVar4[6] = pdVar4[1] * pdVar4[5] - pdVar4[2] * pdVar4[4];
  pdVar4[7] = pdVar4[2] * pdVar4[3] - *pdVar4 * pdVar4[5];
  pdVar4[8] = *pdVar4 * pdVar4[4] - pdVar4[1] * pdVar4[3];
  pdVar4 = *(double **)(param_1 + 0x10);
  pdVar4[3] = pdVar4[7] * pdVar4[2] - pdVar4[8] * pdVar4[1];
  pdVar4[4] = pdVar4[8] * *pdVar4 - pdVar4[6] * pdVar4[2];
  pdVar4[5] = pdVar4[6] * pdVar4[1] - pdVar4[7] * *pdVar4;
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0xc);
  *(double *)(iVar1 + 0x48) =
       *(double *)(iVar2 + 0x1c) * *(double *)(iVar1 + 0x18) +
       *(double *)(iVar2 + 0x24) * *(double *)(iVar1 + 0x20) +
       *(double *)(iVar2 + 0x2c) * *(double *)(iVar1 + 0x28);
  *(double *)(iVar1 + 0x50) =
       *(double *)(iVar2 + 0x34) * *(double *)(iVar1 + 0x18) +
       *(double *)(iVar2 + 0x3c) * *(double *)(iVar1 + 0x20) +
       *(double *)(iVar2 + 0x44) * *(double *)(iVar1 + 0x28);
  *(double *)(iVar1 + 0x58) =
       *(double *)(iVar2 + 0x4c) * *(double *)(iVar1 + 0x18) +
       *(double *)(iVar2 + 0x54) * *(double *)(iVar1 + 0x20) +
       *(double *)(iVar2 + 0x5c) * *(double *)(iVar1 + 0x28);
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0xc);
  *(double *)(iVar1 + 0x60) =
       *(double *)(iVar2 + 0x1c) * *(double *)(iVar1 + 0x30) +
       *(double *)(iVar2 + 0x24) * *(double *)(iVar1 + 0x38) +
       *(double *)(iVar2 + 0x2c) * *(double *)(iVar1 + 0x40);
  *(double *)(iVar1 + 0x68) =
       *(double *)(iVar2 + 0x34) * *(double *)(iVar1 + 0x30) +
       *(double *)(iVar2 + 0x3c) * *(double *)(iVar1 + 0x38) +
       *(double *)(iVar2 + 0x44) * *(double *)(iVar1 + 0x40);
  *(double *)(iVar1 + 0x70) =
       *(double *)(iVar2 + 0x4c) * *(double *)(iVar1 + 0x30) +
       *(double *)(iVar2 + 0x54) * *(double *)(iVar1 + 0x38) +
       *(double *)(iVar2 + 0x5c) * *(double *)(iVar1 + 0x40);
  return;
}


