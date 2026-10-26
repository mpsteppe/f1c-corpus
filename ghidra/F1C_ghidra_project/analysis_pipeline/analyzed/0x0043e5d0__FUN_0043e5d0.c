// Function: FUN_0043e5d0 @ 0043e5d0
// Size (bytes): 198


void __thiscall FUN_0043e5d0(int param_1,double *param_2,double *param_3)

{
  int iVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double local_20;
  double local_18;
  double local_10;
  
  iVar1 = *(int *)(param_1 + 0x15f0);
  dVar2 = *param_2 - *(double *)(iVar1 + 4);
  dVar4 = param_2[1] - *(double *)(iVar1 + 0xc);
  dVar3 = param_2[2] - *(double *)(iVar1 + 0x14);
  local_20 = dVar4 * param_3[2] - dVar3 * param_3[1];
  local_18 = dVar3 * *param_3 - dVar2 * param_3[2];
  local_10 = dVar2 * param_3[1] - dVar4 * *param_3;
  *(double *)(param_1 + 0x1f04) = *param_3 + *(double *)(param_1 + 0x1f04);
  *(double *)(param_1 + 0x1f0c) = *(double *)(param_1 + 0x1f0c) + param_3[1];
  *(double *)(param_1 + 0x1f14) = param_3[2] + *(double *)(param_1 + 0x1f14);
  *(double *)(param_1 + 0x1f1c) = local_20 + *(double *)(param_1 + 0x1f1c);
  *(double *)(param_1 + 0x1f24) = local_18 + *(double *)(param_1 + 0x1f24);
  *(double *)(param_1 + 0x1f2c) = local_10 + *(double *)(param_1 + 0x1f2c);
  FUN_0044fee0(param_3,&local_20);
  return;
}


