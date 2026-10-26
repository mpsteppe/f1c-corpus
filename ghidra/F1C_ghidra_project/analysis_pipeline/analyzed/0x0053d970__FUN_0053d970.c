// Function: FUN_0053d970 @ 0053d970
// Size (bytes): 538


void __fastcall FUN_0053d970(int *param_1)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  undefined1 auStack_940 [88];
  int iStack_8e8;
  int iStack_8e4;
  uint uStack_86c;
  int iStack_868;
  undefined4 uStack_864;
  undefined4 uStack_860;
  undefined4 uStack_85c;
  undefined4 uStack_858;
  char acStack_854 [256];
  undefined4 uStack_754;
  int iStack_750;
  int iStack_74c;
  undefined4 uStack_748;
  undefined1 auStack_430 [512];
  char acStack_230 [536];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  iVar4 = 0;
  if (0 < param_1[2]) {
    piVar5 = param_1 + 3;
    do {
      piVar7 = piVar5;
      for (iVar3 = 0x10f; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      iVar4 = iVar4 + 1;
      piVar5 = piVar5 + 0x10f;
    } while (iVar4 < param_1[2]);
  }
  param_1[2] = 0;
  iVar4 = (**(code **)(*(int *)param_1[0x43f] + 0x10))((int *)param_1[0x43f]);
  iVar3 = 0;
  if (0 < iVar4) {
    do {
      uVar6 = 0;
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                        ((int *)param_1[0x43f],iVar3,1,0x17,0x17,0);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        uVar6 = 0x1000000;
      }
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                        ((int *)param_1[0x43f],iVar3,1,0x18,0x19,0);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        uVar6 = uVar6 | 0x2000000;
      }
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                        ((int *)param_1[0x43f],iVar3,1,0x18,0x18,0);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        uVar6 = uVar6 | 0x4000000;
      }
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                        ((int *)param_1[0x43f],iVar3,1,0x14,0x14,0);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        uVar6 = uVar6 | 0x8000000;
      }
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                        ((int *)param_1[0x43f],iVar3,1,0x16,0x16,0);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        uVar6 = uVar6 | 0x20000000;
      }
      iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x24))
                        ((int *)param_1[0x43f],iVar3,1,0x16,0x15,0);
      *param_1 = iVar2;
      if (iVar2 == 0) {
        uVar6 = uVar6 | 0x10000000;
      }
      if (uVar6 != 0) {
        iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x34))
                          ((int *)param_1[0x43f],iVar3,1,auStack_940);
        *param_1 = iVar2;
        if ((iVar2 != 0) ||
           ((iStack_750 = iStack_8e8, 0x200 < iStack_8e8 &&
            (iStack_74c = iStack_8e4, 0x200 < iStack_8e4)))) {
          iVar2 = (**(code **)(*(int *)param_1[0x43f] + 0x14))
                            ((int *)param_1[0x43f],iVar3,2,auStack_430);
          *param_1 = iVar2;
          uStack_864 = uStack_18;
          uStack_860 = uStack_14;
          uStack_85c = uStack_10;
          uStack_858 = uStack_c;
          iVar2 = 0;
          do {
            pcVar1 = acStack_230 + iVar2;
            acStack_854[iVar2] = *pcVar1;
            iVar2 = iVar2 + 1;
          } while (*pcVar1 != '\0');
          uStack_748 = 0;
          uStack_754 = 0;
          uStack_86c = uVar6;
          iStack_868 = iVar3;
          FUN_0053d8b0(&uStack_86c);
        }
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar4);
  }
  return;
}


