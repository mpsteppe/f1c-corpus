// Function: FUN_004e0800 @ 004e0800
// Size (bytes): 477


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004e0800(int *param_1,char param_2)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  
  *(undefined1 *)(param_1 + 0x25d) = 0;
  if (param_1[0x229] != 0) {
    FUN_005506a0(0,0,0);
  }
  uVar2 = DAT_008aae70 & 0xff;
  DAT_008aae70 = DAT_008aae70 + 1;
  param_1[0x253] = (int)(*(float *)(&DAT_008aae74 + uVar2 * 4) * _DAT_005ad150 + _DAT_0059e444);
  FUN_004e0db0();
  iVar3 = DAT_008aae64;
  if (param_2 == '\0') {
    if ((*(int *)(*param_1 + 13000) == 0) || (*(int *)(*param_1 + 13000) == 1)) {
      if (DAT_0083ee60 < 0x3ff) {
        DAT_0083ee60 = DAT_0083ee60 + 1;
        DAT_008aae64 = DAT_008aae64 + 0x1b0;
      }
      FUN_004b33b0(2,8,4,*(undefined4 *)(*param_1 + 0x4894),(float)_DAT_008afea0,0);
      *(float *)(iVar3 + 8) = (float)_DAT_008afea0;
    }
  }
  else {
    FUN_004e3890();
  }
  *(undefined1 *)(param_1 + 0x25b) = 1;
  *(undefined1 *)((int)param_1 + 0x96d) = 1;
  FUN_004e0ed0(param_1[0x259]);
  *(undefined1 *)((int)param_1 + 0x979) = 0;
  FUN_004e2ca0(0x3f800000);
  param_1[0x24d] = 0;
  param_1[0x24e] = 0;
  param_1[0x24f] = 0;
  param_1[0x250] = 0;
  param_1[0x251] = 0;
  *(undefined2 *)(param_1 + 0x252) = 0;
  param_1[0x260] = -1;
  param_1[0x261] = -0x800001;
  fVar1 = _DAT_007cf740;
  if (_DAT_007cf740 < _DAT_0059e43c) {
    fVar1 = _DAT_0059e43c;
  }
  param_1[0x262] = (int)(_DAT_0059ec20 / fVar1);
  if ((param_1[0x226] != 0) && (iVar3 = 0, 0 < param_1[0x22d])) {
    piVar4 = param_1 + 0x231;
    do {
      FUN_00551810(*piVar4,0x3f800000);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 4;
    } while (iVar3 < param_1[0x22d]);
  }
  if ((char)param_1[0x263] != '\0') {
    *(undefined1 *)(param_1 + 0x263) = 0;
    param_1 = param_1 + 0x264;
    iVar3 = 0x11;
    do {
      *(undefined1 *)param_1 = 0;
      param_1 = param_1 + 7;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


