// Function: FUN_004e0ed0 @ 004e0ed0
// Size (bytes): 1994


void __thiscall FUN_004e0ed0(int *param_1,int param_2)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  
  iVar4 = 3;
  if ((*(uint *)(*param_1 + 0x48bc) >> 1 & 1) != 0) {
    iVar4 = param_2;
  }
  param_1[0x259] = iVar4;
  bVar2 = true;
  if ((DAT_007ce254 != '\0') && (DAT_007d0410 != 6)) {
    bVar2 = false;
  }
  switch(iVar4) {
  case 0:
    if (param_1[1] != 0) {
      FUN_0054c030(1,1,1,0);
    }
    if (param_1[0x223] != 0) {
      FUN_0054c030(0,0,0,0);
    }
    if (param_1[1] != 0) {
      if (*(int *)(*param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
        bVar1 = 1 < DAT_007cf860;
      }
      else {
        bVar1 = 2 < DAT_007cf860;
      }
      FUN_0054c1b0(bVar1,1,0);
    }
    if ((char)param_1[0x25b] == '\0') {
      if (param_1[0x51] != 0) {
        FUN_0054c030(0,0,0,0);
      }
      if (param_1[0x9b] != 0) {
        FUN_0054c030(0,0,0,0);
      }
      if (param_1[0xe5] != 0) {
        FUN_0054c030(0,0,0,0);
      }
      if (param_1[0x12f] != 0) {
        FUN_0054c030(0,0,0,0);
      }
    }
    if (DAT_007c54e0 == *param_1) {
      uVar3 = FUN_0040cd60();
      switch(uVar3) {
      case 2:
      case 4:
      case 7:
      case 8:
        if ((bVar2) && (*(char *)(*param_1 + 0xc4) != '\x01')) {
          FUN_004f7010(1);
        }
        if (((DAT_005ea518 == DAT_005ea528) && (*(int *)(DAT_005ea528 + 0x34) == 2)) &&
           (DAT_007cf710 == '\0')) {
          if ((param_1[0x18a] != 0) && ((char)param_1[0x19a] != '\0')) {
            FUN_0054c030(0,0,0,0);
          }
          if (param_1[0xe5] != 0) {
            FUN_0054c030(0,0,0,0);
          }
          if (param_1[0x12f] != 0) {
            FUN_0054c030(0,0,0,0);
          }
        }
        goto LAB_004e10ea;
      }
    }
    else {
      FUN_0040cd60();
    }
    if ((bVar2) && (*(char *)(*param_1 + 0xc4) != '\0')) {
      FUN_004f7010(0);
    }
LAB_004e10ea:
    if (*(char *)((int)param_1 + 0x96d) == '\0') {
      if (param_1[0x225] != 0) {
        FUN_0054c030(0,0,0,0);
      }
      if (param_1[0x227] != 0) {
        FUN_0054c030(0,0,0,0);
      }
      if (param_1[0x226] != 0) {
        FUN_0054c030(0,0,0,0);
      }
    }
    param_1 = param_1 + 0x19b;
    iVar4 = 8;
    do {
      if (((*param_1 != 0) && ((char)param_1[0x10] != '\0')) &&
         (*(char *)((int)param_1 + 0x41) == '\0')) {
        FUN_0054c030(0,0,0,0);
      }
      param_1 = param_1 + 0x11;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    return;
  case 1:
    if (param_1[1] != 0) {
      FUN_0054c030(0,0,1,0);
      FUN_0054c030(1,0,0,0);
    }
    if ((param_1[0x179] != 0) && ((char)param_1[0x189] != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if (DAT_007cf710 != '\0') {
      if ((param_1[0x18a] != 0) && ((char)param_1[0x19a] != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
      if (((param_1[0xe5] != 0) && ((char)param_1[0xf5] != '\0')) && ((char)param_1[0x25b] != '\0'))
      {
        FUN_0054c030(1,1,0,0);
      }
      if (((param_1[0x12f] != 0) && ((char)param_1[0x13f] != '\0')) &&
         ((char)param_1[0x25b] != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
    }
    if (DAT_007cfcec != 0) {
      if (((param_1[0x51] != 0) && ((char)param_1[0x61] != '\0')) && ((char)param_1[0x25b] != '\0'))
      {
        FUN_0054c030(1,1,0,0);
      }
      if ((param_1[0x62] != 0) && ((char)param_1[0x72] != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
      if (((param_1[0x9b] != 0) && ((char)param_1[0xab] != '\0')) && ((char)param_1[0x25b] != '\0'))
      {
        FUN_0054c030(1,1,0,0);
      }
      if ((param_1[0xac] != 0) && ((char)param_1[0xbc] != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
      if (param_1[0x224] != 0) {
        FUN_0054c030(1,1,0,0);
      }
    }
    if ((param_1[0x226] != 0) && (*(char *)((int)param_1 + 0x96d) != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[0x228] != 0) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[0x223] != 0) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[1] != 0) {
LAB_004e166c:
      FUN_0054c1b0(0,1,0);
    }
    break;
  case 2:
    if (param_1[1] != 0) {
      FUN_0054c030(0,0,1,0);
      FUN_0054c030(1,0,0,0);
    }
    if (DAT_007cf710 != '\0') {
      if ((param_1[0x18a] != 0) && ((char)param_1[0x19a] != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
      if (((param_1[0xe5] != 0) && ((char)param_1[0xf5] != '\0')) && ((char)param_1[0x25b] != '\0'))
      {
        FUN_0054c030(1,1,0,0);
      }
      if (((param_1[0x12f] != 0) && ((char)param_1[0x13f] != '\0')) &&
         ((char)param_1[0x25b] != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
    }
    if ((param_1[0x179] != 0) && ((char)param_1[0x189] != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if (((param_1[0x51] != 0) && ((char)param_1[0x61] != '\0')) && ((char)param_1[0x25b] != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if ((param_1[0x62] != 0) && ((char)param_1[0x72] != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if (((param_1[0x9b] != 0) && ((char)param_1[0xab] != '\0')) && ((char)param_1[0x25b] != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if ((param_1[0xac] != 0) && ((char)param_1[0xbc] != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[0x224] != 0) {
      FUN_0054c030(1,1,0,0);
    }
    if ((param_1[0x226] != 0) && (*(char *)((int)param_1 + 0x96d) != '\0')) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[0x228] != 0) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[0x223] != 0) {
      FUN_0054c030(1,1,0,0);
    }
    if (param_1[1] != 0) {
      FUN_0054c1b0(0,1,0);
    }
    if ((param_1[0x51] != 0) && ((char)param_1[0x61] != '\0')) {
      if (*(int *)(*param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
        bVar1 = 1 < DAT_007cf860;
      }
      else {
        bVar1 = 2 < DAT_007cf860;
      }
      FUN_0054c1b0(bVar1,0,0);
    }
    if ((param_1[0x9b] != 0) && ((char)param_1[0xab] != '\0')) {
      if (*(int *)(*param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
        bVar1 = 1 < DAT_007cf860;
      }
      else {
        bVar1 = 2 < DAT_007cf860;
      }
      FUN_0054c1b0(bVar1,0,0);
    }
    piVar5 = param_1 + 0x19b;
    iVar4 = 8;
    do {
      if (((*piVar5 != 0) && ((char)piVar5[0x10] != '\0')) &&
         (*(char *)((int)piVar5 + 0x41) != '\0')) {
        FUN_0054c030(1,1,0,0);
      }
      piVar5 = piVar5 + 0x11;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    break;
  case 3:
    if (param_1[1] != 0) {
      FUN_0054c030(0,0,1,0);
      FUN_0054c030(1,0,0,0);
      goto LAB_004e166c;
    }
    break;
  default:
    goto switchD_004e0f1d_default;
  }
  if ((bVar2) && (*(char *)(*param_1 + 0xc4) != '\x01')) {
    FUN_004f7010(1);
  }
switchD_004e0f1d_default:
  return;
}


