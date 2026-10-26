// Function: FUN_0044b040 @ 0044b040
// Size (bytes): 67


void FUN_0044b040(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_20 [8];
  
  FUN_00448e90();
  puVar2 = local_20;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  FUN_00448ec0(param_2);
  FUN_00449a80(local_20,0);
  return;
}


