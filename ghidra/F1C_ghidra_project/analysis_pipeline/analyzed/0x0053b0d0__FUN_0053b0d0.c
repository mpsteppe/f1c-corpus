// Function: FUN_0053b0d0 @ 0053b0d0
// Size (bytes): 59


void FUN_0053b0d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_0053c2a0();
    *puVar1 = &PTR_LAB_005b8938;
    DAT_008b8f18 = puVar1;
    DAT_008b8f24 = puVar1;
    return;
  }
  DAT_008b8f18 = (undefined4 *)0x0;
  DAT_008b8f24 = (undefined4 *)0x0;
  return;
}


