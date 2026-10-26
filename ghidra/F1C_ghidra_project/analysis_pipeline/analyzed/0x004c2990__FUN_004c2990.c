// Function: FUN_004c2990 @ 004c2990
// Size (bytes): 22


undefined4 FUN_004c2990(void)

{
  undefined4 uVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_004c2850();
  if ((int)uVar2 != 0) {
    uVar1 = FUN_004c11d0();
    return uVar1;
  }
  return (int)((ulonglong)uVar2 >> 0x20);
}


