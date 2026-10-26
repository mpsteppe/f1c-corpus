// Function: FUN_0059bcfc @ 0059bcfc
// Size (bytes): 237


uint FUN_0059bcfc(uint param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  short sVar7;
  
  piVar3 = param_2;
  uVar2 = param_1;
  sVar7 = (short)param_1;
  if (sVar7 == -1) {
    return 0xffff;
  }
  uVar1 = param_2[3];
  if ((uVar1 & 1) == 0) {
    if ((uVar1 & 0x80) == 0) {
      return 0xffff;
    }
    if ((uVar1 & 2) != 0) {
      return 0xffff;
    }
  }
  if (param_2[2] == 0) {
    FUN_005957bd(param_2);
  }
  if ((piVar3[3] & 0x40U) == 0) {
    uVar1 = piVar3[4];
    if (uVar1 == 0xffffffff) {
      puVar6 = &DAT_005e7898;
    }
    else {
      puVar6 = (undefined *)((&DAT_008d4920)[(int)uVar1 >> 5] + (uVar1 & 0x1f) * 0x24);
    }
    if ((puVar6[4] & 0x80) != 0) {
      iVar4 = FUN_00596030(&param_1,uVar2);
      if (iVar4 == -1) {
        puVar5 = (undefined4 *)FUN_0058afcf();
        *puVar5 = 0x2a;
        return 0xffff;
      }
      if (*piVar3 == piVar3[2]) {
        if (piVar3[1] != 0) {
          return 0xffff;
        }
        *piVar3 = *piVar3 + iVar4;
      }
      if (iVar4 != 1) {
        *piVar3 = *piVar3 + -1;
        *(undefined1 *)*piVar3 = param_1._1_1_;
      }
      *piVar3 = *piVar3 + -1;
      *(undefined1 *)*piVar3 = (undefined1)param_1;
      piVar3[1] = piVar3[1] + iVar4;
      piVar3[3] = piVar3[3] & 0xffffffefU | 1;
      return uVar2 & 0xffff;
    }
  }
  if (*piVar3 == piVar3[2]) {
    if (piVar3[1] != 0) {
      return 0xffff;
    }
    *piVar3 = *piVar3 + 2;
  }
  piVar3[1] = piVar3[1] + 2;
  *piVar3 = *piVar3 + -2;
  piVar3[3] = piVar3[3] & 0xffffffefU | 1;
  *(short *)*piVar3 = sVar7;
  return (uint)*(ushort *)*piVar3;
}


