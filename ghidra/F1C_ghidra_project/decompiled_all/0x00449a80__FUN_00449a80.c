// Function: FUN_00449a80 @ 00449a80
// Strings:  [Gaussian elimination for HAT poly failed twice, Gaussian elimination for HAT poly failed once, D:\dev\F1_1999_2002\Source\htree.cpp, D:\dev\F1_1999_2002\Source\htree.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00449a80(undefined4 *param_1,int param_2,char param_3)

{
  float fVar1;
  float fVar2;
  undefined8 uVar3;
  float *pfVar4;
  float *pfVar5;
  float *pfVar6;
  char cVar7;
  undefined4 uVar8;
  double *pdVar9;
  int iVar10;
  undefined4 unaff_EBX;
  int iVar11;
  undefined4 unaff_ESI;
  float *local_198 [4];
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  int local_170 [6];
  double local_158 [3];
  undefined8 local_140;
  double dStack_138;
  undefined4 auStack_130 [2];
  undefined8 local_128;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_f0;
  undefined4 uStack_ec;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_b8;
  undefined4 uStack_b4;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_48;
  undefined4 uStack_44;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uVar8 = FUN_004ce8d0(*(undefined2 *)(param_2 + 0x1a));
  param_1[0x15] = uVar8;
  *(undefined1 *)(param_1 + 0x16) = *(undefined1 *)(param_2 + 0x18);
  iVar10 = 0;
  do {
    pfVar6 = (float *)(param_1 + iVar10 * 3 + 0xc);
    pfVar4 = *(float **)(param_2 + iVar10 * 8);
    if (iVar10 == 2) {
      iVar11 = 0;
    }
    else {
      iVar11 = iVar10 + 1;
    }
    local_198[0] = *(float **)(param_2 + iVar11 * 8);
    iVar11 = 2;
    if (iVar10 != 0) {
      iVar11 = iVar10 + -1;
    }
    pfVar5 = *(float **)(param_2 + iVar11 * 8);
    *pfVar6 = pfVar4[3] - local_198[0][3];
    fVar1 = *local_198[0];
    fVar2 = *pfVar4;
    pfVar6[1] = fVar1 - fVar2;
    fVar1 = *pfVar4 * *pfVar6 + (fVar1 - fVar2) * pfVar4[3];
    pfVar6[2] = fVar1;
    if (*pfVar6 * *pfVar5 + pfVar5[3] * pfVar6[1] < fVar1) {
      *pfVar6 = -*pfVar6;
      pfVar6[1] = -pfVar6[1];
      pfVar6[2] = -pfVar6[2];
    }
    iVar10 = iVar10 + 1;
    local_198[iVar10] = (float *)(pfVar6[1] * pfVar6[1] + *pfVar6 * *pfVar6);
    pfVar6 = local_198[2];
  } while (iVar10 < 3);
  while( true ) {
    while (pfVar4 = pfVar6, (float)local_198[1] < (float)pfVar4) {
      local_17c = param_1[0xc];
      local_178 = param_1[0xd];
      local_174 = param_1[0xe];
      param_1[0xc] = param_1[0xf];
      param_1[0xd] = param_1[0x10];
      param_1[0xe] = param_1[0x11];
      param_1[0xf] = local_17c;
      param_1[0x10] = local_178;
      local_198[0] = local_198[1];
      param_1[0x11] = local_174;
      pfVar6 = local_198[1];
      local_198[1] = pfVar4;
    }
    if ((float)local_198[3] <= (float)pfVar4) break;
    local_188 = param_1[0xf];
    local_184 = param_1[0x10];
    local_180 = param_1[0x11];
    param_1[0xf] = param_1[0x12];
    param_1[0x10] = param_1[0x13];
    param_1[0x11] = param_1[0x14];
    param_1[0x12] = local_188;
    param_1[0x13] = local_184;
    param_1[0x14] = local_180;
    pfVar6 = local_198[3];
    local_198[3] = pfVar4;
  }
  iVar10 = 0;
  do {
    local_170[iVar10] = (int)(local_158 + iVar10 * 7);
    if (iVar10 < 3) {
      pfVar6 = *(float **)(param_2 + iVar10 * 8);
      fVar1 = *pfVar6;
      uVar3 = *(undefined8 *)(pfVar6 + 4);
      fVar2 = pfVar6[3];
    }
    else {
      if (iVar10 == 5) {
        iVar11 = 0;
      }
      else {
        iVar11 = iVar10 + -2;
      }
      pfVar6 = *(float **)(param_2 + iVar11 * 8);
      fVar1 = (*pfVar6 + **(float **)(param_2 + -0x18 + iVar10 * 8)) * (float)_DAT_0059e880;
      uVar3 = *(undefined8 *)(*(int *)(param_2 + -0x14 + iVar10 * 8) + 0x10);
      fVar2 = (pfVar6[3] + *(float *)(*(int *)(param_2 + -0x18 + iVar10 * 8) + 0xc)) *
              (float)_DAT_0059e880;
    }
    iVar11 = iVar10 + 1;
    auStack_130[iVar10 * 0xe] = 0;
    auStack_130[iVar10 * 0xe + 1] = 0x3ff00000;
    local_158[iVar10 * 7] = (double)(fVar1 * fVar1);
    local_158[iVar10 * 7 + 1] = (double)(fVar2 * fVar2);
    local_158[iVar10 * 7 + 2] = (double)(fVar2 * fVar1);
    (&local_140)[iVar10 * 7] = (double)fVar1;
    (&dStack_138)[iVar10 * 7] = (double)fVar2;
    (&local_128)[iVar10 * 7] = uVar3;
    iVar10 = iVar11;
  } while (iVar11 < 6);
  iVar10 = FUN_005677b0();
  if ((iVar10 != 0) &&
     (cVar7 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_htree_005c4434,0x122), cVar7 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_Gaussian_elimination_for_HAT_pol_005c4404);
  }
  param_1[1] = local_128._4_4_;
  *param_1 = (undefined4)local_128;
  param_1[2] = local_f0;
  param_1[4] = local_b8;
  param_1[3] = uStack_ec;
  param_1[5] = uStack_b4;
  param_1[7] = uStack_7c;
  param_1[6] = local_80;
  param_1[8] = local_48;
  param_1[10] = local_10;
  param_1[9] = uStack_44;
  param_1[0xb] = uStack_c;
  iVar10 = 0;
  do {
    pfVar6 = *(float **)(param_2 + iVar10 * 8);
    fVar1 = pfVar6[3];
    if ((float)_DAT_0059ea08 <
        ABS(((fVar1 * (float)(double)CONCAT44(uStack_ec,local_f0) +
             (float)(double)CONCAT44(uStack_44,local_48)) * fVar1 +
             (*pfVar6 * (float)(double)CONCAT44(local_128._4_4_,(undefined4)local_128) +
              fVar1 * (float)(double)CONCAT44(uStack_b4,local_b8) +
             (float)(double)CONCAT44(uStack_7c,local_80)) * *pfVar6 +
            (float)(double)CONCAT44(uStack_c,local_10)) - (float)*(double *)(pfVar6 + 4))) {
      if (iVar10 < 3) {
        iVar10 = 0;
        pdVar9 = local_158 + 1;
        do {
          pfVar6 = *(float **)(param_2 + iVar10 * 8);
          iVar10 = iVar10 + 1;
          pdVar9[-1] = (double)*pfVar6;
          *pdVar9 = (double)pfVar6[3];
          *(undefined4 *)(pdVar9 + 1) = 0;
          *(undefined4 *)((int)pdVar9 + 0xc) = 0x3ff00000;
          *(float *)(pdVar9 + 2) = pfVar6[4];
          *(float *)((int)pdVar9 + 0x14) = pfVar6[5];
          pdVar9 = pdVar9 + 7;
        } while (iVar10 < 3);
        iVar10 = FUN_005677b0();
        if (iVar10 != 0) {
          cVar7 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_htree_005c4434,0x148);
          if (cVar7 != '\0') {
            FUN_004d7aa0(&DAT_008ad25c,s_Gaussian_elimination_for_HAT_pol_005c43d4);
          }
          return 0xffffffff;
        }
        *param_1 = 0;
        param_1[1] = 0;
        param_1[2] = 0;
        param_1[3] = 0;
        param_1[4] = 0;
        param_1[5] = 0;
        param_1[6] = (undefined4)local_140;
        param_1[7] = local_140._4_4_;
        param_1[8] = local_108;
        param_1[9] = local_104;
        param_1[10] = local_d0;
        param_1[0xb] = local_cc;
      }
      break;
    }
    iVar10 = iVar10 + 1;
  } while (iVar10 < 3);
  if (param_3 == '\0') {
    return 0;
  }
  uVar8 = FUN_0059d738(unaff_ESI,unaff_EBX);
  return uVar8;
}


