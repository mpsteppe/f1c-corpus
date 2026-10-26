// Function: FUN_00597388 @ 00597388
// Size (bytes): 386


undefined4 FUN_00597388(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  code *pcVar5;
  undefined4 *puVar6;
  undefined4 local_10;
  undefined4 local_c;
  
  bVar1 = false;
  if (param_1 == 2) {
    puVar6 = &DAT_008d41e8;
    pcVar5 = DAT_008d41e8;
LAB_0059740e:
    bVar1 = true;
    FUN_0058dfea(1);
    iVar2 = param_1;
  }
  else {
    if (((param_1 != 4) && (param_1 != 8)) && (param_1 != 0xb)) {
      if (param_1 == 0xf) {
        puVar6 = &DAT_008d41f4;
        pcVar5 = DAT_008d41f4;
      }
      else if (param_1 == 0x15) {
        puVar6 = &DAT_008d41ec;
        pcVar5 = DAT_008d41ec;
      }
      else {
        if (param_1 != 0x16) {
          return 0xffffffff;
        }
        puVar6 = &DAT_008d41f0;
        pcVar5 = DAT_008d41f0;
      }
      goto LAB_0059740e;
    }
    iVar2 = FUN_0058e0c7();
    iVar4 = FUN_0059750a(param_1,*(undefined4 *)(iVar2 + 0x50));
    puVar6 = (undefined4 *)(iVar4 + 8);
    pcVar5 = (code *)*puVar6;
  }
  if (pcVar5 == (code *)0x1) {
    if (!bVar1) {
      return 0;
    }
    FUN_0058e04b(1);
    return 0;
  }
  if (pcVar5 == (code *)0x0) {
    if (bVar1) {
      FUN_0058e04b(1);
    }
                    /* WARNING: Subroutine does not return */
    __exit(3);
  }
  if (((param_1 == 8) || (param_1 == 0xb)) || (param_1 == 4)) {
    local_c = *(undefined4 *)(iVar2 + 0x54);
    *(undefined4 *)(iVar2 + 0x54) = 0;
    if (param_1 == 8) {
      local_10 = *(undefined4 *)(iVar2 + 0x58);
      *(undefined4 *)(iVar2 + 0x58) = 0x8c;
      goto LAB_00597482;
    }
  }
  else {
LAB_00597482:
    if (param_1 == 8) {
      if (DAT_005e7888 < DAT_005e788c + DAT_005e7888) {
        iVar3 = DAT_005e7888 * 0xc;
        iVar4 = DAT_005e7888;
        do {
          iVar3 = iVar3 + 0xc;
          *(undefined4 *)(*(int *)(iVar2 + 0x50) + -4 + iVar3) = 0;
          iVar4 = iVar4 + 1;
        } while (iVar4 < DAT_005e788c + DAT_005e7888);
      }
      goto LAB_005974c0;
    }
  }
  *puVar6 = 0;
LAB_005974c0:
  if (bVar1) {
    FUN_0058e04b(1);
  }
  if (param_1 == 8) {
    (*pcVar5)(8,*(undefined4 *)(iVar2 + 0x58));
  }
  else {
    (*pcVar5)(param_1);
    if ((param_1 != 0xb) && (param_1 != 4)) {
      return 0;
    }
  }
  *(undefined4 *)(iVar2 + 0x54) = local_c;
  if (param_1 == 8) {
    *(undefined4 *)(iVar2 + 0x58) = local_10;
  }
  return 0;
}


