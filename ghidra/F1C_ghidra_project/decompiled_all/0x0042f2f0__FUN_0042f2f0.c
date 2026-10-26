// Function: FUN_0042f2f0 @ 0042f2f0
// Strings:  [%.1f %s, %d %s]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0042f2f0(int param_1,int param_2,int param_3)

{
  double *pdVar1;
  double dVar2;
  undefined4 local_14;
  
  pdVar1 = (double *)((param_2 * 0xb + param_3) * 0x40 + 0xb0 + param_1);
  switch(param_3) {
  case 0:
    param_1 = param_1 + 0x28;
    dVar2 = ((double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1) * _DAT_0059ea30;
    break;
  case 1:
    dVar2 = (double)*(int *)((int)pdVar1 + 0x14) * pdVar1[1] + *pdVar1;
    if (*(int *)(param_1 + 4) == 0) {
      FUN_0058815f((int)pdVar1 + 0x1e,s__d__s_005c3778,(int)ROUND(dVar2),param_1 + 8);
      return;
    }
    param_1 = param_1 + 8;
    dVar2 = dVar2 * _DAT_0059ea28;
    break;
  case 2:
    local_14 = 0;
    if (param_2 == 1) {
      local_14 = 0xbfe00000;
    }
    else if (param_2 == 2) {
      local_14 = 0x3fe00000;
    }
    FUN_0042f260(pdVar1,0,local_14);
    return;
  case 3:
  case 9:
    FUN_0042f260(pdVar1,0,0);
    return;
  case 4:
    FUN_0042f180(pdVar1);
    return;
  case 5:
  case 6:
  case 7:
  case 8:
    FUN_0042f1e0(pdVar1);
    return;
  case 10:
    FUN_0058815f((int)pdVar1 + 0x1e,&DAT_005c3280,*(int *)((int)pdVar1 + 0x14) + 1);
    return;
  default:
    return;
  }
  FUN_0058815f((int)pdVar1 + 0x1e,s___1f__s_005c36f4,dVar2,param_1);
  return;
}


