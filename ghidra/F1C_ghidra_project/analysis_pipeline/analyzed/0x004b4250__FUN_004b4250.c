// Function: FUN_004b4250 @ 004b4250
// Size (bytes): 138


undefined4 __fastcall FUN_004b4250(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  byte local_101;
  undefined1 local_100;
  undefined4 local_ff;
  
  FUN_00566c00(param_1,4);
  local_101 = 0;
  FUN_00566c00(&local_101,1);
  local_100 = DAT_005ea438;
  puVar2 = &local_ff;
  for (iVar1 = 0x3f; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined2 *)puVar2 = 0;
  *(undefined1 *)((int)puVar2 + 2) = 0;
  if (local_101 != 0) {
    FUN_00566c00(&local_100,local_101);
  }
  (&local_100)[local_101] = 0;
  FUN_00566650(&local_100);
  return 1;
}


