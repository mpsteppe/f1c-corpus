// Function: FUN_005837f0 @ 005837f0
// Size (bytes): 653


undefined4 * __thiscall FUN_005837f0(undefined4 *param_1,int param_2)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059cf61;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_0058a6eb(param_1 + 1,0x28,1,&LAB_00585ea0,FUN_00583aa0);
  local_4 = 0;
  FUN_0057a020();
  param_1[0x20] = (uint)*(ushort *)(param_2 + 10);
  FUN_005835f0();
  local_4._0_1_ = 1;
  param_1[0x35] = 0;
  *(undefined1 *)(param_1 + 0x37) = 0;
  param_1[0x36] = 0xffffffff;
  FUN_005862c0();
  local_4._0_1_ = 2;
  param_1[0x3c] = 0;
  *(undefined1 *)(param_1 + 0x3e) = 0;
  param_1[0x3d] = 0xffffffff;
  FUN_00586500();
  param_1[0x3f] = 0;
  param_1[0x40] = 0;
  param_1[0x41] = 0;
  param_1[0x42] = 0;
  local_4._0_1_ = 4;
  FUN_004ba820();
  param_1[0x47] = 0;
  param_1[0x48] = 0;
  param_1[0x49] = 0;
  param_1[0x4a] = 0;
  local_4._0_1_ = 8;
  FUN_005876f0();
  local_4._0_1_ = 9;
  FUN_004ba820();
  local_4._0_1_ = 10;
  param_1[0x155] = 0;
  *(undefined1 *)(param_1 + 0x157) = 0;
  param_1[0x156] = 0xffffffff;
  FUN_00582360();
  local_4._0_1_ = 0xb;
  FUN_004ba820();
  local_4._0_1_ = 0xc;
  param_1[0x15c] = 0;
  *(undefined1 *)(param_1 + 0x15e) = 0;
  param_1[0x15d] = 0xffffffff;
  FUN_00582360();
  local_4._0_1_ = 0xd;
  FUN_004ba820();
  local_4._0_1_ = 0xe;
  param_1[0x163] = 0;
  *(undefined1 *)(param_1 + 0x165) = 0;
  param_1[0x164] = 0xffffffff;
  FUN_00582360();
  local_4._0_1_ = 0xf;
  FUN_004ba820();
  local_4._0_1_ = 0x10;
  param_1[0x16a] = 0;
  *(undefined1 *)(param_1 + 0x16c) = 0;
  param_1[0x16b] = 0xffffffff;
  FUN_00582360();
  local_4._0_1_ = 0x11;
  param_1[0x16d] = 0;
  param_1[0x16e] = 0;
  *(undefined1 *)(param_1 + 0x170) = 0;
  param_1[0x16f] = 0xffffffff;
  FUN_00586500();
  local_4._0_1_ = 0x12;
  param_1[0x171] = 0;
  *(undefined1 *)(param_1 + 0x172) = 0;
  param_1[0x186] = 0;
  *(undefined1 *)(param_1 + 0x188) = 0;
  param_1[0x187] = 0xffffffff;
  FUN_00586560();
  local_4._0_1_ = 0x13;
  FUN_00587030(0xffffffff,0xff,0);
  local_4._0_1_ = 0x14;
  param_1[400] = 0;
  *(undefined1 *)(param_1 + 0x192) = 0;
  param_1[0x191] = 0xffffffff;
  FUN_005865c0();
  local_4 = CONCAT31(local_4._1_3_,0x15);
  FUN_005836a0();
  *param_1 = &PTR_LAB_005b8b60;
  *(undefined1 *)(param_1 + 0x17) = 0;
  *(undefined1 *)((int)param_1 + 0x5d) = 1;
  param_1[0x18] = 0x40;
  *(undefined1 *)(param_1 + 0x19) = 0;
  param_1[0x1e] = *(undefined4 *)(param_2 + 4);
  param_1[0x1f] = 0;
  FUN_00585f60();
  FUN_00583660(0);
  FUN_00585f90();
  param_1[0x38] = 0;
  param_1[0x39] = 0x40f86a00;
  param_1[0x3a] = DAT_005b8b5c;
  param_1[0x150] = param_1;
  param_1[0x193] = 0x2ee;
  ExceptionList = local_c;
  return param_1;
}


