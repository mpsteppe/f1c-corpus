// Function: FUN_004491c0 @ 004491c0
// Size (bytes): 233


undefined4 __thiscall FUN_004491c0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int local_50;
  undefined1 local_48 [72];
  
  FUN_00448f00(local_48);
  iVar5 = 0;
  do {
    cVar3 = FUN_00448fc0(local_48,*(undefined4 *)(param_2 + iVar5 * 8));
    if (cVar3 != '\0') {
      return 1;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  FUN_00448f00(local_48);
  iVar5 = 0;
  do {
    cVar3 = FUN_00448fc0(local_48,*(undefined4 *)(param_1 + iVar5 * 8));
    if (cVar3 != '\0') {
      return 1;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 3);
  iVar5 = 0;
  do {
    if (iVar5 == 2) {
      iVar4 = 0;
    }
    else {
      iVar4 = iVar5 + 1;
    }
    uVar1 = *(undefined4 *)(param_1 + iVar4 * 8);
    uVar2 = *(undefined4 *)(param_2 + iVar5 * 8);
    local_50 = 0;
    do {
      if (iVar5 == 2) {
        iVar4 = 0;
      }
      else {
        iVar4 = iVar5 + 1;
      }
      cVar3 = FUN_00449000(*(undefined4 *)(param_1 + iVar5 * 8),uVar1,uVar2,
                           *(undefined4 *)(param_2 + iVar4 * 8));
      if (cVar3 != '\0') {
        return 1;
      }
      local_50 = local_50 + 1;
    } while (local_50 < 3);
    iVar5 = iVar5 + 1;
    if (2 < iVar5) {
      return 0;
    }
  } while( true );
}


