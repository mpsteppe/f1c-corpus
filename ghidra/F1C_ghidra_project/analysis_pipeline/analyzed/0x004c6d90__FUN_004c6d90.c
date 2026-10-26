// Function: FUN_004c6d90 @ 004c6d90
// Size (bytes): 237


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004c6d90(int param_1,undefined4 param_2)

{
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  FUN_004e0800(param_2);
  FUN_004e45b0();
  FUN_00410b60(param_1 + 0xc);
  if ((char)param_2 != '\0') {
    FUN_004bb810();
  }
  FUN_004d10e0(param_1,local_c,local_18);
  FUN_004d1100(param_1,local_c,local_18);
  FUN_004d1140(param_1,local_c,local_18);
  if ((char)param_2 != '\0') {
    FUN_004d1180(param_1,local_c,local_18);
    FUN_004ef7c0(local_c,local_18);
  }
  FUN_00424790(param_2);
  FUN_004c6b60(1);
  *(undefined4 *)(param_1 + 0x48b4) = 0xff7fffff;
  FUN_004d1670();
  if (_DAT_005ea408 < DAT_0059e440 != (_DAT_005ea408 == DAT_0059e440)) {
    FUN_004e4910();
  }
  return;
}


