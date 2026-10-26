// Function: FUN_0059325d @ 0059325d
// Size (bytes): 93


undefined4 FUN_0059325d(int param_1)

{
  int iVar1;
  
  DAT_008d4904 = HeapCreate((uint)(param_1 == 0),0x1000,0);
  if (DAT_008d4904 != (HANDLE)0x0) {
    DAT_008d4908 = FUN_00593115();
    if (DAT_008d4908 == 3) {
      iVar1 = FUN_00593dd3(0x3f8);
    }
    else {
      if (DAT_008d4908 != 2) {
        return 1;
      }
      iVar1 = FUN_0059491a();
    }
    if (iVar1 != 0) {
      return 1;
    }
    HeapDestroy(DAT_008d4904);
  }
  return 0;
}


