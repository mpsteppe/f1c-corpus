// Function: FUN_0044f0a0 @ 0044f0a0
// Size (bytes): 61


void __fastcall FUN_0044f0a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  *(undefined4 *)(param_1 + 0xc84) = 0;
  iVar1 = 0;
  puVar2 = (undefined4 *)(param_1 + 0x87c);
  do {
    *(undefined1 *)(param_1 + 0x37c + iVar1) = 0;
    *puVar2 = 0;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0x100);
  puVar2 = (undefined4 *)(param_1 + 0xc88);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


