
undefined4 __fastcall FUN_0048e3a0(int param_1)

{
  int *piVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar1 = (int *)(param_1 + 0xe4);
  uVar5 = 0;
  if (*(int *)(param_1 + 0xe4) != 0) {
    FUN_00551f80(*(int *)(param_1 + 0xe4));
  }
  puVar2 = *(undefined1 **)(param_1 + 0xb0);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  puVar3 = operator_new(0x80);
  *puVar3 = 0;
  puVar2 = DAT_005ec3f0;
  if (DAT_005ec3f0 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_00566650(puVar2);
  puVar2 = *(undefined1 **)(param_1 + 0xb8);
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  FUN_005665b0(puVar2);
  puVar2 = puVar3;
  if (puVar3 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  iVar4 = FUN_00551f10(piVar1,puVar2,0,0);
  *(undefined4 *)(param_1 + 0xec) = 0;
  *(undefined4 *)(param_1 + 0xe8) = 0;
  if (iVar4 == 0) {
    iVar4 = *piVar1;
    *(undefined1 *)(param_1 + 0xf8) = 0;
    if (iVar4 != 0) {
      *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(iVar4 + 0xc);
      *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(iVar4 + 0x10);
      FUN_00551eb0(DAT_007cf2cc);
    }
  }
  else {
    *piVar1 = 0;
    uVar5 = 1;
  }
  if (puVar3 != (undefined1 *)0x0) {
    FUN_00587bcf(puVar3);
  }
  return uVar5;
}

