// Function: FUN_004b3ad0 @ 004b3ad0
// Size (bytes): 30


void __fastcall FUN_004b3ad0(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  puVar1 = param_1 + 1;
  param_1[0x1b003] = puVar1;
  param_1[0x1b002] = puVar1;
  param_1[0x1b001] = puVar1;
  *param_1 = 0;
  return;
}


