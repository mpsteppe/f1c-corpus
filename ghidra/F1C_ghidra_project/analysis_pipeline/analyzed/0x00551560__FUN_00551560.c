// Function: FUN_00551560 @ 00551560
// Size (bytes): 506


undefined4 __thiscall FUN_00551560(int param_1,int param_2)

{
  byte bVar1;
  void *pvVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  byte *pbVar11;
  bool bVar12;
  undefined4 *local_10;
  int local_4;
  
  iVar7 = *(int *)(param_1 + 0x13c);
  if (*(int *)(param_1 + 0x130) == 0) {
    if (iVar7 == 0) {
      pvVar2 = operator_new(0x28);
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
        *(undefined4 *)(param_1 + 0x13c) = 0;
      }
      else {
        iVar3 = FUN_005510f0(1);
        *(int *)(param_1 + 0x13c) = iVar3;
      }
    }
    else {
      for (iVar3 = *(int *)(iVar7 + 0x24); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {
        iVar7 = iVar3;
      }
      pvVar2 = operator_new(0x28);
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_005510f0(1);
      }
      *(int *)(iVar7 + 0x24) = iVar3;
    }
    *(undefined4 *)(iVar3 + 0x14) = 1;
    **(undefined4 **)(iVar3 + 0x18) = 0;
  }
  else {
    if (iVar7 == 0) {
      pvVar2 = operator_new(0x28);
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
        *(undefined4 *)(param_1 + 0x13c) = 0;
      }
      else {
        iVar3 = FUN_005510f0(*(undefined4 *)(param_1 + 0x130));
        *(int *)(param_1 + 0x13c) = iVar3;
      }
    }
    else {
      for (iVar3 = *(int *)(iVar7 + 0x24); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x24)) {
        iVar7 = iVar3;
      }
      pvVar2 = operator_new(0x28);
      if (pvVar2 == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = FUN_005510f0(*(undefined4 *)(param_1 + 0x130));
      }
      *(int *)(iVar7 + 0x24) = iVar3;
    }
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(param_1 + 0x130);
    puVar8 = *(undefined4 **)(param_1 + 0x134);
    puVar10 = *(undefined4 **)(iVar3 + 0x18);
    for (uVar6 = (uint)(*(int *)(param_1 + 0x130) * 0x88) >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    for (iVar7 = 0; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar10 = *(undefined1 *)puVar8;
      puVar8 = (undefined4 *)((int)puVar8 + 1);
      puVar10 = (undefined4 *)((int)puVar10 + 1);
    }
    local_10 = *(undefined4 **)(iVar3 + 0x18);
    local_4 = 0;
    if (0 < *(int *)(param_1 + 0x130)) {
      do {
        pbVar11 = *(byte **)(param_2 + 0x10);
        iVar7 = 0;
        if (0 < *(int *)(param_2 + 0xc)) {
          do {
            pbVar4 = (byte *)(local_10 + 0x11);
            pbVar9 = pbVar11;
            do {
              bVar1 = *pbVar4;
              bVar12 = bVar1 < *pbVar9;
              if (bVar1 != *pbVar9) {
LAB_005516e4:
                iVar5 = (1 - (uint)bVar12) - (uint)(bVar12 != 0);
                goto LAB_005516e9;
              }
              if (bVar1 == 0) break;
              bVar1 = pbVar4[1];
              bVar12 = bVar1 < pbVar9[1];
              if (bVar1 != pbVar9[1]) goto LAB_005516e4;
              pbVar4 = pbVar4 + 2;
              pbVar9 = pbVar9 + 2;
            } while (bVar1 != 0);
            iVar5 = 0;
LAB_005516e9:
            if (iVar5 == 0) {
              *local_10 = *(undefined4 *)(pbVar11 + 0x20);
              break;
            }
            pbVar11 = pbVar11 + 0x2c;
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(param_2 + 0xc));
        }
        if (iVar7 == *(int *)(param_2 + 0xc)) {
          *local_10 = 0xffffffff;
        }
        local_10 = local_10 + 0x22;
        local_4 = local_4 + 1;
      } while (local_4 < *(int *)(param_1 + 0x130));
    }
  }
  *(int *)(iVar3 + 0x1c) = param_2;
  FUN_00551440();
  return 0;
}


