// Function: FUN_005506a0 @ 005506a0
// Size (bytes): 191


void __thiscall FUN_005506a0(int param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_3 == 0) {
    iVar3 = *(int *)(param_1 + 0x204);
    if (iVar3 != 0) {
      do {
        iVar4 = *(int *)(iVar3 + 0x118);
        if (iVar4 != 0) {
          piVar1 = (int *)(*(int *)(iVar3 + 0x11c) + 0x34);
          do {
            if ((1 < *(int *)(*(int *)(piVar1[-0xc] + 0xa8) + 0x48)) &&
               (param_2 < *(int *)(*(int *)(piVar1[-0xc] + 0xa8) + 0x50))) {
              *piVar1 = param_2;
            }
            piVar1 = piVar1 + 0x10;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
        }
        iVar3 = *(int *)(iVar3 + 0x10);
      } while (iVar3 != 0);
      return;
    }
  }
  else {
    iVar3 = *(int *)(param_3 + 0xa8);
    if (1 < *(int *)(param_4 * 0x94 + 0x48 + iVar3)) {
      for (iVar4 = *(int *)(param_1 + 0x204); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x10)) {
        iVar2 = *(int *)(iVar4 + 0x118);
        if (iVar2 != 0) {
          piVar1 = (int *)(*(int *)(iVar4 + 0x11c) + 0x34);
          do {
            if ((piVar1[-0xc] == param_3) && (param_2 < *(int *)(param_4 * 0x94 + iVar3 + 0x50))) {
              *piVar1 = param_2;
            }
            piVar1 = piVar1 + 0x10;
            iVar2 = iVar2 + -1;
          } while (iVar2 != 0);
        }
      }
    }
  }
  return;
}


