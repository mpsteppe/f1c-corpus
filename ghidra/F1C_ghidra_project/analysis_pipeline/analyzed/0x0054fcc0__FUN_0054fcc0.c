// Function: FUN_0054fcc0 @ 0054fcc0
// Size (bytes): 93


void __thiscall FUN_0054fcc0(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    *(undefined4 *)(param_1 + 0x84) = 0xbf;
    break;
  case 1:
    *(undefined4 *)(param_1 + 0x84) = 0x7f;
    *(undefined4 *)(param_1 + 0x84) = 0xbf;
    return;
  case 2:
    *(undefined4 *)(param_1 + 0x84) = 0x3f;
    *(undefined4 *)(param_1 + 0x84) = 0xbf;
    return;
  case 3:
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined4 *)(param_1 + 0x84) = 0xbf;
    return;
  }
  *(undefined4 *)(param_1 + 0x84) = 0xbf;
  return;
}


