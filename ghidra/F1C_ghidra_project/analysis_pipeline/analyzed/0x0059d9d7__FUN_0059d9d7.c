// Function: FUN_0059d9d7 @ 0059d9d7
// Size (bytes): 99


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0059d9d7(undefined4 param_1,undefined4 param_2,float param_3)

{
  int iVar1;
  float fVar2;
  float *pfVar3;
  int unaff_EBX;
  int unaff_ESI;
  
  pfVar3 = (float *)(unaff_EBX + 0x39d4);
  do {
    if (unaff_ESI == 8) {
      fVar2 = pfVar3[0x395] / pfVar3[-1];
      pfVar3 = pfVar3 + 0x395;
    }
    else {
      fVar2 = *pfVar3 / pfVar3[-1];
    }
    fVar2 = fVar2 * *(float *)(unaff_EBX + 0x3a0c) * _DAT_005ad198;
    if (fVar2 < param_3) {
      fVar2 = param_3;
    }
    iVar1 = *(int *)(unaff_EBX + 0x39f8);
    if (unaff_ESI < 8) {
      pfVar3[0x11] = fVar2;
    }
    else {
      pfVar3[10] = fVar2;
    }
    unaff_ESI = unaff_ESI + 1;
    pfVar3 = pfVar3 + 1;
  } while (unaff_ESI <= iVar1);
  FUN_004e6d93();
  return;
}


