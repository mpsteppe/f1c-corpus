// Function: FUN_004b5040 @ 004b5040
// Size (bytes): 124


undefined4 __thiscall FUN_004b5040(int param_1,byte param_2)

{
  FUN_00566c00(param_1,1);
  FUN_00566c00(&param_2,1);
  FUN_00566c00(param_1 + 1,param_2);
  *(undefined1 *)(param_2 + 1 + param_1) = 0;
  FUN_00566c00(param_1 + 0x41,0x20);
  FUN_00566c00(param_1 + 0x61,0x20);
  FUN_00566c00(param_1 + 0x84,4);
  FUN_00566c00(param_1 + 0x88,4);
  return 1;
}


