// Function: FUN_00459a40 @ 00459a40
// Size (bytes): 148


void __thiscall FUN_00459a40(int param_1,int param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  double *pdVar5;
  double *pdVar6;
  double local_30;
  double local_28;
  double local_20;
  double local_10;
  double local_8;
  
  fVar1 = *(float *)(param_2 + 8);
  fVar2 = *(float *)(param_2 + 0x30) * fVar1;
  local_10 = (double)fVar2;
  local_8 = (double)(*(float *)(param_2 + 0x34) * fVar1);
  fVar1 = *(float *)(param_2 + 0x2c) * fVar1 + (float)*(double *)(param_1 + 0xd8);
  local_30 = (double)fVar1;
  fVar2 = fVar2 + (float)*(double *)(param_1 + 0xe0);
  local_28 = (double)fVar2;
  local_20 = local_8 + *(double *)(param_1 + 0xe8);
  pdVar5 = &local_30;
  pdVar6 = (double *)(param_1 + 0xd8);
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pdVar6 = *(undefined4 *)pdVar5;
    pdVar5 = (double *)((int)pdVar5 + 4);
    pdVar6 = (double *)((int)pdVar6 + 4);
  }
  *param_3 = fVar1;
  param_3[1] = fVar2;
  fVar3 = (float)local_20;
  param_3[2] = fVar3;
  FUN_0054b3b0(fVar1,fVar2,fVar3);
  return;
}


