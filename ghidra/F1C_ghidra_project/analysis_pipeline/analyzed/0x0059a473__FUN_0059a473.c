// Function: FUN_0059a473 @ 0059a473
// Size (bytes): 86


void __thiscall FUN_0059a473(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  *(bool *)(param_1 + 0x48) = param_3 == 1;
  if (param_3 == 0) {
    FUN_00598c70();
    if (param_1 != -0x4c) {
      FUN_00598c1c();
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
  }
  FUN_0059a4c9();
  *(undefined4 *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x40) = DAT_008d5a60;
  uVar1 = DAT_008d5a60;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  return;
}


