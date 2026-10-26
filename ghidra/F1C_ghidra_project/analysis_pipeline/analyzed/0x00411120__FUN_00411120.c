// Function: FUN_00411120 @ 00411120
// Size (bytes): 513


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00411120(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x24)) {
    do {
      FUN_0040f300((float)_DAT_008afea0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x24));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x30)) {
    do {
      FUN_0040f300((float)_DAT_008afea0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x30));
  }
  iVar4 = 0;
  if (0 < *(int *)(param_1 + 0x3c)) {
    do {
      FUN_0040f300((float)_DAT_008afea0);
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(param_1 + 0x3c));
  }
  uVar5 = 0;
  if (0 < *(int *)(param_1 + 0x48)) {
    iVar4 = 0;
    do {
      if ((iVar4 < 0x3a80) &&
         (iVar1 = (int)(uVar5 + ((int)uVar5 >> 0x1f & 3U)) >> 2,
         (&DAT_005ef9a0)[iVar1 * 0x1230] != -1)) {
        uVar3 = uVar5 & 0x80000003;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
        }
        if (((&DAT_005ecf0c)[iVar1 * 0x1230 + uVar3 * 0x4a] == 0) ||
           ((char)(&DAT_005ecf0c + iVar1 * 0x1230 + uVar3 * 0x4a)[0x10] == '\0')) goto LAB_0041120f;
      }
      else {
LAB_0041120f:
        FUN_0040f300((float)_DAT_008afea0);
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x24;
    } while ((int)uVar5 < *(int *)(param_1 + 0x48));
  }
  uVar5 = 0;
  if (0 < *(int *)(param_1 + 0x54)) {
    iVar4 = 0;
    do {
      if (iVar4 < 0x1d40) {
        iVar1 = (int)uVar5 / 2;
        uVar3 = uVar5 & 0x80000001;
        bVar6 = uVar3 == 0;
        if ((int)uVar3 < 0) {
          bVar6 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
        }
        if (!bVar6) {
          if ((&DAT_005ed3f0)[iVar1 * 0x1230] != 0) {
            cVar2 = (&DAT_005ed430)[iVar1 * 0x48c0];
            goto LAB_0041128d;
          }
          goto LAB_00411291;
        }
        if ((&DAT_005ed3ac)[iVar1 * 0x1230] == 0) goto LAB_00411291;
        cVar2 = (&DAT_005ed3ec)[iVar1 * 0x48c0];
LAB_0041128d:
        if (cVar2 == '\0') goto LAB_00411291;
      }
      else {
LAB_00411291:
        FUN_0040f300((float)_DAT_008afea0);
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x24;
    } while ((int)uVar5 < *(int *)(param_1 + 0x54));
  }
  uVar5 = 0;
  if (0 < *(int *)(param_1 + 0x60)) {
    iVar4 = 0;
    do {
      if (iVar4 < 0x7500) {
        uVar3 = uVar5 & 0x80000007;
        if ((int)uVar3 < 0) {
          uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
        }
        if (((&DAT_005ed434)
             [((int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3) * 0x1230 + uVar3 * 0x11] == 0) ||
           ((char)(&DAT_005ed434 +
                  ((int)(uVar5 + ((int)uVar5 >> 0x1f & 7U)) >> 3) * 0x1230 + uVar3 * 0x11)[0x10] ==
            '\0')) goto LAB_004112fe;
      }
      else {
LAB_004112fe:
        FUN_0040f300((float)_DAT_008afea0);
      }
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x24;
    } while ((int)uVar5 < *(int *)(param_1 + 0x60));
  }
  return;
}


