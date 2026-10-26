// Function: FUN_00556790 @ 00556790
// Size (bytes): 25


undefined8 __fastcall FUN_00556790(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  longlong lVar1;
  
  lVar1 = (longlong)param_3 * (longlong)param_4 + 0x8000;
  return CONCAT44(param_2,(uint)lVar1 >> 0x10 | (int)((ulonglong)lVar1 >> 0x20) << 0x10);
}


