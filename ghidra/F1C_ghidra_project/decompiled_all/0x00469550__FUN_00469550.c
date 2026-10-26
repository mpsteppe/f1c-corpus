// Function: FUN_00469550 @ 00469550
// Strings:  [PlayerNameNeverUsed]


uint __thiscall FUN_00469550(int param_1,char *param_2)

{
  char cVar1;
  uint in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 local_200;
  undefined4 local_1ff;
  
  if (param_2 != (char *)0x0) {
    iVar2 = -1;
    in_EAX = 0;
    pcVar5 = param_2;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (iVar2 != -2) {
      iVar2 = *(int *)(param_1 + 0x450);
      iVar4 = 0;
      if (iVar2 < 1) {
LAB_00469611:
        return CONCAT31((int3)((uint)iVar2 >> 8),1);
      }
      while( true ) {
        FUN_004693e0(iVar4);
        local_200 = DAT_005ea438;
        puVar6 = &local_1ff;
        for (iVar3 = 0x7f; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = 0;
          puVar6 = puVar6 + 1;
        }
        *(undefined2 *)puVar6 = 0;
        *(undefined1 *)((int)puVar6 + 2) = 0;
        FUN_00568910(0x200);
        iVar3 = FUN_00588410(&local_200,param_2);
        if (iVar3 == 0) break;
        iVar4 = iVar4 + 1;
        if (iVar2 <= iVar4) {
          return CONCAT31((int3)((uint)iVar2 >> 8),1);
        }
      }
      in_EAX = 0;
      if (DAT_007d2e41 != '\0') {
        in_EAX = FUN_00588410(s_PlayerNameNeverUsed_005c6970,param_2);
        iVar2 = 0;
        if (in_EAX == 0) goto LAB_00469611;
      }
    }
  }
  return in_EAX & 0xffffff00;
}


