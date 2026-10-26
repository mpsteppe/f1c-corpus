// Function: FUN_004e19a0 @ 004e19a0
// Size (bytes): 40


void __fastcall FUN_004e19a0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = 0;
  puVar2 = (undefined4 *)(param_1 + 0xb70);
  do {
    FUN_004e17c0(iVar1,*puVar2);
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 1;
  } while (iVar1 < 0xe);
  return;
}


