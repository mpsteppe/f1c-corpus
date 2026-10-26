// Function: FUN_0054a160 @ 0054a160
// Size (bytes): 70


void __thiscall FUN_0054a160(int param_1,int param_2)

{
  if (param_2 == 0x1000) {
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffffdfff | 0x1000;
  }
  else if (param_2 == 0x2000) {
    *(uint *)(param_1 + 0xec) = *(uint *)(param_1 + 0xec) & 0xffffefff | 0x2000;
    return;
  }
  return;
}


