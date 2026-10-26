// Function: FUN_0054e080 @ 0054e080
// Size (bytes): 81


void __fastcall FUN_0054e080(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  FUN_00545f40();
  if (0 < *(int *)(param_1 + 0x120)) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(*(int *)(iVar3 + 8 + *(int *)(param_1 + 0x124)) + 4);
      uVar2 = *(uint *)(iVar1 + 0x9c);
      if ((uVar2 & 2) != 0) {
        *(uint *)(iVar1 + 0x9c) = uVar2 | 1;
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 0x24;
    } while (iVar4 < *(int *)(param_1 + 0x120));
  }
  return;
}


