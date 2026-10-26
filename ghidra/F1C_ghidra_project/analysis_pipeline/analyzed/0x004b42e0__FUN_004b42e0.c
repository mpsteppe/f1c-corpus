// Function: FUN_004b42e0 @ 004b42e0
// Size (bytes): 116


undefined4 FUN_004b42e0(undefined4 param_1,undefined4 param_2,uint *param_3)

{
  uint *puVar1;
  undefined1 uVar2;
  
  puVar1 = param_3;
  FUN_00566bd0(param_3,4);
  if (((*puVar1 & 0xe0000000) == 0x20000000) && ((*puVar1 & 0xfc0000) == 0)) {
    uVar2 = __ftol();
    param_3 = (uint *)CONCAT31(param_3._1_3_,uVar2);
    FUN_00566bd0(&param_3,1);
  }
  FUN_00566bd0(puVar1 + 2,*puVar1 >> 8 & 0x3ff);
  return 1;
}


