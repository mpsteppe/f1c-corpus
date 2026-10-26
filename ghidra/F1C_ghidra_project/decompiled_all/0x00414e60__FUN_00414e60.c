// Function: FUN_00414e60 @ 00414e60
// Strings:  [%s%s%s\tv%s_, CircuitE, CircuitB, CountryE, CountryB]


undefined4 __fastcall FUN_00414e60(undefined4 *param_1)

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
  puVar3 = DAT_005ec420;
  if (DAT_005ec420 == (undefined1 *)0x0) {
    puVar3 = &DAT_005ea438;
  }
  puVar1 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_80,s__s_s_s_tv_s__005c23b8,puVar1,puVar3,puVar4,puVar4);
  FUN_0058815f(local_100,&DAT_005be860,local_80,s_CountryB_005c240c);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417f60(param_1 + 3,param_1[2],0,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,s_CountryE_005c2400);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417f60(param_1 + 8,param_1[2],0,0);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,s_CircuitB_005c23f4);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417f60(param_1 + 0xd,param_1[2],1,1);
  }
  FUN_0058815f(local_100,&DAT_005be860,local_80,s_CircuitE_005c23e8);
  iVar2 = FUN_00414900();
  if (iVar2 != 0) {
    FUN_00417f60(param_1 + 0x12,param_1[2],1,0);
  }
  return 0;
}


