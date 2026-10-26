// Function: FUN_00552ff0 @ 00552ff0
// Size (bytes): 73


void __thiscall FUN_00552ff0(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x54) = param_2;
  switch(param_3) {
  case 0:
    *(undefined4 *)(param_1 + 0x58) = 0xbf;
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x58) = 0x7f;
    return;
  case 2:
    *(undefined4 *)(param_1 + 0x58) = 0x3f;
    return;
  case 3:
    *(undefined4 *)(param_1 + 0x58) = 0;
    return;
  case 4:
    *(undefined4 *)(param_1 + 0x58) = 0xff;
    return;
  }
  return;
}


