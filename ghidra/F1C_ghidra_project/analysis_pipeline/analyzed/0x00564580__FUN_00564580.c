// Function: FUN_00564580 @ 00564580
// Size (bytes): 29


float10 FUN_00564580(double param_1)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_005644f0();
  if (iVar1 == 0) {
    return (float10)param_1;
  }
  fVar2 = (float10)FUN_0058850f(*(undefined4 *)(iVar1 + 4));
  return fVar2;
}


