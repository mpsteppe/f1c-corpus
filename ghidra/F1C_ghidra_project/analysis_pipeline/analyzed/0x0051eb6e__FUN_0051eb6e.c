// Function: FUN_0051eb6e @ 0051eb6e
// Size (bytes): 135


void FUN_0051eb6e(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)param_1[1])(param_1,1,0x58);
  param_1[0x69] = (int)puVar1;
  puVar1[0x11] = 0;
  puVar1[0xd] = 0;
  *puVar1 = FUN_0051ea90;
  puVar1[2] = &DAT_0051dfca;
  puVar1[3] = &LAB_0051eb5a;
  if (4 < param_1[0x19]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x36;
    *(undefined4 *)(*param_1 + 0x18) = 4;
    (**(code **)*param_1)(param_1);
  }
  if (0x100 < param_1[0x15]) {
    *(undefined4 *)(*param_1 + 0x14) = 0x38;
    *(undefined4 *)(*param_1 + 0x18) = 0x100;
    (**(code **)*param_1)(param_1);
  }
  FUN_0051e2ba();
  FUN_0051e3e7(param_1);
  if (param_1[0x13] == 2) {
    FUN_0051ea5a();
  }
  return;
}


