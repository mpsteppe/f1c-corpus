// Function: FUN_00407f10 @ 00407f10
// Size (bytes): 157


undefined4 __thiscall FUN_00407f10(int param_1,byte *param_2)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  
  if (param_2 != (byte *)0x0) {
    pbVar7 = &DAT_005ea438;
    pbVar3 = param_2;
    do {
      bVar1 = *pbVar3;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_00407f4c:
        iVar4 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_00407f51;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar3[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_00407f4c;
      pbVar3 = pbVar3 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar4 = 0;
LAB_00407f51:
    if (iVar4 != 0) {
      piVar2 = *(int **)(param_1 + 0x18);
      *(int **)(param_1 + 0x20) = piVar2;
      if (piVar2 != (int *)0x0) {
        iVar4 = *piVar2;
        while (iVar4 != 0) {
          if (*(int *)(iVar4 + 0x5c) != -1) {
            uVar5 = FUN_00499e20(param_2);
            iVar6 = FUN_00588410(uVar5);
            if (iVar6 == 0) {
              return *(undefined4 *)(iVar4 + 0x5c);
            }
          }
          if (*(int *)(param_1 + 0x20) != 0) {
            *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
          }
          if (*(int **)(param_1 + 0x20) == (int *)0x0) {
            return 0xffffffff;
          }
          iVar4 = **(int **)(param_1 + 0x20);
        }
      }
    }
  }
  return 0xffffffff;
}


