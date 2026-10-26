// Function: FUN_00568b00 @ 00568b00
// Size (bytes): 159


undefined4 __fastcall FUN_00568b00(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 local_800 [2048];
  
  iVar1 = FUN_00587db0(param_1,&DAT_005be828);
  if (iVar1 != 0) {
    iVar2 = FUN_00587db0(param_2,&DAT_005c2ab0);
    if (iVar2 != 0) {
      iVar3 = FUN_0058803f(local_800,1,0x800);
      while (0 < iVar3) {
        FUN_00588678(local_800,1,iVar3,iVar2);
        iVar3 = FUN_0058803f(local_800,1,0x800,iVar1);
      }
      FUN_00587d02(iVar1);
      FUN_00587d02(iVar2);
      return 1;
    }
    FUN_00587d02(iVar1);
  }
  return 0;
}


