// Function: FUN_0053c360 @ 0053c360
// Size (bytes): 368


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_0053c360(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5)

{
  undefined1 *puVar1;
  void *pvVar2;
  
  DAT_008b8e30 = 0;
  puVar1 = &DAT_008b5a3c;
  do {
    *puVar1 = 0;
    puVar1 = puVar1 + 0x84;
  } while ((int)puVar1 < 0x8b6abc);
  DAT_008b6ac0 = 0;
  DAT_008b8f14 = 0;
  DAT_008b8ee0 = 0xffffffff;
  DAT_008b8e34 = 0xffffffff;
  DAT_008b6ac4 = 1;
  DAT_008b8e24 = 1;
  DAT_008b8e2c = 1;
  DAT_008b8e28 = 1;
  _DAT_008b8dc4 = 0;
  DAT_008b8dc8 = 0;
  _DAT_008b8dcc = 0;
  _DAT_008b8dd0 = 0;
  DAT_008b8f18 = 0;
  DAT_008b8f1c = 0;
  DAT_008b8f20 = 0;
  if ((param_5 & 2) != 0) goto LAB_0053c462;
  if ((param_5 & 4) == 0) {
    if ((param_5 & 8) != 0) {
      DAT_008b8cec = 3;
      _DAT_008b8cf0 = 0x3eaab368;
      _DAT_008b8cf4 = 0x3eaab368;
      goto LAB_0053c433;
    }
  }
  else {
    DAT_008b8cec = 2;
    _DAT_008b8cf0 = 0x3f000000;
    _DAT_008b8cf4 = 0x3f000000;
LAB_0053c433:
    FUN_0053d930(0xffffffff,0xffffffff,16000,12000);
  }
  FUN_0053d750();
  FUN_0055be80(param_4,param_5 & 1);
LAB_0053c462:
  FUN_0053b0d0();
  FUN_005566d0();
  pvVar2 = operator_new(0xa0);
  if (pvVar2 == (void *)0x0) {
    DAT_008b8f04 = 0;
  }
  else {
    DAT_008b8f04 = FUN_0055f080();
  }
  FUN_0055f0d0(param_1);
  FUN_0055f060();
  pvVar2 = operator_new(0xc);
  if (pvVar2 != (void *)0x0) {
    DAT_008b8f2c = FUN_005593b0();
    return 0;
  }
  DAT_008b8f2c = 0;
  return 0;
}


