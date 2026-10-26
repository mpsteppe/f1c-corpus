// Function: FUN_0040d100 @ 0040d100
// Size (bytes): 151


void __fastcall FUN_0040d100(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    switch(DAT_007cfdc4) {
    default:
      FUN_00409440(2,0,1);
      FUN_0040cde0(2,0);
      break;
    case 1:
      FUN_00409440(1,0,1);
      FUN_0040cde0(1,0);
      return;
    case 2:
      FUN_00409440(0,0,1);
      FUN_0040cde0(0,0);
      return;
    case 3:
      FUN_00409440(3,0,1);
      FUN_0040cde0(3,0);
      return;
    case 4:
      FUN_00409440(3,0,1);
      FUN_0040cde0(5,0);
      return;
    }
  }
  return;
}


