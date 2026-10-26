// Function: FUN_0049a2f0 @ 0049a2f0
// Size (bytes): 60


void __fastcall FUN_0049a2f0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = *(int *)(param_1 + iVar3 * 4);
    while (iVar2 != 0) {
      iVar1 = *(int *)(iVar2 + 0x18);
      FUN_0049a270();
      FUN_00587bcf(iVar2);
      iVar2 = iVar1;
    }
    *(undefined4 *)(param_1 + iVar3 * 4) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x1a);
  return;
}


