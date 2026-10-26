// Function: FUN_0047f230 @ 0047f230
// Size (bytes): 193


void FUN_0047f230(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined1 *local_8;
  int local_4;
  
  if (DAT_008ac394 != (undefined4 *)0x0) {
    local_8 = (undefined1 *)*DAT_008ac394;
    if (local_8 == (undefined1 *)0x0) {
      local_8 = &DAT_005ea438;
    }
    if (0 < DAT_005c329c) {
      iVar4 = 0;
      local_4 = DAT_005c329c;
      do {
        iVar1 = DAT_007d2e48 + 0x4714;
        iVar6 = 0;
        if (0 < DAT_008ac390) {
          iVar5 = 0;
          do {
            puVar2 = *(undefined1 **)(iVar5 + (int)DAT_008ac394);
            if (puVar2 == (undefined1 *)0x0) {
              puVar2 = &DAT_005ea438;
            }
            iVar3 = FUN_00588410(iVar1 + iVar4,puVar2);
            if (iVar3 == 0) goto LAB_0047f2d8;
            iVar6 = iVar6 + 1;
            iVar5 = iVar5 + 0x424;
          } while (iVar6 < DAT_008ac390);
        }
        if (local_8 != (undefined1 *)0x0) {
          FUN_004c78f0(0);
        }
LAB_0047f2d8:
        iVar4 = iVar4 + 0x48c0;
        local_4 = local_4 + -1;
      } while (local_4 != 0);
    }
  }
  return;
}


