// Function: FUN_0053f3f0 @ 0053f3f0
// Strings:  [Invalid parameters]


undefined4 __thiscall FUN_0053f3f0(int *param_1,uint *param_2,int param_3,int param_4,uint param_5)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_c;
  int local_8;
  uint local_4;
  
  puVar2 = param_2;
  if ((param_5 & 0x20) == 0) {
    if ((param_5 & 0x100) == 0) {
      if ((param_5 & 0x40) == 0) {
        if ((param_5 & 0x400) == 0) {
          local_c = param_5 >> 0x10 & 0x10;
        }
        else {
          local_c = 6;
        }
      }
      else {
        local_c = 4;
      }
    }
    else {
      local_c = 3;
    }
  }
  else {
    local_c = 2;
  }
  if (param_2 == (uint *)0x0) {
    FUN_0055c650(&param_5,*(undefined4 *)(param_3 + 0x30),0);
    if (param_5 == 0x15) {
      param_5 = 0x16;
    }
    else if (param_5 == 0x19) {
      param_5 = 0x18;
    }
    local_c = 0;
    local_4 = 0;
  }
  else {
    local_4 = param_2[0x41];
    iVar3 = FUN_0055bde0(param_2[0x46]);
    FUN_0055c650(&param_5,*(undefined4 *)(iVar3 + 0x14),0);
    FUN_0055c450(param_5,&local_8,0);
    if (local_8 == 0x10) {
      uVar1 = *puVar2;
      if ((uVar1 & 0x1000000) == 0) {
        if ((uVar1 & 0x4000000) == 0) {
          if ((uVar1 & 0x2000000) != 0) {
            param_5 = 0x19;
          }
        }
        else {
          param_5 = 0x18;
        }
      }
      else {
        param_5 = 0x17;
      }
    }
    else if ((local_8 == 0x18) || (local_8 == 0x20)) {
      uVar1 = *puVar2;
      if ((uVar1 & 0x8000000) == 0) {
        if ((uVar1 & 0x20000000) == 0) {
          if ((uVar1 & 0x10000000) != 0) {
            param_5 = 0x15;
          }
        }
        else {
          param_5 = 0x16;
        }
      }
      else {
        param_5 = 0x14;
      }
    }
  }
  FUN_0055c650(&param_2,*(undefined4 *)(param_3 + 0x30),0);
  if (param_2 == (uint *)0x15) {
    param_2 = (uint *)0x16;
  }
  else if (param_2 == (uint *)0x19) {
    param_2 = (uint *)0x18;
  }
  if (puVar2 != (uint *)0x0) {
    FUN_0055c450(param_2,&local_8,0);
    if (local_8 == 0x10) {
      uVar1 = *puVar2;
      if ((uVar1 & 0x1000000) == 0) {
        if ((uVar1 & 0x4000000) == 0) {
          if ((uVar1 & 0x2000000) != 0) {
            param_2 = (uint *)0x19;
          }
        }
        else {
          param_2 = (uint *)0x18;
        }
      }
      else {
        param_2 = (uint *)0x17;
      }
    }
    else if ((local_8 == 0x18) || (local_8 == 0x20)) {
      uVar1 = *puVar2;
      if ((uVar1 & 0x8000000) == 0) {
        if ((uVar1 & 0x20000000) == 0) {
          if ((uVar1 & 0x10000000) != 0) {
            param_2 = (uint *)0x15;
          }
        }
        else {
          param_2 = (uint *)0x16;
        }
      }
      else {
        param_2 = (uint *)0x14;
      }
    }
  }
  iVar3 = param_4;
  iVar5 = 0;
  iVar6 = param_3;
  do {
    if (iVar5 == 0) {
      iVar6 = 0x47;
    }
    else if (iVar5 == 1) {
      iVar6 = 0x4d;
    }
    else if (iVar5 == 2) {
      iVar6 = 0x50;
    }
    iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x28))
                      ((int *)param_1[0x43f],local_4,1,param_5,2,1,iVar6);
    *param_1 = iVar4;
    if (iVar4 == 0) {
      iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x30))
                        ((int *)param_1[0x43f],local_4,1,param_5,param_2,iVar6);
      *param_1 = iVar4;
      if (iVar4 == 0) {
        iVar4 = (**(code **)(*(int *)param_1[0x440] + 0x68))
                          ((int *)param_1[0x440],*(undefined4 *)(param_3 + 0x1c),
                           *(undefined4 *)(param_3 + 0x20),iVar6,local_c,iVar3 + 0xc);
        *param_1 = iVar4;
        if (iVar4 == 0) {
          *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) | 2;
          return 0;
        }
      }
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  FUN_0053c590(0xffffffff,s_Invalid_parameters_005dbcd0);
  return 0xffffffff;
}


