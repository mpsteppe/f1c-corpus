// Function: FUN_0050895d @ 0050895d
// Size (bytes): 235


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_0050895d(int param_1,uint param_2,uint param_3,int param_4)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  byte *extraout_EDX;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (*(int *)(param_1 + 0x1048) != 0) {
    param_4 = FUN_00506ce2(param_4);
  }
  iVar2 = *(int *)(param_1 + 0x2c);
  FUN_00507473();
  if (*(int *)(param_1 + 0x1058) != 0) {
    iVar5 = 0;
    pbVar4 = extraout_EDX;
    do {
      fVar1 = *(float *)(iVar2 + ((param_3 & 3) + (param_2 & 3) * 8) * 4 + (uVar6 & 3) * 4);
      pfVar3 = (float *)(param_4 + iVar5);
      *pbVar4 = (char)(int)ROUND(*(float *)(iVar5 + 0xc + param_4) * _DAT_0059e8d8 + fVar1) << 4 |
                (byte)(int)ROUND((*pfVar3 * _DAT_005adb18 +
                                 pfVar3[1] * _DAT_005adb1c + pfVar3[2] * _DAT_005adb20) *
                                 _DAT_0059e8d8 + fVar1);
      pbVar4 = pbVar4 + 1;
      uVar6 = uVar6 + 1;
      iVar5 = iVar5 + 0x10;
    } while (uVar6 < *(uint *)(param_1 + 0x1058));
  }
  return;
}


