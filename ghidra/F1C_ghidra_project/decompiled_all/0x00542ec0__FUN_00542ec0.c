// Function: FUN_00542ec0 @ 00542ec0
// Strings:  [%s\%s, Could not locate bitmap file %s]


undefined4 __thiscall FUN_00542ec0(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  char local_700;
  undefined4 local_6ff;
  undefined1 local_400 [256];
  char local_300;
  undefined4 local_2ff;
  
  if ((param_2 != (char *)0x0) && (DAT_008b8e28 != 0)) {
    local_700 = DAT_005ea438;
    puVar7 = &local_6ff;
    for (iVar4 = 0xbf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = 0;
    *(undefined1 *)((int)puVar7 + 2) = 0;
    local_300 = DAT_005ea438;
    puVar7 = &local_2ff;
    for (iVar4 = 0xbf; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = 0;
    *(undefined1 *)((int)puVar7 + 2) = 0;
    uVar5 = 0xffffffff;
    pcVar8 = param_2;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    if (0x300 < ~uVar5 - 1) {
      param_2[0x2ff] = '\0';
    }
    iVar4 = -(int)param_2;
    do {
      cVar1 = *param_2;
      param_2[(int)(&local_700 + iVar4)] = cVar1;
      param_2 = param_2 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(&local_700);
    uVar5 = *(uint *)(param_1 + 0x18) & 0xf;
    iVar4 = FUN_00543050(&local_700,uVar5);
    if (iVar4 == 0) {
      return 0;
    }
    iVar4 = 0;
    if (0 < DAT_008b8e30) {
      puVar6 = &DAT_008b5a3c;
      do {
        FUN_0058815f(&local_300,s__s__s_005c2d64,puVar6,&local_700);
        iVar2 = FUN_00543050(&local_300,uVar5);
        if (iVar2 == 0) {
          return 0;
        }
        iVar4 = iVar4 + 1;
        puVar6 = puVar6 + 0x84;
      } while (iVar4 < DAT_008b8e30);
    }
    if (iVar4 == DAT_008b8e30) {
      iVar4 = 0;
      for (iVar2 = DAT_008b8f14; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x130)) {
        iVar3 = FUN_00560050(param_1,&local_700);
        if (iVar3 == 0) {
          return 0;
        }
        iVar4 = iVar4 + 1;
      }
    }
    else {
      iVar4 = -1;
    }
    if (iVar4 == DAT_008b6ac0) {
      FUN_0058815f(local_400,s_Could_not_locate_bitmap_file__s_005dbd94,&local_300);
      FUN_0053c590(0xffffffff,local_400);
    }
  }
  return 0xffffffff;
}


