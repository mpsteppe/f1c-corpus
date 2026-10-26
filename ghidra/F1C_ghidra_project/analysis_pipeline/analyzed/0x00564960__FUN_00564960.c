// Function: FUN_00564960 @ 00564960
// Size (bytes): 37


void __fastcall FUN_00564960(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int extraout_ECX;
  uint uVar2;
  uint uVar3;
  
  puVar1 = (undefined4 *)FUN_005648b0();
  uVar3 = *(uint *)(extraout_ECX + 8);
  for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *puVar1 = *param_2;
    param_2 = param_2 + 1;
    puVar1 = puVar1 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar1 = (undefined4 *)((int)puVar1 + 1);
  }
  return;
}


