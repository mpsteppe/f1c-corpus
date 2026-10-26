// Function: FUN_0058dd28 @ 0058dd28
// Size (bytes): 22


uint FUN_0058dd28(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7ff00000) != 0x7ff00000) {
    return param_2 & 0x7ff00000;
  }
  return param_2;
}


