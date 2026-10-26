// Function: FUN_0056d1c0 @ 0056d1c0
// Size (bytes): 264


void __fastcall FUN_0056d1c0(int param_1)

{
  int iVar1;
  double *pdVar2;
  double *pdVar3;
  int iVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  
  iVar1 = *(int *)(param_1 + 4);
  pdVar2 = *(double **)(param_1 + 8);
  pdVar3 = *(double **)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 0xc);
  dVar7 = (*(double *)(iVar1 + 0x1c) * *pdVar2 +
           *(double *)(iVar1 + 0x24) * pdVar2[1] + *(double *)(iVar1 + 0x2c) * pdVar2[2] +
          *(double *)(iVar1 + 4)) -
          (*pdVar3 * *(double *)(iVar4 + 0x1c) +
           *(double *)(iVar4 + 0x24) * pdVar3[1] + *(double *)(iVar4 + 0x2c) * pdVar3[2] +
          *(double *)(iVar4 + 4));
  dVar5 = (*(double *)(iVar1 + 0x34) * *pdVar2 +
           *(double *)(iVar1 + 0x3c) * pdVar2[1] + *(double *)(iVar1 + 0x44) * pdVar2[2] +
          *(double *)(iVar1 + 0xc)) -
          (*(double *)(iVar4 + 0x34) * *pdVar3 +
           *(double *)(iVar4 + 0x3c) * pdVar3[1] + *(double *)(iVar4 + 0x44) * pdVar3[2] +
          *(double *)(iVar4 + 0xc));
  dVar6 = (*(double *)(iVar1 + 0x4c) * *pdVar2 +
           *(double *)(iVar1 + 0x54) * pdVar2[1] + *(double *)(iVar1 + 0x5c) * pdVar2[2] +
          *(double *)(iVar1 + 0x14)) -
          (*(double *)(iVar4 + 0x4c) * *pdVar3 +
           *(double *)(iVar4 + 0x54) * pdVar3[1] + *(double *)(iVar4 + 0x5c) * pdVar3[2] +
          *(double *)(iVar4 + 0x14));
  dVar5 = SQRT(dVar7 * dVar7 + dVar5 * dVar5 + dVar6 * dVar6);
  pdVar2[7] = dVar5;
  *(double *)(*(int *)(param_1 + 0x10) + 0x38) = dVar5;
  return;
}


