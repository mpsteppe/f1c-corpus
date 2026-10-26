// Function: FUN_00587930 @ 00587930
// Size (bytes): 188


void __thiscall FUN_00587930(int param_1,int param_2,int param_3,undefined4 param_4)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar5 = 0;
  if (0 < param_3) {
    do {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x414) + 0x58))();
      bVar1 = *(byte *)(iVar5 + param_2);
      uVar3 = (uint)((*(uint *)(iVar2 + 0x24) & 7) != 0) + (*(uint *)(iVar2 + 0x24) >> 3);
      if (bVar1 == uVar3) {
        puVar7 = (undefined4 *)(iVar5 + 1 + param_2);
        puVar8 = *(undefined4 **)(iVar2 + 0x14);
        for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar8 = *(undefined1 *)puVar7;
          puVar7 = (undefined4 *)((int)puVar7 + 1);
          puVar8 = (undefined4 *)((int)puVar8 + 1);
        }
      }
      iVar6 = iVar5 + 1 + (uint)bVar1;
      iVar5 = iVar6 + 1;
      uVar3 = (uint)*(byte *)(iVar6 + param_2);
      FUN_00587510(iVar5 + param_2,uVar3);
      *(undefined4 *)(iVar2 + 4) = param_4;
      iVar5 = iVar5 + uVar3;
      FUN_00585400(iVar2);
    } while (iVar5 < param_3);
  }
  return;
}


