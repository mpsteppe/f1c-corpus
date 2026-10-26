// Function: FUN_0057ba10 @ 0057ba10
// Size (bytes): 606


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_0057ba10(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c8c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_005837f0(param_2,param_3);
  puVar2 = param_2;
  puVar3 = param_1 + 0x242;
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  local_4 = 0;
  FUN_0057a160();
  local_4._0_1_ = 1;
  param_1[0x250] = &PTR_FUN_005b8b3c;
  *(undefined2 *)(param_1 + 0x29b) = 0;
  param_1[0x29c] = 0;
  FUN_0057a1e0();
  local_4._0_1_ = 2;
  FUN_00587460(0x800);
  local_4._0_1_ = 3;
  FUN_0057b8c0();
  param_1[0x2ab] = 0;
  param_1[0x2ac] = 0;
  param_1[0x2ad] = 0;
  param_1[0x2ae] = 0;
  local_4._0_1_ = 4;
  param_1[0x2af] = 0;
  *(undefined1 *)(param_1 + 0x2b1) = 0;
  param_1[0x2b0] = 0xffffffff;
  FUN_00582360();
  param_1[0x2b2] = 0;
  param_1[0x2b3] = 0;
  param_1[0x2b4] = 0;
  param_1[0x2b5] = 0;
  local_4._0_1_ = 6;
  param_1[0x2b6] = 0;
  *(undefined1 *)(param_1 + 0x2b8) = 0;
  param_1[0x2b7] = 0xffffffff;
  FUN_00582360();
  param_1[0x2b9] = 0;
  param_1[0x2ba] = 0;
  param_1[699] = 0;
  param_1[700] = 0;
  local_4._0_1_ = 8;
  param_1[0x2bd] = 0;
  *(undefined1 *)(param_1 + 0x2bf) = 0;
  param_1[0x2be] = 0xffffffff;
  FUN_00582360();
  param_1[0x2c0] = 0;
  param_1[0x2c1] = 0;
  param_1[0x2c2] = 0;
  param_1[0x2c3] = 0;
  local_4._0_1_ = 10;
  param_1[0x2c4] = 0;
  *(undefined1 *)(param_1 + 0x2c6) = 0;
  param_1[0x2c5] = 0xffffffff;
  FUN_00582360();
  param_1[0x2c7] = 0;
  param_1[0x2c8] = 0;
  param_1[0x2c9] = 0;
  param_1[0x2ca] = 0;
  local_4._0_1_ = 0xc;
  param_1[0x2cb] = 0;
  *(undefined1 *)(param_1 + 0x2cd) = 0;
  param_1[0x2cc] = 0xffffffff;
  FUN_00582360();
  local_4._0_1_ = 0xd;
  param_1[0x2cf] = 0;
  *(undefined1 *)(param_1 + 0x2d1) = 0;
  param_1[0x2d0] = 0xffffffff;
  FUN_00586500();
  local_4._0_1_ = 0xe;
  FUN_005824f0();
  local_4._0_1_ = 0xf;
  param_1[0x2da] = 0;
  *(undefined1 *)(param_1 + 0x2dc) = 0;
  param_1[0x2db] = 0xffffffff;
  FUN_00582720();
  local_4._0_1_ = 0x10;
  FUN_005828b0();
  local_4._0_1_ = 0x11;
  param_1[0x2e5] = 0;
  *(undefined1 *)(param_1 + 0x2e7) = 0;
  param_1[0x2e6] = 0xffffffff;
  FUN_00582720();
  local_4._0_1_ = 0x12;
  FUN_00581d40();
  local_4._0_1_ = 0x13;
  FUN_00581fd0();
  *param_1 = &PTR_LAB_005b8a68;
  param_1[0x24e] = 0xffffffff;
  param_1[0x24f] = 0xffffffff;
  *(undefined1 *)(param_1 + 0x29d) = 0;
  *(undefined1 *)((int)param_1 + 0xa75) = 0;
  *(undefined1 *)((int)param_1 + 0xa76) = 0;
  param_1[0x2a9] = 0;
  param_1[0x2aa] = 0;
  param_1[0x1dd] = param_2[3];
  local_4 = CONCAT31(local_4._1_3_,0x14);
  DAT_008d3e28 = 0;
  _DAT_008d3e24 = param_1;
  FUN_0057e480();
  ExceptionList = local_c;
  return param_1;
}


