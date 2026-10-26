// Function: FUN_00540050 @ 00540050
// Size (bytes): 102


undefined4 __thiscall
FUN_00540050(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 *param_5,int param_6)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_c;
  
  iVar1 = FUN_005006d5(param_2,param_3,&local_1c);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0xffffffff;
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = local_1c;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_18;
  }
  if (param_6 != 0) {
    FUN_0055c450(local_c,0,param_6);
  }
  return 0;
}


