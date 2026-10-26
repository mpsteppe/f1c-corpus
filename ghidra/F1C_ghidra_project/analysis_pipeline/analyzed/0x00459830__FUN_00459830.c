// Function: FUN_00459830 @ 00459830
// Size (bytes): 278


void __thiscall FUN_00459830(int param_1,undefined4 *param_2)

{
  int iVar1;
  double *pdVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_48 [6];
  double local_30;
  double local_28;
  double local_20;
  double local_18;
  double local_10;
  double local_8;
  
  if (*(int *)(param_1 + 0xd0) != 0) {
    FUN_0054b4d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                 *(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                 *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
    FUN_0054fae0(0x8000000);
  }
  local_30 = (double)*(float *)(param_1 + 4);
  local_28 = (double)*(float *)(param_1 + 8);
  local_20 = (double)*(float *)(param_1 + 0xc);
  pdVar2 = &local_30;
  puVar3 = (undefined4 *)(param_1 + 0xd8);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pdVar2;
    pdVar2 = (double *)((int)pdVar2 + 4);
    puVar3 = puVar3 + 1;
  }
  local_18 = (double)*(float *)(param_1 + 0x10);
  local_10 = (double)*(float *)(param_1 + 0x14);
  local_8 = (double)*(float *)(param_1 + 0x18);
  local_48[0] = 0;
  local_48[1] = 0;
  local_48[2] = 0;
  local_48[3] = 0;
  local_48[4] = 0;
  local_48[5] = 0;
  FUN_005691d0(&local_18);
  puVar3 = local_48;
  puVar4 = (undefined4 *)(param_1 + 0x138);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_00569280(local_48);
  *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(param_1 + 0xc4) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(param_1 + 200) = *(undefined4 *)(param_1 + 0xc);
  *param_2 = *(undefined4 *)(param_1 + 4);
  param_2[1] = *(undefined4 *)(param_1 + 8);
  param_2[2] = *(undefined4 *)(param_1 + 0xc);
  return;
}


