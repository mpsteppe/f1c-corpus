// Function: FUN_00464ae0 @ 00464ae0
// Size (bytes): 35


uint __thiscall FUN_00464ae0(int param_1,uint param_2,int param_3)

{
  if ((char)*(byte *)(param_2 + param_1) < '\0') {
    return param_2 & 0xffffff00;
  }
  return (uint)(param_3 <= (int)(*(byte *)(param_2 + param_1) & 0x7f));
}


