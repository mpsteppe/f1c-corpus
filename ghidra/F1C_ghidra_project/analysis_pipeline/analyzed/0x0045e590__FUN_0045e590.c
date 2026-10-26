// Function: FUN_0045e590 @ 0045e590
// Size (bytes): 19


void __fastcall FUN_0045e590(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 0x1d4);
  for (iVar1 = 0x68; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  return;
}


