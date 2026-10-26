// Function: FUN_004d1c40 @ 004d1c40
// Size (bytes): 133


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004d1c40(int param_1,int param_2,int param_3,char param_4)

{
  float fVar1;
  float fVar2;
  undefined4 in_EAX;
  undefined3 uVar4;
  int iVar3;
  undefined3 extraout_var;
  uint uVar5;
  ushort uVar6;
  
  uVar4 = (undefined3)((uint)in_EAX >> 8);
  if (param_4 == '\0') {
    uVar5 = (uint)*(byte *)(param_2 + 400 + param_1);
    if ((int)uVar5 < DAT_005c329c) {
      iVar3 = param_3 * 0x1230 + param_2;
      fVar1 = (float)(&DAT_005f0774)[iVar3];
      uVar6 = (ushort)(fVar1 < _DAT_0059e670) << 8 |
              (ushort)(NAN(fVar1) || NAN(_DAT_0059e670)) << 10 |
              (ushort)(fVar1 == _DAT_0059e670) << 0xe;
      if (fVar1 == _DAT_0059e670) {
LAB_004d1cbd:
        return CONCAT22((short)((uint)iVar3 >> 0x10),uVar6);
      }
      fVar1 = (float)(&DAT_005f0774)[iVar3];
      fVar2 = (float)(&DAT_005f0774)[uVar5 * 0x1230 + param_2];
      uVar6 = (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
              (ushort)(fVar2 == fVar1) << 0xe;
      if (fVar2 < fVar1) goto LAB_004d1cbd;
    }
    FUN_00419690(param_2,param_3,uVar5);
    uVar4 = extraout_var;
  }
  *(char *)(param_2 + 400 + param_1) = (char)param_3;
  return CONCAT31(uVar4,1);
}


