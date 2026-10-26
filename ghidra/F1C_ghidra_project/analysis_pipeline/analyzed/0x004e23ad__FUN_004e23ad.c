// Function: FUN_004e23ad @ 004e23ad
// Size (bytes): 28


void __fastcall FUN_004e23ad(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(param_1 + 0x1ec);
  iVar2 = 4;
  do {
    *puVar1 = 0xffffffff;
    puVar1 = puVar1 + 0x4a;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


