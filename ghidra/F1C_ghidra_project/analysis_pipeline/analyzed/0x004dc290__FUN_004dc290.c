// Function: FUN_004dc290 @ 004dc290
// Size (bytes): 39


undefined4 * FUN_004dc290(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[1] = 4;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[3] = 0;
    *puVar1 = &PTR_LAB_005ad11c;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


