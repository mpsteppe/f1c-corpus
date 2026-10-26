// Function: FUN_00542650 @ 00542650
// Size (bytes): 38


void __thiscall FUN_00542650(int param_1,int param_2)

{
  if (param_2 != 0) {
    *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) | 0x20;
    return;
  }
  *(uint *)(param_1 + 0x80) = *(uint *)(param_1 + 0x80) & 0xffffffdf;
  return;
}


