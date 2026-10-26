// Function: FUN_004669a0 @ 004669a0
// Size (bytes): 138


undefined4 __fastcall FUN_004669a0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 local_40;
  undefined4 local_3f;
  
  iVar1 = *param_1;
  local_40 = DAT_005ea438;
  puVar4 = &local_3f;
  for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined2 *)puVar4 = 0;
  *(undefined1 *)((int)puVar4 + 2) = 0;
  (**(code **)(iVar1 + 0xb4))();
  uVar2 = __ftol();
  FUN_0058815f(&local_40,&DAT_005c37cc,uVar2);
  FUN_00566650(&local_40);
  return 0;
}


