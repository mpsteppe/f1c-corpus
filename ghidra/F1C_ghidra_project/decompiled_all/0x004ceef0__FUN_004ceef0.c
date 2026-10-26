// Function: FUN_004ceef0 @ 004ceef0
// Strings:  [%s%sterrain.ini]


void FUN_004ceef0(undefined4 param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  
  puVar2 = DAT_005ec420;
  if (DAT_005ec420 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  puVar1 = DAT_005ec3d8;
  if (DAT_005ec3d8 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(param_1,s__s_sterrain_ini_005d3930,puVar1,puVar2);
  return;
}


