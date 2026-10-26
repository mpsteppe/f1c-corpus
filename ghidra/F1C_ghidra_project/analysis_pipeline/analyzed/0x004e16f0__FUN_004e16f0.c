// Function: FUN_004e16f0 @ 004e16f0
// Size (bytes): 206


void __thiscall FUN_004e16f0(int param_1,float *param_2,float *param_3,undefined4 param_4)

{
  float *pfVar1;
  int local_10;
  float local_c;
  float local_8;
  float local_4;
  
  if (DAT_008aceb8 != 0) {
    pfVar1 = (float *)(param_1 + 0x998);
    local_10 = 0x11;
    do {
      if (*(char *)(pfVar1 + -2) != '\0') {
        local_c = *param_2 * pfVar1[-1] + param_2[2] * pfVar1[1] + param_2[1] * *pfVar1 + *param_3;
        local_8 = param_2[3] * pfVar1[-1] + param_2[5] * pfVar1[1] + param_2[4] * *pfVar1 +
                  param_3[1];
        local_4 = param_2[6] * pfVar1[-1] + param_2[8] * pfVar1[1] + param_2[7] * *pfVar1 +
                  param_3[2];
        FUN_004cce90(&local_c,*(char *)(pfVar1 + -2),pfVar1 + 2,*(undefined1 *)((int)pfVar1 + -7),
                     param_4);
      }
      pfVar1 = pfVar1 + 7;
      local_10 = local_10 + -1;
    } while (local_10 != 0);
  }
  return;
}


