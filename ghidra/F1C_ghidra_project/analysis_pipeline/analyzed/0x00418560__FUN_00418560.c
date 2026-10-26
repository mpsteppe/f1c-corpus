// Function: FUN_00418560 @ 00418560
// Size (bytes): 314


undefined4 __thiscall FUN_00418560(int param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_c;
  
  if ((*param_2 != -1) && (cVar1 = FUN_00418b90(*param_2), cVar1 != '\0')) {
    param_2[1] = *(int *)(&DAT_005bf9b0 + *param_2 * 0x14);
    iVar5 = -1;
    iVar6 = 0;
    iVar2 = FUN_00418b70(*param_2);
    param_2[7] = iVar2;
    iVar4 = 0;
    local_c = 0;
    pfVar3 = (float *)(param_1 + 0x86c);
    do {
      if ((int)pfVar3[5] <= *(int *)(local_c + 0x880 + param_1)) {
        local_c = (-0x86c - param_1) + (int)pfVar3;
        iVar6 = iVar4;
      }
      if (iVar5 < 0) {
        if (*pfVar3 != -1.0) {
          if (*pfVar3 <= (float)param_2[2]) {
            if (((float)param_2[2] != *pfVar3) || (iVar2 <= (int)pfVar3[5])) goto LAB_00418614;
          }
        }
        iVar5 = iVar4;
      }
LAB_00418614:
      iVar4 = iVar4 + 1;
      pfVar3 = pfVar3 + 8;
    } while (iVar4 < 0x14);
    if (-1 < iVar5) {
      if (iVar5 < iVar6) {
        param_1 = iVar6 * 0x20 + 0x864 + param_1;
        iVar6 = iVar6 - iVar5;
        do {
          param_1 = param_1 + -0x20;
          FUN_004145c0(param_1);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      else if ((iVar6 < iVar5) && (iVar6 < iVar5 + -1)) {
        param_1 = iVar6 * 0x20 + 0x864 + param_1;
        iVar6 = (iVar5 + -1) - iVar6;
        do {
          param_1 = param_1 + 0x20;
          FUN_004145c0(param_1);
          iVar6 = iVar6 + -1;
        } while (iVar6 != 0);
      }
      FUN_004145c0(param_2);
      return 1;
    }
  }
  return 0;
}


