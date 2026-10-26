// Function: FUN_0052e5e0 @ 0052e5e0
// Size (bytes): 262


void __thiscall
FUN_0052e5e0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  
  uVar5 = 0;
  iVar6 = (int)*(char *)(param_3 + param_2 * 2);
  if (iVar6 != 0) {
    iVar1 = iVar6 + 1;
    uVar2 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
    uVar3 = *(undefined4 *)(param_1 + 0x24a8);
    uVar4 = *(uint *)(&DAT_005b4788 + iVar1 * 4);
    *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar1;
    uVar5 = (undefined2)
            ((int)(*(int *)(param_6 + (*(int *)(param_4 + param_2 * 4) + iVar1 * 0x40) * 4) *
                  (*(int *)(&DAT_005b4820 + iVar6 * 4) +
                  ((uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18)
                   >> (-(((byte)uVar3 & 7) + (char)iVar1) & 0x1f) & uVar4))) >> 0xc);
  }
  *(undefined2 *)(param_5 + param_2 * 2) = uVar5;
  uVar5 = 0;
  iVar6 = (int)*(char *)(param_3 + 1 + param_2 * 2);
  if (iVar6 != 0) {
    iVar1 = iVar6 + 1;
    uVar2 = *(uint *)((*(int *)(param_1 + 0x24a8) >> 3) + *(int *)(param_1 + 0x24a4));
    uVar3 = *(undefined4 *)(param_1 + 0x24a8);
    uVar4 = *(uint *)(&DAT_005b4788 + iVar1 * 4);
    *(int *)(param_1 + 0x24a8) = *(int *)(param_1 + 0x24a8) + iVar1;
    uVar5 = (undefined2)
            ((int)(*(int *)(param_6 + (*(int *)(param_4 + 0x80 + param_2 * 4) + iVar1 * 0x40) * 4) *
                  (*(int *)(&DAT_005b4820 + iVar6 * 4) +
                  ((uVar2 >> 0x18 | (uVar2 & 0xff0000) >> 8 | (uVar2 & 0xff00) << 8 | uVar2 << 0x18)
                   >> (-(((byte)uVar3 & 7) + (char)iVar1) & 0x1f) & uVar4))) >> 0xc);
  }
  *(undefined2 *)(param_5 + 0x40 + param_2 * 2) = uVar5;
  return;
}


