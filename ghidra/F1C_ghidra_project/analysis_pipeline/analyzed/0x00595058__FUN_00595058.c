// Function: FUN_00595058 @ 00595058
// Size (bytes): 53


uint FUN_00595058(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = FUN_005950a3();
  uVar1 = uVar1 & ~param_2 | param_1 & param_2;
  FUN_00595135(uVar1);
  return uVar1;
}


