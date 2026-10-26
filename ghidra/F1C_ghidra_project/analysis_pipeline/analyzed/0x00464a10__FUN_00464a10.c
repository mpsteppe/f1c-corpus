// Function: FUN_00464a10 @ 00464a10
// Size (bytes): 43


void __thiscall FUN_00464a10(byte *param_1,int param_2)

{
  byte bVar1;
  
  bVar1 = *param_1;
  param_2 = (bVar1 & 0x7f) + param_2;
  if (0x7f < param_2) {
    param_2 = 0x7f;
  }
  *param_1 = (bVar1 ^ (byte)param_2) & 0x7f ^ bVar1;
  return;
}


