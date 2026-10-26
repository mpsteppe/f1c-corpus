// Function: FUN_004bef60 @ 004bef60
// Size (bytes): 305


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

byte __thiscall FUN_004bef60(int param_1,int param_2,float param_3)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  
  bVar5 = 0;
  if (DAT_007c56a4 != 7) {
    return 0;
  }
  iVar3 = 0;
  piVar2 = (int *)(param_2 + 0x834);
  do {
    if ((*piVar2 == 0) || ((char)piVar2[0x10] == '\0')) {
      return 1;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 0x4a;
  } while (iVar3 < 4);
  if (*(int *)(param_2 + 0x3d6c) == 2) {
    return 2;
  }
  if (DAT_007cea5c == 3) {
    iVar3 = FUN_0042aeb0(*(undefined4 *)(param_2 + 0x403c));
    return (iVar3 < 0) - 1U & 2;
  }
  if ((*(char *)(param_1 + 0x340) != '\0') &&
     (uVar4 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
     fVar1 = ((*(float *)(param_2 + 0x44d0) * _DAT_0059e444) / (float)*(int *)(param_1 + 0x35c)) *
             param_3,
     *(float *)(&DAT_008aae74 + uVar4 * 4) < fVar1 !=
     (*(float *)(&DAT_008aae74 + uVar4 * 4) == fVar1))) {
    bVar5 = 1;
  }
  if (((*(char *)(param_1 + 0x341) != '\0') && (bVar5 != 1)) &&
     (fVar1 = ((_DAT_0059e43c - *(float *)(param_2 + 0x44dc) * _DAT_0059e444) /
              (float)*(int *)(param_1 + 0x35c)) * param_3 * *(float *)(param_1 + 0x344),
     uVar4 = DAT_008aae70 & 0xff, DAT_008aae70 = DAT_008aae70 + 1,
     *(float *)(&DAT_008aae74 + uVar4 * 4) < fVar1 !=
     (*(float *)(&DAT_008aae74 + uVar4 * 4) == fVar1))) {
    bVar5 = 2;
  }
  return bVar5;
}


