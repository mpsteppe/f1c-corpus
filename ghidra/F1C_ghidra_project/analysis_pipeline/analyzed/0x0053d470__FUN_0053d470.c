// Function: FUN_0053d470 @ 0053d470
// Size (bytes): 77


int __fastcall
FUN_0053d470(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x30);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0053c2c0();
  }
  *param_1 = iVar2;
  if (iVar2 == 0) {
    return -1;
  }
  iVar2 = FUN_0053c360(param_2,param_3,param_4,param_5);
  return -(uint)(iVar2 != 0);
}


