// Function: FUN_00545f50 @ 00545f50
// Size (bytes): 166


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00545f50(void)

{
  float fVar1;
  
  if (DAT_008b8f00 != (code *)0x0) {
    switch(DAT_008b8ef8) {
    case 1:
      fVar1 = (_DAT_0059e43c - (float)DAT_008b8ee8 / (float)_DAT_008b8ef0) * _DAT_0059e8ec;
      if (_DAT_0059e7f8 <= fVar1) {
        (*DAT_008b8f00)(fVar1);
        return 0;
      }
      break;
    case 2:
      fVar1 = (_DAT_0059e43c - (float)DAT_008b8eec / (float)_DAT_008b8ef4) * _DAT_0059e990 +
              _DAT_0059e8ec;
      if (_DAT_0059e7f8 <= fVar1) {
        (*DAT_008b8f00)(fVar1);
        return 0;
      }
      break;
    case 3:
      (*DAT_008b8f00)(0x42c80000);
      return 0;
    }
  }
  return 0;
}


