// Function: FUN_00518c1e @ 00518c1e
// Strings:  [Ignoring incorrect gAMA value when sRGB is also present, Out of place gAMA chunk, Invalid gAMA after IDAT, Incorrect gAMA chunk length, Missing IHDR before gAMA]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00518c1e(int param_1,int param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_2;
  iVar3 = param_1;
  uVar1 = *(uint *)(param_1 + 0x58);
  if ((uVar1 & 1) == 0) {
    FUN_00511869(param_1,"Missing IHDR before gAMA");
  }
  else {
    if ((uVar1 & 4) != 0) goto LAB_00518c4f;
    if ((uVar1 & 2) == 0) {
      if (((param_2 != 0) && ((*(uint *)(param_2 + 8) & 1) != 0)) &&
         ((*(uint *)(param_2 + 8) & 0x800) == 0)) goto LAB_00518c4f;
    }
    else {
      FUN_00511887(param_1,"Out of place gAMA chunk");
    }
  }
  if (param_3 == 4) {
    FUN_00517f58(iVar3,&param_1,4);
    iVar5 = FUN_00518828(iVar3,0);
    if (iVar5 != 0) {
      return;
    }
    iVar5 = FUN_00517f35();
    if (iVar5 == 0) {
      return;
    }
    if ((*(uint *)(iVar4 + 8) & 0x800) != 0) {
      fVar2 = (float)iVar5;
      if (iVar5 < 0) {
        fVar2 = fVar2 + _DAT_005adb14;
      }
      if ((float)_DAT_005afd68 < ABS(fVar2 - (float)_DAT_005afd70)) {
        FUN_00511887(iVar3,"Ignoring incorrect gAMA value when sRGB is also present");
        return;
      }
    }
    fVar2 = (float)iVar5;
    if (iVar5 < 0) {
      fVar2 = fVar2 + _DAT_005adb14;
    }
    fVar2 = fVar2 * _DAT_005ad260;
    *(float *)(iVar3 + 0x130) = fVar2;
    FUN_00513a56(iVar3,iVar4,(double)fVar2);
    return;
  }
LAB_00518c4f:
  FUN_00511887(iVar3);
  FUN_00518828(iVar3,param_3);
  return;
}


