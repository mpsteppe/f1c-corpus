// Function: FUN_00475d90 @ 00475d90
// Size (bytes): 611


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00475d90(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  cVar1 = FUN_00487160(0,&local_8,&local_10);
  if ((cVar1 != '\0') &&
     (cVar1 = FUN_00487160(1,&local_c,&local_14), iVar3 = local_8, iVar4 = local_10, cVar1 != '\0'))
  {
    if (local_c < local_8) {
      local_8 = local_c;
      local_c = iVar3;
    }
    if (local_14 < local_10) {
      local_10 = local_14;
      local_14 = iVar4;
    }
    uVar2 = FUN_00495150();
    FUN_00494c20(local_8,local_10,local_8,local_14 + -1,0,uVar2);
    FUN_00494c20(local_8,local_14,local_c + -1,local_14,0,uVar2);
    FUN_00494c20(local_c,local_14,local_c,local_10 + 1,0,uVar2);
    FUN_00494c20(local_c,local_10,local_8 + 1,local_10,0,uVar2);
    FUN_00475d30();
    iVar4 = local_14;
    if (*(int *)(param_1 + 0x118) == 0) {
      iVar4 = local_c + local_8 >> 1;
      FUN_00494c20(iVar4,local_10 + 1,iVar4,local_14 + -1,0xff,uVar2);
      if (_DAT_007cd458 < DAT_0059e440) {
        iVar3 = iVar4 + -1;
        local_4 = (local_8 - iVar3) + 1;
        iVar4 = __ftol();
        iVar4 = iVar3 - iVar4;
      }
      else {
        iVar4 = iVar4 + 1;
        local_4 = (local_c - iVar4) + -1;
        iVar3 = __ftol();
        iVar3 = iVar3 + iVar4;
      }
      if ((iVar4 <= iVar3) && (iVar5 = local_10 + 1, iVar5 < local_14)) {
        do {
          FUN_00494c20(iVar4,iVar5,iVar3,iVar5,0xff0000,uVar2);
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_14);
        return 0;
      }
    }
    else {
      local_4 = (local_14 - local_10) + -1;
      iVar3 = __ftol();
      iVar3 = iVar4 - iVar3;
      if (iVar3 < iVar4) {
        do {
          FUN_00494c20(local_8 + 1,iVar3,local_c + -1,iVar3,0xff0000,uVar2);
          iVar3 = iVar3 + 1;
        } while (iVar3 < local_14);
      }
    }
  }
  return 0;
}


