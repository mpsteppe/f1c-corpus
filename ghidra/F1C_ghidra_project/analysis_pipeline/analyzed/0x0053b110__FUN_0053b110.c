// Function: FUN_0053b110 @ 0053b110
// Size (bytes): 29


float10 FUN_0053b110(float param_1,float param_2)

{
  float10 fVar1;
  
  fVar1 = (float10)log2((float10)param_1);
  fVar1 = (float10)f2xm1((float10)param_2 * fVar1);
  return (float10)(float)((float10)1 + fVar1);
}


