// Function: FUN_004649f0 @ 004649f0
// Size (bytes): 20


void __thiscall FUN_004649f0(byte *param_1,char param_2)

{
  if (param_2 != '\0') {
    *param_1 = 0x80;
    return;
  }
  *param_1 = *param_1 & 0x7f;
  return;
}


