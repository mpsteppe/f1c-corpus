// Function: FUN_004b03f0 @ 004b03f0
// Strings:  [PlayerNameNeverUsed]


undefined4 __fastcall FUN_004b03f0(int param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 local_120 [32];
  undefined1 local_100;
  undefined4 local_ff;
  
  FUN_00565dc0();
  FUN_0058815f(local_120,&PTR_DAT_005d1ff0,&DAT_005cc1f4);
  puVar1 = DAT_005ec440;
  if (DAT_005ec440 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00565f80(local_120,1,puVar1,1);
  FUN_00566380(2);
  iVar2 = FUN_005662d0();
  if (iVar2 == 0) {
    FUN_004b09a0(s_PlayerNameNeverUsed_005c6970);
    uVar3 = FUN_004b03f0();
    *(undefined1 *)(param_1 + 0x49a8) = 1;
    *(undefined1 *)(param_1 + 0x49a9) = 1;
  }
  else {
    local_100 = DAT_005ea438;
    puVar5 = &local_ff;
    for (iVar4 = 0x3f; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    *(undefined2 *)puVar5 = 0;
    *(undefined1 *)((int)puVar5 + 2) = 0;
    puVar1 = DAT_005ec440;
    if (DAT_005ec440 == (undefined1 *)0x0) {
      puVar1 = &DAT_005ea438;
    }
    FUN_0058815f(&local_100,&DAT_005be860,puVar1,iVar2);
    uVar3 = FUN_004b04e0(&local_100,1);
  }
  FUN_00565e20();
  return uVar3;
}


