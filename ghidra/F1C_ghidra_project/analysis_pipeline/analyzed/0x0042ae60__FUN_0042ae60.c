// Function: FUN_0042ae60 @ 0042ae60
// Size (bytes): 36


uint __fastcall FUN_0042ae60(int param_1)

{
  uint in_EAX;
  
  if ((DAT_007c56a4 != 5) ||
     ((in_EAX = 1, *(int *)(param_1 + 0x454c) != 1 && (*(int *)(param_1 + 0x4094) == 2)))) {
    in_EAX = in_EAX & 0xffffff00;
  }
  return in_EAX;
}


