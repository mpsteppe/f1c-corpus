// Function: FUN_0059a980 @ 0059a980
// Size (bytes): 66


void __fastcall FUN_0059a980(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  FUN_0059a8d8(0);
  puVar2 = *(undefined4 **)(param_1 + 0x18);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x1c);
  while (puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    FUN_00587bcf(puVar2);
    puVar2 = puVar1;
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return;
}


