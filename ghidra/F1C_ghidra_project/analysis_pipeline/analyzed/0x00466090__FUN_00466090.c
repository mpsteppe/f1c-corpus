// Function: FUN_00466090 @ 00466090
// Size (bytes): 128


undefined4 * __fastcall FUN_00466090(undefined4 *param_1)

{
  FUN_0048e600();
  param_1[0x3e] = 0x40a00000;
  param_1[0x40] = 0x40a00000;
  param_1[0x3c] = 0;
  *(undefined1 *)(param_1 + 0x3d) = 0;
  *(undefined1 *)((int)param_1 + 0xf5) = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  param_1[0x43] = 0;
  param_1[0x45] = 0;
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  *param_1 = &PTR_FUN_0059f140;
  param_1[0x3f] = 0x41200000;
  param_1[0x44] = 0x3f800000;
  param_1[0x46] = 0xbf800000;
  param_1[0x49] = 0xbf800000;
  return param_1;
}


