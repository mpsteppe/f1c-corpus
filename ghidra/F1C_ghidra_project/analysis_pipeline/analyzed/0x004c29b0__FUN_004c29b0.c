// Function: FUN_004c29b0 @ 004c29b0
// Size (bytes): 23


undefined4 FUN_004c29b0(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_004c2850();
  if ((int)uVar2 != 0) {
    uVar1 = FUN_004c11e0();
    return uVar1;
  }
  return (int)((ulonglong)uVar2 >> 0x20);
}


