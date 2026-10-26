// Function: FUN_004dc220 @ 004dc220
// Size (bytes): 48


undefined4 * __fastcall FUN_004dc220(int param_1)

{
  undefined4 *puVar1;
  
  if ((param_1 == 0) && (puVar1 = operator_new(0x10), puVar1 != (undefined4 *)0x0)) {
    puVar1[1] = 3;
    *(undefined1 *)(puVar1 + 2) = 0;
    puVar1[3] = 0;
    *puVar1 = &PTR_LAB_005ad0f8;
    return puVar1;
  }
  return (undefined4 *)0x0;
}


