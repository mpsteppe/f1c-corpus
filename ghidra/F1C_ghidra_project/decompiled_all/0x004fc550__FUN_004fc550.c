// Function: FUN_004fc550 @ 004fc550
// Strings:  [COMMON\, LOGOMAP.MAS, WCCLOUDR, WCCLOUDS]


void __thiscall FUN_004fc550(int param_1,char param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 local_c;
  undefined1 *local_8;
  undefined4 local_4;
  
  local_c = 0;
  local_8 = operator_new(0x100);
  *local_8 = 0;
  local_4 = 0x100;
  puVar1 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_00566650(puVar1);
  puVar1 = DAT_005ec420;
  if (DAT_005ec420 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_005665b0(puVar1);
  FUN_005665b0(s_COMMON__005d3c34);
  FUN_005665b0(s_LOGOMAP_MAS_005d3c3c);
  puVar1 = local_8;
  if (local_8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  iVar2 = FUN_0053cbc0(&local_c,puVar1);
  if (iVar2 == 0) {
    if (param_2 != '\0') {
      FUN_004fc2f0(local_c);
    }
    FUN_004fc400(s_WCCLOUDS_005d6f5c,param_1 + 0x50);
    FUN_004fc400(s_WCCLOUDR_005d6f50,param_1 + 0x84);
    FUN_0053ce40(local_c);
  }
  if (local_8 != (undefined1 *)0x0) {
    FUN_00587bcf(local_8);
  }
  return;
}


