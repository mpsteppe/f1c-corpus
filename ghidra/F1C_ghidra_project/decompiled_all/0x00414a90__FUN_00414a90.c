// Function: FUN_00414a90 @ 00414a90
// Strings:  [%s%s%s\tv%s_, %s%s%s\pws%s_]


undefined4 __fastcall FUN_00414a90(undefined4 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 local_100 [128];
  undefined1 local_80 [128];
  
  puVar4 = (undefined1 *)*param_1;
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  puVar3 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  puVar1 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_80,s__s_s_s_pws_s__005c23d8,puVar1,puVar3,puVar4,puVar4);
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23d4);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417640(param_1 + 3,param_1[2],0,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23d0);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417640(param_1 + 8,param_1[2],0,0);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23cc);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417af0(param_1 + 0xd,param_1[2],0,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&PTR_LAB_00454451_3_005c23c8);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417af0(param_1 + 0x12,param_1[2],0,0);
  }
  puVar4 = (undefined1 *)*param_1;
  if (puVar4 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  puVar3 = DAT_005ec428;
  if (DAT_005ec428 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  puVar1 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_80,s__s_s_s_tv_s__005c23b8,puVar1,puVar3,puVar4,puVar4);
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23d4);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417640(param_1 + 0x17,param_1[2],1,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23d0);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417640(param_1 + 0x1c,param_1[2],1,0);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&DAT_005c23cc);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417af0(param_1 + 0x21,param_1[2],1,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,&PTR_LAB_00454451_3_005c23c8);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417af0(param_1 + 0x26,param_1[2],1,0);
  }
  return 0;
}


