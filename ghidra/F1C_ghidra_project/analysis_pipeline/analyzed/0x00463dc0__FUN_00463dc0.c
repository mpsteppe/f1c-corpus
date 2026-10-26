// Function: FUN_00463dc0 @ 00463dc0
// Size (bytes): 53


int __thiscall FUN_00463dc0(int *param_1,int param_2)

{
  char cVar1;
  
  cVar1 = FUN_005001f0();
  if (cVar1 != '\0') {
    return *param_1 + 0x4188 + param_2 * 0x368;
  }
  return 0;
}


