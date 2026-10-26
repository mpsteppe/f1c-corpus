// Function: FUN_004c77d0 @ 004c77d0
// Size (bytes): 283


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004c77d0(int param_1)

{
  float fVar1;
  int iVar2;
  char cVar3;
  float10 fVar4;
  float10 fVar5;
  
  if ((*(int *)(param_1 + 13000) != 0) && (*(int *)(param_1 + 13000) != 1)) {
    return;
  }
  cVar3 = FUN_00461db0();
  if (cVar3 != '\0') {
    if (DAT_0059e440 <= *(float *)(param_1 + 0x48b8)) {
      if (_DAT_0059e7ec < *(float *)(param_1 + 0x48b8)) {
        *(undefined4 *)(param_1 + 0x48b8) = 0x40a00000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x48b8) = 0;
    }
    fVar1 = *(float *)(param_1 + 0x48b8) - (float)_DAT_008afe90;
    *(float *)(param_1 + 0x48b8) = fVar1;
    if (DAT_0059e440 < fVar1) {
      return;
    }
    fVar4 = (float10)FUN_00462ff0(*(undefined4 *)(param_1 + 0x4894),0xbf800000);
    fVar5 = fVar4 + (float10)*(float *)(param_1 + 0x48b8);
    if (fVar5 < (float10)(float)-fVar4) {
      fVar5 = (float10)(float)-fVar4;
    }
    *(float *)(param_1 + 0x48b8) = (float)fVar5;
  }
  iVar2 = DAT_008aae64;
  if (0x3fe < DAT_0083ee60) {
    FUN_004c71c0(DAT_008aae64);
    FUN_004ef2e0();
    return;
  }
  DAT_0083ee60 = DAT_0083ee60 + 1;
  DAT_008aae64 = DAT_008aae64 + 0x1b0;
  FUN_004c71c0(iVar2);
  FUN_004ef2e0();
  return;
}


