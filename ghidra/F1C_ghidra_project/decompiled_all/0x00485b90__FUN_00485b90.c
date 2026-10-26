// Function: FUN_00485b90 @ 00485b90
// Strings:  [POPUP_ADDPROFILE_FORCED, ADD PROFILE FORCED]


int __fastcall FUN_00485b90(int param_1,char param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  DAT_005cc9e8 = 5;
  if (DAT_007cd8c0 == (int *)0x0) {
    pvVar1 = operator_new(0x21a4);
    if (pvVar1 == (void *)0x0) {
      DAT_007cd8c0 = (int *)0x0;
    }
    else {
      DAT_007cd8c0 = (int *)FUN_0047f370();
    }
    uVar6 = 600;
    uVar5 = 800;
    uVar4 = 0;
    uVar3 = 0;
    FUN_00490920(0,0,800,600);
    FUN_00491760(uVar3,uVar4,uVar5,uVar6);
    FUN_004944a0(DAT_007cd8c0,0,0,1);
    FUN_004963c0();
    FUN_004b03f0();
    FUN_00496840();
    DAT_005cc9e0 = DAT_007cf2cc;
    FUN_004c85d0();
    FUN_004a0ad0();
    do {
      iVar2 = ShowCursor(1);
    } while (iVar2 < 1);
    FUN_004637a0();
    FUN_00463bc0();
    if (DAT_005cc9e8 == -1) {
      return -1;
    }
    if (param_1 != 0) goto LAB_00485cb2;
  }
  else {
    if (param_1 != 0) goto LAB_00485cb2;
    DAT_005cc9e4 = 2;
    do {
      iVar2 = ShowCursor(1);
    } while (iVar2 < 1);
    if (DAT_007c569c == 5) {
      FUN_004a0a80();
    }
    else {
      FUN_004a03f0();
    }
  }
  (**(code **)(*DAT_007cd8c0 + 0x24))();
  uVar6 = 600;
  uVar5 = 800;
  uVar4 = 0;
  uVar3 = 0;
  FUN_00490920(0,0,800,600);
  FUN_00491760(uVar3,uVar4,uVar5,uVar6);
  FUN_00490920();
  FUN_00491770();
LAB_00485cb2:
  if (DAT_007d2e40 != '\0') {
    DAT_007d2e40 = '\0';
    FUN_00497940(s_POPUP_ADDPROFILE_FORCED_005c6b5c,0xffffffff);
    FUN_004988d0(s_ADD_PROFILE_FORCED_005cc1fc);
  }
  FUN_00496930();
  if ((DAT_005cc9e8 == 5) && (FUN_00496e90(0), DAT_005cc9e8 == 5)) {
    DAT_005cc9e8 = 0;
  }
  FUN_004c8650(0xbf800000);
  if (param_2 != '\0') {
    DAT_005cc9e8 = -1;
  }
  if (DAT_005cc9e8 == -1) {
    FUN_00485df0();
  }
  else {
    if (DAT_005cc9e8 == 1) {
      FUN_00496e40();
      do {
        iVar2 = ShowCursor(0);
      } while (-1 < iVar2);
      FUN_0047f230();
      FUN_0047f300();
      FUN_004a0030();
      return DAT_005cc9e8;
    }
    if (DAT_005cc9e8 == 2) {
      FUN_004a00a0();
      return DAT_005cc9e8;
    }
  }
  return DAT_005cc9e8;
}


