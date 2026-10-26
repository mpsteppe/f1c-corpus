// Function: FUN_0040a610 @ 0040a610
// Size (bytes): 72


undefined4 __thiscall FUN_0040a610(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_2) {
  case 0:
    return *(undefined4 *)(param_1 + 0x10);
  case 1:
    return *(undefined4 *)(param_1 + 0x14);
  case 2:
    return *(undefined4 *)(param_1 + 0x18);
  case 3:
    return *(undefined4 *)(param_1 + 0x1c);
  case 4:
    return *(undefined4 *)(param_1 + 0x20);
  case 5:
    return *(undefined4 *)(param_1 + 0x24);
  case 6:
    return *(undefined4 *)(param_1 + 0x28);
  case 7:
    return *(undefined4 *)(param_1 + 0x2c);
  case 8:
    uVar1 = *(undefined4 *)(param_1 + 0x30);
  }
  return uVar1;
}


