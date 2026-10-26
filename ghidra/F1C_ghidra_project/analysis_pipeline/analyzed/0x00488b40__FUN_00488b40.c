// Function: FUN_00488b40 @ 00488b40
// Size (bytes): 119


undefined4 __thiscall FUN_00488b40(int *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  bool bVar5;
  
  if (param_2 == (byte *)0x0) {
    return 0xffffffff;
  }
  pbVar2 = (byte *)param_1[0x2c];
  pbVar3 = param_2;
  if (pbVar2 == (byte *)0x0) {
    pbVar2 = &DAT_005ea438;
  }
  do {
    bVar1 = *pbVar3;
    bVar5 = bVar1 < *pbVar2;
    if (bVar1 != *pbVar2) {
LAB_00488b94:
      iVar4 = (1 - (uint)bVar5) - (uint)(bVar5 != 0);
      goto LAB_00488b99;
    }
    if (bVar1 == 0) break;
    bVar1 = pbVar3[1];
    bVar5 = bVar1 < pbVar2[1];
    if (bVar1 != pbVar2[1]) goto LAB_00488b94;
    pbVar2 = pbVar2 + 2;
    pbVar3 = pbVar3 + 2;
  } while (bVar1 != 0);
  iVar4 = 0;
LAB_00488b99:
  if (iVar4 != 0) {
    FUN_00566650(param_2);
    (**(code **)(*param_1 + 0x2c))(1);
  }
  return 0;
}


