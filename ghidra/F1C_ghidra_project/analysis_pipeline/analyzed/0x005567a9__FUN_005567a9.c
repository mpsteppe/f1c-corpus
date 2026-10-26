// Function: FUN_005567a9 @ 005567a9
// Size (bytes): 42


undefined8 __fastcall FUN_005567a9(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = (int)param_3 < 0;
  if (bVar2) {
    param_3 = -param_3;
  }
  iVar1 = (int)(CONCAT44(((int)param_3 >> 0x1f) << 0x10 | param_3 >> 0x10,param_3 << 0x10) /
               (longlong)param_4);
  if (bVar2) {
    iVar1 = -iVar1;
  }
  return CONCAT44(param_2,iVar1);
}


