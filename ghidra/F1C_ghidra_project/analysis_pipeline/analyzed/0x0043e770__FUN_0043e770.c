// Function: FUN_0043e770 @ 0043e770
// Size (bytes): 273


void __thiscall FUN_0043e770(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = param_2 * 0x464 + 0x28c + param_1;
  iVar5 = *(int *)(iVar6 + 0x160);
  *(undefined1 *)(iVar6 + 0x1c4) = 1;
  if (iVar5 == 0) {
    iVar6 = *(int *)(iVar6 + 0x15c);
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x15b4)) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x15b8) + 4 + iVar4);
        iVar3 = *(int *)(param_1 + 0x15b8) + iVar4;
        if (((iVar2 == iVar6) && (*(int *)(iVar3 + 0xc) == *(int *)(param_1 + 0x141c))) ||
           ((*(int *)(iVar3 + 0xc) == iVar6 && (iVar2 == *(int *)(param_1 + 0x141c))))) {
          *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) | 1;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x30;
      } while (iVar5 < *(int *)(param_1 + 0x15b4));
    }
    iVar5 = 0;
    if (0 < *(int *)(param_1 + 0x15bc)) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(*(int *)(param_1 + 0x15c0) + 4 + iVar4);
        iVar3 = *(int *)(param_1 + 0x15c0) + iVar4;
        if (((iVar2 == iVar6) && (*(int *)(iVar3 + 0xc) == *(int *)(param_1 + 0x141c))) ||
           ((*(int *)(iVar3 + 0xc) == iVar6 && (iVar2 == *(int *)(param_1 + 0x141c))))) {
          *(uint *)(iVar3 + 0x2c) = *(uint *)(iVar3 + 0x2c) | 1;
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x30;
      } while (iVar5 < *(int *)(param_1 + 0x15bc));
    }
  }
  else {
    *(undefined1 *)(iVar6 + 0x200) = 1;
    iVar6 = 0;
    if (0 < *(int *)(param_1 + 0x15c4)) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(param_1 + 0x15c8) + iVar4;
        if ((*(int *)(*(int *)(param_1 + 0x15c8) + 4 + iVar4) == iVar5) ||
           (*(int *)(iVar2 + 0xc) == iVar5)) {
          puVar1 = (uint *)(iVar2 + 0x44);
          *puVar1 = *puVar1 | 1;
        }
        iVar6 = iVar6 + 1;
        iVar4 = iVar4 + 0x48;
      } while (iVar6 < *(int *)(param_1 + 0x15c4));
      return;
    }
  }
  return;
}


