// Function: FUN_005388d0 @ 005388d0
// Size (bytes): 112


void __fastcall FUN_005388d0(int param_1,int param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  int iVar5;
  short asStack_20 [16];
  
  sVar3 = 0;
  iVar5 = 1;
  do {
    sVar3 = (*(short *)(param_3 + iVar5 * 2 + -2) + sVar3) * 2;
    iVar2 = iVar5 + 1;
    asStack_20[iVar5] = sVar3;
    iVar5 = iVar2;
  } while (iVar2 < 0x10);
  iVar5 = 0;
  if (-1 < param_2) {
    do {
      uVar4 = (uint)*(ushort *)(param_1 + 2 + iVar5 * 4);
      if (uVar4 != 0) {
        asStack_20[uVar4] = asStack_20[uVar4] + 1;
        uVar1 = FUN_00539670();
        *(undefined2 *)(param_1 + iVar5 * 4) = uVar1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 <= param_2);
  }
  return;
}


