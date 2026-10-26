// Function: FUN_00543130 @ 00543130
// Strings:  [Error opening bitmap file %s]


undefined4 FUN_00543130(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  undefined1 local_100 [256];
  
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 == 0) {
    FUN_0058815f(local_100,s_Error_opening_bitmap_file__s_005dbdec,param_1);
    FUN_0053c590(0xfffffffe,local_100);
    return 0xfffffffe;
  }
  FUN_00587f64(iVar1,0,2);
  uVar2 = FUN_0058ace6(iVar1);
  FUN_00587f64(iVar1,0,0);
  pvVar3 = operator_new(uVar2);
  FUN_0058803f(pvVar3,1,uVar2,iVar1);
  FUN_00587d02(iVar1);
  iVar1 = FUN_00540050(pvVar3,uVar2,param_2,param_3,param_4);
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  FUN_00587bcf(pvVar3);
  return 0;
}


