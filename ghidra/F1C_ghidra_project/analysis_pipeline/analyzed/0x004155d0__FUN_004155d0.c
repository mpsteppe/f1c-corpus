// Function: FUN_004155d0 @ 004155d0
// Size (bytes): 121


int __thiscall FUN_004155d0(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  
  if (param_2 != 0) {
    iVar1 = *(int *)(param_1 + 0x2c);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        if ((iVar5 < 0) || (*(int *)(param_1 + 0x2c) <= iVar5)) {
LAB_00415612:
          puVar2 = (undefined4 *)0x0;
        }
        else {
          puVar2 = *(undefined4 **)(param_1 + 0x20);
          for (iVar4 = iVar5; 0 < iVar4; iVar4 = iVar4 + -1) {
            if (puVar2 == (undefined4 *)0x0) goto LAB_00415612;
            puVar2 = (undefined4 *)puVar2[1];
          }
          if (puVar2 == (undefined4 *)0x0) goto LAB_00415612;
          puVar2 = (undefined4 *)*puVar2;
        }
        puVar3 = (undefined1 *)*puVar2;
        if (puVar3 == (undefined1 *)0x0) {
          puVar3 = &DAT_005ea438;
        }
        iVar4 = FUN_00588410(puVar3,param_2);
        if (iVar4 == 0) {
          return iVar5;
        }
        iVar5 = iVar5 + 1;
        if (iVar1 <= iVar5) {
          return -1;
        }
      } while( true );
    }
  }
  return -1;
}


