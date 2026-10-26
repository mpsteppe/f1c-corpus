// Function: FUN_00544c50 @ 00544c50
// Size (bytes): 215


void __thiscall FUN_00544c50(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  do {
    piVar3 = (int *)(param_1 + 0x40);
    if ((*(byte *)(param_2 + 0x3c) & 0x10) == 0) {
      piVar3 = (int *)(param_1 + 0x3c);
    }
    for (iVar1 = *(int *)(param_2 + 0x204); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x10)) {
      *(int *)(param_1 + 0x38) = *(int *)(param_1 + 0x38) + *(int *)(iVar1 + 0x120);
      *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + 1;
      iVar4 = 0;
      if (0 < *(int *)(iVar1 + 0x118)) {
        iVar5 = 0;
        do {
          *(undefined2 *)(*(int *)(iVar1 + 0x11c) + 2 + iVar5) = 0;
          uVar2 = *(uint *)(*(int *)(iVar1 + 0x11c) + iVar5);
          *(uint *)(*(int *)(iVar1 + 0x11c) + iVar5) = uVar2 << 0x10 | uVar2;
          FUN_005473c0();
          *piVar3 = *piVar3 + *(int *)(*(int *)(iVar1 + 0x11c) + 8 + iVar5);
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0x40;
        } while (iVar4 < *(int *)(iVar1 + 0x118));
      }
    }
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
    if (*(int *)(param_2 + 0x44) != 0) {
      FUN_00544c50(*(int *)(param_2 + 0x44));
    }
    param_2 = *(int *)(param_2 + 0x4c);
  } while (param_2 != 0);
  return;
}


