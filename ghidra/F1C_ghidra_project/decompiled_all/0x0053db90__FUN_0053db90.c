// Function: FUN_0053db90 @ 0053db90
// Strings:  [Error enum display modes, Could not get current display mode]


undefined4 __thiscall FUN_0053db90(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  int *piStack_664;
  int *piStack_660;
  uint uStack_65c;
  uint uStack_658;
  undefined4 uStack_654;
  int iStack_650;
  undefined4 uStack_64c;
  int *piStack_648;
  uint uStack_644;
  undefined4 uStack_640;
  undefined4 uStack_63c;
  int aiStack_638 [2];
  int *piStack_630;
  uint uStack_62c;
  undefined4 uStack_628;
  undefined4 uStack_624;
  undefined4 uStack_620;
  undefined4 uStack_61c;
  int *piStack_618;
  uint uStack_614;
  undefined4 uStack_610;
  undefined4 uStack_60c;
  undefined4 uStack_608;
  undefined4 uStack_604;
  int *piStack_600;
  uint uStack_5fc;
  undefined4 uStack_5f8;
  undefined4 uStack_5f4;
  undefined4 uStack_5f0;
  undefined4 uStack_5ec;
  int *piStack_5e8;
  uint uStack_5e4;
  undefined4 uStack_5e0;
  undefined4 *puStack_5dc;
  int *piStack_5d8;
  uint uStack_5d4;
  undefined4 uStack_5d0;
  undefined4 uStack_5cc;
  undefined4 uStack_5c8;
  undefined4 uStack_5c4;
  int *piStack_5c0;
  uint uStack_5bc;
  undefined4 uStack_5b8;
  undefined4 uStack_5b4;
  undefined4 uStack_5b0;
  undefined4 uStack_5ac;
  int *piStack_5a8;
  uint uStack_5a4;
  undefined4 uStack_5a0;
  uint uStack_59c;
  undefined4 uStack_598;
  uint uStack_594;
  int *piStack_590;
  uint uStack_58c;
  undefined4 uStack_588;
  undefined4 uStack_584;
  undefined4 uStack_580;
  undefined4 uStack_57c;
  int *piStack_578;
  uint uStack_574;
  undefined4 uStack_570;
  undefined4 uStack_56c;
  undefined4 uStack_568;
  undefined4 uStack_564;
  int *piStack_560;
  uint uStack_55c;
  undefined4 uStack_558;
  undefined4 uStack_554;
  undefined4 uStack_550;
  undefined4 uStack_54c;
  int *piStack_548;
  uint uStack_544;
  undefined4 uStack_540;
  undefined1 *puStack_53c;
  undefined1 local_42c [1016];
  int iStack_34;
  
  puStack_53c = local_42c;
  uStack_544 = param_2[0x41];
  piStack_548 = (int *)param_1[0x43f];
  uStack_540 = 2;
  uStack_54c = 0x53dbc0;
  iVar1 = (**(code **)(*piStack_548 + 0x14))();
  *param_1 = iVar1;
  if (iStack_34 == 0x104a) {
    uStack_54c = 0x300;
    uStack_550 = 0x400;
    uStack_554 = 0xffffffff;
    uStack_558 = 0xffffffff;
    uStack_55c = 0x53dbe4;
    FUN_0053d930();
  }
  uStack_55c = param_2[0x41];
  piStack_560 = (int *)param_1[0x43f];
  iVar4 = 0;
  uStack_54c = 0;
  uStack_550 = 0x17;
  uStack_554 = 0x17;
  uStack_558 = 1;
  uStack_564 = 0x53dc00;
  iVar1 = (**(code **)(*piStack_560 + 0x24))();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = *param_2 | 0x1000000;
  }
  uStack_574 = param_2[0x41];
  piStack_578 = (int *)param_1[0x43f];
  uStack_564 = 0;
  uStack_568 = 0x19;
  uStack_56c = 0x18;
  uStack_570 = 1;
  uStack_57c = 0x53dc26;
  iVar1 = (**(code **)(*piStack_578 + 0x24))();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = *param_2 | 0x2000000;
  }
  uStack_58c = param_2[0x41];
  piStack_590 = (int *)param_1[0x43f];
  uStack_57c = 0;
  uStack_580 = 0x18;
  uStack_584 = 0x18;
  uStack_588 = 1;
  uStack_594 = 0x53dc4c;
  iVar1 = (**(code **)(*piStack_590 + 0x24))();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = *param_2 | 0x4000000;
  }
  uStack_5a4 = param_2[0x41];
  piStack_5a8 = (int *)param_1[0x43f];
  uStack_594 = 0;
  uStack_598 = 0x14;
  uStack_59c = 0x14;
  uStack_5a0 = 1;
  uStack_5ac = 0x53dc72;
  iVar1 = (**(code **)(*piStack_5a8 + 0x24))();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = *param_2 | 0x8000000;
  }
  uStack_5bc = param_2[0x41];
  piStack_5c0 = (int *)param_1[0x43f];
  uStack_5ac = 0;
  uStack_5b0 = 0x16;
  uStack_5b4 = 0x16;
  uStack_5b8 = 1;
  uStack_5c4 = 0x53dc98;
  iVar1 = (**(code **)(*piStack_5c0 + 0x24))();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = *param_2 | 0x20000000;
  }
  uStack_5d4 = param_2[0x41];
  piStack_5d8 = (int *)param_1[0x43f];
  uStack_5c4 = 0;
  uStack_5c8 = 0x15;
  uStack_5cc = 0x16;
  uStack_5d0 = 1;
  puStack_5dc = (undefined4 *)0x53dcbe;
  iVar1 = (**(code **)(*piStack_5d8 + 0x24))();
  *param_1 = iVar1;
  if (iVar1 == 0) {
    *param_2 = *param_2 | 0x10000000;
  }
  piStack_5e8 = (int *)param_1[0x43f];
  puStack_5dc = &uStack_5a0;
  uStack_5e4 = param_2[0x41];
  uStack_5e0 = 1;
  uStack_5ec = 0x53dce4;
  iVar1 = (**(code **)(*piStack_5e8 + 0x34))();
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if ((uStack_594 & 0x10000) == 0) {
    uVar3 = *param_2 & 0xfffffffb;
  }
  else {
    uVar3 = *param_2 | 4;
  }
  *param_2 = uVar3;
  if ((uStack_594 & 0x100000) == 0) {
    uVar3 = uVar3 & 0xffbfffff;
  }
  else {
    uVar3 = uVar3 | 0x400000;
  }
  *param_2 = uVar3;
  if ((uStack_594 & 0x80000) == 0) {
    uVar3 = uVar3 & 0xfffffff7;
  }
  else {
    uVar3 = uVar3 | 8;
  }
  *param_2 = uVar3;
  if ((uStack_5a4 & 0x80000) == 0) {
    uVar3 = *param_2 & 0xfffffffe;
  }
  else {
    uVar3 = *param_2 | 1;
  }
  *param_2 = uVar3;
  if ((uStack_59c & 1) == 0) {
    uVar3 = *param_2 & 0xffffffef;
  }
  else {
    uVar3 = *param_2 | 0x10;
  }
  uStack_5fc = param_2[0x41];
  uStack_5ec = 2;
  uStack_5f0 = 0;
  uStack_5f4 = 0x17;
  uStack_5f8 = 1;
  *param_2 = uVar3;
  piStack_600 = (int *)param_1[0x43f];
  uStack_604 = 0x53dd7e;
  iVar1 = (**(code **)(*piStack_600 + 0x2c))();
  if (iVar1 == 0) {
LAB_0053dda0:
    *param_2 = *param_2 | 0x20;
  }
  else {
    uStack_614 = param_2[0x41];
    piStack_618 = (int *)param_1[0x43f];
    uStack_604 = 2;
    uStack_608 = 0;
    uStack_60c = 0x16;
    uStack_610 = 1;
    uStack_61c = 0x53dd9c;
    iVar1 = (**(code **)(*piStack_618 + 0x2c))();
    if (iVar1 == 0) goto LAB_0053dda0;
  }
  uStack_614 = param_2[0x41];
  piStack_618 = (int *)param_1[0x43f];
  uStack_604 = 3;
  uStack_608 = 0;
  uStack_60c = 0x17;
  uStack_610 = 1;
  uStack_61c = 0x53ddbd;
  iVar1 = (**(code **)(*piStack_618 + 0x2c))();
  if (iVar1 == 0) {
LAB_0053dddf:
    *param_2 = *param_2 | 0x80;
  }
  else {
    uStack_62c = param_2[0x41];
    piStack_630 = (int *)param_1[0x43f];
    uStack_61c = 3;
    uStack_620 = 0;
    uStack_624 = 0x16;
    uStack_628 = 1;
    aiStack_638[1] = 0x53dddb;
    iVar1 = (**(code **)(*piStack_630 + 0x2c))();
    if (iVar1 == 0) goto LAB_0053dddf;
  }
  uStack_62c = param_2[0x41];
  piStack_630 = (int *)param_1[0x43f];
  uStack_61c = 4;
  uStack_620 = 0;
  uStack_624 = 0x17;
  uStack_628 = 1;
  aiStack_638[1] = 0x53ddff;
  iVar1 = (**(code **)(*piStack_630 + 0x2c))();
  if (iVar1 == 0) {
LAB_0053de21:
    *param_2 = *param_2 | 0x40;
  }
  else {
    uStack_644 = param_2[0x41];
    piStack_648 = (int *)param_1[0x43f];
    aiStack_638[1] = 4;
    aiStack_638[0] = 0;
    uStack_63c = 0x16;
    uStack_640 = 1;
    uStack_64c = 0x53de1d;
    iVar1 = (**(code **)(*piStack_648 + 0x2c))();
    if (iVar1 == 0) goto LAB_0053de21;
  }
  uStack_644 = param_2[0x41];
  piStack_648 = (int *)param_1[0x43f];
  aiStack_638[1] = 6;
  aiStack_638[0] = 0;
  uStack_63c = 0x17;
  uStack_640 = 1;
  uStack_64c = 0x53de3e;
  iVar1 = (**(code **)(*piStack_648 + 0x2c))();
  if (iVar1 == 0) {
LAB_0053de60:
    *param_2 = *param_2 | 0x200;
  }
  else {
    uStack_65c = param_2[0x41];
    piStack_660 = (int *)param_1[0x43f];
    uStack_64c = 6;
    iStack_650 = 0;
    uStack_654 = 0x16;
    uStack_658 = 1;
    piStack_664 = (int *)0x53de5c;
    iVar1 = (**(code **)(*piStack_660 + 0x2c))();
    if (iVar1 == 0) goto LAB_0053de60;
  }
  uStack_65c = param_2[0x41];
  piStack_660 = (int *)param_1[0x43f];
  uStack_64c = 0x10;
  iStack_650 = 0;
  uStack_654 = 0x17;
  uStack_658 = 1;
  piStack_664 = (int *)0x53de80;
  iVar1 = (**(code **)(*piStack_660 + 0x2c))();
  if (iVar1 != 0) {
    piStack_664 = (int *)0x10;
    iVar1 = (**(code **)(*(int *)param_1[0x43f] + 0x2c))
                      ((int *)param_1[0x43f],param_2[0x41],1,0x16,0);
    if (iVar1 != 0) goto LAB_0053dea8;
  }
  *param_2 = *param_2 | 0x80000;
LAB_0053dea8:
  piStack_664 = aiStack_638;
  param_2[0x44] = 0;
  param_2[0x45] = 0;
  iVar1 = (**(code **)(*(int *)param_1[0x43f] + 0x20))((int *)param_1[0x43f],param_2[0x41]);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_0053c590(0xffffffff,s_Could_not_get_current_display_mo_005dbcac);
    return 0xffffffff;
  }
  iVar1 = aiStack_638[0];
  if (aiStack_638[0] == 0x16) {
    iVar1 = 0x15;
  }
  FUN_0055c450(iVar1,&uStack_65c,&uStack_658);
  iVar1 = (**(code **)(*(int *)param_1[0x43f] + 0x18))((int *)param_1[0x43f],param_2[0x41]);
  if (iVar1 < 1) {
    FUN_0053c590(0xffffffff,s_Error_enum_display_modes_005dbc90);
    return 0xffffffff;
  }
  if (0 < iVar1) {
    do {
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x1c))
                        ((int *)param_1[0x43f],param_2[0x41],iVar4,&uStack_65c);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                          ((int *)param_1[0x43f],param_2[0x41],1,uStack_640,iStack_650,1);
        *param_1 = iVar2;
        piStack_664 = (int *)0x0;
        iVar2 = iStack_650;
        if (iStack_650 == 0x16) {
          iVar2 = 0x15;
        }
        FUN_0055c450(iVar2,&piStack_664,&piStack_660);
        if (0xf < (int)piStack_664) {
          if (uStack_65c == 0x2c0) {
            bVar5 = uStack_658 == 0x1e0;
LAB_0053e01b:
            if (bVar5) goto LAB_0053e04e;
          }
          else {
            if (uStack_65c == 0x2d0) {
              bVar5 = uStack_658 == 0x1e0;
              goto LAB_0053e01b;
            }
            if (uStack_65c == 0x358) {
              bVar5 = uStack_658 == 0x1e0;
              goto LAB_0053e01b;
            }
            if ((uStack_65c == 0x3c0) || (uStack_65c == 0x500)) {
              bVar5 = uStack_658 == 0x2d0;
              goto LAB_0053e01b;
            }
          }
          if (((((uint)param_1[0x542] <= uStack_65c) && ((uint)param_1[0x543] <= uStack_658)) &&
              (uStack_65c <= (uint)param_1[0x544])) && (uStack_658 <= (uint)param_1[0x544])) {
            FUN_0055bc00(uStack_65c,uStack_658,piStack_660,uStack_654);
          }
        }
      }
LAB_0053e04e:
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return 0;
}


