// Function: FUN_0054fec0 @ 0054fec0
// Strings:  [Texture %s size not power of 2]


undefined4
FUN_0054fec0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  undefined1 local_40 [64];
  
  bVar1 = false;
  if (param_2 < 0x81) {
    if (param_2 != 0x80) {
      switch(param_2) {
      case 1:
      case 2:
      case 4:
      case 8:
      case 0x10:
      case 0x20:
      case 0x40:
        break;
      default:
switchD_0054fee7_caseD_3:
        bVar1 = true;
      }
    }
  }
  else if (param_2 < 0x401) {
    if ((param_2 != 0x400) && (param_2 != 0x100)) {
      bVar3 = param_2 == 0x200;
LAB_0054ff16:
      if (!bVar3) goto switchD_0054fee7_caseD_3;
    }
  }
  else if (param_2 != 0x800) {
    bVar3 = param_2 == 0x1000;
    goto LAB_0054ff16;
  }
  if (param_3 < 0x81) {
    if (param_3 != 0x80) {
      switch(param_3) {
      case 1:
      case 2:
      case 4:
      case 8:
      case 0x10:
      case 0x20:
      case 0x40:
        break;
      default:
        goto switchD_0054ff3a_caseD_3;
      }
    }
  }
  else if (param_3 < 0x401) {
    if ((param_3 != 0x400) && ((param_3 != 0x100 && (param_3 != 0x200))))
    goto switchD_0054ff3a_caseD_3;
  }
  else if ((param_3 != 0x800) && (param_3 != 0x1000)) goto switchD_0054ff3a_caseD_3;
  if (!bVar1) {
    FUN_0054fe50(param_1);
    iVar2 = FUN_00542950(param_2,param_3,param_4,param_5);
    if (iVar2 != 0) {
      FUN_005502c0();
      return 0xffffffff;
    }
    return 0;
  }
switchD_0054ff3a_caseD_3:
  FUN_0058815f(local_40,s_Texture__s_size_not_power_of_2_005dbfec,param_1);
  FUN_0053c590(0xffffffff,local_40);
  return 0xffffffff;
}


