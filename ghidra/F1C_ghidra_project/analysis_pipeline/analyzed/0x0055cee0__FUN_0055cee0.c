// Function: FUN_0055cee0 @ 0055cee0
// Size (bytes): 100


uint FUN_0055cee0(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 == 6) {
    return ((param_2 & 0xf8) << 5 | param_3 & 0xfc) << 3 | param_4 >> 3 & 0x1fU;
  }
  if (param_1 == 5) {
    uVar1 = ((param_2 & 0xf8) << 5 | param_3 & 0xf8) << 2 | param_4 >> 3 & 0x1fU;
  }
  return uVar1;
}


