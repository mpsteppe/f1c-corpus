// Function: FUN_005427d0 @ 005427d0
// Strings:  [%s\%s, Could not locate bitmap file %s]


undefined4 FUN_005427d0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  undefined1 local_700 [256];
  char local_600 [768];
  undefined1 local_300 [768];
  
  if (param_1 != (char *)0x0) {
    uVar5 = 0xffffffff;
    pcVar7 = param_1;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    if (0x300 < ~uVar5 - 1) {
      param_1[0x2ff] = '\0';
    }
    iVar2 = -(int)param_1;
    do {
      cVar1 = *param_1;
      param_1[(int)(local_600 + iVar2)] = cVar1;
      param_1 = param_1 + 1;
    } while (cVar1 != '\0');
    FUN_00589901(local_600);
    iVar2 = FUN_00543130(local_600,param_2,param_3,param_4);
    if (iVar2 != 0) {
      iVar2 = 0;
      if (0 < DAT_008b8e30) {
        puVar6 = &DAT_008b5a3c;
        do {
          FUN_0058815f(local_300,s__s__s_005c2d64,puVar6,local_600);
          iVar3 = FUN_00543130(local_300,param_2,param_3,param_4);
          if (iVar3 == 0) break;
          iVar2 = iVar2 + 1;
          puVar6 = puVar6 + 0x84;
        } while (iVar2 < DAT_008b8e30);
      }
      if (iVar2 == DAT_008b8e30) {
        iVar2 = 0;
        iVar3 = DAT_008b8f14;
        while ((iVar3 != 0 && (iVar4 = FUN_0055fe70(local_600,param_2,param_3,param_4), iVar4 != 0))
              ) {
          iVar3 = *(int *)(iVar3 + 0x130);
          iVar2 = iVar2 + 1;
        }
      }
      else {
        iVar2 = -1;
      }
      if (iVar2 == DAT_008b6ac0) {
        FUN_0058815f(local_700,s_Could_not_locate_bitmap_file__s_005dbd94,local_600);
        FUN_0053c590(0xffffffff,local_700);
        return 0xffffffff;
      }
    }
  }
  return 0;
}


