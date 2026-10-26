// Function: FUN_004c2850 @ 004c2850
// Size (bytes): 16


undefined4 __fastcall FUN_004c2850(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 4);
  *(undefined4 **)(param_1 + 8) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}


