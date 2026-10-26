// Function: FUN_004e5ae0 @ 004e5ae0
// Size (bytes): 1146


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004e5ae0(int param_1)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  
  fVar2 = *(float *)(param_1 + 0x3518);
  pfVar1 = (float *)(param_1 + 0x3540);
  *pfVar1 = fVar2 * *(float *)(param_1 + 0x354c);
  *(float *)(param_1 + 0x3544) = fVar2 * *(float *)(param_1 + 0x3550);
  *(float *)(param_1 + 0x3548) = fVar2 * *(float *)(param_1 + 0x3554);
  *(float *)(param_1 + 0x3534) =
       *pfVar1 * *(float *)(param_1 + 0x34b0) +
       *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x3544) +
       *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x3548);
  *(float *)(param_1 + 0x3538) =
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x3544) +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x3548) +
       *(float *)(param_1 + 0x34bc) * *pfVar1;
  *(float *)(param_1 + 0x353c) =
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x3544) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x3548) +
       *(float *)(param_1 + 0x34c8) * *pfVar1;
  fVar2 = *(float *)(param_1 + 0x34a8);
  *(float *)(param_1 + 0x34d4) = fVar2 * *(float *)(param_1 + 0x34ec) + *(float *)(param_1 + 0x34d4)
  ;
  *(float *)(param_1 + 0x34d8) = fVar2 * *(float *)(param_1 + 0x34f0) + *(float *)(param_1 + 0x34d8)
  ;
  *(float *)(param_1 + 0x34dc) = fVar2 * *(float *)(param_1 + 0x34f4) + *(float *)(param_1 + 0x34dc)
  ;
  fVar2 = *(float *)(param_1 + 0x34a8);
  *(float *)(param_1 + 0x34ec) = fVar2 * *(float *)(param_1 + 0x3534) + *(float *)(param_1 + 0x34ec)
  ;
  *(float *)(param_1 + 0x34f0) = fVar2 * *(float *)(param_1 + 0x3538) + *(float *)(param_1 + 0x34f0)
  ;
  *(float *)(param_1 + 0x34f4) = fVar2 * *(float *)(param_1 + 0x353c) + *(float *)(param_1 + 0x34f4)
  ;
  local_10 = *(float *)(param_1 + 0x34a8);
  local_18 = local_10 * *(float *)(param_1 + 0x3504);
  local_14 = local_10 * *(float *)(param_1 + 0x3508);
  local_10 = local_10 * *(float *)(param_1 + 0x350c);
  FUN_00567120(&local_18,param_1 + 0x34e0);
  local_c = *(float *)(param_1 + 0x3558) * *(float *)(param_1 + 0x3564) *
            *(float *)(param_1 + 0x3528);
  fVar2 = *(float *)(param_1 + 0x34a8);
  *(float *)(param_1 + 0x3504) = local_c * fVar2 + *(float *)(param_1 + 0x3504);
  *(float *)(param_1 + 0x3508) =
       *(float *)(param_1 + 0x355c) * *(float *)(param_1 + 0x3568) * *(float *)(param_1 + 0x352c) *
       fVar2 + *(float *)(param_1 + 0x3508);
  *(float *)(param_1 + 0x350c) =
       *(float *)(param_1 + 0x3560) * *(float *)(param_1 + 0x356c) * *(float *)(param_1 + 0x3530) *
       fVar2 + *(float *)(param_1 + 0x350c);
  *(float *)(param_1 + 0x34f8) =
       *(float *)(param_1 + 0x34b0) * *(float *)(param_1 + 0x34ec) +
       *(float *)(param_1 + 0x34bc) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34c8) * *(float *)(param_1 + 0x34f4);
  iVar6 = 4;
  *(float *)(param_1 + 0x34fc) =
       *(float *)(param_1 + 0x34b4) * *(float *)(param_1 + 0x34ec) +
       *(float *)(param_1 + 0x34c0) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34cc) * *(float *)(param_1 + 0x34f4);
  *(float *)(param_1 + 0x3500) =
       *(float *)(param_1 + 0x34b8) * *(float *)(param_1 + 0x34ec) +
       *(float *)(param_1 + 0x34c4) * *(float *)(param_1 + 0x34f0) +
       *(float *)(param_1 + 0x34d0) * *(float *)(param_1 + 0x34f4);
  do {
    FUN_004e43d0();
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = *(int *)(param_1 + 0x39b4);
  if (iVar6 == 0) {
    fVar2 = *(float *)(param_1 + 0x3898) + *(float *)(param_1 + 0x37a0);
LAB_004e5ddc:
    fVar2 = fVar2 * _DAT_0059e450;
  }
  else {
    if (iVar6 != 1) {
      if (iVar6 != 2) goto LAB_004e5de8;
      fVar2 = *(float *)(param_1 + 0x36a8) + *(float *)(param_1 + 0x35b0);
      goto LAB_004e5ddc;
    }
    fVar2 = (*(float *)(param_1 + 0x3898) + *(float *)(param_1 + 0x37a0) +
             *(float *)(param_1 + 0x36a8) + *(float *)(param_1 + 0x35b0)) * _DAT_0059e7f8;
  }
  *(float *)(param_1 + 0x3964) = fVar2;
LAB_004e5de8:
  fVar2 = -(*(float *)(param_1 + 0x39c8) * *(float *)(param_1 + 0x3964));
  bVar4 = *(float *)(param_1 + 0x3978) < DAT_0059e440;
  bVar5 = *(float *)(param_1 + 0x3978) == DAT_0059e440;
  *(float *)(param_1 + 0x3964) = fVar2;
  if ((bVar4 == bVar5) && (*(float *)(param_1 + 0x3994) != DAT_0059e440)) {
    if (*(int *)(param_1 + 0x39f0) == 0) {
      *(float *)(param_1 + 0x3994) =
           *(float *)(param_1 + 0x39a0) * *(float *)(param_1 + 0x398c) *
           *(float *)(param_1 + 0x34a8) + *(float *)(param_1 + 0x3994);
    }
    else if ((*(int *)(param_1 + 0x39f0) == 1) && (*(char *)(param_1 + 0x39ec) != '\0')) {
      fVar3 = (*(float *)(param_1 + 0x3990) - *(float *)(param_1 + 0x399c)) *
              *(float *)(param_1 + 0x3570) + *(float *)(param_1 + 0x399c);
      if (*(float *)(param_1 + 0x3994) < fVar3) {
        fVar3 = *(float *)(param_1 + 0x3994);
      }
      if (fVar3 <= fVar2) {
        *(float *)(param_1 + 0x3994) = fVar2;
      }
      else {
        *(float *)(param_1 + 0x3994) = fVar3;
      }
    }
    else {
      *(float *)(param_1 + 0x3994) = fVar2;
    }
    if (*(float *)(param_1 + 0x3994) < *(float *)(param_1 + 0x399c)) {
      *(undefined4 *)(param_1 + 0x3994) = *(undefined4 *)(param_1 + 0x399c);
      return;
    }
    if (*(float *)(param_1 + 0x3998) < *(float *)(param_1 + 0x3994)) {
      *(undefined4 *)(param_1 + 0x3994) = *(undefined4 *)(param_1 + 0x3998);
      return;
    }
  }
  else if ((*(float *)(param_1 + 0x3994) <= DAT_0059e440) ||
          (fVar2 = *(float *)(param_1 + 0x39a0) * *(float *)(param_1 + 0x398c) *
                   *(float *)(param_1 + 0x34a8) + *(float *)(param_1 + 0x3994),
          *(float *)(param_1 + 0x3994) = fVar2, fVar2 < DAT_0059e440)) {
    *(undefined4 *)(param_1 + 0x3994) = 0;
  }
  return;
}


