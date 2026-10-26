// Function: FUN_004ec080 @ 004ec080
// Size (bytes): 274


void __thiscall FUN_004ec080(int *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float local_24;
  float local_20;
  float local_1c;
  double local_18;
  double local_10;
  double local_8;
  
  fVar2 = *(float *)(param_2 + 8);
  fVar4 = fVar2 * *(float *)(param_2 + 0x2c);
  fVar3 = fVar2 * *(float *)(param_2 + 0x30);
  fVar2 = fVar2 * *(float *)(param_2 + 0x34);
  pfVar1 = (float *)(param_1 + 0xd35);
  *pfVar1 = fVar4 + *pfVar1;
  param_1[0xd36] = (int)(fVar3 + (float)param_1[0xd36]);
  param_1[0xd37] = (int)(fVar2 + (float)param_1[0xd37]);
  FUN_004e23d0(pfVar1,param_1 + 0xd38,param_1 + 0xd2c);
  FUN_004e16c0();
  if (param_1[0xcaf] == 0) {
    local_18 = (double)fVar4;
    local_10 = (double)fVar3;
    local_8 = (double)fVar2;
    FUN_0043e6a0(&local_18);
    return;
  }
  if (param_1[0xcaf] == 2) {
    iVar5 = FUN_00463dc0(*(undefined4 *)(*param_1 + 0x4894));
    if (iVar5 != 0) {
      FUN_004b2420(&local_24,&local_18);
      local_24 = local_24 + fVar4;
      local_20 = local_20 + fVar3;
      local_1c = local_1c + fVar2;
      FUN_004b2310(&local_24,&local_18);
    }
  }
  return;
}


