// Function: FUN_00552910 @ 00552910
// Size (bytes): 646


undefined1 __thiscall
FUN_00552910(int param_1,byte param_2,int param_3,int param_4,undefined4 param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  float *pfVar14;
  
  if ((0x1f < param_2) && (uVar12 = (uint)param_2, (int)uVar12 < *(int *)(param_1 + 0x44))) {
    iVar11 = (int)*(short *)(param_1 + -0x98 + uVar12 * 8);
    iVar13 = (int)*(short *)(param_1 + -0x96 + uVar12 * 8);
    iVar9 = *(int *)(param_1 + 0x34) + -1;
    iVar10 = *(int *)(param_1 + 0x38) + -1;
    if ((*(uint *)(param_1 + 0x24) & 0x10000) != 0) {
      FUN_00543250(iVar11,iVar13 + 1,param_5,param_3,param_4,iVar9,*(int *)(param_1 + 0x38) + -2,
                   *(undefined4 *)(param_1 + 0x2c),0);
      return *(undefined1 *)(param_1 + -0x94 + uVar12 * 8);
    }
    fVar1 = (float)param_3 * *(float *)(param_1 + 0x5c);
    fVar2 = (float)param_4 * *(float *)(param_1 + 0x60);
    fVar3 = (float)(iVar9 + param_3) * *(float *)(param_1 + 0x5c);
    fVar4 = (float)(iVar10 + param_4) * *(float *)(param_1 + 0x60);
    fVar6 = (float)*(int *)(*(int *)(param_1 + 100) + 0x1c);
    fVar5 = (float)iVar11 / fVar6;
    fVar7 = (float)*(int *)(*(int *)(param_1 + 100) + 0x20);
    fVar8 = (float)iVar13 / fVar7;
    fVar6 = (float)iVar9 / fVar6 + fVar5;
    fVar7 = (float)iVar10 / fVar7 + fVar8;
    **(float **)(param_1 + 0x10) = fVar1;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar5;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar8;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar1;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar5;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar7;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar3;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar6;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar7;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar3;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar4;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar6;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar7;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar3;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar6;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar8;
    pfVar14 = (float *)(*(int *)(param_1 + 0x10) + 0x1c);
    *(float **)(param_1 + 0x10) = pfVar14;
    *pfVar14 = fVar1;
    *(float *)(*(int *)(param_1 + 0x10) + 4) = fVar2;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 8) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = 0x3f800000;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10) = *(undefined4 *)(param_1 + 0x48);
    *(float *)(*(int *)(param_1 + 0x10) + 0x14) = fVar5;
    *(float *)(*(int *)(param_1 + 0x10) + 0x18) = fVar8;
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 0x1c;
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 6;
    return *(undefined1 *)(param_1 + -0x94 + uVar12 * 8);
  }
  return 0;
}


