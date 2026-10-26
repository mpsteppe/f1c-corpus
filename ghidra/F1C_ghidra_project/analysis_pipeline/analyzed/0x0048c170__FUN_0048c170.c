// Function: FUN_0048c170 @ 0048c170
// Size (bytes): 180


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_0048c170(int param_1)

{
  float10 fVar1;
  char cVar2;
  int iVar3;
  float10 fVar4;
  longlong lVar5;
  undefined8 uVar6;
  
  cVar2 = FUN_00486710();
  if (cVar2 != '\0') {
    return 0xffffffff;
  }
  if (*(char *)(param_1 + 0x304) != '\0') {
    fVar4 = (float10)FUN_00498730();
    fVar4 = fVar4 + (float10)*(float *)(param_1 + 0x318);
    fVar1 = (float10)_DAT_0059e908;
    *(float *)(param_1 + 0x318) = (float)fVar4;
    if (fVar1 <= fVar4) {
      *(float *)(param_1 + 0x318) =
           (float)(fVar4 - (float10)_DAT_0059e450 * (fVar4 - (float10)_DAT_0059e7fc));
      __ftol();
      lVar5 = FUN_00486720();
      iVar3 = (int)((ulonglong)lVar5 >> 0x20);
      if (((int)lVar5 != 0) && (0xffffffff < lVar5)) {
        do {
          uVar6 = FUN_00486720();
          (**(code **)((int)((ulonglong)uVar6 >> 0x20) + 0xb8))((int)uVar6 == 4);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      return 0;
    }
    return 0;
  }
  return 0xffffffff;
}


