// Function: FUN_00487f70 @ 00487f70
// Size (bytes): 481


undefined4 __thiscall FUN_00487f70(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int extraout_EDX;
  undefined8 uVar7;
  int local_8;
  int local_4;
  
  pcVar2 = (char *)param_1[0x2c];
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar6 = -1;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar6 == -2) {
    return 0xffffffff;
  }
  if (param_1[0x32] != 0) {
    uVar7 = FUN_00486720();
    if (((int)uVar7 == 0) || ((int)uVar7 == 2)) {
      cVar1 = FUN_00486710();
      if (cVar1 == '\0') {
        puVar3 = *(undefined1 **)(extraout_EDX + 0x40);
      }
      else {
        puVar3 = *(undefined1 **)(extraout_EDX + 0x48);
      }
    }
    else {
      puVar3 = *(undefined1 **)((int)((ulonglong)uVar7 >> 0x20) + 0x48);
    }
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    if (puVar3 != (undefined1 *)0x0) {
      FUN_00498560(puVar3);
      puVar3 = (undefined1 *)param_1[0x2c];
      if (puVar3 == (undefined1 *)0x0) {
        puVar3 = &DAT_005ea438;
      }
      FUN_004983b0(puVar3,&local_4,&local_8,1);
      if ((0 < local_4) && (0 < local_8)) {
        if (param_1[0x27] == 0) {
          if (param_1[0x26] == 0) {
            return 0xffffffff;
          }
          iVar6 = *(int *)(param_1[0x26] + 0xc);
          iVar4 = (**(code **)(*param_1 + 0x18))();
          if (iVar4 - iVar6 < 0) {
            iVar6 = ((param_1[4] - param_1[3]) - local_4) / 2 + param_1[3];
          }
          else {
            iVar6 = (**(code **)(*param_1 + 0x18))();
          }
          iVar4 = *(int *)(param_1[0x26] + 4);
        }
        else {
          iVar6 = *(int *)(param_1[0x27] + 0xc);
          iVar4 = (**(code **)(*param_1 + 0x18))();
          if (iVar4 - iVar6 < 0) {
            iVar4 = *(int *)(param_1[0x27] + 4);
            iVar6 = ((param_1[4] - param_1[3]) - local_4) / 2 + param_1[3];
          }
          else {
            iVar6 = (**(code **)(*param_1 + 0x18))();
            iVar4 = *(int *)(param_1[0x27] + 4);
          }
        }
        iVar5 = (**(code **)(*param_1 + 0x1c))();
        if (iVar5 - iVar4 < 0) {
          iVar4 = ((param_1[2] - param_1[1]) - local_8) / 2 + param_1[1];
        }
        else {
          iVar4 = (**(code **)(*param_1 + 0x1c))();
        }
        puVar3 = (undefined1 *)param_1[0x2c];
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        FUN_004981f0(puVar3,iVar4,iVar4 + local_8,iVar6,iVar6 + local_4,1);
        *param_2 = iVar4;
        *param_3 = iVar4 + local_8;
        *param_4 = iVar6;
        *param_5 = iVar6 + local_4;
      }
    }
  }
  return 0;
}


