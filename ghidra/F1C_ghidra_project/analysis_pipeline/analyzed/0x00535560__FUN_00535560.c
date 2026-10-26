// Function: FUN_00535560 @ 00535560
// Size (bytes): 62


int __fastcall FUN_00535560(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_00534e70();
  iVar2 = FUN_00534e70();
  iVar3 = FUN_00534e70();
  iVar4 = FUN_00534e70();
  if (iVar4 == -1) {
    *(undefined4 *)(param_1 + 0x38) = 0xfffffffd;
  }
  return iVar4 * 0x1000000 + iVar1 + iVar2 * 0x100 + iVar3 * 0x10000;
}


