// Function: FUN_0048e250 @ 0048e250
// Size (bytes): 173


undefined4 __fastcall FUN_0048e250(int *param_1)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  bool bVar6;
  int iVar7;
  undefined4 uVar8;
  
  pbVar5 = (byte *)param_1[0x2c];
  if (pbVar5 == (byte *)0x0) {
    pbVar5 = &DAT_005ea438;
  }
  pbVar2 = (byte *)param_1[0x3a];
  if (pbVar2 == (byte *)0x0) {
    pbVar2 = &DAT_005ea438;
  }
  do {
    bVar1 = *pbVar2;
    bVar6 = bVar1 < *pbVar5;
    if (bVar1 != *pbVar5) {
LAB_0048e29d:
      iVar3 = (1 - (uint)bVar6) - (uint)(bVar6 != 0);
      goto LAB_0048e2a2;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar2[1];
    bVar6 = bVar1 < pbVar5[1];
    if (bVar1 != pbVar5[1]) goto LAB_0048e29d;
    pbVar2 = pbVar2 + 2;
    pbVar5 = pbVar5 + 2;
  } while (bVar1 != 0);
  iVar3 = 0;
LAB_0048e2a2:
  if (iVar3 != 0) {
    (**(code **)(*param_1 + 0xa0))();
    return 0;
  }
  if ((param_1[0x39] == 0) && (param_1[0x38] != 0)) {
    iVar3 = param_1[1];
    iVar7 = param_1[3];
    uVar8 = 0x20;
    uVar4 = FUN_00495150(iVar7,iVar3,0x20);
    FUN_00551cf0(uVar4,iVar7,iVar3,uVar8);
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return 0;
}


