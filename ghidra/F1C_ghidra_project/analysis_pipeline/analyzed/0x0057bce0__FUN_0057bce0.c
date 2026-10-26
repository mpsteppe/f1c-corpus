// Function: FUN_0057bce0 @ 0057bce0
// Size (bytes): 510


void __fastcall FUN_0057bce0(undefined4 *param_1)

{
  BOOL BVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0059c990;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005b8a68;
  local_4 = 0xc;
  FUN_0057e530();
  FUN_0057fbe0();
  local_4._0_1_ = 0xb;
  if (*(char *)(param_1 + 0x2fd) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2fb]);
    if (BVar1 != 0) {
      param_1[0x2fb] = 0;
    }
  }
  FUN_00582dc0();
  local_4._0_1_ = 10;
  if (*(char *)(param_1 + 0x2f2) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2f0]);
    if (BVar1 != 0) {
      param_1[0x2f0] = 0;
    }
  }
  FUN_00582ce0();
  local_4._0_1_ = 9;
  if (*(char *)(param_1 + 0x2e7) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2e5]);
    if (BVar1 != 0) {
      param_1[0x2e5] = 0;
    }
  }
  FUN_00582a10();
  local_4 = CONCAT31(local_4._1_3_,8);
  if (*(char *)(param_1 + 0x2dc) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2da]);
    if (BVar1 != 0) {
      param_1[0x2da] = 0;
    }
  }
  FUN_00582650();
  if (*(char *)(param_1 + 0x2d1) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2cf]);
    if (BVar1 != 0) {
      param_1[0x2cf] = 0;
    }
  }
  local_4._0_1_ = 6;
  if (*(char *)(param_1 + 0x2cd) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2cb]);
    if (BVar1 != 0) {
      param_1[0x2cb] = 0;
    }
  }
  FUN_00581a80();
  local_4._0_1_ = 5;
  if (*(char *)(param_1 + 0x2c6) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2c4]);
    if (BVar1 != 0) {
      param_1[0x2c4] = 0;
    }
  }
  FUN_00581a80();
  local_4._0_1_ = 4;
  if (*(char *)(param_1 + 0x2bf) != '\0') {
    BVar1 = CloseHandle((HANDLE)param_1[0x2bd]);
    if (BVar1 != 0) {
      param_1[0x2bd] = 0;
    }
  }
  FUN_005819c0();
  local_4._0_1_ = 0xd;
  FUN_00582310();
  local_4._0_1_ = 3;
  FUN_00581880();
  local_4._0_1_ = 0xe;
  FUN_00582310();
  local_4._0_1_ = 2;
  FUN_005822b0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00499ae0();
  param_1[0x250] = &PTR_LAB_005b8a00;
  local_4 = 0xffffffff;
  FUN_00583ae0();
  ExceptionList = local_c;
  return;
}


