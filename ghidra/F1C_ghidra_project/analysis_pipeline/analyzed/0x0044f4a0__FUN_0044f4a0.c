// Function: FUN_0044f4a0 @ 0044f4a0
// Size (bytes): 61


bool __thiscall FUN_0044f4a0(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = FUN_00404f10();
  if (((cVar1 != '\0') && (DAT_007c569c == 5)) && (param_2 != 1)) {
    return false;
  }
  return *(char *)(param_2 + 0x37c + param_1) != '\0';
}


