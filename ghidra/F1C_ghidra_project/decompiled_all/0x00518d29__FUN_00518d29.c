// Function: FUN_00518d29 @ 00518d29
// Strings:  [Ignoring incorrect gAMA value when sRGB is also present, Duplicate sRGB chunk, Out of place sRGB chunk, Invalid sRGB after IDAT, Incorrect sRGB chunk length, Missing IHDR before sRGB]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00518d29(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = param_1;
  uVar1 = *(uint *)(param_1 + 0x58);
  if ((uVar1 & 1) == 0) {
    FUN_00511869(param_1,"Missing IHDR before sRGB");
  }
  else {
    if ((uVar1 & 4) != 0) {
      pcVar4 = "Invalid sRGB after IDAT";
      goto LAB_00518d4f;
    }
    if ((uVar1 & 2) == 0) {
      if ((param_2 != 0) && ((*(byte *)(param_2 + 9) & 8) != 0)) {
        pcVar4 = "Duplicate sRGB chunk";
        goto LAB_00518d4f;
      }
    }
    else {
      FUN_00511887(param_1,"Out of place sRGB chunk");
    }
  }
  if (param_3 == 1) {
    FUN_00517f58(uVar2,(int)&param_1 + 3,1);
    iVar3 = FUN_00518828(uVar2,0);
    if (iVar3 != 0) {
      return;
    }
    uVar1 = param_1 >> 0x18;
    if (3 < uVar1) {
      FUN_00511887(uVar2,"Unknown sRGB intent");
      return;
    }
    if (((*(byte *)(param_2 + 8) & 1) != 0) &&
       ((float)_DAT_005afd68 <
        ABS((*(float *)(uVar2 + 0x130) * _DAT_005afdf8 + (float)_DAT_0059e880) -
            (float)_DAT_005afd70))) {
      FUN_00511887(uVar2,"Ignoring incorrect gAMA value when sRGB is also present");
    }
    FUN_00513b51(uVar2,param_2,uVar1);
    return;
  }
  pcVar4 = "Incorrect sRGB chunk length";
LAB_00518d4f:
  FUN_00511887(uVar2,pcVar4);
  FUN_00518828(uVar2,param_3);
  return;
}


