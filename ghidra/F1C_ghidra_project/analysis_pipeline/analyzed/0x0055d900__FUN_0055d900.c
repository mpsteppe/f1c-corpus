// Function: FUN_0055d900 @ 0055d900
// Size (bytes): 325


void __fastcall FUN_0055d900(int param_1)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  float unaff_EBX;
  float unaff_ESI;
  float fStack_3c;
  int local_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  undefined1 local_18 [20];
  
  local_38 = *(int *)(param_1 + 4);
  if ((*(byte *)(local_38 + 0x9c) & 0x20) == 0) {
    uVar5 = *(undefined4 *)(DAT_008b8f28 + 0x120);
    (**(code **)(*DAT_008b8f24 + 0x18))(DAT_008b8f28,uVar5,local_38,(short)local_18);
    (**(code **)(*DAT_008b8f24 + 0x14))(uVar5,*(undefined4 *)(param_1 + 4),&local_38);
    sVar1 = (short)ROUND(*(float *)(*(int *)(param_1 + 4) + 0x50) * DAT_0059fec8);
    sVar2 = (short)ROUND(unaff_ESI + fStack_34);
    sVar3 = (short)ROUND(unaff_EBX + fStack_30);
    sVar4 = (short)ROUND(fStack_3c + fStack_2c);
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      iVar7 = 0;
      do {
        *(uint *)(iVar7 + 0x18 + *(int *)(param_1 + 0x20)) =
             CONCAT13((0 < sVar1) * (sVar1 < 0x100) * (char)sVar1 - (0xff < sVar1),
                      CONCAT12((0 < sVar4) * (sVar4 < 0x100) * (char)sVar4 - (0xff < sVar4),
                               CONCAT11((0 < sVar3) * (sVar3 < 0x100) * (char)sVar3 - (0xff < sVar3)
                                        ,(0 < sVar2) * (sVar2 < 0x100) * (char)sVar2 -
                                         (0xff < sVar2))));
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x40;
      } while (iVar6 < *(int *)(param_1 + 8));
      return;
    }
  }
  else {
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 8)) {
      iVar8 = 0;
      iVar7 = 0;
      do {
        *(undefined4 *)(iVar8 + 0x18 + *(int *)(param_1 + 0x20)) =
             *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18 + iVar7);
        iVar6 = iVar6 + 1;
        iVar7 = iVar7 + 0x30;
        iVar8 = iVar8 + 0x40;
      } while (iVar6 < *(int *)(param_1 + 8));
    }
  }
  return;
}


