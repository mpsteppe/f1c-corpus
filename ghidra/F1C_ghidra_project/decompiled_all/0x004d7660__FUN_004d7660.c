// Function: FUN_004d7660 @ 004d7660
// Strings:  [%s%s%s, D:\dev\F1_1999_2002\Source\tire_manager.cpp, No tire brands (*.tbc) in %s or memory allocation error, *.tbc]


void __fastcall FUN_004d7660(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int *piVar5;
  undefined1 *puVar6;
  int *piVar7;
  undefined1 local_200 [512];
  
  FUN_004d7800();
  iVar2 = FUN_00567740();
  puVar6 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar6 = &DAT_005ea438;
  }
  puVar3 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  FUN_0058815f(local_200,&DAT_005be860,puVar3,puVar6);
  FUN_00565f80(s___tbc_005d49dc,1,local_200,1);
  iVar4 = FUN_00565f70();
  *param_1 = iVar4;
  piVar5 = operator_new(iVar4 * 0x24 + 4);
  if (piVar5 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = piVar5 + 1;
    *piVar5 = iVar4;
    if (-1 < iVar4 + -1) {
      do {
        FUN_004d7020();
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  param_1[1] = (int)piVar7;
  if (((*param_1 == 0) || (piVar7 == (int *)0x0)) &&
     (cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_tire__005d45e4,0x401), cVar1 != '\0')) {
    FUN_004d7aa0(&DAT_008ad25c,s_No_tire_brands____tbc__in__s_or_m_005d49a4,local_200);
  }
  FUN_00565f50();
  iVar4 = FUN_005662d0();
  while (iVar4 != 0) {
    puVar6 = DAT_005ec428;
    if (DAT_005ec428 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    puVar3 = DAT_005ec3d8;
    if (DAT_005ec3d8 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    FUN_0058815f(local_200,s__s_s_s_005c6784,puVar3,puVar6,iVar4);
    FUN_004d7150(local_200);
    cVar1 = FUN_00565f20();
    if (cVar1 == '\0') break;
    iVar4 = FUN_005662d0();
  }
  FUN_00565eb0();
  if (iVar2 != 0x200) {
    FUN_00567780();
  }
  return;
}


