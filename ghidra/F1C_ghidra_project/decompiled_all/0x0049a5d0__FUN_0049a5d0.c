// Function: FUN_0049a5d0 @ 0049a5d0
// Strings:  [current_page]


void __fastcall FUN_0049a5d0(undefined4 *param_1)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 uVar6;
  
  bVar1 = false;
  switch(*param_1) {
  case 1:
    bVar1 = true;
  case 2:
    puVar5 = (undefined1 *)param_1[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar5 = (undefined1 *)FUN_0049a460(puVar5);
    if ((puVar5 == (undefined1 *)0x0) &&
       (puVar5 = (undefined1 *)param_1[1], puVar5 == (undefined1 *)0x0)) {
      puVar5 = &DAT_005ea438;
    }
    iVar2 = FUN_004976c0(puVar5);
    if (iVar2 == 0) {
      return;
    }
    if (bVar1) {
      if (bVar1) {
        uVar6 = 0xffffffff;
        goto LAB_0049a643;
      }
    }
    else {
      uVar6 = 0;
LAB_0049a643:
      FUN_00497890(iVar2,uVar6);
    }
    puVar5 = *(undefined1 **)(iVar2 + 0x34);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    break;
  case 3:
    puVar5 = (undefined1 *)param_1[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar5 = (undefined1 *)FUN_0049a460(puVar5);
    if ((puVar5 == (undefined1 *)0x0) &&
       (puVar5 = (undefined1 *)param_1[1], puVar5 == (undefined1 *)0x0)) {
      puVar5 = &DAT_005ea438;
    }
    iVar2 = FUN_004976c0(puVar5);
    if (param_1[5] != 0) {
      FUN_00497d00(param_1[5]);
    }
    FUN_00497890(iVar2,1);
    puVar5 = *(undefined1 **)(iVar2 + 0x34);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    break;
  case 4:
    puVar5 = (undefined1 *)param_1[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar5 = (undefined1 *)FUN_0049a460(puVar5);
    if ((puVar5 == (undefined1 *)0x0) &&
       (puVar5 = (undefined1 *)param_1[1], puVar5 == (undefined1 *)0x0)) {
      puVar5 = &DAT_005ea438;
    }
    iVar2 = FUN_004976c0(puVar5);
    if (param_1[5] != 0) {
      FUN_00497d00(param_1[5]);
    }
    FUN_00497890(iVar2,2);
    puVar5 = *(undefined1 **)(iVar2 + 0x34);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    break;
  case 5:
    puVar5 = (undefined1 *)param_1[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar5 = (undefined1 *)FUN_0049a460(puVar5);
    if ((puVar5 == (undefined1 *)0x0) &&
       (puVar5 = (undefined1 *)param_1[1], puVar5 == (undefined1 *)0x0)) {
      puVar5 = &DAT_005ea438;
    }
    iVar2 = FUN_004976c0(puVar5);
    if (param_1[5] != 0) {
      FUN_00497d00(param_1[5]);
    }
    FUN_00497890(iVar2,3);
    puVar5 = *(undefined1 **)(iVar2 + 0x34);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    break;
  case 6:
    puVar5 = (undefined1 *)param_1[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar5 = (undefined1 *)FUN_0049a460(puVar5);
    if ((puVar5 == (undefined1 *)0x0) &&
       (puVar5 = (undefined1 *)param_1[1], puVar5 == (undefined1 *)0x0)) {
      puVar5 = &DAT_005ea438;
    }
    iVar2 = FUN_004976c0(puVar5);
    if (param_1[5] != 0) {
      FUN_00497d00(param_1[5]);
    }
    FUN_00497890(iVar2,4);
    puVar5 = *(undefined1 **)(iVar2 + 0x34);
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    break;
  case 7:
    puVar5 = (undefined1 *)param_1[1];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar5 = (undefined1 *)FUN_0049a460(puVar5);
    if ((puVar5 == (undefined1 *)0x0) &&
       (puVar5 = (undefined1 *)param_1[1], puVar5 == (undefined1 *)0x0)) {
      puVar5 = &DAT_005ea438;
    }
    iVar2 = FUN_00497650(puVar5);
    if (iVar2 != 0) {
      FUN_004974a0(iVar2);
      return;
    }
  default:
    return;
  case 9:
    puVar5 = (undefined1 *)param_1[3];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    puVar4 = (undefined1 *)param_1[1];
    if (puVar4 == (undefined1 *)0x0) {
      puVar4 = &DAT_005ea438;
    }
    FUN_0049a490(puVar4,puVar5);
    return;
  case 10:
    thunk_FUN_00495b30();
    return;
  case 0xb:
    DAT_005cc9e8 = 0xffffffff;
    return;
  case 0xc:
    puVar5 = (undefined1 *)param_1[3];
    if (puVar5 == (undefined1 *)0x0) {
      puVar5 = &DAT_005ea438;
    }
    piVar3 = (int *)FUN_00497750(puVar5);
    if (piVar3 == (int *)0x0) {
      return;
    }
    (**(code **)(*piVar3 + 0x8c))();
    FUN_004979c0(piVar3);
    (**(code **)(*piVar3 + 0x90))();
    return;
  }
  FUN_0049a490(s_current_page_005ccb44,puVar5);
  return;
}


