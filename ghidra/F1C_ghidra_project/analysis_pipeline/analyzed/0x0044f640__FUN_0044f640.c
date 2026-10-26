// Function: FUN_0044f640 @ 0044f640
// Size (bytes): 58


undefined4 __thiscall FUN_0044f640(int param_1,int param_2)

{
  HCURSOR hCursor;
  
  if (((-1 < param_2) && (param_2 < *(int *)(param_1 + 0xa8))) &&
     (hCursor = *(HCURSOR *)(param_1 + 0x30 + param_2 * 0x14), hCursor != (HCURSOR)0x0)) {
    SetCursor(hCursor);
    *(int *)(param_1 + 0xac) = param_2;
    return 1;
  }
  return 0;
}


