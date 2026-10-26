// Function: FUN_00478ed0 @ 00478ed0
// Size (bytes): 164


undefined4 __fastcall FUN_00478ed0(int *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined1 *puVar5;
  
  pcVar2 = (char *)param_1[0x57];
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar4 = -1;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (iVar4 != -2) {
    puVar5 = DAT_007ce5d0;
    if (DAT_007ce5d0 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar3 = (undefined1 *)param_1[0x57];
    if (puVar3 == (undefined1 *)0x0) {
      puVar3 = &DAT_005ea438;
    }
    iVar4 = FUN_00588410(puVar3,puVar5);
    if (iVar4 == 0) goto LAB_00478f38;
  }
  puVar5 = DAT_007ce5d0;
  if (DAT_007ce5d0 == (undefined1 *)0x0) {
    puVar5 = &DAT_005ea438;
  }
  (**(code **)(*param_1 + 0xb0))(puVar5);
LAB_00478f38:
  if (((DAT_007c569c == 5) && (DAT_007d0410 == 5)) && (param_1[0x54] != 0)) {
    (**(code **)(*param_1 + 0x3c))(1);
    DAT_007cff48 = 1;
  }
  FUN_00479320();
  return 0;
}


