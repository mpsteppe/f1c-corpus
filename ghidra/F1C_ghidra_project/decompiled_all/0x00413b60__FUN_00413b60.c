// Function: FUN_00413b60 @ 00413b60
// Strings:  [F1_2002.gdb, F1_2001.gdb, F1_2000.gdb, F1_1999.gdb]


undefined4 FUN_00413b60(int param_1,int param_2,undefined4 param_3,char param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0xffffffff;
  if (param_2 != 1) {
    return 0xffffffff;
  }
  if (param_4 != '\0') {
    return 0xffffffff;
  }
  puVar1 = DAT_007d0434;
  if (DAT_007d0434 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_00588410(puVar1,s_F1_1999_gdb_005bf994);
  if (iVar2 == 0) {
    switch(param_3) {
    case 1:
      uVar3 = 0x14e;
      break;
    case 2:
      uVar3 = 0x152;
      break;
    case 3:
      uVar3 = 0x156;
      break;
    case 4:
      uVar3 = 0x15a;
      break;
    case 5:
      uVar3 = 0x15e;
      break;
    case 6:
      uVar3 = 0x162;
      break;
    case 7:
      uVar3 = 0x166;
      break;
    case 8:
      uVar3 = 0x16a;
      break;
    case 9:
      uVar3 = 0x16e;
      break;
    case 10:
      uVar3 = 0x172;
      break;
    case 0xb:
      uVar3 = 0x176;
      break;
    case 0xc:
      uVar3 = 0x17a;
      break;
    case 0xd:
      uVar3 = 0x17e;
      break;
    case 0xe:
      uVar3 = 0x182;
      break;
    case 0xf:
      uVar3 = 0x186;
      break;
    case 0x10:
      uVar3 = 0x18a;
      break;
    case 0x11:
      uVar3 = 0x18e;
      break;
    default:
      goto switchD_00413bb2_default;
    }
  }
  else {
    puVar1 = DAT_007d0434;
    if (DAT_007d0434 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    iVar2 = FUN_00588410(puVar1,s_F1_2000_gdb_005bf988);
    if (iVar2 == 0) {
      switch(param_3) {
      case 1:
        uVar3 = 0x14f;
        break;
      case 2:
        uVar3 = 0x153;
        break;
      case 3:
        uVar3 = 0x157;
        break;
      case 4:
        uVar3 = 0x15b;
        break;
      case 5:
        uVar3 = 0x15f;
        break;
      case 6:
        uVar3 = 0x163;
        break;
      case 7:
        uVar3 = 0x167;
        break;
      case 8:
        uVar3 = 0x16b;
        break;
      case 9:
        uVar3 = 0x16f;
        break;
      case 10:
        uVar3 = 0x173;
        break;
      case 0xb:
        uVar3 = 0x177;
        break;
      case 0xc:
        uVar3 = 0x17b;
        break;
      case 0xd:
        uVar3 = 0x17f;
        break;
      case 0xe:
        uVar3 = 0x183;
        break;
      case 0xf:
        uVar3 = 0x187;
        break;
      case 0x10:
        uVar3 = 0x18b;
        break;
      case 0x11:
        uVar3 = 399;
        break;
      default:
        goto switchD_00413bb2_default;
      }
    }
    else {
      puVar1 = DAT_007d0434;
      if (DAT_007d0434 == (undefined1 *)0x0) {
        puVar1 = &DAT_005ea438;
      }
      iVar2 = FUN_00588410(puVar1,s_F1_2001_gdb_005bf97c);
      if (iVar2 == 0) {
        switch(param_3) {
        case 1:
          uVar3 = 0x150;
          break;
        case 2:
          uVar3 = 0x154;
          break;
        case 3:
          uVar3 = 0x158;
          break;
        case 4:
          uVar3 = 0x15c;
          break;
        case 5:
          uVar3 = 0x160;
          break;
        case 6:
          uVar3 = 0x164;
          break;
        case 7:
          uVar3 = 0x168;
          break;
        case 8:
          uVar3 = 0x16c;
          break;
        case 9:
          uVar3 = 0x170;
          break;
        case 10:
          uVar3 = 0x174;
          break;
        case 0xb:
          uVar3 = 0x178;
          break;
        case 0xc:
          uVar3 = 0x17c;
          break;
        case 0xd:
          uVar3 = 0x180;
          break;
        case 0xe:
          uVar3 = 0x184;
          break;
        case 0xf:
          uVar3 = 0x188;
          break;
        case 0x10:
          uVar3 = 0x18c;
          break;
        case 0x11:
          uVar3 = 400;
          break;
        default:
          goto switchD_00413bb2_default;
        }
      }
      else {
        puVar1 = DAT_007d0434;
        if (DAT_007d0434 == (undefined1 *)0x0) {
          puVar1 = &DAT_005ea438;
        }
        iVar2 = FUN_00588410(puVar1,s_F1_2002_gdb_005bf970);
        if (iVar2 != 0) {
          return 0xffffffff;
        }
        switch(param_3) {
        case 1:
          uVar3 = 0x14d;
          break;
        case 2:
          uVar3 = 0x151;
          break;
        case 3:
          uVar3 = 0x155;
          break;
        case 4:
          uVar3 = 0x159;
          break;
        case 5:
          uVar3 = 0x15d;
          break;
        case 6:
          uVar3 = 0x161;
          break;
        case 7:
          uVar3 = 0x165;
          break;
        case 8:
          uVar3 = 0x169;
          break;
        case 9:
          uVar3 = 0x16d;
          break;
        case 10:
          uVar3 = 0x171;
          break;
        case 0xb:
          uVar3 = 0x175;
          break;
        case 0xc:
          uVar3 = 0x179;
          break;
        case 0xd:
          uVar3 = 0x17d;
          break;
        case 0xe:
          uVar3 = 0x181;
          break;
        case 0xf:
          uVar3 = 0x185;
          break;
        case 0x10:
          uVar3 = 0x189;
          break;
        case 0x11:
          uVar3 = 0x18d;
          break;
        default:
          goto switchD_00413bb2_default;
        }
      }
    }
  }
  *(undefined4 *)(param_1 + 8) = uVar3;
  uVar3 = FUN_00414180(1);
  *(undefined4 *)(param_1 + 0xc) = uVar3;
  uVar3 = 1;
switchD_00413bb2_default:
  return uVar3;
}


