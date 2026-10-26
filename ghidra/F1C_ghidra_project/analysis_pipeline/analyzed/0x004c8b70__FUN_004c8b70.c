// Function: FUN_004c8b70 @ 004c8b70
// Size (bytes): 296


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c8b70(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  undefined1 local_18 [4];
  float local_14;
  undefined1 local_c [12];
  
  if ((DAT_008ab6e4 == 2) && (iVar4 = FUN_004b9e30(), iVar4 != 5)) {
    bVar1 = true;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    bVar1 = false;
  }
  cVar3 = DAT_007cf2b4;
  cVar5 = '\x01';
  if ((DAT_007ce254 == '\0') || (cVar5 = DAT_007cf2b4, DAT_008ac4c4 == (int *)0x0)) {
    if (!bVar1) goto LAB_004c8c0b;
  }
  else if (!bVar1) {
    FUN_004d1140(DAT_007c54e8,local_c,local_18);
    local_14 = _DAT_0059e660 - local_14;
    (**(code **)(*DAT_008ac4c4 + 0x1c))(local_c,local_18);
    cVar5 = cVar3;
LAB_004c8c0b:
    if ((DAT_007c56ac != '\0') || (cVar5 == '\0')) goto LAB_004c8c64;
  }
  iVar4 = DAT_005c329c;
  iVar6 = 0;
  if (0 < DAT_005c329c) {
    do {
      FUN_004f8440();
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  if (DAT_008ac4c4 != (int *)0x0) {
    (**(code **)(*DAT_008ac4c4 + 8))();
  }
  FUN_0054a200(0x20,1);
  FUN_004c7de0();
LAB_004c8c64:
  FUN_004186f0();
  if ((!bVar2) && (DAT_007ce254 != '\0')) {
    FUN_004c8920();
    return;
  }
  FUN_004c8a10();
  return;
}


