// Function: FUN_0053f720 @ 0053f720
// Strings:  [%s - 0x%x, %s - 0x%x, %s - 0x%x, Could not allocate DirectDraw surface, Could not allocate DirectDraw surface, Could not allocate DirectDraw surface]


undefined4 __thiscall FUN_0053f720(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined8 uVar5;
  int iVar6;
  int local_10c;
  int iStack_108;
  undefined4 local_104;
  undefined1 auStack_100 [256];
  
  iVar6 = *(int *)(param_2 + 0x30);
  iVar1 = param_1[0x443];
  local_104 = 0;
  if (iVar6 == 7) {
    iVar6 = 8;
  }
  FUN_0055c650(&local_10c,iVar6,0);
  if ((*(uint *)(param_2 + 0x18) & 0x10) != 0) {
    if (local_10c == 0x15) {
      local_10c = 0x16;
    }
    else if (local_10c == 0x19) {
      local_10c = 0x18;
    }
  }
  if ((*(uint *)(param_2 + 0x18) & 1) != 0) {
    iVar6 = (**(code **)(*(int *)param_1[0x440] + 0x6c))
                      ((int *)param_1[0x440],*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),local_10c,param_2 + 8);
    *param_1 = iVar6;
    if (iVar6 != 0) goto LAB_0053fb31;
  }
  if ((*(uint *)(param_2 + 0x18) & 2) != 0) {
    if ((*(uint *)(param_2 + 0x18) & 0x40000) != 0) {
      if (*(int *)(param_2 + 0x24) == 0x20) {
        local_10c = param_1[0x4fb];
      }
      else {
        local_10c = iVar1;
        if (*(int *)(param_2 + 0x24) == 0x10) {
          local_10c = param_1[0x4fa];
        }
      }
      iStack_108 = *(int *)param_1[0x43f];
      uVar5 = FUN_0055bfc0(1,iVar1,1,1,local_10c);
      iVar6 = (**(code **)(iStack_108 + 0x28))((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      *param_1 = iVar6;
      if (iVar6 != 0) {
        FUN_0058815f(auStack_100,s__s___0x_x_005dbd0c,s_Could_not_allocate_DirectDraw_su_005dbd18,
                     iVar6);
        FUN_0053c590(0xffffffff,auStack_100);
        return 0xffffffff;
      }
    }
    iVar6 = (**(code **)(*(int *)param_1[0x440] + 100))
                      ((int *)param_1[0x440],*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),local_10c,0,0,param_2 + 0xc);
    *param_1 = iVar6;
    if (iVar6 != 0) goto LAB_0053f876;
  }
  if ((*(uint *)(param_2 + 0x18) & 0x40008) != 0) {
    if (*(int *)(param_2 + 0x24) == 0x20) {
      local_10c = param_1[0x4fb];
    }
    else {
      local_10c = iVar1;
      if (*(int *)(param_2 + 0x24) == 0x10) {
        local_10c = param_1[0x4fa];
      }
    }
    iStack_108 = *(int *)param_1[0x43f];
    uVar5 = FUN_0055bfc0(1,iVar1,1,3,local_10c);
    iVar6 = (**(code **)(iStack_108 + 0x28))((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
    *param_1 = iVar6;
    if (iVar6 != 0) {
      local_104 = 0;
      if (*(int *)(param_2 + 0x24) == 0x20) {
        local_10c = param_1[0x4fa];
      }
      else {
        local_10c = iVar1;
        if (*(int *)(param_2 + 0x24) == 0x10) {
          local_10c = param_1[0x4fb];
        }
      }
      iStack_108 = *(int *)param_1[0x43f];
      uVar5 = FUN_0055bfc0(1,iVar1,1,3,local_10c);
      iVar6 = (**(code **)(iStack_108 + 0x28))((int)((ulonglong)uVar5 >> 0x20),(int)uVar5);
      *param_1 = iVar6;
      if (iVar6 != 0) {
        if (local_10c == 0) {
          iVar6 = *(int *)(param_2 + 0x24);
          if (iVar6 == 0x10) {
            uVar2 = param_1[0x4ea];
            if ((uVar2 & 0x1000000) == 0) {
              if ((uVar2 & 0x4000000) == 0) {
                if ((uVar2 & 0x2000000) != 0) {
                  local_10c = 0x19;
                }
              }
              else {
                local_10c = 0x18;
              }
            }
            else {
              local_10c = 0x17;
            }
          }
          else if ((iVar6 == 0x18) || (iVar6 == 0x20)) {
            uVar2 = param_1[0x4ea];
            if ((uVar2 & 0x8000000) == 0) {
              if ((uVar2 & 0x20000000) == 0) {
                if ((uVar2 & 0x10000000) != 0) {
                  local_10c = 0x15;
                }
              }
              else {
                local_10c = 0x16;
              }
            }
            else {
              local_10c = 0x14;
            }
          }
        }
        *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffbfff7 | 4;
        FUN_0055c450(local_10c,0,param_2 + 0x30);
        goto LAB_0053fa44;
      }
    }
    *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) | 0x80400;
    param_3 = 1;
    local_104 = 1;
    FUN_0055c450(local_10c,0,param_2 + 0x30);
  }
LAB_0053fa44:
  if ((*(byte *)(param_2 + 0x18) & 8) != 0) {
    iVar6 = param_3;
    if (param_3 == 0) {
      iVar6 = 1;
    }
    iVar6 = (**(code **)(*(int *)param_1[0x440] + 0x50))
                      ((int *)param_1[0x440],*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),iVar6,local_104,local_10c,0,param_2 + 0x14);
    *param_1 = iVar6;
    if (iVar6 == 0) {
      if (((*(uint *)(param_2 + 0x18) & 0x40000) != 0) &&
         ((*(uint *)(param_2 + 0x18) & 0x200000) == 0)) {
        pvVar3 = operator_new(0x3c);
        if (pvVar3 == (void *)0x0) {
          uVar4 = 0;
        }
        else {
          uVar4 = FUN_005426a0();
        }
        *(undefined4 *)(param_2 + 4) = uVar4;
        iVar6 = FUN_0053f3f0(0,param_2,uVar4,0);
        if (iVar6 != 0) {
          return 0;
        }
        FUN_005404d0(param_2,0,0,*(undefined4 *)(param_2 + 0x1c),*(undefined4 *)(param_2 + 0x20),0);
      }
    }
    else {
      if ((*(uint *)(param_2 + 0x18) & 0x40000) == 0) {
LAB_0053f876:
        FUN_0058815f(auStack_100,s__s___0x_x_005dbd0c,s_Could_not_allocate_DirectDraw_su_005dbd18,
                     iVar6);
        FUN_0053c590(0xffffffff,auStack_100);
        return 0xffffffff;
      }
      *(uint *)(param_2 + 0x18) = *(uint *)(param_2 + 0x18) & 0xfffbfff7 | 4;
    }
  }
  if ((*(byte *)(param_2 + 0x18) & 4) != 0) {
    if (param_3 == 0) {
      param_3 = 1;
    }
    iVar6 = (**(code **)(*(int *)param_1[0x440] + 0x50))
                      ((int *)param_1[0x440],*(undefined4 *)(param_2 + 0x1c),
                       *(undefined4 *)(param_2 + 0x20),param_3,0,local_10c,2,param_2 + 0x10);
    *param_1 = iVar6;
    if (iVar6 != 0) {
LAB_0053fb31:
      FUN_0058815f(auStack_100,s__s___0x_x_005dbd0c,s_Could_not_allocate_DirectDraw_su_005dbd18,
                   iVar6);
      FUN_0053c590(0xffffffff,auStack_100);
      return 0xffffffff;
    }
  }
  return 0;
}


