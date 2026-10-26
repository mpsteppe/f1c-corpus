// Function: FUN_004e6d93 @ 004e6d93
// Size (bytes): 4516


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e6d93(undefined4 param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  double dVar4;
  double dVar5;
  int iVar6;
  double *pdVar7;
  float *pfVar8;
  int iVar9;
  float *pfVar10;
  int unaff_EBX;
  int unaff_EBP;
  undefined4 *puVar11;
  int iVar12;
  undefined4 *puVar13;
  int *piStack0000000c;
  float fStack00000010;
  float in_stack_00000014;
  float in_stack_00000018;
  float in_stack_0000001c;
  float in_stack_00000034;
  float in_stack_00000038;
  float in_stack_0000003c;
  float in_stack_00000040;
  float in_stack_00000044;
  float in_stack_00000048;
  float in_stack_0000004c;
  float in_stack_00000050;
  float in_stack_00000054;
  float in_stack_00000058;
  float in_stack_0000005c;
  float in_stack_00000060;
  float fStack00000064;
  float in_stack_0000006c;
  float in_stack_00000070;
  float in_stack_00000074;
  float in_stack_00000078;
  float in_stack_0000007c;
  float in_stack_00000080;
  float in_stack_00000084;
  float in_stack_00000088;
  float in_stack_0000008c;
  float in_stack_00000090;
  float in_stack_00000094;
  float in_stack_00000098;
  float in_stack_0000009c;
  float in_stack_000000a0;
  float in_stack_000000a4;
  float in_stack_000000a8;
  float in_stack_000000ac;
  float in_stack_000000b0;
  float fStack000000b4;
  float in_stack_000000bc;
  float in_stack_000000c0;
  float in_stack_000000c4;
  float in_stack_000000c8;
  float in_stack_000000cc;
  float in_stack_000000d0;
  float in_stack_0000010c;
  float in_stack_00000110;
  float in_stack_00000114;
  float in_stack_00000118;
  float in_stack_0000011c;
  float in_stack_00000124;
  undefined4 in_stack_00000128;
  float in_stack_0000012c;
  float in_stack_00000134;
  float in_stack_00000138;
  float in_stack_0000013c;
  float in_stack_00000144;
  float in_stack_00000150;
  float in_stack_00000154;
  float in_stack_00000158;
  float in_stack_0000015c;
  float in_stack_00000160;
  float in_stack_00000164;
  
  iVar9 = *(int *)(unaff_EBP + 8);
  iVar12 = 0;
  fVar1 = (float)*(int *)(iVar9 + 0x1344) * (float)*(double *)(iVar9 + 0x1338) +
          (float)*(double *)(iVar9 + 0x1330);
  do {
    if (iVar12 == 0) {
      iVar9 = param_2 + 0x13d0;
      iVar6 = param_2 + 0x14d8;
      pfVar8 = (float *)(unaff_EBX + 0x3a30);
    }
    else {
      iVar9 = param_2 + 0x15e0;
      iVar6 = param_2 + 0x16e8;
      pfVar8 = (float *)(unaff_EBX + 0x3a44);
    }
    iVar12 = iVar12 + 1;
    *pfVar8 = (float)(((float10)*(double *)(iVar6 + 0xb0) + (float10)*(double *)(iVar9 + 0xb0)) *
                     (float10)_DAT_0059e880);
    pfVar8[1] = (float)(((float10)*(double *)(iVar6 + 0xa8) + (float10)*(double *)(iVar9 + 0xa8)) *
                       (float10)_DAT_0059e880);
    pfVar8[2] = (float)(((float10)*(double *)(iVar6 + 200) + (float10)*(double *)(iVar9 + 200)) *
                       (float10)_DAT_005ad190);
    pfVar8[3] = (float)(((float10)*(double *)(iVar6 + 0xd0) + (float10)*(double *)(iVar9 + 0xd0)) *
                       (float10)_DAT_005ad190);
    pfVar8[4] = (fVar1 * (float)*(double *)(iVar9 + 0xe0) + (float)*(double *)(iVar9 + 0xd8) +
                fVar1 * (float)*(double *)(iVar6 + 0xe0) + (float)*(double *)(iVar6 + 0xd8)) *
                (float)_DAT_005ad190;
  } while (iVar12 < 2);
  iVar9 = *(int *)(unaff_EBP + 8);
  fVar1 = (float)*(int *)(iVar9 + 0x1384) * (float)*(double *)(iVar9 + 0x1378) +
          (float)*(double *)(iVar9 + 0x1370);
  fStack00000010 = (_DAT_0059e43c - fVar1) * *(float *)(unaff_EBX + 0x3a30);
  *(float *)(unaff_EBX + 0x3a30) = fStack00000010;
  fVar1 = fVar1 * *(float *)(unaff_EBX + 0x3a44);
  *(float *)(unaff_EBX + 0x3a44) = fVar1;
  if (fStack00000010 == DAT_0059e440) {
    *(undefined4 *)(unaff_EBX + 0x3618) = 0;
    *(undefined4 *)(unaff_EBX + 0x3710) = 0;
  }
  else {
    fVar2 = _DAT_0059e43c / fStack00000010;
    *(float *)(unaff_EBX + 0x3618) = fVar2;
    *(float *)(unaff_EBX + 0x3710) = fVar2;
  }
  if (fVar1 == DAT_0059e440) {
    *(undefined4 *)(unaff_EBX + 0x3808) = 0;
    *(undefined4 *)(unaff_EBX + 0x3900) = 0;
  }
  else {
    fVar1 = _DAT_0059e43c / fVar1;
    *(float *)(unaff_EBX + 0x3808) = fVar1;
    *(float *)(unaff_EBX + 0x3900) = fVar1;
  }
  iVar12 = 4;
  pdVar7 = (double *)(iVar9 + 0x138);
  fVar1 = DAT_0059e440;
  do {
    iVar12 = iVar12 + -1;
    fVar1 = (float)*(int *)((int)pdVar7 + 0xc) * (float)*pdVar7 + (float)pdVar7[-1] + fVar1;
    pdVar7 = pdVar7 + 0x58;
  } while (iVar12 != 0);
  piStack0000000c = (int *)(fVar1 * _DAT_0059e84c);
  iVar9 = *(int *)(unaff_EBP + 8);
  iVar12 = *(int *)(unaff_EBP + 0xc);
  fStack000000b4 = (*(float *)(unaff_EBX + 0x3594) + *(float *)(unaff_EBX + 0x368c)) * _DAT_0059e450
  ;
  fStack00000064 = (*(float *)(unaff_EBX + 0x3784) + *(float *)(unaff_EBX + 0x387c)) * _DAT_0059e450
  ;
  FUN_004f3190((float)*(int *)(iVar9 + 0xe04) * (float)*(double *)(iVar9 + 0xdf8) +
               (float)*(double *)(iVar9 + 0xdf0),&stack0x00000144,&stack0x00000134);
  FUN_004f3190((float)*(int *)(iVar9 + 0xe44) * (float)*(double *)(iVar9 + 0xe38) +
               (float)*(double *)(iVar9 + 0xe30),&stack0x00000138,&stack0x0000013c);
  in_stack_000000c0 = fStack000000b4 + (float)*(double *)(iVar12 + 0x2f0);
  FUN_004f68b0((float)*(int *)(iVar9 + 0x1284) * (float)*(double *)(iVar9 + 0x1278) +
               (float)*(double *)(iVar9 + 0x1270),piStack0000000c,&stack0x00000150,&stack0x0000010c)
  ;
  fVar1 = fStack00000064 + (float)*(double *)(iVar12 + 0x3ec);
  FUN_004f6950((float)*(int *)(iVar9 + 0x12c4) * (float)*(double *)(iVar9 + 0x12b8) +
               (float)*(double *)(iVar9 + 0x12b0),&stack0x0000015c,&stack0x00000110);
  in_stack_000000c4 = fStack00000064 + (float)*(double *)(iVar12 + 0x424);
  FUN_004f69e0((float)*(int *)(iVar9 + 0x1344) * (float)*(double *)(iVar9 + 0x1338) +
               (float)*(double *)(iVar9 + 0x1330),
               (float)*(int *)(iVar9 + 0x1304) * (float)*(double *)(iVar9 + 0x12f8) +
               (float)*(double *)(iVar9 + 0x12f0),piStack0000000c,&stack0x00000114,&stack0x00000058)
  ;
  in_stack_000000bc = fStack00000064 + (float)*(double *)(iVar12 + 0x510);
  FUN_004f6a50(piStack0000000c,&stack0x0000009c);
  fVar2 = in_stack_00000138 + in_stack_00000144;
  *(undefined4 *)(unaff_EBX + 0x3a58) = 0;
  *(undefined4 *)(unaff_EBX + 0x3a5c) = 0;
  *(undefined4 *)(unaff_EBX + 0x3a60) = 0;
  in_stack_00000060 = in_stack_00000154 + fVar2;
  fStack00000064 = in_stack_00000164 + in_stack_00000158 + fVar2;
  in_stack_0000006c = in_stack_00000114 + in_stack_0000015c + in_stack_00000150 + fVar2;
  *(float *)(unaff_EBX + 0x3a64) = in_stack_0000006c;
  in_stack_00000070 = in_stack_00000118 + in_stack_00000160 + in_stack_00000060;
  *(float *)(unaff_EBX + 0x3a68) = in_stack_00000070;
  in_stack_00000074 = in_stack_0000011c + fStack00000064;
  *(float *)(unaff_EBX + 0x3a6c) = in_stack_00000074;
  *(undefined4 *)(unaff_EBX + 0x3a74) = 0;
  *(undefined4 *)(unaff_EBX + 0x3a78) = *(undefined4 *)(unaff_EBX + 0x3a6c);
  fStack00000010 =
       -(in_stack_00000110 + in_stack_0000009c + in_stack_00000058 + in_stack_0000010c +
         in_stack_0000013c + in_stack_00000134);
  *(float *)(unaff_EBX + 0x3a70) = fStack00000010;
  *(float *)(unaff_EBX + 0x3a7c) = fStack00000010;
  *(float *)(unaff_EBX + 0x3a80) = -(in_stack_0000009c + in_stack_00000058);
  if (fStack00000010 != DAT_0059e440) {
    *(float *)(unaff_EBX + 0x3a74) =
         -((in_stack_00000058 * in_stack_000000c4 +
           in_stack_0000009c * in_stack_000000bc +
           in_stack_0000010c * in_stack_000000c0 + in_stack_00000110 * fVar1) / fStack00000010);
  }
  iVar9 = *(int *)(unaff_EBP + 0xc);
  *(float *)(unaff_EBX + 0x3a74) =
       ((float)*(double *)(iVar9 + 0x11c) - *(float *)(unaff_EBX + 0x3a74)) *
       (float)*(double *)(iVar9 + 0x124) + *(float *)(unaff_EBX + 0x3a74);
  puVar11 = (undefined4 *)(iVar9 + 0x17f0);
  puVar13 = (undefined4 *)(unaff_EBX + 0x3d78);
  for (iVar12 = 0x9e; iVar12 != 0; iVar12 = iVar12 + -1) {
    *puVar13 = *puVar11;
    puVar11 = puVar11 + 1;
    puVar13 = puVar13 + 1;
  }
  if ((((*(int *)(unaff_EBX + 0xcc8) != 0) && (*(float *)(unaff_EBX + 0x3d9c) == DAT_0059e440)) &&
      (*(float *)(unaff_EBX + 0x3da0) == DAT_0059e440)) &&
     (*(float *)(unaff_EBX + 0x3da4) == DAT_0059e440)) {
    FUN_0054b420(unaff_EBX + 0x3d9c,unaff_EBX + 0x3da0,unaff_EBX + 0x3da4);
  }
  *(float *)(unaff_EBX + 0x3d9c) = in_stack_00000014 + *(float *)(unaff_EBX + 0x3d9c);
  *(float *)(unaff_EBX + 0x3da0) = in_stack_00000018 + *(float *)(unaff_EBX + 0x3da0);
  *(float *)(unaff_EBX + 0x3da4) = in_stack_0000001c + *(float *)(unaff_EBX + 0x3da4);
  if (((*(int *)(unaff_EBX + 0xd0c) != 0) && (*(float *)(unaff_EBX + 0x3dcc) == DAT_0059e440)) &&
     ((*(float *)(unaff_EBX + 0x3dd0) == DAT_0059e440 &&
      (*(float *)(unaff_EBX + 0x3dd4) == DAT_0059e440)))) {
    FUN_0054b420(unaff_EBX + 0x3dcc,unaff_EBX + 0x3dd0,unaff_EBX + 0x3dd4);
  }
  piStack0000000c = (int *)(unaff_EBX + 0xd50);
  fStack00000010 = 1.12104e-44;
  *(float *)(unaff_EBX + 0x3dcc) = in_stack_00000014 + *(float *)(unaff_EBX + 0x3dcc);
  *(float *)(unaff_EBX + 0x3dd0) = in_stack_00000018 + *(float *)(unaff_EBX + 0x3dd0);
  *(float *)(unaff_EBX + 0x3dd4) = in_stack_0000001c + *(float *)(unaff_EBX + 0x3dd4);
  pfVar8 = (float *)(unaff_EBX + 0x3eb8);
  do {
    if (((*piStack0000000c != 0) && (pfVar8[-2] == DAT_0059e440)) &&
       ((pfVar8[-1] == DAT_0059e440 && (*pfVar8 == DAT_0059e440)))) {
      FUN_0054b420(pfVar8 + -2,pfVar8 + -1,pfVar8);
    }
    piStack0000000c = piStack0000000c + 0x11;
    pfVar8[-2] = in_stack_00000014 + pfVar8[-2];
    fStack00000010 = (float)((int)fStack00000010 + -1);
    pfVar8[-1] = in_stack_00000018 + pfVar8[-1];
    *pfVar8 = in_stack_0000001c + *pfVar8;
    pfVar8 = pfVar8 + 3;
  } while (fStack00000010 != 0.0);
  *(undefined4 *)(unaff_EBX + 0x3a9c) = 0;
  *(undefined4 *)(unaff_EBX + 0x3b54) = 0;
  *(undefined4 *)(unaff_EBX + 0x3b58) = 0;
  *(undefined4 *)(unaff_EBX + 0x3b5c) = 0;
  FUN_004e9bd0();
  *(undefined4 *)(unaff_EBX + 0x3be8) = 0;
  *(undefined4 *)(unaff_EBX + 0x3bec) = 0;
  *(undefined4 *)(unaff_EBX + 0x3bf0) = 0;
  iVar9 = 4;
  pfVar8 = (float *)(unaff_EBX + 0x3594);
  do {
    iVar9 = iVar9 + -1;
    *(float *)(unaff_EBX + 0x3be8) = pfVar8[-2] + *(float *)(unaff_EBX + 0x3be8);
    *(float *)(unaff_EBX + 0x3bec) = pfVar8[-1] + *(float *)(unaff_EBX + 0x3bec);
    *(float *)(unaff_EBX + 0x3bf0) = *(float *)(unaff_EBX + 0x3bf0) + *pfVar8;
    pfVar8 = pfVar8 + 0x3e;
  } while (iVar9 != 0);
  iVar9 = 0;
  *(float *)(unaff_EBX + 0x3be8) = *(float *)(unaff_EBX + 0x3be8) * _DAT_0059e7f8;
  *(float *)(unaff_EBX + 0x3bec) = *(float *)(unaff_EBX + 0x3bec) * _DAT_0059e7f8;
  *(float *)(unaff_EBX + 0x3bf0) = *(float *)(unaff_EBX + 0x3bf0) * _DAT_0059e7f8;
  *(undefined4 *)(unaff_EBX + 0x3b6c) = 0;
  *(undefined1 *)(unaff_EBX + 0x3b74) = 0;
  *(undefined1 *)(unaff_EBX + 0x3b75) = 0;
  do {
    if (iVar9 < 4) {
      in_stack_0000012c = _DAT_0059e670;
      if ((iVar9 != 0) && (iVar9 != 1)) {
        in_stack_0000012c = _DAT_0059e43c;
      }
      in_stack_00000124 = _DAT_0059e43c;
      if ((iVar9 != 0) && (iVar9 != 2)) {
        in_stack_00000124 = _DAT_0059e670;
      }
      in_stack_00000128 = 0;
      FUN_004dd7c0(&stack0x00000090);
      in_stack_00000040 = in_stack_00000090;
      iVar12 = iVar9 * 0x128 + unaff_EBX;
      in_stack_00000044 = in_stack_00000094;
      in_stack_00000048 = in_stack_00000098;
      if (*(int *)(iVar12 + 0x828) != 0) {
        FUN_004dd7c0(&stack0x00000040);
        in_stack_00000040 = in_stack_00000040 + *(float *)(iVar12 + 0x82c);
        in_stack_00000044 = in_stack_00000044 + *(float *)(iVar12 + 0x830);
        in_stack_00000048 = in_stack_00000048 + *(float *)(iVar12 + 0x834);
      }
      in_stack_00000034 = in_stack_00000090;
      in_stack_00000038 = in_stack_00000094;
      in_stack_0000003c = in_stack_00000098;
      if (((iVar9 == 0) || (iVar9 == 1)) && (*(int *)(unaff_EBX + 0xcc8) != 0)) {
        FUN_004dd7c0(&stack0x00000034);
        in_stack_00000034 = in_stack_00000034 + *(float *)(unaff_EBX + 0xccc);
        in_stack_00000038 = in_stack_00000038 + *(float *)(unaff_EBX + 0xcd0);
        in_stack_00000098 = in_stack_0000003c + *(float *)(unaff_EBX + 0xcd4);
      }
      fVar1 = in_stack_00000090;
      if ((iVar9 == 0) || (iVar9 == 2)) {
        fVar2 = in_stack_00000034;
        if (in_stack_00000034 < in_stack_00000040) {
          fVar2 = in_stack_00000040;
        }
        if (in_stack_00000090 <= fVar2) {
          if (in_stack_00000040 <= in_stack_00000034) {
            iVar12 = unaff_EBX + iVar9 * 0xc;
            fVar1 = in_stack_00000034;
          }
          else {
            iVar12 = unaff_EBX + iVar9 * 0xc;
            fVar1 = in_stack_00000040;
          }
        }
        else {
          iVar12 = unaff_EBX + iVar9 * 0xc;
        }
      }
      else {
        fVar2 = in_stack_00000034;
        if (in_stack_00000040 < in_stack_00000034) {
          fVar2 = in_stack_00000040;
        }
        if ((fVar2 <= in_stack_00000090) &&
           (fVar1 = in_stack_00000034, in_stack_00000040 < in_stack_00000034)) {
          fVar1 = in_stack_00000040;
        }
        iVar12 = unaff_EBX + iVar9 * 0xc;
      }
      puVar11 = (undefined4 *)(unaff_EBX + (iVar9 * 3 + 0xeaf) * 4);
      *(float *)(iVar12 + 0x3ab8) = fVar1 + in_stack_00000014;
      *puVar11 = 0;
      fVar1 = in_stack_00000098;
      if ((iVar9 == 0) || (iVar9 == 1)) {
        fVar2 = in_stack_00000098;
        if (in_stack_00000048 < in_stack_00000098) {
          fVar2 = in_stack_00000048;
        }
        if ((fVar2 <= in_stack_00000098) &&
           (fVar1 = in_stack_00000048, in_stack_00000098 <= in_stack_00000048)) goto LAB_004e778e;
      }
      else {
        fVar2 = in_stack_00000098;
        if (in_stack_00000098 < in_stack_00000048) {
          fVar2 = in_stack_00000048;
        }
        if ((in_stack_00000098 <= fVar2) &&
           (fVar1 = in_stack_00000048, in_stack_00000048 <= in_stack_00000098)) {
LAB_004e778e:
          fVar1 = in_stack_00000098;
        }
      }
      iVar6 = *(int *)(unaff_EBP + 0xc);
      *(float *)(iVar12 + 0x3ac0) = fVar1 + in_stack_0000001c;
      if ((*(byte *)(iVar6 + 0x3c) & 1) != 0) {
        fVar1 = in_stack_00000054;
        if (iVar9 == 0) {
          in_stack_0000006c = in_stack_00000014 + in_stack_00000084;
LAB_004e7803:
          in_stack_00000074 = fVar1 + in_stack_0000001c;
        }
        else {
          if (iVar9 == 1) {
            in_stack_0000006c = in_stack_00000014 + in_stack_0000004c;
            goto LAB_004e7803;
          }
          fVar1 = in_stack_00000084;
          if ((iVar9 == 2) || (fVar1 = in_stack_0000004c, iVar9 == 3)) {
            in_stack_0000006c = in_stack_00000014 + fVar1;
            fVar1 = in_stack_0000008c;
            goto LAB_004e7803;
          }
        }
        *(float *)(iVar12 + 0x3ab8) =
             *(float *)(iVar12 + 0x3ab8) * _DAT_005ace00 + in_stack_0000006c * _DAT_005ad18c;
        *(float *)(iVar12 + 0x3ac0) =
             *(float *)(iVar12 + 0x3ac0) * _DAT_005ace00 + in_stack_00000074 * _DAT_005ad18c;
      }
      if ((*(byte *)(iVar6 + 0x3c) & 2) != 0) {
        *puVar11 = 0xbc75c28f;
      }
      in_stack_0000003c = in_stack_00000098;
      if ((*(byte *)(iVar6 + 0x3c) & 4) != 0) {
        if ((iVar9 == 0) || (iVar9 == 2)) {
          fVar1 = *(float *)(iVar12 + 0x3ab8) + _DAT_0059e454;
        }
        else {
          fVar1 = *(float *)(iVar12 + 0x3ab8) - _DAT_0059e454;
        }
        *(float *)(iVar12 + 0x3ab8) = fVar1;
      }
    }
    else if (iVar9 < 8) {
      if (iVar9 == 4) {
        pfVar8 = (float *)(unaff_EBX + 0x3ae8);
        *pfVar8 = 0.0;
        *(float *)(unaff_EBX + 0x3af0) = in_stack_00000054 + in_stack_0000001c;
LAB_004e7950:
        pfVar8[1] = 0.0;
      }
      else {
        if (iVar9 == 5) {
          pfVar8 = (float *)(unaff_EBX + 0x3af4);
          *pfVar8 = 0.0;
          *(float *)(unaff_EBX + 0x3afc) = in_stack_0000008c + in_stack_0000001c;
          goto LAB_004e7950;
        }
        if (iVar9 == 6) {
          pfVar8 = (float *)(unaff_EBX + 0x3b00);
          fVar1 = in_stack_0000004c;
LAB_004e794b:
          *pfVar8 = in_stack_00000014 + fVar1;
          pfVar8[2] = 0.0;
          goto LAB_004e7950;
        }
        if (iVar9 == 7) {
          pfVar8 = (float *)(unaff_EBX + 0x3b0c);
          fVar1 = in_stack_00000084;
          goto LAB_004e794b;
        }
      }
      iVar12 = *(int *)(unaff_EBP + 0xc);
      if ((*(byte *)(iVar12 + 0x3c) & 2) != 0) {
        iVar6 = iVar9 * 3 + 0xeaf;
        *(float *)(unaff_EBX + iVar6 * 4) = *(float *)(unaff_EBX + iVar6 * 4) - _DAT_005acd44;
      }
      if ((*(byte *)(iVar12 + 0x3c) & 4) != 0) {
        if (iVar9 == 6) {
          *(float *)(unaff_EBX + 0x3b00) = *(float *)(unaff_EBX + 0x3b00) - _DAT_005ad188;
        }
        else if (iVar9 == 7) {
          *(float *)(unaff_EBX + 0x3b0c) = *(float *)(unaff_EBX + 0x3b0c) + _DAT_005ad188;
        }
      }
    }
    else if (iVar9 < 0xc) {
      in_stack_00000078 = _DAT_0059e450;
      if ((iVar9 == 8) || (iVar9 == 9)) {
        if ((*(byte *)(*(int *)(unaff_EBP + 0xc) + 0x3c) & 8) == 0) {
          in_stack_00000078 = _DAT_0059e84c;
          if (iVar9 == 8) {
            in_stack_00000078 = _DAT_005ad184;
          }
          in_stack_00000080 = 0.0;
        }
        else if (iVar9 == 8) {
          in_stack_00000080 = -0.1;
          in_stack_00000078 = _DAT_0059e99c;
        }
        else {
          in_stack_00000080 = -0.1;
        }
        in_stack_0000007c = 1.0;
        FUN_004dd7c0(&stack0x000000a0);
        in_stack_000000ac = in_stack_000000a0 + in_stack_00000014;
        pfVar8 = (float *)(unaff_EBX + 0x3ab8 + iVar9 * 0xc);
        *pfVar8 = in_stack_000000ac;
        in_stack_000000b0 = in_stack_000000a4 + in_stack_00000018;
        pfVar8[1] = in_stack_000000b0;
        fStack000000b4 = in_stack_000000a8 + in_stack_0000001c;
        pfVar8[2] = fStack000000b4;
      }
      else {
        if ((*(byte *)(*(int *)(unaff_EBP + 0xc) + 0x3c) & 8) == 0) {
          in_stack_00000078 = _DAT_0059e84c;
          if (iVar9 == 10) {
            in_stack_00000078 = _DAT_005ad184;
          }
        }
        else if (iVar9 == 10) {
          in_stack_00000078 = _DAT_0059e99c;
        }
        in_stack_0000007c = 1.0;
        in_stack_00000080 = 0.8;
        FUN_004dd7c0(&stack0x000000a0);
        if (*(int *)(unaff_EBX + 0xd0c) != 0) {
          FUN_004dd7c0(&stack0x000000c8);
          in_stack_000000c8 = in_stack_000000c8 + *(float *)(unaff_EBX + 0xd10);
          in_stack_000000cc = in_stack_000000cc + *(float *)(unaff_EBX + 0xd14);
          in_stack_000000d0 = in_stack_000000d0 + *(float *)(unaff_EBX + 0xd18);
          if (in_stack_000000a0 * in_stack_00000078 +
              in_stack_000000a4 * in_stack_0000007c + in_stack_000000a8 * in_stack_00000080 <
              in_stack_000000c8 * in_stack_00000078 +
              in_stack_000000cc * in_stack_0000007c + in_stack_000000d0 * in_stack_00000080) {
            *(undefined1 *)(unaff_EBX + 0x3b74) = 1;
            in_stack_000000a0 = in_stack_000000c8;
            in_stack_000000a4 = in_stack_000000cc;
            in_stack_000000a8 = in_stack_000000d0;
          }
        }
      }
      in_stack_0000005c = in_stack_000000a0 + in_stack_00000014;
      iVar12 = unaff_EBX + iVar9 * 0xc;
      *(float *)(iVar12 + 0x3ab8) = in_stack_0000005c;
      in_stack_00000060 = in_stack_000000a4 + in_stack_00000018;
      *(float *)(iVar12 + 0x3abc) = in_stack_00000060;
      fStack00000064 = in_stack_000000a8 + in_stack_0000001c;
      *(float *)(iVar12 + 0x3ac0) = fStack00000064;
      if ((*(byte *)(*(int *)(unaff_EBP + 0xc) + 0x3c) & 4) != 0) {
        if (iVar9 + -8 < 2) {
          *(float *)(iVar12 + 0x3ac0) = *(float *)(iVar12 + 0x3ac0) - _DAT_0059e7f8;
          pfVar8 = (float *)(unaff_EBX + (iVar9 * 3 + 0xeaf) * 4);
          *pfVar8 = *pfVar8 + _DAT_0059e7e8;
        }
        else {
          iVar12 = iVar9 * 3 + 0xeaf;
          *(float *)(unaff_EBX + iVar12 * 4) = *(float *)(unaff_EBX + iVar12 * 4) + _DAT_0059e8c8;
        }
      }
    }
    else {
      puVar11 = (undefined4 *)(unaff_EBX + 0x3ab8 + iVar9 * 0xc);
      *puVar11 = 0;
      puVar11[2] = 0;
      puVar11[1] = (in_stack_00000018 + in_stack_00000050) * _DAT_0059e450;
    }
    fVar1 = *(float *)(unaff_EBX + 0x3ac0 + iVar9 * 0xc);
    pfVar8 = (float *)(unaff_EBX + 0x3ab8 + iVar9 * 0xc);
    fVar2 = pfVar8[1];
    fVar3 = *pfVar8;
    fVar1 = SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);
    if (*(float *)(unaff_EBX + 0x3b6c) < fVar1) {
      *(float *)(unaff_EBX + 0x3b6c) = fVar1;
    }
    iVar9 = iVar9 + 1;
    if (0xc < iVar9) {
      iVar9 = 0xd;
      *(float *)(unaff_EBX + 0x3b70) = *(float *)(unaff_EBX + 0x3b6c) + _DAT_0059e84c;
      pfVar8 = (float *)&stack0x00000174;
      pfVar10 = (float *)(unaff_EBX + 0x3abc);
      do {
        pfVar8[-1] = -in_stack_00000014;
        iVar9 = iVar9 + -1;
        *pfVar8 = -in_stack_00000018;
        pfVar8[1] = -in_stack_0000001c;
        pfVar8[2] = pfVar10[-1] - in_stack_00000014;
        pfVar8[3] = *pfVar10 - in_stack_00000018;
        pfVar8[4] = pfVar10[1] - in_stack_0000001c;
        pfVar8 = pfVar8 + 8;
        pfVar10 = pfVar10 + 3;
      } while (iVar9 != 0);
      FUN_0054f830(&stack0x00000170,0xd);
      *(undefined1 *)(unaff_EBX + 0x3ff0) = 0;
      *(undefined4 *)(unaff_EBX + 0x3ff4) = 0;
      *(undefined4 *)(unaff_EBX + 0x3ff8) = 0;
      *(undefined4 *)(unaff_EBX + 0x3ffc) = 0;
      *(undefined4 *)(unaff_EBX + 0x4000) = 0;
      *(undefined4 *)(unaff_EBX + 0x4004) = 0;
      *(undefined4 *)(unaff_EBX + 0x4008) = 0;
      *(undefined4 *)(unaff_EBX + 0x400c) = 0;
      *(undefined4 *)(unaff_EBX + 0x4010) = 0;
      in_stack_000000ac =
           (*(float *)(unaff_EBX + 0x358c) + *(float *)(unaff_EBX + 0x3684)) * _DAT_0059e450;
      fStack000000b4 =
           (*(float *)(unaff_EBX + 0x3594) + *(float *)(unaff_EBX + 0x368c)) * _DAT_0059e450;
      iVar9 = *(int *)(unaff_EBP + 0xc);
      in_stack_00000088 = -(float)*(double *)(iVar9 + 0x60);
      in_stack_0000012c = *(float *)(unaff_EBX + 0x3784) + *(float *)(unaff_EBX + 0x387c);
      *(undefined4 *)(unaff_EBX + 0x3d48) = 0;
      *(undefined4 *)(unaff_EBX + 0x3d4c) = 0;
      *(undefined4 *)(unaff_EBX + 0x3d50) = 0;
      in_stack_0000005c =
           (*(float *)(unaff_EBX + 0x377c) + *(float *)(unaff_EBX + 0x3874)) * _DAT_0059e450;
      in_stack_00000060 =
           (*(float *)(unaff_EBX + 0x3780) + *(float *)(unaff_EBX + 0x3878)) * _DAT_0059e450;
      fStack00000064 = in_stack_0000012c * _DAT_0059e450;
      dVar4 = *(double *)(iVar9 + 0x1350);
      dVar5 = *(double *)(iVar9 + 0x1348);
      *(float *)(unaff_EBX + 0x3d54) = in_stack_0000005c + (float)*(double *)(iVar9 + 0x1340);
      *(float *)(unaff_EBX + 0x3d58) = in_stack_00000088 + (float)dVar5;
      *(float *)(unaff_EBX + 0x3d5c) = fStack00000064 + (float)dVar4;
      *(undefined4 *)(unaff_EBX + 0x1c) = *(undefined4 *)(unaff_EBX + 0x3d54);
      *(undefined4 *)(unaff_EBX + 0x20) = *(undefined4 *)(unaff_EBX + 0x3d58);
      *(undefined4 *)(unaff_EBX + 0x24) = *(undefined4 *)(unaff_EBX + 0x3d5c);
      *(undefined4 *)(unaff_EBX + 0x3d60) = 0;
      in_stack_00000084 = in_stack_0000005c;
      in_stack_0000008c = fStack00000064;
      in_stack_000000b0 = in_stack_00000088;
      FUN_004ee150(iVar9);
      *(undefined4 *)(unaff_EBX + 0x4014) = 0;
      *(undefined1 *)(unaff_EBX + 0x4018) = 0;
      *(undefined4 *)(unaff_EBX + 0x401c) = 0;
      iVar9 = _rand();
      *(int *)(unaff_EBX + 0x4020) = iVar9;
      FUN_0059da3a();
      return;
    }
  } while( true );
}


