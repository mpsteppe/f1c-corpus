// Function: FUN_004c07f0 @ 004c07f0
// Size (bytes): 81


void __fastcall FUN_004c07f0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0xd8);
  iVar2 = 0x30;
  do {
    puVar1[-0x30] = 0xffffffff;
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(param_1 + 0x198) = 0;
  *(undefined4 *)(param_1 + 0x19c) = 0;
  *(undefined4 *)(param_1 + 0x1a0) = 0;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0xffffffff;
  *(undefined1 *)(param_1 + 0x1b0) = 0;
  return;
}


