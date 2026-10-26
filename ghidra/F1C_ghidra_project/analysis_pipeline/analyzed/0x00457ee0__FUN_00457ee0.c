// Function: FUN_00457ee0 @ 00457ee0
// Size (bytes): 163


void __fastcall FUN_00457ee0(int *param_1)

{
  float *pfVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_1[1]) {
    do {
      if (iVar2 == 0) {
        *(undefined4 *)(*param_1 + 0x18) = 0;
      }
      else {
        pfVar1 = (float *)(iVar2 * 0x1c + *param_1);
        pfVar1[6] = SQRT((*pfVar1 - pfVar1[-7]) * (*pfVar1 - pfVar1[-7]) +
                         (pfVar1[1] - pfVar1[-6]) * (pfVar1[1] - pfVar1[-6]) +
                         (pfVar1[2] - pfVar1[-5]) * (pfVar1[2] - pfVar1[-5])) + pfVar1[-1];
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_1[1]);
  }
  param_1[2] = *(int *)(iVar2 * 0x1c + -0x3c + *param_1);
  return;
}


