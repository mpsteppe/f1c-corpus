// Function: FUN_00491cf0 @ 00491cf0
// Size (bytes): 21


undefined4 __fastcall FUN_00491cf0(int *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*param_1 + 0x1c);
  *(undefined4 **)(*param_1 + 0x24) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}


