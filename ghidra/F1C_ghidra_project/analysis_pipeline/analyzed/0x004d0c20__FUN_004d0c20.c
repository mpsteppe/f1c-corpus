// Function: FUN_004d0c20 @ 004d0c20
// Size (bytes): 206


uint FUN_004d0c20(byte *param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  bool bVar7;
  
  uVar5 = (uint)*param_1;
  uVar4 = (uint)*param_2;
  if (*(int *)(&DAT_005f073c + uVar5 * 0x48c0) == 3) {
    if (*(int *)(&DAT_005f073c + uVar4 * 0x48c0) != 3) {
      return 1;
    }
    iVar1 = (&DAT_005f0738)[uVar4 * 0x1230];
    iVar2 = (&DAT_005f0738)[uVar5 * 0x1230];
    bVar7 = SBORROW4(iVar2,iVar1);
    iVar3 = iVar2 - iVar1;
    bVar6 = iVar2 == iVar1;
    if (iVar2 < iVar1) {
      return 0xffffffff;
    }
  }
  else {
    if (*(int *)(&DAT_005f073c + uVar4 * 0x48c0) == 3) {
      return 0xffffffff;
    }
    if (DAT_0059e440 <= (float)(&DAT_005f0774)[uVar4 * 0x1230]) {
      if (DAT_0059e440 > (float)(&DAT_005f0774)[uVar5 * 0x1230]) {
        return 1;
      }
      if ((float)(&DAT_005f0774)[uVar5 * 0x1230] < (float)(&DAT_005f0774)[uVar4 * 0x1230]) {
        return 0xffffffff;
      }
      if ((float)(&DAT_005f0774)[uVar4 * 0x1230] < (float)(&DAT_005f0774)[uVar5 * 0x1230]) {
        return 1;
      }
    }
    else if (DAT_0059e440 <= (float)(&DAT_005f0774)[uVar5 * 0x1230]) {
      return 0xffffffff;
    }
    iVar1 = (&DAT_005f0738)[uVar4 * 0x1230];
    iVar2 = (&DAT_005f0738)[uVar5 * 0x1230];
    bVar7 = SBORROW4(iVar2,iVar1);
    iVar3 = iVar2 - iVar1;
    bVar6 = iVar2 == iVar1;
    if (iVar2 < iVar1) {
      return 0xffffffff;
    }
  }
  if (!bVar6 && bVar7 == iVar3 < 0) {
    return 1;
  }
  if (&DAT_005f070c + uVar5 * 0x48c0 < &DAT_005f070c + uVar4 * 0x48c0) {
    return 0xffffffff;
  }
  return (uint)(&DAT_005f070c + uVar4 * 0x48c0 < &DAT_005f070c + uVar5 * 0x48c0);
}


