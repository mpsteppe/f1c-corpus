// Function: FUN_00414600 @ 00414600
// Strings:  [%stv%s_, %spws%s_]


undefined4 __thiscall FUN_00414600(undefined4 *param_1,char param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 local_100 [128];
  undefined1 local_80 [128];
  
  puVar1 = (undefined1 *)*param_1;
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  puVar10 = DAT_005ec470;
  if (DAT_005ec470 == (undefined1 *)0x0) {
    puVar10 = &DAT_005ea438;
  }
  FUN_0058815f(local_80,s__spws_s__005c23ac,puVar10,puVar1);
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23a8);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00415d90(param_1 + 4,param_1[2],0,1,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23a4);
  iVar3 = FUN_00414900();
  if (iVar3 != 0) {
    FUN_00415d90(param_1 + 9,param_1[2],0,1,0);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23a0);
  iVar4 = FUN_00414900();
  if (iVar4 != 0) {
    FUN_00415d90(param_1 + 0xe,param_1[2],0,0,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c239c);
  iVar5 = FUN_00414900();
  if (iVar5 != 0) {
    FUN_00415d90(param_1 + 0x13,param_1[2],0,0,0);
  }
  puVar1 = (undefined1 *)*param_1;
  if (puVar1 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  puVar10 = DAT_005ec470;
  if (DAT_005ec470 == (undefined1 *)0x0) {
    puVar10 = &DAT_005ea438;
  }
  FUN_0058815f(local_80,s__stv_s__005c2394,puVar10,puVar1);
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23a8);
  iVar6 = FUN_00414900();
  if (iVar6 != 0) {
    FUN_00415d90(param_1 + 0x18,param_1[2],1,1,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23a4);
  iVar7 = FUN_00414900();
  if (iVar7 != 0) {
    FUN_00415d90(param_1 + 0x1d,param_1[2],1,1,0);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23a0);
  iVar8 = FUN_00414900();
  if (iVar8 != 0) {
    FUN_00415d90(param_1 + 0x22,param_1[2],1,0,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c239c);
  iVar9 = FUN_00414900();
  if (iVar9 != 0) {
    FUN_00415d90(param_1 + 0x27,param_1[2],1,0,0);
  }
  if ((param_2 != '\0') &&
     (iVar9 != 0 &&
      (iVar8 != 0 &&
      (iVar7 != 0 && (iVar6 != 0 && (iVar5 != 0 && (iVar4 != 0 && (iVar3 != 0 && iVar2 != 0))))))))
  {
    FUN_004149a0();
    return 1;
  }
  return 0;
}


