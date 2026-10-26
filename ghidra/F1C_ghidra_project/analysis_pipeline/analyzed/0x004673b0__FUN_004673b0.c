// Function: FUN_004673b0 @ 004673b0
// Size (bytes): 126


void __fastcall FUN_004673b0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_40;
  undefined4 local_3f;
  
  local_40 = DAT_005ea438;
  puVar2 = &local_3f;
  for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  if (*(int *)(param_1 + 0x32c) == 4) {
    FUN_0042f470(*(undefined4 *)(param_1 + 0x324));
  }
  else {
    FUN_0042f2f0(*(int *)(param_1 + 0x32c),*(undefined4 *)(param_1 + 0x328));
  }
  FUN_0058815f(&local_40,&DAT_005c2c18,*(int *)(param_1 + 800) + 0x1e);
  FUN_00467430(&local_40);
  return;
}


