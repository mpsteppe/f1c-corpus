
undefined4 __fastcall FUN_0046dd30(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 auStack_84 [132];
  
  iVar2 = (**(code **)(**(int **)(param_1 + 0x40) + 0x1c))(0x22);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_00489940();
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  iVar2 = FUN_00489950();
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  uVar3 = FUN_00587ece(iVar2);
  FUN_00461550();
  cVar1 = FUN_00462010(uVar3,auStack_84,0,0,&stack0xffffff7b);
  if ((cVar1 != '\0') && (iVar2 = FUN_004615f0(2), iVar2 != 0)) {
    iVar2 = -1;
    pcVar4 = &DAT_007cd850;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (iVar2 == -2) {
      FUN_00497940(s_Multi_Client_Password_Entry_005c6c70,0xffffffff);
      FUN_004988d0(s_Client_Password_Entry_005c6c58);
      goto LAB_0046ddfb;
    }
  }
  cVar1 = FUN_00462c00(uVar3,&DAT_007cd850);
  if (cVar1 != '\0') {
    *(undefined4 *)(param_1 + 0xe4) = 0x40800000;
  }
LAB_0046ddfb:
  FUN_004b0170();
  return 0xffffffff;
}

