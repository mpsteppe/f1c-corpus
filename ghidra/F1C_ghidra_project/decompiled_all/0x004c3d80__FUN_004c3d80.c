// Function: FUN_004c3d80 @ 004c3d80
// Strings:  [%s%s%s, D:\dev\F1_1999_2002\Source\setup.cpp, Failed reading data for %s, *.veh]


int FUN_004c3d80(void)

{
  char cVar1;
  undefined1 *puVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  int iVar6;
  undefined1 local_200 [512];
  
  FUN_00565eb0();
  puVar5 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  puVar2 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_0058815f(local_200,&DAT_005be860,puVar2,puVar5);
  FUN_00565f80(s___veh_005d3098,1,local_200,1);
  if (DAT_008ac394 != (int *)0x0) {
    iVar6 = *(int *)((int)DAT_008ac394 + -4);
    iVar3 = (int)DAT_008ac394 + -4;
    if (-1 < iVar6 + -1) {
      do {
        FUN_004c3130();
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    FUN_00587bcf(iVar3);
  }
  iVar3 = FUN_00565f70();
  piVar4 = operator_new(iVar3 * 0x424 + 4);
  if (piVar4 == (int *)0x0) {
    DAT_008ac394 = (int *)0x0;
    piVar4 = DAT_008ac394;
  }
  else {
    *piVar4 = iVar3;
    piVar4 = piVar4 + 1;
    if (-1 < iVar3 + -1) {
      do {
        FUN_004c3050();
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  DAT_008ac394 = piVar4;
  FUN_00565f50();
  iVar3 = FUN_005662d0();
  while (iVar3 != 0) {
    puVar5 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar2 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar2 = &DAT_005ea438;
    }
    FUN_0058815f(local_200,s__s_s_s_005c6784,puVar2,puVar5,iVar3);
    FUN_00589901(local_200);
    FUN_00566650(local_200);
    iVar3 = FUN_004c3200();
    if (iVar3 == 0) {
      DAT_008ac390 = DAT_008ac390 + 1;
    }
    else {
      cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_setup_005d3044,0x204);
      if (cVar1 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_Failed_reading_data_for__s_005d307c,local_200);
      }
    }
    cVar1 = FUN_00565f20();
    if (cVar1 == '\0') break;
    iVar3 = FUN_005662d0();
  }
  FUN_00565eb0();
  FUN_004c4240();
  return DAT_008ac390;
}


