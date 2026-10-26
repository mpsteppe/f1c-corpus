// Function: FUN_004dc600 @ 004dc600
// Size (bytes): 95


void __fastcall
FUN_004dc600(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0053d1f0(param_1);
  *param_4 = 0;
  *param_3 = 0;
  if (iVar1 != 0) {
    FUN_005531f0(param_2,param_3,param_4,0);
    uVar2 = __ftol();
    *param_3 = uVar2;
    uVar2 = __ftol();
    *param_4 = uVar2;
  }
  return;
}


