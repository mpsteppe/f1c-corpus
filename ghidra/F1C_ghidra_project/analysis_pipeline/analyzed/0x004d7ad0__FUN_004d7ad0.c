// Function: FUN_004d7ad0 @ 004d7ad0
// Size (bytes): 44


void __fastcall FUN_004d7ad0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x18);
  iVar2 = 3;
  do {
    puVar1[3] = 0;
    *puVar1 = 0;
    puVar1[-6] = 0xffffffff;
    puVar1[-3] = 0xffffffff;
    puVar1 = puVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


