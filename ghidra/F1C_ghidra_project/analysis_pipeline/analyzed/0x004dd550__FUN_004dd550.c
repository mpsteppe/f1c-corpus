// Function: FUN_004dd550 @ 004dd550
// Size (bytes): 332


void __fastcall FUN_004dd550(undefined4 param_1,float *param_2,float *param_3)

{
  uint uVar1;
  float *pfVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float *pfVar6;
  int iVar7;
  
  pfVar2 = param_3;
  iVar3 = FUN_004dd4e0();
  *param_2 = 3.4028235e+38;
  param_2[1] = 3.4028235e+38;
  param_2[2] = 3.4028235e+38;
  *param_3 = -3.4028235e+38;
  param_3[1] = -3.4028235e+38;
  param_3[2] = -3.4028235e+38;
  iVar4 = FUN_0054c210();
  param_3 = (float *)0x0;
  if (0 < iVar4) {
    do {
      iVar5 = FUN_0054c230(param_3);
      if (*(float *)(iVar5 + 0xf4) == DAT_0059e440) {
        uVar1 = *(uint *)(iVar5 + 0x14);
        if ((uVar1 & 0x2000000) == 0) {
          iVar5 = 4 - (uint)((uVar1 & 0x40) != 0);
        }
        else {
          iVar5 = 2 - (uint)((uVar1 & 0x40) != 0);
        }
      }
      else {
        iVar5 = 0;
      }
      if (iVar3 <= iVar5) {
        iVar5 = FUN_0054e100();
        iVar7 = 0;
        if (0 < iVar5) {
          do {
            pfVar6 = (float *)FUN_0054e120(iVar7);
            if (*pfVar6 < *param_2) {
              *param_2 = *pfVar6;
            }
            if (pfVar6[1] < param_2[1]) {
              param_2[1] = pfVar6[1];
            }
            if (pfVar6[2] < param_2[2]) {
              param_2[2] = pfVar6[2];
            }
            if (*pfVar2 < *pfVar6) {
              *pfVar2 = *pfVar6;
            }
            if (pfVar2[1] < pfVar6[1]) {
              pfVar2[1] = pfVar6[1];
            }
            if (pfVar2[2] < pfVar6[2]) {
              pfVar2[2] = pfVar6[2];
            }
            iVar7 = iVar7 + 1;
          } while (iVar7 < iVar5);
        }
      }
      param_3 = (float *)((int)param_3 + 1);
    } while ((int)param_3 < iVar4);
  }
  return;
}


