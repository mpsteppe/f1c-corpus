// Function: FUN_00477280 @ 00477280
// Size (bytes): 273


void __thiscall FUN_00477280(int param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  
  if ((*(int *)(param_1 + 0x9c) != 0) && (*(int *)(param_2 + 0x9c) != 0)) {
    pbVar7 = *(byte **)(*(int *)(param_1 + 0x9c) + 0x34);
    if (pbVar7 == (byte *)0x0) {
      pbVar7 = &DAT_005ea438;
    }
    pbVar2 = *(byte **)(*(int *)(param_2 + 0x9c) + 0x34);
    if (pbVar2 == (byte *)0x0) {
      pbVar2 = &DAT_005ea438;
    }
    do {
      bVar1 = *pbVar2;
      bVar8 = bVar1 < *pbVar7;
      if (bVar1 != *pbVar7) {
LAB_004772e8:
        iVar3 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        goto LAB_004772ed;
      }
      if (bVar1 == 0) break;
      bVar1 = pbVar2[1];
      bVar8 = bVar1 < pbVar7[1];
      if (bVar1 != pbVar7[1]) goto LAB_004772e8;
      pbVar2 = pbVar2 + 2;
      pbVar7 = pbVar7 + 2;
    } while (bVar1 != 0);
    iVar3 = 0;
LAB_004772ed:
    if (iVar3 == 0) {
      iVar3 = 0;
      if (0 < *(int *)(param_1 + 0xfc)) {
        do {
          if ((-1 < iVar3) && (iVar3 < *(int *)(param_1 + 0xfc))) {
            piVar5 = *(int **)(param_1 + 0xf0);
            for (iVar6 = iVar3; 0 < iVar6; iVar6 = iVar6 + -1) {
              if (piVar5 == (int *)0x0) goto LAB_0047733b;
              piVar5 = (int *)piVar5[1];
            }
            if (((piVar5 != (int *)0x0) && (*piVar5 != 0)) && (*(int *)(*piVar5 + 0x30) == param_2))
            {
              FUN_0048fdb0(param_2);
              return;
            }
          }
LAB_0047733b:
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(param_1 + 0xfc));
      }
      pvVar4 = operator_new(0x34);
      if (pvVar4 == (void *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)FUN_0048fd60();
      }
      FUN_0048fdb0(param_2);
      (**(code **)(*piVar5 + 0x10))(0);
      FUN_0048f5d0(piVar5,1);
      FUN_0048f640();
    }
  }
  return;
}


