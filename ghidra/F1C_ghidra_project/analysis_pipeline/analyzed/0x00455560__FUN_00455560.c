// Function: FUN_00455560 @ 00455560
// Size (bytes): 30


undefined1 * __thiscall FUN_00455560(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)0x0;
  if ((param_2 < 0x2c) &&
     (puVar1 = *(undefined1 **)(param_1 + 0x22b0 + param_2 * 8), puVar1 == (undefined1 *)0x0)) {
    puVar1 = &DAT_005ea438;
  }
  return puVar1;
}


