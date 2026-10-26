// Function: FUN_0043da10 @ 0043da10
// Strings:  [RQPhdC\, D:\dev\F1_1999_2002\Source\hdvehicle.cpp, D:\dev\F1_1999_2002\Source\hdvehicle.cpp, Tire optimum camber angle should be less than 90 degrees, Could not find one of tire slip curves %s/%s/%s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0043da10(int param_1,int param_2)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  char cVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined1 *puVar13;
  float *pfVar14;
  int extraout_EDX;
  double *pdVar15;
  float10 fVar16;
  float10 fVar17;
  float10 fVar18;
  
  iVar8 = FUN_004d7570(*(undefined4 *)(param_1 + 0x145c));
  if ((param_2 == 0) || (pdVar15 = (double *)(iVar8 + 0x160), param_2 == 1)) {
    pdVar15 = (double *)(iVar8 + 0x18);
  }
  iVar8 = param_2 * 0x464 + 0x28c + param_1;
  *(undefined4 *)(iVar8 + 0x20c) = *(undefined4 *)(pdVar15 + 4);
  *(undefined4 *)(iVar8 + 0x210) = *(undefined4 *)((int)pdVar15 + 0x24);
  *(undefined4 *)(iVar8 + 0x214) = *(undefined4 *)(pdVar15 + 5);
  *(undefined4 *)(iVar8 + 0x218) = *(undefined4 *)((int)pdVar15 + 0x2c);
  *(double *)(iVar8 + 0x21c) = pdVar15[6] * _DAT_0059ec68;
  *(double *)(iVar8 + 0x224) = pdVar15[6] * _DAT_0059ec60;
  fVar16 = (float10)FUN_004d6ae0(*(undefined4 *)(iVar8 + 0x37c),*(undefined4 *)(iVar8 + 0x380));
  *(double *)(iVar8 + 0x22c) = (double)fVar16;
  *(undefined4 *)(iVar8 + 0x234) = *(undefined4 *)(pdVar15 + 9);
  *(undefined4 *)(iVar8 + 0x238) = *(undefined4 *)((int)pdVar15 + 0x4c);
  FUN_004d5c70(*(undefined4 *)(pdVar15 + 10),*(undefined4 *)((int)pdVar15 + 0x54),
               *(undefined4 *)(pdVar15 + 0xb),*(undefined4 *)((int)pdVar15 + 0x5c),
               *(undefined4 *)(pdVar15 + 0xc),*(undefined4 *)((int)pdVar15 + 100));
  *(undefined4 *)(iVar8 + 0x44c) = *(undefined4 *)pdVar15;
  *(undefined4 *)(iVar8 + 0x450) = *(undefined4 *)((int)pdVar15 + 4);
  *(undefined4 *)(iVar8 + 0x278) = *(undefined4 *)pdVar15;
  *(undefined4 *)(iVar8 + 0x27c) = *(undefined4 *)((int)pdVar15 + 4);
  *(double *)(iVar8 + 0x280) = *pdVar15 - pdVar15[2];
  *(undefined4 *)(iVar8 + 0x454) = *(undefined4 *)(pdVar15 + 1);
  *(undefined4 *)(iVar8 + 0x458) = *(undefined4 *)((int)pdVar15 + 0xc);
  *(undefined4 *)(iVar8 + 0x288) = *(undefined4 *)(pdVar15 + 1);
  *(undefined4 *)(iVar8 + 0x28c) = *(undefined4 *)((int)pdVar15 + 0xc);
  *(double *)(iVar8 + 0x290) = pdVar15[1] - pdVar15[3];
  dVar1 = pdVar15[1];
  dVar2 = *pdVar15;
  dVar3 = pdVar15[2];
  dVar4 = pdVar15[3];
  FUN_004d5ee0(*(undefined4 *)(pdVar15 + 0xd),*(undefined4 *)((int)pdVar15 + 0x6c),
               *(undefined4 *)(pdVar15 + 0xe),*(undefined4 *)((int)pdVar15 + 0x74),
               *(undefined4 *)(pdVar15 + 0xf),*(undefined4 *)((int)pdVar15 + 0x7c));
  FUN_004d5ee0(*(undefined4 *)(pdVar15 + 0x10),*(undefined4 *)((int)pdVar15 + 0x84),
               *(undefined4 *)(pdVar15 + 0x11),*(undefined4 *)((int)pdVar15 + 0x8c),
               *(undefined4 *)(pdVar15 + 0x12),*(undefined4 *)((int)pdVar15 + 0x94));
  puVar9 = *(undefined1 **)(pdVar15 + 0x26);
  if (puVar9 == (undefined1 *)0x0) {
    puVar9 = &DAT_005ea438;
  }
  uVar10 = FUN_004d75d0(puVar9);
  *(undefined4 *)(iVar8 + 0x2d8) = uVar10;
  puVar9 = *(undefined1 **)(pdVar15 + 0x27);
  if (puVar9 == (undefined1 *)0x0) {
    puVar9 = &DAT_005ea438;
  }
  uVar10 = FUN_004d75d0(puVar9);
  *(undefined4 *)(iVar8 + 0x2dc) = uVar10;
  puVar9 = *(undefined1 **)(pdVar15 + 0x28);
  if (puVar9 == (undefined1 *)0x0) {
    puVar9 = &DAT_005ea438;
  }
  iVar11 = FUN_004d75d0(puVar9);
  *(int *)(iVar8 + 0x2e0) = iVar11;
  if ((((*(int *)(iVar8 + 0x2d8) == 0) || (*(int *)(iVar8 + 0x2dc) == 0)) || (iVar11 == 0)) &&
     ((DAT_007c569c != 5 &&
      (cVar7 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_hdveh_005c421c,0xe92), cVar7 != '\0'))))
  {
    puVar9 = *(undefined1 **)(pdVar15 + 0x28);
    if (puVar9 == (undefined1 *)0x0) {
      puVar9 = &DAT_005ea438;
    }
    puVar13 = *(undefined1 **)(pdVar15 + 0x27);
    if (puVar13 == (undefined1 *)0x0) {
      puVar13 = &DAT_005ea438;
    }
    puVar12 = *(undefined1 **)(pdVar15 + 0x26);
    if (puVar12 == (undefined1 *)0x0) {
      puVar12 = &DAT_005ea438;
    }
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_one_of_tire_slip_c_005c4364,puVar12,puVar13,puVar9);
  }
  fVar16 = (float10)FUN_004d6830(0,0x3ff00000,0xeb1c432d,0x3f1a36e2);
  fVar17 = (float10)FUN_004d6830(0,0x3ff00000,0xeb1c432d,0x3f1a36e2);
  fVar18 = (float10)FUN_004d6830(0,0x3ff00000,0xeb1c432d,0x3f1a36e2);
  *(double *)(iVar8 + 0x2e4) =
       (double)((float10)_DAT_0059e420 /
               (((float10)(double)fVar16 + (float10)(double)fVar16 + fVar18 +
                (float10)(double)fVar17) * (float10)_DAT_0059ec58));
  if (((_DAT_0059e898 <= pdVar15[0x13]) && (DAT_007c569c != 5)) &&
     (cVar7 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_hdveh_005c421c,0xea3), cVar7 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_Tire_optimum_camber_angle_should_005c4328);
  }
  dVar6 = _DAT_0059e430;
  dVar5 = pdVar15[0x13];
  *(double *)(iVar8 + 0x2f4) = dVar5;
  if (dVar5 <= dVar6) {
    *(undefined4 *)(iVar8 + 0x304) = 0;
    *(undefined4 *)(iVar8 + 0x308) = 0;
  }
  else {
    *(double *)(iVar8 + 0x304) = _DAT_0059e898 / dVar5;
  }
  *(undefined4 *)(iVar8 + 0x2ec) = *(undefined4 *)(pdVar15 + 0x14);
  *(undefined4 *)(iVar8 + 0x2f0) = *(undefined4 *)((int)pdVar15 + 0xa4);
  *(double *)(iVar8 + 0x2fc) = pdVar15[0x15] * _DAT_0059ec50;
  *(double *)(iVar8 + 0x30c) = _DAT_0059e890 / (_DAT_0059e898 - *(double *)(iVar8 + 0x2f4));
  *(undefined4 *)(iVar8 + 0x34c) = 0x8f5c28f6;
  *(undefined4 *)(iVar8 + 0x350) = 0x40767dc2;
  *(undefined4 *)(iVar8 + 0x354) = *(undefined4 *)(iVar8 + 0x34c);
  *(undefined4 *)(iVar8 + 0x358) = *(undefined4 *)(iVar8 + 0x350);
  *(undefined4 *)(iVar8 + 0x35c) = *(undefined4 *)(iVar8 + 0x354);
  *(undefined4 *)(iVar8 + 0x360) = *(undefined4 *)(iVar8 + 0x358);
  dVar5 = *(double *)(iVar8 + 0x37c) * _DAT_0059eb40;
  *(undefined4 *)(iVar8 + 0x364) = 0x8f5c28f6;
  *(double *)(iVar8 + 0x36c) = dVar5;
  *(undefined4 *)(iVar8 + 0x368) = 0x40767dc2;
  *(undefined4 *)(iVar8 + 0x128) = 0x402c0000;
  *(undefined4 *)(iVar8 + 0x374) = *(undefined4 *)(iVar8 + 0x37c);
  *(undefined4 *)(iVar8 + 0x378) = *(undefined4 *)(iVar8 + 0x380);
  *(undefined4 *)(iVar8 + 0x124) = 0;
  *(undefined4 *)(iVar8 + 900) = *(undefined4 *)(pdVar15 + 7);
  *(undefined4 *)(iVar8 + 0x388) = *(undefined4 *)((int)pdVar15 + 0x3c);
  *(undefined4 *)(iVar8 + 0x38c) = *(undefined4 *)(pdVar15 + 8);
  *(undefined4 *)(iVar8 + 0x390) = *(undefined4 *)((int)pdVar15 + 0x44);
  if (DAT_007ce958 != 0) {
    *(undefined4 *)(iVar8 + 0x124) = 0;
    dVar5 = *(double *)(iVar8 + 900) * _DAT_0059ec48;
    *(undefined4 *)(iVar8 + 0x128) = 0x40318000;
    *(double *)(iVar8 + 900) = dVar5;
    *(double *)(iVar8 + 0x38c) = *(double *)(iVar8 + 0x38c) * _DAT_0059ec48;
    *(double *)(iVar8 + 0x234) = *(double *)(iVar8 + 0x234) * _DAT_0059ec48;
  }
  *(double *)(iVar8 + 300) = _DAT_0059e420 / *(double *)(iVar8 + 0x124);
  *(double *)(iVar8 + 0x334) = pdVar15[0x23] + _DAT_0059eac8;
  *(undefined4 *)(iVar8 + 0x33c) = *(undefined4 *)(pdVar15 + 0x24);
  *(undefined4 *)(iVar8 + 0x340) = *(undefined4 *)((int)pdVar15 + 0x124);
  *(undefined4 *)(iVar8 + 0x344) = *(undefined4 *)(pdVar15 + 0x25);
  *(undefined4 *)(iVar8 + 0x348) = *(undefined4 *)((int)pdVar15 + 300);
  *(undefined4 *)(iVar8 + 0x45c) = *(undefined4 *)(pdVar15 + 0x16);
  *(undefined4 *)(iVar8 + 0x460) = *(undefined4 *)((int)pdVar15 + 0xb4);
  *(undefined4 *)(iVar8 + 0x32c) = *(undefined4 *)(pdVar15 + 0x16);
  *(undefined4 *)(iVar8 + 0x330) = *(undefined4 *)((int)pdVar15 + 0xb4);
  *(undefined4 *)(iVar8 + 0x3a4) = *(undefined4 *)(pdVar15 + 0x17);
  *(undefined4 *)(iVar8 + 0x3a8) = *(undefined4 *)((int)pdVar15 + 0xbc);
  *(double *)(iVar8 + 0x3ac) = pdVar15[0x18] * *(double *)(iVar8 + 0x2e4);
  *(undefined4 *)(iVar8 + 0x3b4) = *(undefined4 *)(pdVar15 + 0x19);
  *(undefined4 *)(iVar8 + 0x3b8) = *(undefined4 *)((int)pdVar15 + 0xcc);
  *(undefined4 *)(iVar8 + 0x3bc) = *(undefined4 *)(pdVar15 + 0x1a);
  *(undefined4 *)(iVar8 + 0x3c0) = *(undefined4 *)((int)pdVar15 + 0xd4);
  *(undefined4 *)(iVar8 + 0x3c4) = *(undefined4 *)(pdVar15 + 0x1b);
  *(undefined4 *)(iVar8 + 0x3c8) = *(undefined4 *)((int)pdVar15 + 0xdc);
  dVar6 = (double)DAT_007d0c60;
  dVar5 = pdVar15[0x1c];
  *(undefined4 *)(iVar8 + 0x394) = 0;
  *(undefined4 *)(iVar8 + 0x398) = 0x3ff00000;
  *(double *)(iVar8 + 0x3cc) = dVar6 * dVar5 * *(double *)(iVar8 + 0x2e4);
  FUN_00438100();
  dVar5 = _DAT_0059e430;
  if (extraout_EDX < DAT_008acea8) {
    pfVar14 = (float *)(DAT_008aceac + 0xc);
    iVar8 = DAT_008acea8;
    do {
      if (dVar5 < (double)(pfVar14[-1] - *pfVar14)) {
        dVar5 = (double)(pfVar14[-1] - *pfVar14);
      }
      pfVar14 = pfVar14 + 0x1b;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  *(double *)(param_1 + 0xac) = ((dVar3 + dVar4) / (dVar1 + dVar2)) * dVar5;
  return;
}


