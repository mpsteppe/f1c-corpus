// Function: FUN_004c3f80 @ 004c3f80
// Size (bytes): 89


void FUN_004c3f80(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = DAT_008ac38c;
  if ((param_1 != 0) && (iVar5 = 0, 0 < DAT_008ac390)) {
    iVar4 = 0;
    while( true ) {
      puVar2 = *(undefined1 **)(iVar4 + DAT_008ac394);
      if (puVar2 == (undefined1 *)0x0) {
        puVar2 = &DAT_005ea438;
      }
      iVar3 = FUN_00588410(puVar2,param_1);
      iVar1 = iVar5;
      if (iVar3 == 0) break;
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x424;
      if (DAT_008ac390 <= iVar5) {
        return;
      }
    }
  }
  DAT_008ac38c = iVar1;
  return;
}


