// Function: FUN_0045d530 @ 0045d530
// Size (bytes): 509


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_0045d530(undefined4 *param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  
  FUN_00461550();
  param_1[0x2d] = 0;
  param_1[0x2e] = 0xffffffff;
  param_1[0x2f] = 0;
  param_1[0x30] = 0xffffffff;
  iVar2 = 0x68;
  do {
    FUN_00461470();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1[0xfef] = &PTR_FUN_0059f0cc;
  param_1[0xff0] = 0;
  param_1[0xff2] = 0;
  param_1[0xff3] = 0;
  param_1[0xff4] = 0;
  param_1[0xff5] = 0;
  iVar2 = 0x68;
  do {
    FUN_004ff670();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_0045c750();
  FUN_0045c0a0();
  param_1[0x6ddc] = 0;
  param_1[0x6ddd] = 0;
  param_1[0x6dde] = 0;
  param_1[0x6ddf] = 0;
  param_1[0x6de0] = 0;
  param_1[0x6de1] = 0;
  param_1[0x6de2] = 0;
  param_1[0x6de3] = 0;
  FUN_0045cd50();
  fVar1 = _DAT_0059e43c;
  *param_1 = param_2;
  fVar1 = fVar1 / _DAT_0059f098;
  param_1[2] = 0;
  param_1[1] = fVar1;
  param_1[3] = DAT_0059f09c;
  param_1[4] = DAT_0059f09c;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  *(undefined1 *)(param_1 + 8) = 0;
  *(undefined1 *)((int)param_1 + 0x21) = 0;
  param_1[9] = DAT_0059f0a4;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined1 *)((int)param_1 + 0x29) = 1;
  param_1[0xb] = 0xbf800000;
  *(undefined1 *)(param_1 + 0xc) = 0;
  *(undefined1 *)(param_1 + 0x31) = 1;
  *(undefined1 *)((int)param_1 + 0xc5) = 0;
  *(undefined1 *)((int)param_1 + 0xc6) = 0;
  *(undefined1 *)((int)param_1 + 199) = 0;
  *(undefined1 *)(param_1 + 0x32) = 0;
  *(undefined1 *)(param_1 + 0x47) = 0;
  *(undefined1 *)(param_1 + 0x5b) = 0;
  param_1[0x6b] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x6c) = 0;
  param_1[0x74] = 0;
  FUN_0045e590();
  *(undefined1 *)(param_1 + 0xdd) = 0;
  param_1[0xde] = 0;
  param_1[0xdf] = 0;
  param_1[0xe0] = 0;
  param_1[0xe1] = 0;
  param_1[0xe2] = 0;
  param_1[0xe3] = 0;
  param_1[0xe4] = 0;
  param_1[0xf85] = 0;
  param_1[0xfee] = 0;
  param_1[0xff1] = 0;
  *(undefined1 *)((int)param_1 + 0x3fd9) = 0;
  *(undefined1 *)(param_1 + 0x6dda) = 0;
  *(undefined1 *)((int)param_1 + 0x1b769) = 0;
  *(undefined1 *)((int)param_1 + 0x1b76a) = 0;
  *(undefined1 *)((int)param_1 + 0x1b76b) = 0;
  *(undefined1 *)(param_1 + 0x6ddb) = 0;
  *(undefined1 *)((int)param_1 + 0x1b76d) = 0;
  *(undefined1 *)((int)param_1 + 0x1b76e) = 0;
  *(undefined1 *)(param_1 + 0xff6) = 8;
  return param_1;
}


