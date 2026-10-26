// Function: FUN_004d91e0 @ 004d91e0
// Size (bytes): 58


undefined4 FUN_004d91e0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_1) {
  case 0:
    return 100;
  case 1:
  case 3:
  case 4:
  case 5:
  case 6:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x12:
  case 0x14:
  case 0x15:
  case 0x16:
  case 0x17:
  case 0x18:
    uVar1 = 0x32;
    break;
  case 2:
  case 0xd:
    return 0x31;
  case 7:
  case 8:
  case 0x13:
    return 0x33;
  case 0x11:
    return 0x34;
  }
  return uVar1;
}


