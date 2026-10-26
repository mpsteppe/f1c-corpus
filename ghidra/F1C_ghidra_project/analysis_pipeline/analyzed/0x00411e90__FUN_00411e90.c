// Function: FUN_00411e90 @ 00411e90
// Size (bytes): 901


undefined4 FUN_00411e90(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  uVar2 = _rand();
  uVar2 = uVar2 & 0x80000001;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xfffffffe) + 1;
  }
  cVar1 = '\x01' - (uVar2 != 0);
  _rand();
  switch(*(undefined4 *)(param_2 + 0xc)) {
  case 1:
    uVar3 = FUN_00413600(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0);
    return uVar3;
  case 2:
    uVar3 = FUN_00413710(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0);
    return uVar3;
  default:
    uVar3 = 0;
switchD_00411ed0_caseD_2c:
    return uVar3;
  case 4:
  case 0x2f:
    uVar3 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0,cVar1);
    return uVar3;
  case 5:
  case 10:
  case 0x17:
    uVar3 = FUN_00412490(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0,1);
    return uVar3;
  case 6:
  case 0x1b:
  case 0x1d:
  case 0x26:
  case 0x35:
  case 0x36:
    uVar3 = FUN_00412490(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0,0);
    return uVar3;
  case 8:
  case 9:
  case 0xc:
  case 0x33:
    uVar3 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0,cVar1);
    return uVar3;
  case 0xd:
  case 0x1c:
    uVar3 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0,0);
    return uVar3;
  case 0xe:
    uVar3 = FUN_00412e50(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0);
    return uVar3;
  case 0x10:
    uVar3 = FUN_00412490(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0,0);
    return uVar3;
  case 0x11:
  case 0x34:
    uVar3 = FUN_00414010(param_4,*(undefined4 *)(param_3 + 0x14));
    return uVar3;
  case 0x13:
  case 0x29:
    uVar3 = FUN_00412e50(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x14:
    uVar3 = FUN_00413b60(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0);
    return uVar3;
  case 0x16:
  case 0x1a:
    uVar3 = FUN_00413710(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x18:
  case 0x19:
    uVar3 = FUN_00413600(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x1e:
    uVar3 = FUN_004133b0(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x1f:
    uVar3 = FUN_00413820(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x20:
    uVar3 = FUN_004139c0(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x22:
  case 0x23:
    uVar3 = FUN_00412490(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0,1);
    return uVar3;
  case 0x25:
    uVar3 = FUN_004122c0(param_4,param_1,*(undefined4 *)(param_3 + 0x10),0,0);
    return uVar3;
  case 0x2a:
    uVar3 = FUN_00413820(param_4,param_1,*(undefined4 *)(param_3 + 0x18),0);
    return uVar3;
  case 0x2b:
    uVar3 = FUN_004139c0(param_4,param_1,*(undefined4 *)(param_3 + 0x18),0);
    return uVar3;
  case 0x2c:
    goto switchD_00411ed0_caseD_2c;
  case 0x30:
    uVar3 = FUN_00413b60(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  case 0x32:
    uVar3 = FUN_00412c30(param_4,param_1,*(undefined4 *)(param_3 + 0x14),0);
    return uVar3;
  }
}


