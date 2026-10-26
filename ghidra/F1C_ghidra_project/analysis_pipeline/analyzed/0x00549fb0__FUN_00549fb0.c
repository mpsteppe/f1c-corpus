// Function: FUN_00549fb0 @ 00549fb0
// Size (bytes): 236


undefined4 __thiscall FUN_00549fb0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  uint uVar5;
  int iVar6;
  
  uVar5 = *(uint *)(param_1 + 4);
  if ((uVar5 & 0x50) != 0) {
    *(uint *)(param_1 + 4) = uVar5 | 2;
    return 0;
  }
  fVar2 = *(float *)(param_2 + 0x24) + *(float *)(param_1 + 0x7c);
  uVar5 = uVar5 & 0xfffffff0;
  fVar3 = *(float *)(param_2 + 0x28) + *(float *)(param_1 + 0x80);
  fVar1 = *(float *)(param_2 + 0x2c);
  *(uint *)(param_1 + 4) = uVar5;
  fVar1 = fVar1 + *(float *)(param_1 + 0x84);
  if (*(float *)(param_2 + 8) <
      SQRT(fVar2 * fVar2 + fVar3 * fVar3 + fVar1 * fVar1) - *(float *)(param_1 + 0x18)) {
    *(uint *)(param_1 + 4) = uVar5 | 8;
    return 0;
  }
  iVar6 = 0;
  *(uint *)(param_1 + 4) = uVar5 | 1;
  pfVar4 = (float *)(param_2 + 0x104);
  while( true ) {
    fVar1 = ((-(pfVar4[-2] * *(float *)(param_1 + 0x7c)) - pfVar4[-1] * *(float *)(param_1 + 0x80))
            - *pfVar4 * *(float *)(param_1 + 0x84)) - pfVar4[1];
    if (*(float *)(param_1 + 0x18) < fVar1) {
      *(uint *)(param_1 + 4) = uVar5 | 2;
      return 0;
    }
    if (-*(float *)(param_1 + 0x18) < fVar1) break;
    iVar6 = iVar6 + 1;
    pfVar4 = pfVar4 + 4;
    if (5 < iVar6) {
      return 0;
    }
  }
  *(uint *)(param_1 + 4) = uVar5 | 4;
  return 0;
}


