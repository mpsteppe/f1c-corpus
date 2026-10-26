// Function: FUN_004f8a70 @ 004f8a70
// Size (bytes): 59


void FUN_004f8a70(void)

{
  int iVar1;
  char cVar2;
  
  iVar1 = _rand();
  if (iVar1 < 0x2aaa) {
    cVar2 = '\x14';
  }
  else {
    cVar2 = (iVar1 < 0x5554) + '\x12';
  }
  FUN_004f87c0(cVar2,2,0x3f800000,0x3f800000);
  return;
}


