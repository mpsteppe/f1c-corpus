// Function: FUN_0054b570 @ 0054b570
// Size (bytes): 512


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_0054b570(int param_1,int param_2,int param_3)

{
  float fVar1;
  uint uVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float *pfVar5;
  undefined4 *puVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float local_40 [4];
  float local_30 [4];
  float local_20 [4];
  undefined4 local_10 [4];
  
  if ((*(uint *)(param_1 + 0x3c) & 0x2100) != 0) {
    FUN_0054b330(0x40,0,0);
  }
  uVar2 = *(uint *)(param_1 + 0x3c);
  if ((uVar2 & 0x40) == 0) {
    if (param_2 != 0) {
      if ((uVar2 & 0x2000) == 0) {
        if ((uVar2 & 0x100) != 0) {
          *(float *)(param_1 + 0x30) = _DAT_0059e660 - *(float *)(param_2 + 0x34);
          *(float *)(param_1 + 0x2c) = -*(float *)(param_2 + 0x30);
          *(float *)(param_1 + 0x34) = -*(float *)(param_2 + 0x38);
        }
      }
      else {
        *(float *)(param_1 + 0x30) = _DAT_0059e660 - *(float *)(param_2 + 0x34);
      }
    }
    if ((uVar2 & 0x20) != 0) {
      *(uint *)(param_1 + 0x3c) = uVar2 & 0xffffffdf;
      FUN_0053b240(*(undefined4 *)(param_1 + 0x60),*(undefined4 *)(param_1 + 100),
                   *(undefined4 *)(param_1 + 0x68));
      FUN_0053b200(*(undefined4 *)(param_1 + 0x54),*(undefined4 *)(param_1 + 0x58),
                   *(undefined4 *)(param_1 + 0x5c));
    }
    if ((*(byte *)(param_1 + 0x3c) & 1) == 0) {
      if (*(int *)(param_1 + 0x40) == 0) {
        pfVar3 = (float *)(param_1 + 0x114);
        pfVar5 = (float *)(param_1 + 0x124);
        pfVar7 = (float *)(param_1 + 0x134);
        puVar10 = (undefined4 *)(param_1 + 0x144);
      }
      else {
        pfVar3 = (float *)(param_1 + 0xd4);
        pfVar5 = (float *)(param_1 + 0xe4);
        pfVar7 = (float *)(param_1 + 0xf4);
        puVar10 = (undefined4 *)(param_1 + 0x104);
      }
    }
    else {
      pfVar3 = local_40;
      pfVar5 = local_30;
      pfVar7 = local_20;
      puVar10 = local_10;
    }
    fVar11 = (float10)fsin((float10)*(float *)(param_1 + 0x2c));
    fVar12 = (float10)fcos((float10)*(float *)(param_1 + 0x2c));
    fVar13 = (float10)fsin((float10)*(float *)(param_1 + 0x30));
    fVar14 = (float10)fcos((float10)*(float *)(param_1 + 0x30));
    fVar1 = (float)fVar14;
    fVar14 = (float10)fsin((float10)*(float *)(param_1 + 0x34));
    fVar15 = (float10)fcos((float10)*(float *)(param_1 + 0x34));
    pfVar3[3] = 0.0;
    *pfVar3 = (float)(fVar13 * fVar11 * fVar14 + (float10)(float)(fVar15 * (float10)fVar1));
    pfVar3[1] = (float)(fVar14 * fVar12);
    pfVar3[2] = (float)((float10)(float)(fVar14 * (float10)fVar1) * fVar11 - fVar15 * fVar13);
    pfVar5[3] = 0.0;
    *pfVar5 = (float)(fVar13 * fVar11 * fVar15 - (float10)(float)(fVar14 * (float10)fVar1));
    pfVar5[1] = (float)(fVar15 * fVar12);
    pfVar5[2] = (float)((float10)(float)(fVar15 * (float10)fVar1) * fVar11 + fVar14 * fVar13);
    pfVar7[3] = 0.0;
    *pfVar7 = (float)(fVar13 * fVar12);
    pfVar7[1] = (float)-fVar11;
    pfVar7[2] = (float)((float10)fVar1 * fVar12);
    *puVar10 = *(undefined4 *)(param_1 + 0x20);
    puVar10[1] = *(undefined4 *)(param_1 + 0x24);
    puVar10[2] = *(undefined4 *)(param_1 + 0x28);
    puVar10[3] = 0x3f800000;
    *(uint *)(param_1 + 0x3c) = *(uint *)(param_1 + 0x3c) | 0x40;
    FUN_0054b770(0);
    puVar10 = (undefined4 *)(param_1 + 0x154);
    puVar4 = (undefined4 *)(param_1 + 0x114);
    iVar9 = 4;
    do {
      iVar8 = 4;
      puVar6 = puVar10;
      do {
        *puVar6 = *puVar4;
        puVar6 = puVar6 + 4;
        puVar4 = puVar4 + 1;
        iVar8 = iVar8 + -1;
      } while (iVar8 != 0);
      puVar10 = puVar10 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    if (param_3 != 0) {
      *(uint *)(param_3 + 0x14) = *(uint *)(param_3 + 0x14) & 0xdfffffd7;
    }
    return 1;
  }
  return 0;
}


