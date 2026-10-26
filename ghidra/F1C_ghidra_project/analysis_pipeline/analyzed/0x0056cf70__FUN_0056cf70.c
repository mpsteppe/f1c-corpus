// Function: FUN_0056cf70 @ 0056cf70
// Size (bytes): 161


void __fastcall FUN_0056cf70(int param_1)

{
  double *pdVar1;
  int iVar2;
  
  pdVar1 = *(double **)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  pdVar1[3] = *(double *)(iVar2 + 0x1c) * *pdVar1 +
              *(double *)(iVar2 + 0x24) * pdVar1[1] + *(double *)(iVar2 + 0x2c) * pdVar1[2];
  pdVar1[4] = *(double *)(iVar2 + 0x34) * *pdVar1 +
              *(double *)(iVar2 + 0x3c) * pdVar1[1] + *(double *)(iVar2 + 0x44) * pdVar1[2];
  pdVar1[5] = *(double *)(iVar2 + 0x4c) * *pdVar1 +
              *(double *)(iVar2 + 0x54) * pdVar1[1] + *(double *)(iVar2 + 0x5c) * pdVar1[2];
  pdVar1 = *(double **)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0xc);
  pdVar1[3] = *(double *)(iVar2 + 0x1c) * *pdVar1 +
              *(double *)(iVar2 + 0x24) * pdVar1[1] + *(double *)(iVar2 + 0x2c) * pdVar1[2];
  pdVar1[4] = *(double *)(iVar2 + 0x34) * *pdVar1 +
              *(double *)(iVar2 + 0x3c) * pdVar1[1] + *(double *)(iVar2 + 0x44) * pdVar1[2];
  pdVar1[5] = *(double *)(iVar2 + 0x4c) * *pdVar1 +
              *(double *)(iVar2 + 0x54) * pdVar1[1] + *(double *)(iVar2 + 0x5c) * pdVar1[2];
  return;
}


