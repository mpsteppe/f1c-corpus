// Function: FUN_0059163b @ 0059163b
// Size (bytes): 84


float10 FUN_0059163b(undefined4 param_1,double param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  float10 fVar2;
  
  if (DAT_005e9ad0 == 0) {
    fVar2 = (float10)FUN_00591bf1(1,param_1,param_2,0,param_2,param_3);
    return fVar2;
  }
  puVar1 = (undefined4 *)FUN_0058afcf();
  *puVar1 = 0x21;
  FUN_00591e66();
  return (float10)param_2;
}


