// Function: FUN_004957a0 @ 004957a0
// Size (bytes): 112


void __thiscall FUN_004957a0(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0 < param_2) {
    do {
      sVar1 = *(short *)(param_3 + iVar4 * 2);
      if (sVar1 == 1) {
        if ((param_1[6] != 0) && (iVar2 = *(int *)(param_1[6] + 0x50), iVar2 != 0)) {
          puVar3 = *(undefined1 **)(iVar2 + 0x60);
          goto LAB_004957e5;
        }
      }
      else if (((sVar1 == 0x1c) && (param_1[6] != 0)) &&
              (iVar2 = *(int *)(param_1[6] + 0x50), iVar2 != 0)) {
        puVar3 = *(undefined1 **)(iVar2 + 0x58);
LAB_004957e5:
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        FUN_004988d0(puVar3);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_2);
  }
  (**(code **)(*param_1 + 0x20))(param_2,param_3,param_4);
  return;
}


