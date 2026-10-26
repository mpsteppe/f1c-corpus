// Function: FUN_00414010 @ 00414010
// Size (bytes): 212


undefined4 FUN_00414010(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0xffffffff;
  switch(param_2) {
  case 1:
    uVar1 = 0x71;
    break;
  case 2:
    uVar1 = 0x72;
    break;
  case 3:
    uVar1 = 0x73;
    break;
  case 4:
    uVar1 = 0x74;
    break;
  case 5:
    uVar1 = 0x75;
    break;
  case 6:
    uVar1 = 0x76;
    break;
  case 7:
    uVar1 = 0x77;
    break;
  case 8:
    uVar1 = 0x78;
    break;
  case 9:
    uVar1 = 0x79;
    break;
  case 10:
    uVar1 = 0x7a;
    break;
  case 0xb:
    uVar1 = 0x7b;
    break;
  case 0xc:
    uVar1 = 0x7c;
    break;
  case 0xd:
    uVar1 = 0x7d;
    break;
  case 0xe:
    uVar1 = 0x7e;
    break;
  case 0xf:
    uVar1 = 0x7f;
    break;
  case 0x10:
    uVar1 = 0x80;
    break;
  case 0x11:
    uVar1 = 0x81;
    break;
  case 0x12:
    uVar1 = 0x82;
    break;
  case 0x13:
    uVar1 = 0x83;
    break;
  case 0x14:
    uVar1 = 0x84;
    break;
  case 0x15:
    uVar1 = 0x85;
    break;
  case 0x16:
    uVar1 = 0x86;
    break;
  default:
    goto switchD_00414021_default;
  }
  *(undefined4 *)(param_1 + 8) = uVar1;
  uVar1 = FUN_00414180(0);
  *(undefined4 *)(param_1 + 0xc) = uVar1;
  uVar1 = 1;
switchD_00414021_default:
  return uVar1;
}


