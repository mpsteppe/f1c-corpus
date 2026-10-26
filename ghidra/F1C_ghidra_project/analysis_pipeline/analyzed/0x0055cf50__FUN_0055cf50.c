// Function: FUN_0055cf50 @ 0055cf50
// Size (bytes): 687


void __thiscall FUN_0055cf50(undefined4 *param_1,int param_2,byte *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 unaff_retaddr;
  undefined4 uVar7;
  int iStack_4c;
  undefined1 local_40 [32];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int iStack_14;
  
  iVar1 = *(int *)(param_3 + 4);
  FUN_00553db0();
  if (param_1[0x4f3] != 0) {
    param_1[0x4f3] = 0;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x94))
                      ((int *)param_1[0x440],0x100,param_1 + 0x503);
    *param_1 = uVar2;
  }
  if (param_1[0x53c] != 0) {
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x1c,1);
    *param_1 = uVar2;
  }
  if (param_1[0x4f1] != 1) {
    param_1[0x4f1] = 1;
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x88,1);
    *param_1 = uVar2;
  }
  FUN_00554be0(1);
  param_1[0x45c] = 0x100;
  if ((*(byte *)(iVar1 + 0x9c) & 0x20) != 0) {
    FUN_00554be0(0);
    param_1[0x45c] = param_1[0x45c] | 0x800;
  }
  if ((*(byte *)(iVar1 + 0x9c) & 0x40) != 0) {
    param_1[0x45c] = param_1[0x45c] | 0x400;
  }
  if (*(char *)(*(int *)(iVar1 + 0xa8) + 0x40) < '\0') {
    param_1[0x45c] = param_1[0x45c] | 1;
  }
  FUN_00554790(param_1[0x45c],*(undefined4 *)(iVar1 + 0xac),
               *(undefined4 *)(*(int *)(iVar1 + 0xa8) + 0x84));
  iVar5 = *(int *)(iVar1 + 0xa4);
  iVar4 = 0;
  iStack_4c = 0;
  if (0 < iVar5) {
    do {
      iVar6 = 0;
      if (iVar4 < iVar5) {
        iVar5 = iVar4 * 0x94;
        do {
          if ((int)param_1[0x4ec] <= iVar6) break;
          iVar4 = FUN_005504d0(0,iVar4);
          if (iVar4 == 0) {
            uStack_20 = 0;
            iStack_14 = 0;
          }
          else {
            iVar3 = FUN_00554f80(param_2,iVar4);
            if (iVar3 == 0) {
              return;
            }
            uStack_20 = 7;
            uStack_1c = 2;
            iStack_14 = iVar4;
            if ((char)*(undefined4 *)(*(int *)(iVar1 + 0xa8) + 0x40 + iVar5) < '\0') {
              uStack_1c = 3;
            }
          }
          FUN_005546a0(local_40,iVar6);
          iVar4 = iStack_4c + 1;
          iVar5 = iVar5 + 0x94;
          iVar6 = iVar6 + 1;
          iStack_4c = iVar4;
        } while (iVar4 < *(int *)(iVar1 + 0xa4));
      }
      FUN_00553fa0(iVar6);
      FUN_00554700(*(undefined4 *)(param_3 + 0x1c));
      uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x154))
                        ((int *)param_1[0x440],*(undefined4 *)(*(int *)(param_3 + 0x24) + 0x18),
                         *(undefined4 *)(param_3 + 0x2c));
      *param_1 = uVar2;
      if ((*param_3 & 0x10) == 0) {
        iVar5 = param_2 / 3;
        uVar2 = *(undefined4 *)(param_3 + 0x30);
        uVar7 = 4;
      }
      else {
        iVar5 = param_2 / 2;
        uVar2 = *(undefined4 *)(param_3 + 0x30);
        uVar7 = 2;
      }
      uVar2 = (**(code **)(*(int *)param_1[0x440] + 0x11c))
                        ((int *)param_1[0x440],uVar7,0,unaff_retaddr,uVar2,iVar5);
      *param_1 = uVar2;
      iVar5 = *(int *)(iVar1 + 0xa4);
    } while (iVar4 < iVar5);
  }
  if (param_1[0x53c] != 0) {
    uVar2 = (**(code **)(*(int *)param_1[0x440] + 200))((int *)param_1[0x440],0x1c,0);
    *param_1 = uVar2;
  }
  return;
}


