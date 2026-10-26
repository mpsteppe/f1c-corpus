// Function: FUN_0053e070 @ 0053e070
// Strings:  [Invalid parameters, %s - 0x%X, Could not set display mode]


int __thiscall FUN_0053e070(int *param_1,uint *param_2)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 in_stack_00000014;
  char *pcVar10;
  int *piVar11;
  int *piStack_770;
  uint uStack_76c;
  undefined4 uStack_768;
  uint uStack_764;
  undefined4 uStack_760;
  int iStack_75c;
  int iStack_758;
  int *piStack_754;
  uint uStack_750;
  undefined4 uStack_74c;
  uint uStack_748;
  undefined4 uStack_744;
  undefined4 uStack_740;
  undefined4 uStack_73c;
  int *piStack_738;
  uint uStack_734;
  undefined4 uStack_730;
  undefined4 uStack_72c;
  int iStack_728;
  undefined4 uStack_724;
  undefined4 uStack_720;
  int *piStack_71c;
  uint uStack_718;
  undefined4 uStack_714;
  undefined4 uStack_710;
  undefined4 uStack_70c;
  undefined4 uStack_708;
  undefined4 uStack_704;
  int *piStack_700;
  uint uStack_6fc;
  uint uStack_6f8;
  undefined4 uStack_6f4;
  undefined4 uStack_6f0;
  undefined4 uStack_6ec;
  undefined4 uStack_6e8;
  int *piStack_6e4;
  uint uStack_6e0;
  undefined4 uStack_6dc;
  undefined4 uStack_6d8;
  int iStack_6d4;
  undefined4 uStack_6d0;
  undefined4 uStack_6cc;
  int *piStack_6c8;
  uint uStack_6c4;
  undefined4 uStack_6c0;
  undefined4 uStack_6bc;
  undefined4 uStack_6b8;
  undefined4 uStack_6b4;
  undefined4 uStack_6b0;
  int *piStack_6ac;
  uint uStack_6a8;
  undefined4 uStack_6a4;
  undefined4 uStack_6a0;
  undefined4 uStack_69c;
  char acStack_698 [8];
  int *piStack_690;
  uint uStack_68c;
  undefined4 uStack_688;
  undefined4 uStack_684;
  int iStack_680;
  undefined4 uStack_67c;
  undefined4 uStack_678;
  int *piStack_674;
  uint uStack_670;
  undefined4 uStack_66c;
  undefined4 uStack_668;
  undefined4 uStack_664;
  undefined4 uStack_660;
  undefined4 uStack_65c;
  int *piStack_658;
  uint uStack_654;
  undefined4 uStack_650;
  undefined4 uStack_64c;
  undefined4 uStack_648;
  undefined4 uStack_644;
  undefined4 uStack_640;
  int *piStack_63c;
  uint uStack_638;
  undefined4 uStack_634;
  undefined4 uStack_630;
  int *piStack_62c;
  undefined1 *puStack_628;
  undefined1 local_604 [96];
  undefined1 auStack_5a4 [1016];
  int iStack_1ac;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_148;
  int iStack_144;
  int iStack_140;
  uint uStack_138;
  int iStack_134;
  
  puStack_628 = (undefined1 *)0x53e093;
  FUN_0053ead0();
  if (param_1[0x440] == 0) {
    puStack_628 = (undefined1 *)0x53e0aa;
    FUN_0053d970();
  }
  FUN_0055bdc0();
  puStack_628 = (undefined1 *)0x53e0c7;
  pvVar2 = operator_new(0x3c);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005426a0();
  }
  param_1[0x549] = iVar3;
  puStack_628 = (undefined1 *)0x53e0e6;
  pvVar2 = operator_new(0x3c);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005426a0();
  }
  param_1[0x54a] = iVar3;
  puStack_628 = (undefined1 *)0x53e105;
  pvVar2 = operator_new(0x3c);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005426a0();
  }
  param_1[0x54b] = iVar3;
  piVar9 = param_1 + 0x441;
  for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar9 = 0;
    piVar9 = piVar9 + 1;
  }
  puStack_628 = (undefined1 *)in_stack_00000014;
  uStack_630 = 0x53e143;
  piStack_62c = param_1 + 0x443;
  FUN_0055c650();
  piStack_62c = (int *)param_1[0x443];
  puStack_628 = local_604;
  uStack_630 = 0x53e153;
  FUN_0055c450();
  uStack_638 = param_2[0x41];
  piStack_63c = (int *)param_1[0x43f];
  puStack_628 = (undefined1 *)0x3;
  piStack_62c = (int *)0x1;
  uStack_630 = 0x17;
  uStack_634 = 1;
  uStack_640 = 0x53e174;
  iVar3 = (**(code **)(*piStack_63c + 0x28))();
  if (iVar3 == 0) {
    piStack_62c = (int *)0x1;
  }
  uStack_654 = param_2[0x41];
  piStack_658 = (int *)param_1[0x43f];
  uStack_640 = 0x18;
  uStack_644 = 3;
  uStack_648 = 1;
  uStack_64c = 0x18;
  uStack_650 = 1;
  uStack_65c = 0x53e1a1;
  iVar4 = (**(code **)(*piStack_658 + 0x28))();
  uStack_670 = param_2[0x41];
  piStack_674 = (int *)param_1[0x43f];
  uStack_65c = 0x19;
  uStack_660 = 3;
  uStack_664 = 1;
  uStack_668 = 0x18;
  uStack_66c = 1;
  uStack_678 = 0x53e1c7;
  iVar5 = (**(code **)(*piStack_674 + 0x28))();
  uStack_68c = param_2[0x41];
  piStack_690 = (int *)param_1[0x43f];
  uStack_678 = 0x17;
  uStack_67c = 3;
  iStack_680 = 1;
  uStack_684 = 0x18;
  uStack_688 = 1;
  acStack_698[4] = -0x13;
  acStack_698[5] = -0x1f;
  acStack_698[6] = 'S';
  acStack_698[7] = '\0';
  iVar6 = (**(code **)(*piStack_690 + 0x28))();
  iVar3 = 1;
  if (iVar6 != 0) {
    iVar3 = iStack_680;
  }
  if (iVar5 == 0) {
    param_1[0x4fa] = 0x19;
  }
  else if (iVar4 == 0) {
    param_1[0x4fa] = 0x18;
  }
  else if (iVar3 != 0) {
    param_1[0x4fa] = 0x17;
  }
  uStack_6a8 = param_2[0x41];
  piStack_6ac = (int *)param_1[0x43f];
  acStack_698[4] = '\x15';
  acStack_698[5] = '\0';
  acStack_698[6] = '\0';
  acStack_698[7] = '\0';
  acStack_698[0] = '\x03';
  acStack_698[1] = '\0';
  acStack_698[2] = '\0';
  acStack_698[3] = '\0';
  uStack_69c = 1;
  uStack_6a0 = 0x16;
  uStack_6a4 = 1;
  iStack_680 = 0;
  uStack_6b0 = 0x53e24b;
  iVar3 = (**(code **)(*piStack_6ac + 0x28))();
  if (iVar3 == 0) {
    uStack_69c = 1;
  }
  uStack_6c4 = param_2[0x41];
  piStack_6c8 = (int *)param_1[0x43f];
  uStack_6b0 = 0x16;
  uStack_6b4 = 3;
  uStack_6b8 = 1;
  uStack_6bc = 0x16;
  uStack_6c0 = 1;
  uStack_6cc = 0x53e274;
  iVar3 = (**(code **)(*piStack_6c8 + 0x28))();
  uStack_6e0 = param_2[0x41];
  piStack_6e4 = (int *)param_1[0x43f];
  uStack_6cc = 0x17;
  uStack_6d0 = 3;
  iStack_6d4 = 1;
  uStack_6d8 = 0x16;
  uStack_6dc = 1;
  uStack_6e8 = 0x53e29c;
  iVar4 = (**(code **)(*piStack_6e4 + 0x28))();
  if (iStack_6d4 == 0) {
    if (iVar3 == 0) {
      param_1[0x4fb] = 0x16;
    }
    else if (iVar4 == 0) {
      param_1[0x4fb] = 0x17;
    }
  }
  else {
    param_1[0x4fb] = 0x15;
  }
  uStack_6fc = param_2[0x41];
  piStack_700 = (int *)param_1[0x43f];
  uStack_6e8 = 0x17;
  uStack_6ec = 3;
  uStack_6f0 = 0;
  uStack_6f4 = 0x17;
  uStack_6f8 = 1;
  iStack_6d4 = 0;
  uStack_704 = 0x53e2fc;
  iVar3 = (**(code **)(*piStack_700 + 0x28))();
  if (iVar3 == 0) {
    uStack_6f0 = 1;
  }
  uStack_718 = param_2[0x41];
  piStack_71c = (int *)param_1[0x43f];
  uStack_704 = 0x18;
  uStack_708 = 3;
  uStack_70c = 0;
  uStack_710 = 0x17;
  uStack_714 = 1;
  uStack_720 = 0x53e328;
  iVar3 = (**(code **)(*piStack_71c + 0x28))();
  uStack_734 = param_2[0x41];
  piStack_738 = (int *)param_1[0x43f];
  uStack_720 = 0x19;
  uStack_724 = 3;
  iStack_728 = 0;
  uStack_72c = 0x17;
  uStack_730 = 1;
  uStack_73c = 0x53e34e;
  iVar4 = (**(code **)(*piStack_738 + 0x28))();
  if (iStack_728 != 0) {
    param_1[0x500] = 0x17;
  }
  if (iVar4 == 0) {
    if (iVar3 == 0) {
LAB_0053e381:
      param_1[0x501] = 0x18;
    }
    else {
      param_1[0x501] = 0x19;
    }
  }
  else if (iVar3 == 0) goto LAB_0053e381;
  uStack_750 = param_2[0x41];
  piStack_754 = (int *)param_1[0x43f];
  uStack_73c = 0x15;
  uStack_740 = 3;
  uStack_744 = 0;
  uStack_748 = 0x16;
  uStack_74c = 1;
  iStack_758 = 0x53e3ab;
  iVar3 = (**(code **)(*piStack_754 + 0x28))();
  uStack_76c = param_2[0x41];
  piStack_770 = (int *)param_1[0x43f];
  iStack_758 = 0x16;
  iStack_75c = 3;
  uStack_760 = 0;
  uStack_764 = 0x16;
  uStack_768 = 1;
  iVar4 = (**(code **)(*piStack_770 + 0x28))();
  if (iVar3 == 0) {
    param_1[0x4fd] = 0x15;
  }
  if (iVar4 == 0) {
    param_1[0x4fc] = 0x16;
  }
  if (piStack_754 == (int *)0x10) {
    uVar7 = *param_2;
    if ((uVar7 & 0x1000000) == 0) {
      if ((uVar7 & 0x4000000) == 0) {
        if ((uVar7 & 0x2000000) != 0) {
          param_1[0x443] = 0x19;
        }
      }
      else {
        param_1[0x443] = 0x18;
      }
    }
    else {
      param_1[0x443] = 0x17;
    }
    iVar3 = param_1[0x4fa];
LAB_0053e49f:
    FUN_0055c450(iVar3,0,param_1 + 0x556);
  }
  else if ((piStack_754 == (int *)0x18) || (piStack_754 == (int *)0x20)) {
    uVar7 = *param_2;
    if ((uVar7 & 0x8000000) == 0) {
      if ((uVar7 & 0x20000000) == 0) {
        if ((uVar7 & 0x10000000) != 0) {
          param_1[0x443] = 0x15;
        }
      }
      else {
        param_1[0x443] = 0x16;
      }
    }
    else {
      param_1[0x443] = 0x14;
    }
    iVar3 = param_1[0x4fb];
    goto LAB_0053e49f;
  }
  if (((uStack_138 & 0x100560) != 0) && ((*param_2 & 0x802e0) != 0)) {
    if ((uStack_138 & 0x20) == 0) {
      if ((uStack_138 & 0x100) == 0) {
        if ((uStack_138 & 0x40) == 0) {
          if ((uStack_138 & 0x400) == 0) {
            if (((uStack_138 & 0x100000) != 0) &&
               (iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x2c))
                                  ((int *)param_1[0x43f],param_2[0x41],1,param_1[0x443],0,0x10),
               iVar3 == 0)) {
              param_1[0x445] = 0x10;
              iStack_75c = 0x100000;
            }
          }
          else {
            iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x2c))
                              ((int *)param_1[0x43f],param_2[0x41],1,param_1[0x443],0,6);
            if (iVar3 == 0) {
              param_1[0x445] = 6;
              iStack_75c = 0x400;
            }
          }
        }
        else {
          iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x2c))
                            ((int *)param_1[0x43f],param_2[0x41],1,param_1[0x443],0,4);
          if (iVar3 == 0) {
            param_1[0x445] = 4;
            iStack_75c = 0x40;
          }
        }
      }
      else {
        iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x2c))
                          ((int *)param_1[0x43f],param_2[0x41],1,param_1[0x443],0,3);
        if (iVar3 == 0) {
          param_1[0x445] = 3;
          iStack_75c = 0x100;
        }
      }
    }
    else {
      iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x2c))
                        ((int *)param_1[0x43f],param_2[0x41],1,param_1[0x443],0,2);
      if (iVar3 == 0) {
        param_1[0x445] = 2;
        iStack_75c = 0x20;
      }
    }
  }
  if ((uStack_138 & 2) == 0) {
    param_1[0x448] = 1;
    if (iStack_75c == 0) {
      param_1[0x445] = 0;
      if (((char)uStack_138 < '\0') && ((*param_2 & 0x10) != 0)) {
        param_1[0x446] = 4;
      }
      else {
        param_1[0x446] = 3;
      }
    }
    else {
      param_1[0x446] = 1;
    }
    param_1[0x44c] = 0;
  }
  else {
    param_1[0x448] = 0;
    if (iStack_75c == 0) {
      param_1[0x445] = 0;
      param_1[0x446] = 2;
    }
    else {
      param_1[0x446] = 1;
    }
    if (((char)uStack_138 < '\0') && ((*param_2 & 0x10) != 0)) {
      param_1[0x44d] = 1;
      param_1[0x44c] = iStack_134;
    }
    else {
      param_1[0x44d] = -0x80000000;
      param_1[0x44c] = iStack_134;
    }
  }
  piVar9 = param_1 + 0x441;
  *piVar9 = iStack_144;
  param_1[0x442] = iStack_140;
  param_1[0x447] = iStack_148;
  param_1[0x444] = 1;
  param_1[0x449] = 0;
  param_1[0x44a] = 0x50;
  if (iStack_758 == 0) {
    piVar11 = (int *)param_1[0x440];
    iVar3 = (**(code **)(*piVar11 + 0x38))(piVar11,piVar9);
  }
  else {
    if ((*param_2 & 4) == 0) {
      uVar8 = 0x20;
      param_1[0x44e] = 0;
LAB_0053e74c:
      param_1[0x4f6] = 0;
    }
    else {
      param_1[0x4f6] = 0;
      if (param_1[0x4f5] == 0) {
        uVar8 = 0x40;
        param_1[0x44e] = 2;
      }
      else {
        uVar8 = 0x80;
        param_1[0x44e] = 1;
      }
      if (param_1[0x4f8] != 2) {
        uVar8 = 0x80;
        param_1[0x44e] = 1;
        goto LAB_0053e74c;
      }
    }
    iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x3c))
                      ((int *)param_1[0x43f],param_2[0x41],1,iStack_148,uVar8,piVar9,param_1 + 0x440
                      );
    piVar11 = piVar9;
  }
  piVar9 = param_1 + 0x440;
  *param_1 = iVar3;
  if (iVar3 != 0) {
    FUN_0058815f(acStack_698,s__s___0x_X_005dbce4,s_Could_not_set_display_mode_005dbcf0,iVar3);
    pcVar10 = acStack_698;
LAB_0053e7a1:
    FUN_0053c590(0xffffffff,pcVar10);
    return -1;
  }
  param_1[1] = param_2[0x41];
  iVar3 = (**(code **)(*(int *)*piVar9 + 0x40))((int *)*piVar9,0,0,param_1[0x54a] + 0xc);
  *param_1 = iVar3;
  iVar3 = (**(code **)(**(int **)(param_1[0x54a] + 0xc) + 8))(*(int **)(param_1[0x54a] + 0xc));
  *param_1 = iVar3;
  *(undefined4 *)(param_1[0x54a] + 0x1c) = uStack_160;
  *(undefined4 *)(param_1[0x54a] + 0x20) = uStack_15c;
  *(undefined4 *)(param_1[0x54a] + 0x18) = 0x40002;
  uVar8 = FUN_0055c3c0(param_1[0x54a]);
  *(undefined4 *)(param_1[0x54a] + 0x30) = uVar8;
  if ((*param_2 & 8) != 0) {
    piVar1 = (int *)*piVar9;
    if (piVar11 == (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 200))(piVar1,0xa1,0);
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 200))(piVar1,0xa1,1);
    }
    *param_1 = iVar3;
    iVar3 = FUN_0053f3f0(param_2,param_1[0x54a],param_1[0x54b],piVar11);
    if (iVar3 != 0) {
      return -1;
    }
    iVar3 = (**(code **)(*(int *)*piVar9 + 0x7c))
                      ((int *)*piVar9,0,*(undefined4 *)(param_1[0x54b] + 0xc));
    *param_1 = iVar3;
    if (iVar3 != 0) {
      pcVar10 = s_Invalid_parameters_005dbcd0;
      goto LAB_0053e7a1;
    }
  }
  uVar7 = (**(code **)(*(int *)*piVar9 + 0x10))((int *)*piVar9);
  param_2[0x45] = uVar7;
  iVar3 = (**(code **)(*(int *)*piVar9 + 0x1c))((int *)*piVar9,&piStack_770);
  *param_1 = iVar3;
  if (iVar3 == 0) {
    param_1[0x4eb] = uStack_6e0;
    param_1[0x4ec] = uStack_6e0;
    iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x14))
                      ((int *)param_1[0x43f],param_2[0x41],2,auStack_5a4);
    *param_1 = iVar3;
    if (iStack_1ac == 0x104a) {
      param_1[0x4ea] = param_1[0x4ea] | 0x2000;
      param_1[0x554] = 1;
      param_1[0x555] = 0x100;
    }
    if ((uStack_748 & 0x20000) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 1;
    }
    if ((uStack_76c & 0x4000) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 2;
    }
    param_1[0x4ee] = 1;
    if ((uStack_764 & 0x4000) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x100;
    }
    if ((uStack_764 & 0x100) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x4000;
    }
    if ((char)uStack_764 < '\0') {
      param_1[0x4ea] = param_1[0x4ea] | 0x8000;
    }
    if ((uStack_6f8 & 0x800000) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x20;
    }
    if ((uStack_6f8 & 0x16) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x40;
    }
    if ((uStack_76c & 0x1000) != 0) {
      param_1[0x4ea] = param_1[0x4ea] | 4;
    }
    iVar3 = param_1[0x443];
    iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x28))
                      ((int *)param_1[0x43f],param_2[0x41],1,iVar3,0,3,0x31545844);
    if (iVar4 == 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x1000;
    }
    iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x28))
                      ((int *)param_1[0x43f],param_2[0x41],1,iVar3,0,3,0x32545844);
    if (iVar4 == 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x10000;
    }
    iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x28))
                      ((int *)param_1[0x43f],param_2[0x41],1,iVar3,0,3,0x33545844);
    if (iVar4 == 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x20000;
    }
    iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x28))
                      ((int *)param_1[0x43f],param_2[0x41],1,iVar3,0,3,0x34545844);
    if (iVar4 == 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x40000;
    }
    iVar3 = (**(code **)(*(int *)param_1[0x43f] + 0x28))
                      ((int *)param_1[0x43f],param_2[0x41],1,iVar3,0,3,0x35545844);
    if (iVar3 == 0) {
      param_1[0x4ea] = param_1[0x4ea] | 0x80000;
    }
  }
  iVar3 = FUN_0053eb70(0);
  return -(uint)(iVar3 != 0);
}


