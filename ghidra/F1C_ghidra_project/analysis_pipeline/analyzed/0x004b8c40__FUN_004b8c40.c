// Function: FUN_004b8c40 @ 004b8c40
// Size (bytes): 331


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b8c40(float param_1,char param_2)

{
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  float10 fVar1;
  undefined4 uVar2;
  
  uVar2 = 0x3f800000;
  switch(param_1) {
  case 0.0:
    fVar1 = (float10)FUN_004b8790();
    param_1 = (float)(fVar1 - (float10)_DAT_008afe90);
    if ((param_2 == '\0') && (param_1 < *(float *)(extraout_ECX + 0xf88))) {
      param_1 = *(float *)(extraout_ECX + 0xf88);
    }
    FUN_004b86e0(param_1);
    *(undefined4 *)(extraout_ECX_00 + 0xf8c) = 4;
    break;
  case 1.4013e-45:
    fVar1 = (float10)FUN_004b8790();
    FUN_004b86e0((float)fVar1);
    *(undefined4 *)(extraout_ECX_01 + 0xf8c) = 5;
    FUN_004c8d60();
    return;
  case 2.8026e-45:
    fVar1 = (float10)FUN_004b8790();
    FUN_004b86e0((float)(fVar1 + (float10)_DAT_008afe90));
    *(undefined4 *)(extraout_ECX_02 + 0xf8c) = 6;
    break;
  case 4.2039e-45:
    fVar1 = (float10)FUN_004b8790();
    FUN_004b86e0((float)((float10)_DAT_008afe90 * (float10)_DAT_005acb58 + fVar1));
    *(undefined4 *)(extraout_ECX_03 + 0xf8c) = 6;
    uVar2 = 0x3f000000;
    break;
  case 5.60519e-45:
    fVar1 = (float10)FUN_004b8790();
    FUN_004b86e0((float)((float10)_DAT_008afe90 * (float10)_DAT_005acd64 + fVar1));
    *(undefined4 *)(extraout_ECX_04 + 0xf8c) = 7;
    uVar2 = 0x3fd5c28f;
    break;
  default:
    if (param_1 == 1.4013e-45) {
      FUN_004c8d60(0x3f800000);
      return;
    }
  }
  FUN_004c8d70(uVar2);
  FUN_004c8dc0(uVar2);
  return;
}


