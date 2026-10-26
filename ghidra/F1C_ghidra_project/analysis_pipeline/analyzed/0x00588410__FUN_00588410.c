// Function: FUN_00588410 @ 00588410
// Size (bytes): 208


char FUN_00588410(byte *param_1,byte *param_2)

{
  bool bVar1;
  int iVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  char cVar6;
  uint uVar7;
  
  iVar2 = DAT_008d5a5c;
  if (DAT_008d3f38 == 0) {
    bVar5 = 0xff;
    do {
      do {
        if (bVar5 == 0) {
          return '\0';
        }
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar4 == bVar5);
      bVar3 = bVar5 + 0xbf + (-((byte)(bVar5 + 0xbf) < 0x1a) & 0x20U) + 0x41;
      bVar4 = bVar4 + 0xbf;
      bVar5 = bVar4 + (-(bVar4 < 0x1a) & 0x20U) + 0x41;
    } while (bVar5 == bVar3);
    cVar6 = (bVar5 < bVar3) * -2 + '\x01';
  }
  else {
    LOCK();
    DAT_008d5a5c = DAT_008d5a5c + 1;
    UNLOCK();
    bVar1 = 0 < DAT_008d5a58;
    if (bVar1) {
      LOCK();
      UNLOCK();
      DAT_008d5a5c = iVar2;
      FUN_0058dfea(0x13);
    }
    uVar7 = (uint)bVar1;
    bVar5 = 0xff;
    do {
      do {
        cVar6 = '\0';
        if (bVar5 == 0) goto LAB_005884bf;
        bVar5 = *param_2;
        param_2 = param_2 + 1;
        bVar4 = *param_1;
        param_1 = param_1 + 1;
      } while (bVar5 == bVar4);
      bVar4 = FUN_0058b4d4(bVar4,bVar5);
      bVar5 = FUN_0058b4d4();
    } while (bVar4 == bVar5);
    cVar6 = (bVar4 < bVar5) * -2 + '\x01';
LAB_005884bf:
    if (uVar7 == 0) {
      LOCK();
      DAT_008d5a5c = DAT_008d5a5c + -1;
      UNLOCK();
    }
    else {
      FUN_0058e04b(0x13);
    }
  }
  return cVar6;
}


