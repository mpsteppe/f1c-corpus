// Function: FUN_00419120 @ 00419120
// Size (bytes): 629


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00419120(int param_1,int param_2,int param_3,int param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int local_20 [8];
  
  if (DAT_007d0308 == 0) {
    return;
  }
  if (DAT_007cf3c8 == DAT_0059e440) {
    return;
  }
  if (DAT_007c56a8 == 8) {
    return;
  }
  if (*(int *)(param_1 + 0x1b0 + *(int *)(param_2 + 0x4894) * 4) == param_4) {
    return;
  }
  if (param_3 == param_4) {
    return;
  }
  FUN_004144d0();
  if (DAT_007c56a4 != 7) goto LAB_00419368;
  if (*(int *)(DAT_007c54e8 + 0x4894) == *(int *)(param_2 + 0x4894)) {
    iVar7 = param_4;
    if (param_4 == 1) {
      FUN_004189f0(0x103);
      FUN_004189f0(0x78);
      uVar6 = 0x78;
    }
    else {
      if (param_3 <= param_4) goto LAB_00419368;
      iVar4 = FUN_004d1b50(param_4);
      iVar4 = iVar4 * 0x48c0;
      if (((((&DAT_005efb24)[iVar4] != '\0') || (*(int *)(&DAT_005f073c + iVar4) != 0)) ||
          (*(int *)(param_2 + 0x403c) < 1)) ||
         (((fVar1 = *(float *)(&DAT_005efbb8 + iVar4) - *(float *)(param_2 + 0x34e0),
           fVar3 = *(float *)(&DAT_005efbbc + iVar4) - *(float *)(param_2 + 0x34e4),
           fVar2 = *(float *)(&DAT_005efbc0 + iVar4) - *(float *)(param_2 + 0x34e8),
           fVar1 = fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2,
           fVar1 < _DAT_0059e804 == (fVar1 == _DAT_0059e804) ||
           (_DAT_008afea0 - (double)_DAT_0059e800 <=
            (double)*(float *)(param_1 + 0x4fc + *(int *)(param_2 + 0x4894) * 4))) ||
          (uVar5 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
          _DAT_0059e7fc <= *(float *)(&DAT_008aae74 + uVar5 * 4))))) goto LAB_00419368;
      FUN_004189f0(0x103);
      FUN_004189f0(0x78);
      uVar5 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      if (_DAT_0059e7f8 <= *(float *)(&DAT_008aae74 + uVar5 * 4)) {
        uVar6 = 0x78;
      }
      else {
        uVar6 = 0x103;
        iVar7 = *(int *)(&DAT_005f0f74 + iVar4);
      }
    }
  }
  else {
    if ((param_4 != 1) || (*(int *)(param_2 + 0x403c) < 1)) goto LAB_00419368;
    iVar7 = *(int *)(param_2 + 0x489c);
    uVar6 = 0xc6;
  }
  FUN_004144f0(uVar6,iVar7,0xffffffff,0xffffffff,0xffffffff,0xc0000000,0xc0000000);
LAB_00419368:
  if (local_20[0] != -1) {
    FUN_00418560(local_20);
    *(int *)(param_1 + 0x1b0 + *(int *)(param_2 + 0x4894) * 4) = param_4;
  }
  return;
}


