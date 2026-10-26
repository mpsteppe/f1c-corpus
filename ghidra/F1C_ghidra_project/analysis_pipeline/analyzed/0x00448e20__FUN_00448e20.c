// Function: FUN_00448e20 @ 00448e20
// Size (bytes): 36


void __fastcall FUN_00448e20(int param_1)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_1 + 0x18);
  if (10 < uVar2) {
    uVar2 = 0xb;
  }
  if (uVar2 != 0) {
    piVar1 = (int *)(param_1 + 0x1c);
    do {
      *piVar1 = *(int *)(*piVar1 + 0x1c);
      piVar1 = piVar1 + 1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return;
}


