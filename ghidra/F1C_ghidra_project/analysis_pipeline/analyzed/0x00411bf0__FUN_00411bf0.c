// Function: FUN_00411bf0 @ 00411bf0
// Size (bytes): 338


undefined4 FUN_00411bf0(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = _rand();
  uVar1 = uVar1 & 0x80000001;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xfffffffe) + 1;
  }
  switch(*(undefined4 *)(param_2 + 0xc)) {
  case 3:
  case 5:
  case 6:
  case 9:
  case 10:
  case 0xd:
  case 0x13:
  case 0x16:
  case 0x17:
  case 0x18:
  case 0x26:
  case 0x29:
  case 0x2d:
  case 0x30:
  case 0x32:
  case 0x35:
  case 0x36:
  case 0x37:
    uVar2 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1,'\x01' - (uVar1 != 0));
    return uVar2;
  default:
    return 0;
  case 8:
  case 0xf:
  case 0x21:
    uVar2 = FUN_00412490(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1,0);
    return uVar2;
  case 0xb:
  case 0xc:
  case 0x33:
    uVar2 = FUN_00412e50(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1);
    return uVar2;
  case 0x11:
  case 0x1f:
  case 0x20:
  case 0x2a:
  case 0x2b:
  case 0x34:
    uVar2 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1,0);
    return uVar2;
  case 0x12:
  case 0x19:
  case 0x1a:
  case 0x1b:
  case 0x1d:
  case 0x1e:
  case 0x2e:
    uVar2 = FUN_004133b0(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1);
    return uVar2;
  case 0x15:
  case 0x1c:
    uVar2 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1,1);
    return uVar2;
  case 0x27:
  case 0x28:
    uVar2 = FUN_00413710(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1);
    return uVar2;
  case 0x31:
    uVar2 = FUN_00412c30(param_4,param_1,*(undefined4 *)(param_3 + 0x10),1);
    return uVar2;
  }
}


