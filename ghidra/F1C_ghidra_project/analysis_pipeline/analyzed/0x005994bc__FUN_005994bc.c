// Function: FUN_005994bc @ 005994bc
// Size (bytes): 120


void __thiscall FUN_005994bc(int param_1,int param_2,int param_3)

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
  if ((param_2 != 0) && (*(char *)(param_1 + 0x48) == '\0')) {
    *(int *)(param_1 + 0x1c) = param_2;
    *(int *)(param_1 + 0xc) = param_2 + 8;
    *(int *)(param_1 + 0x10) = param_2 + 8;
    *(int *)(param_1 + 0x20) = param_2;
    *(int *)(param_1 + 0x2c) = param_2 + 4;
    *(int *)(param_1 + 0x30) = param_2 + 4;
  }
  *(int *)(param_1 + 0x50) = param_2;
  *(undefined4 *)(param_1 + 0x40) = DAT_008d5a68;
  uVar1 = DAT_008d5a68;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = uVar1;
  return;
}


