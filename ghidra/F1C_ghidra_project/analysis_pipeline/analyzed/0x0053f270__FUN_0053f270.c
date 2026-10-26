// Function: FUN_0053f270 @ 0053f270
// Size (bytes): 374


void __thiscall FUN_0053f270(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(uint *)(param_1 + 0x13a8) & 0x10000000) != 0) {
    if (*(int *)(param_1 + 0x1140) != 0) {
      FUN_00540eb0(*(int *)(param_1 + 0x1140));
      if (*(int *)(param_1 + 0x1140) != 0) {
        FUN_00587bcf(*(int *)(param_1 + 0x1140));
      }
      *(undefined4 *)(param_1 + 0x1140) = 0;
    }
    if (*(int *)(param_1 + 0x113c) != 0) {
      FUN_00540eb0(*(int *)(param_1 + 0x113c));
      if (*(int *)(param_1 + 0x113c) != 0) {
        FUN_00587bcf(*(int *)(param_1 + 0x113c));
      }
      *(undefined4 *)(param_1 + 0x113c) = 0;
    }
    if (*(int *)(param_1 + 0x1144) != 0) {
      FUN_00541040(*(int *)(param_1 + 0x1144));
      if (*(int *)(param_1 + 0x1144) != 0) {
        FUN_00587bcf(*(int *)(param_1 + 0x1144));
      }
      *(undefined4 *)(param_1 + 0x1144) = 0;
    }
    iVar1 = *(int *)(param_1 + 0x1518);
    *(undefined4 *)(param_1 + 0x13a0) = 1;
    *(undefined4 *)(param_1 + 0x14f0) = 0;
    *(undefined4 *)(param_1 + 0x14f4) = 0;
    *(undefined4 *)(param_1 + 0x14f8) = 0;
    *(undefined4 *)(param_1 + 0x14fc) = 0;
    *(undefined4 *)(param_1 + 0x1500) = 0;
    *(undefined4 *)(param_1 + 0x1504) = 0;
    for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
      if (*(int *)(iVar1 + 0x14) != 0) {
        FUN_00540eb0(*(int *)(iVar1 + 0x14));
        *(undefined4 *)(iVar1 + 0x14) = 0;
      }
      iVar2 = *(int *)(iVar1 + 0x10);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
        FUN_00554d70(iVar2);
      }
    }
    for (iVar1 = *(int *)(param_1 + 0x1580); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x870)) {
      FUN_005528b0();
      iVar2 = *(int *)(iVar1 + 0x868);
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x54) != 0)) {
        FUN_00554d70(iVar2);
      }
    }
    if (param_2 != 0) {
      FUN_00544af0();
      FUN_00554e10(param_2);
      uVar3 = FUN_00545f40();
      FUN_00554cc0(uVar3);
      *(uint *)(param_2 + 0xec) = *(uint *)(param_2 + 0xec) | 0x10000;
    }
    *(uint *)(param_1 + 0x13a8) = *(uint *)(param_1 + 0x13a8) & 0xefffffff;
  }
  return;
}


