// Function: FUN_0044f460 @ 0044f460
// Size (bytes): 58


uint __thiscall FUN_0044f460(int param_1,uint param_2)

{
  char cVar1;
  
  cVar1 = FUN_00404f10();
  if (((cVar1 != '\0') && (DAT_007c569c == 5)) && (param_2 != 1)) {
    return param_2 & 0xffffff00;
  }
  return *(byte *)(param_2 + 0x37c + param_1) >> 1 & 1;
}


