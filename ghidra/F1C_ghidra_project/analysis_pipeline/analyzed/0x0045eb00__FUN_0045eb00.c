// Function: FUN_0045eb00 @ 0045eb00
// Size (bytes): 67


void __thiscall FUN_0045eb00(float *param_1,float *param_2,float param_3)

{
  float fVar1;
  float fVar2;
  
  fVar1 = param_1[1];
  fVar2 = param_1[2];
  *param_2 = param_3 * *param_1;
  param_2[1] = param_3 * fVar1;
  param_2[2] = param_3 * fVar2;
  return;
}


