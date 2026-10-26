// Function: FUN_004ba780 @ 004ba780
// Size (bytes): 15


undefined4 __fastcall FUN_004ba780(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  param_1[2] = (int)puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}


