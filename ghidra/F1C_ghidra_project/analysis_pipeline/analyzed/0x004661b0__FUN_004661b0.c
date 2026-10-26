// Function: FUN_004661b0 @ 004661b0
// Size (bytes): 153


undefined4 __fastcall FUN_004661b0(int *param_1)

{
  float fVar1;
  float10 fVar2;
  
  if (param_1[0x3a] != 0) {
    FUN_00496750(param_1,0);
  }
  if (DAT_0059e440 <= (float)param_1[0x49]) {
    fVar2 = (float10)FUN_00498730();
    fVar1 = (float)param_1[0x49];
    param_1[0x49] = (int)(float)((float10)fVar1 - fVar2);
    if ((float10)fVar1 - fVar2 < (float10)DAT_0059e440) {
      FUN_004988a0(1);
      (**(code **)(*param_1 + 0xac))();
    }
  }
  if (((char)param_1[0x3d] != '\0') || (*(char *)((int)param_1 + 0xf5) != '\0')) {
    FUN_00466350();
  }
  FUN_00466650();
  (**(code **)(*param_1 + 0x2c))(1);
  (**(code **)(*param_1 + 0xa8))();
  return 0;
}


