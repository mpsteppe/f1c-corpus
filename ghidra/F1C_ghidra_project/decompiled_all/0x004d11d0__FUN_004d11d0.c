// Function: FUN_004d11d0 @ 004d11d0
// Strings:  [%s%02d:%02d, %s%02d:%02d]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d11d0(undefined4 param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined1 local_80 [128];
  
  if (param_2 == (undefined1 *)0x0) {
    param_2 = &DAT_005ea438;
  }
  uVar1 = __ftol();
  uVar2 = __ftol();
  FUN_0058815f(local_80,s__s_02d__02d_005d3bcc,param_2,uVar1,uVar2);
  FUN_0045bde0(local_80,0);
  uVar1 = __ftol();
  uVar2 = __ftol();
  FUN_0058815f(local_80,s__s_02d__02d_005d3bcc,param_2,uVar1,uVar2);
  FUN_0045bd10(local_80,3,0x1020304);
  return;
}


