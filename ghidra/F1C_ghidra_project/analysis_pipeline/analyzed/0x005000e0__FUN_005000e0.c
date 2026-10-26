// Function: FUN_005000e0 @ 005000e0
// Size (bytes): 129


uint FUN_005000e0(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  double local_34;
  double local_2c;
  double local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  double local_c;
  undefined4 local_4;
  
  local_34 = (double)*(float *)(param_1 + 8);
  local_2c = (double)*(float *)(param_1 + 0xc);
  local_24 = (double)*(float *)(param_1 + 0x10);
  local_1c = 0;
  local_18 = 0x40100000;
  local_14 = 0x40000000;
  local_10 = 0x479e17b8;
  local_4 = 0;
  iVar2 = FUN_0044c4c0(&local_34);
  uVar3 = 0;
  if (iVar2 != 0) {
    param_2 = (float)local_c + param_2;
    fVar1 = *(float *)(param_1 + 0xc);
    uVar4 = (ushort)(param_2 < fVar1) << 8 | (ushort)(NAN(param_2) || NAN(fVar1)) << 10 |
            (ushort)(param_2 == fVar1) << 0xe;
    uVar3 = (uint)uVar4;
    if (param_2 >= fVar1 && (param_2 == fVar1) == 0) {
      *(float *)(param_1 + 0xc) = param_2;
      return CONCAT31((uint3)(byte)(uVar4 >> 8),1);
    }
  }
  return uVar3;
}


