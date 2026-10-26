// Function: FUN_004349a0 @ 004349a0
// Size (bytes): 916


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004349a0(void)

{
  int iVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  float local_558;
  float local_554;
  float local_550;
  float local_54c;
  float local_548;
  float local_544;
  float local_538;
  float local_534;
  float local_530;
  float local_52c;
  undefined1 local_528 [12];
  float local_51c;
  float local_518;
  float local_514;
  float local_510;
  float local_50c;
  float local_508;
  float local_504;
  float local_500;
  float local_4fc;
  float local_4f8;
  float local_4f4;
  float local_4f0;
  float local_4ec;
  float local_4e8;
  float local_4e4;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar1 = DAT_005c329c;
  pfVar2 = &local_514;
  iVar3 = 0x6d;
  iVar4 = 0;
  do {
    pfVar2[-2] = 0.0;
    pfVar2[-1] = 0.0;
    *pfVar2 = 0.0;
    pfVar2 = pfVar2 + 3;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  pfVar2 = &local_4f8;
  do {
    FUN_00403cd0(iVar4,&local_534,local_528);
    iVar4 = iVar4 + 1;
    FUN_00403cd0(iVar4,&local_558,local_528);
    local_538 = local_550 + local_52c;
    local_54c = (local_558 + local_534) * _DAT_0059e450;
    *pfVar2 = local_54c;
    local_548 = (local_554 + local_530) * _DAT_0059e450;
    pfVar2[1] = local_548;
    local_544 = local_538 * _DAT_0059e450;
    pfVar2[2] = local_544;
    pfVar2 = pfVar2 + 3;
  } while (iVar4 < 0x67);
  local_504 = local_4f8 + (local_4f8 - local_4ec);
  local_500 = local_4f4 + (local_4f4 - local_4e8);
  local_4fc = local_4f0 + (local_4f0 - local_4e4);
  local_510 = (local_504 - local_4f8) + local_504;
  local_50c = (local_500 - local_4f4) + local_500;
  local_508 = (local_4fc - local_4f0) + local_4fc;
  local_51c = (local_510 - local_504) + local_510;
  local_518 = (local_50c - local_500) + local_50c;
  local_514 = (local_508 - local_4fc) + local_508;
  local_24 = local_30 + (local_30 - local_3c);
  local_20 = local_2c + (local_2c - local_38);
  local_1c = local_28 + (local_28 - local_34);
  local_18 = (local_24 - local_30) + local_24;
  local_14 = (local_20 - local_2c) + local_20;
  local_10 = (local_1c - local_28) + local_1c;
  local_538 = local_10 - local_1c;
  local_558 = (local_18 - local_24) + local_18;
  local_c = local_558;
  local_554 = (local_14 - local_20) + local_14;
  local_8 = local_554;
  local_550 = local_538 + local_10;
  iVar3 = 0x6d;
  local_4 = local_550;
  pfVar2 = &local_51c;
  do {
    local_54c = -*pfVar2;
    iVar3 = iVar3 + -1;
    local_548 = -pfVar2[1];
    *pfVar2 = local_54c;
    local_544 = -pfVar2[2];
    pfVar2[1] = local_548;
    pfVar2[2] = local_544;
    pfVar2[1] = pfVar2[1] - _DAT_0059e8f8;
    pfVar2 = pfVar2 + 3;
  } while (iVar3 != 0);
  local_500 = local_500 - _DAT_0059e7f8;
  local_50c = local_50c - _DAT_0059e7fc;
  local_518 = local_518 - _DAT_0059ead0;
  FUN_00457f90(&local_51c,iVar1 + 5);
  return;
}


