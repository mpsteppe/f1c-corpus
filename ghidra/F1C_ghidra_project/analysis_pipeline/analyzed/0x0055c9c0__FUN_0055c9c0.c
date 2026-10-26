// Function: FUN_0055c9c0 @ 0055c9c0
// Size (bytes): 118


void __thiscall FUN_0055c9c0(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  float *pfVar2;
  int iVar3;
  
  if (param_1[0x440] != 0) {
    param_1[0x4f9] = param_2;
    iVar3 = 0;
    if (0 < (int)param_1[0x4ec]) {
      pfVar2 = (float *)(param_1 + 0x46e);
      do {
        if (*pfVar2 != (float)param_1[0x4f9]) {
          *pfVar2 = (float)param_1[0x4f9];
          uVar1 = (**(code **)(*(int *)param_1[0x440] + 0xfc))
                            ((int *)param_1[0x440],iVar3,0x13,param_1[0x4f9]);
          *param_1 = uVar1;
        }
        iVar3 = iVar3 + 1;
        pfVar2 = pfVar2 + 0x11;
      } while (iVar3 < (int)param_1[0x4ec]);
    }
  }
  return;
}


