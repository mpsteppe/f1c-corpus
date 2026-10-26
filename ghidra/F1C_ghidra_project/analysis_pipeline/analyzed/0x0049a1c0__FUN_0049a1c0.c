// Function: FUN_0049a1c0 @ 0049a1c0
// Size (bytes): 65


undefined4 __thiscall FUN_0049a1c0(int *param_1,int param_2)

{
  undefined8 uVar1;
  
  if (param_2 == 0) {
    return 0xffffffff;
  }
  if (*param_1 != 0) {
    uVar1 = FUN_00499e00();
    while ((int)uVar1 != 0) {
      FUN_00499e00();
      uVar1 = FUN_00499e00();
    }
    FUN_00499df0((int)((ulonglong)uVar1 >> 0x20));
    return 0;
  }
  *param_1 = param_2;
  return 0;
}


