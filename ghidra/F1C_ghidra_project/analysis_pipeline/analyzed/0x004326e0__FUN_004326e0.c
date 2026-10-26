// Function: FUN_004326e0 @ 004326e0
// Size (bytes): 296


/* WARNING: Removing unreachable block (ram,0x004327fb) */
/* WARNING: Removing unreachable block (ram,0x00432763) */

void __fastcall FUN_004326e0(int *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  int iVar8;
  
  FUN_00432180();
  FUN_00432220();
  FUN_004326d0();
  uVar3 = FUN_004326a0();
  FUN_00566650(uVar3);
  pcVar5 = &DAT_005ea438;
  iVar4 = FUN_00423a00(&DAT_005ea438,&DAT_005ec4cc);
  if (iVar4 != 0) {
    do {
      cVar1 = *pcVar5;
      pcVar5[0x2094] = cVar1;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
  }
  FUN_00566650(&DAT_005ec4cc);
  iVar4 = 0;
  do {
    iVar8 = iVar4 + 1;
    if ((iVar4 < 0) || (*(int *)(*param_1 + 0x2c) <= iVar4)) goto LAB_004327e9;
    puVar2 = *(undefined4 **)(*param_1 + 0x20);
    for (; 0 < iVar4; iVar4 = iVar4 + -1) {
      if (puVar2 == (undefined4 *)0x0) goto LAB_004327e9;
      puVar2 = (undefined4 *)puVar2[1];
    }
    if ((puVar2 == (undefined4 *)0x0) ||
       (puVar2 = (undefined4 *)*puVar2, puVar2 == (undefined4 *)0x0)) goto LAB_004327e9;
    puVar6 = (undefined1 *)*puVar2;
    if (puVar6 == (undefined1 *)0x0) {
      puVar6 = &DAT_005ea438;
    }
    iVar7 = FUN_00588410(puVar6,&DAT_005ea438);
    iVar4 = iVar8;
  } while (iVar7 != 0);
  puVar6 = (undefined1 *)*puVar2;
  if (puVar6 == (undefined1 *)0x0) {
    puVar6 = &DAT_005ea438;
  }
  FUN_00432980(puVar6);
LAB_004327e9:
  FUN_004326d0();
  return;
}


