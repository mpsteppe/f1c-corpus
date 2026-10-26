// Function: FUN_0040d0b0 @ 0040d0b0
// Size (bytes): 58


undefined4 __fastcall FUN_0040d0b0(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x18) != 0) {
    switch(DAT_007cfdc4) {
    default:
      uVar1 = FUN_0040a610(2);
      break;
    case 1:
      uVar1 = FUN_0040a610(1);
      return uVar1;
    case 2:
      uVar1 = FUN_0040a610(0);
      return uVar1;
    case 3:
      uVar1 = FUN_0040a610(3);
      return uVar1;
    }
  }
  return uVar1;
}


