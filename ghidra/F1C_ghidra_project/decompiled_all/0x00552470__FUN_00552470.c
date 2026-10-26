// Function: FUN_00552470 @ 00552470
// Strings:  [Illegal font file type %s, FONTTEX]


undefined4 __thiscall FUN_00552470(int param_1,char *param_2,uint param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  char local_200 [256];
  undefined1 local_100 [256];
  
  uVar8 = 0x8000;
  if ((param_3 & 0x800) != 0) {
    uVar8 = 0x8800;
  }
  if ((param_3 & 2) == 0) {
    uVar8 = 1;
  }
  else {
    uVar8 = uVar8 | 2;
  }
  uVar3 = FUN_0055bfc0();
  iVar4 = FUN_0053d890(uVar3);
  if ((iVar4 != 0) && ((*(int *)(iVar4 + 0x11c) < 0x101 || (*(int *)(iVar4 + 0x120) < 0x101)))) {
    param_3 = param_3 & 0xfffdffff | 0x10000;
  }
  *(uint *)(param_1 + 0x24) = param_3;
  iVar4 = -(int)param_2;
  do {
    cVar2 = *param_2;
    param_2[(int)(local_200 + iVar4)] = cVar2;
    param_2 = param_2 + 1;
  } while (cVar2 != '\0');
  FUN_00589901(local_200);
  iVar4 = FUN_00587c20(local_200,&DAT_005cc79c);
  if (iVar4 == 0) {
    FUN_0058815f(local_100,s_Illegal_font_file_type__s_005dc108,local_200);
    FUN_0053c590(0xffffffff,local_100);
  }
  else {
    piVar1 = (int *)(param_1 + 100);
    iVar4 = FUN_0053cb20(piVar1,local_200,-((param_3 & 0x20000) != 0) & 5,uVar8);
    if ((iVar4 == 0) && (iVar4 = FUN_00552f20(local_200), iVar4 == 0)) {
      if ((*(uint *)(param_1 + 0x24) & 0x20000) == 0) {
        if (((*(uint *)(param_1 + 0x24) & 0x10000) != 0) && ((param_3 & 0x800) == 0)) {
          *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
        }
        return 0;
      }
      iVar4 = FUN_005527c0();
      if (iVar4 == 0) {
        iVar4 = *(int *)(*piVar1 + 0x1c);
        if (iVar4 < 0x21) {
          uVar3 = 0x20;
        }
        else if (iVar4 < 0x41) {
          uVar3 = 0x40;
        }
        else if (iVar4 < 0x81) {
          uVar3 = 0x80;
        }
        else if (iVar4 < 0x101) {
          uVar3 = 0x100;
        }
        else if (iVar4 < 0x201) {
          uVar3 = 0x200;
        }
        else if (iVar4 < 0x401) {
          uVar3 = 0x400;
        }
        else {
          if (0x800 < iVar4) {
            return 0xffffffff;
          }
          uVar3 = 0x800;
        }
        iVar4 = *(int *)(*piVar1 + 0x20);
        if (iVar4 < 0x21) {
          uVar7 = 0x20;
        }
        else if (iVar4 < 0x41) {
          uVar7 = 0x40;
        }
        else if (iVar4 < 0x81) {
          uVar7 = 0x80;
        }
        else if (iVar4 < 0x101) {
          uVar7 = 0x100;
        }
        else if (iVar4 < 0x201) {
          uVar7 = 0x200;
        }
        else if (iVar4 < 0x401) {
          uVar7 = 0x400;
        }
        else {
          if (0x800 < iVar4) {
            return 0xffffffff;
          }
          uVar7 = 0x800;
        }
        pvVar5 = operator_new(0x60);
        if (pvVar5 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          uVar6 = FUN_0054fe10();
        }
        *(undefined4 *)(param_1 + 0x868) = uVar6;
        iVar4 = FUN_0054fec0(s_FONTTEX_005dc124,uVar3,uVar7,5,4);
        if (iVar4 == 0) {
          FUN_00543250(0,0,*(undefined4 *)(*(int *)(param_1 + 0x868) + 0x54),0,0,
                       *(undefined4 *)(*piVar1 + 0x1c),*(undefined4 *)(*piVar1 + 0x20),
                       *(undefined4 *)(param_1 + 0x2c),0);
          FUN_00542e50();
          iVar4 = *piVar1;
          if (iVar4 != 0) {
            FUN_00557470();
            FUN_00587bcf(iVar4);
          }
          *piVar1 = *(int *)(*(int *)(param_1 + 0x868) + 0x54);
          if ((param_3 & 0x800) != 0) {
            return 0;
          }
          *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & 0xffffff7f;
          return 0;
        }
      }
    }
  }
  return 0xffffffff;
}


