// Function: FUN_0049bad0 @ 0049bad0
// Size (bytes): 65


undefined4 FUN_0049bad0(void)

{
  int iVar1;
  float10 fVar2;
  
  fVar2 = (float10)FUN_004f0050();
  iVar1 = FUN_004d1cf0((float)fVar2);
  if (iVar1 != 2) {
    iVar1 = FUN_004d1d40((float)fVar2);
    if (iVar1 != 2) {
      return 0;
    }
  }
  return 1;
}


