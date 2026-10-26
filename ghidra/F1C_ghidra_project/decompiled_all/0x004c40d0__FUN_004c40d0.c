// Function: FUN_004c40d0 @ 004c40d0
// Strings:  [%s%s%s, D:\dev\F1_1999_2002\Source\setup.cpp, Could not find %s, %scommon\%s]


undefined4 FUN_004c40d0(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  undefined1 local_100 [256];
  
  iVar2 = FUN_00587c20(param_1,&DAT_005beb48);
  if (iVar2 == 0) {
    uVar4 = 0xffffffff;
    do {
      pcVar7 = param_2;
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      pcVar7 = param_2 + 1;
      cVar1 = *param_2;
      param_2 = pcVar7;
    } while (cVar1 != '\0');
    uVar4 = ~uVar4;
    iVar2 = -1;
    pcVar9 = param_1;
    do {
      pcVar8 = pcVar9;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar8 = pcVar9 + 1;
      cVar1 = *pcVar9;
      pcVar9 = pcVar8;
    } while (cVar1 != '\0');
    pcVar7 = pcVar7 + -uVar4;
    pcVar9 = pcVar8 + -1;
    for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
  }
  if (param_3 != 0) {
    FUN_0058815f(local_100,&DAT_005be860,param_3,param_1);
    iVar2 = FUN_00587db0(local_100,&DAT_005c36f0);
    if (iVar2 != 0) goto LAB_004c41ca;
  }
  puVar6 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar6 = &DAT_005ea438;
  }
  puVar3 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_0058815f(local_100,s__s_s_s_005c6784,puVar3,puVar6,param_1);
  iVar2 = FUN_00587db0(local_100,&DAT_005c36f0);
  if (iVar2 == 0) {
    puVar6 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    FUN_0058815f(local_100,s__scommon__s_005d30b4,puVar6,param_1);
    iVar2 = FUN_00587db0(local_100,&DAT_005c36f0);
    if (iVar2 == 0) {
      if ((DAT_007c569c != 5) &&
         (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x2c0), cVar1 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find__s_005d30a0,param_1);
      }
      return 0xffffffff;
    }
  }
LAB_004c41ca:
  FUN_00587d02(iVar2);
  FUN_00566650(local_100);
  return 0;
}


