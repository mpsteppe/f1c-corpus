// Function: FUN_004f8030 @ 004f8030
// Size (bytes): 227


void FUN_004f8030(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  switch(param_1) {
  default:
    *param_2 = 1;
    *param_3 = 0;
    return;
  case 1:
  case 4:
  case 7:
  case 0x16:
  case 0x2b:
    *param_2 = 1;
    *param_3 = 0;
    return;
  case 2:
  case 5:
  case 8:
  case 0x17:
  case 0x2c:
    *param_2 = 1;
    *param_3 = 0;
    return;
  case 10:
  case 0x19:
    *param_2 = 1;
    *param_3 = 0;
    return;
  case 0xb:
  case 0x1a:
    *param_2 = 1;
    *param_3 = 0;
    return;
  case 0xc:
  case 0xf:
  case 0x12:
  case 0x1b:
  case 0x1e:
  case 0x21:
  case 0x24:
    *param_2 = 0;
    *param_3 = 0;
    return;
  case 0xd:
  case 0x10:
  case 0x13:
  case 0x1c:
  case 0x1f:
  case 0x22:
  case 0x25:
  case 0x28:
    *param_2 = 0;
    *param_3 = 0;
    return;
  case 0xe:
  case 0x11:
  case 0x1d:
  case 0x20:
  case 0x23:
    *param_2 = 0;
    *param_3 = 0;
    return;
  case 0x14:
  case 0x27:
  case 0x29:
    *param_2 = 0;
    *param_3 = 0;
    return;
  }
}


