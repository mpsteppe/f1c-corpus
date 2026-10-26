// Function: FUN_00486730 @ 00486730
// Size (bytes): 244


uint __fastcall FUN_00486730(int param_1)

{
  char cVar1;
  float10 fVar2;
  uint uVar3;
  undefined2 extraout_var;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 uVar8;
  float10 fVar9;
  
  uVar3 = FUN_00486460(*(undefined4 *)(param_1 + 0x84));
  uVar8 = 0;
  if (uVar3 == 0) {
    return 0;
  }
  if (*(int *)(uVar3 + 0x28) == 0) {
    *(undefined4 *)(param_1 + 0x88) = 0;
    return uVar3 & 0xffffff00;
  }
  fVar9 = (float10)FUN_00498730();
  fVar9 = fVar9 + (float10)*(float *)(param_1 + 0x80);
  *(float *)(param_1 + 0x80) = (float)fVar9;
  fVar2 = (float10)*(float *)(uVar3 + 0x18);
  iVar4 = CONCAT22(extraout_var,
                   (ushort)(fVar9 < fVar2) << 8 | (ushort)(NAN(fVar9) || NAN(fVar2)) << 10 |
                   (ushort)(fVar9 == fVar2) << 0xe);
  if (fVar9 < fVar2 == 0 && (fVar9 == fVar2) == 0) {
    if ((*(int *)(param_1 + 0xdc) != 0) &&
       (iVar4 = *(int *)(param_1 + 0xdc) + -1, *(int *)(param_1 + 0xdc) = iVar4, iVar4 < 1)) {
      pcVar5 = (char *)FUN_00486280();
      if (pcVar5 != (char *)0x0) {
        iVar4 = -1;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        if (iVar4 != -2) {
          uVar6 = FUN_00486280();
          iVar4 = FUN_00497e80(uVar6);
          if (iVar4 != 0) {
            FUN_00498030(iVar4);
          }
        }
      }
    }
    *(undefined4 *)(param_1 + 0x80) = 0;
    if (*(int *)(uVar3 + 0x1c) == 0) {
      iVar4 = *(int *)(param_1 + 0x88) + 1;
      *(int *)(param_1 + 0x88) = iVar4;
      if (*(int *)(uVar3 + 0x10) <= iVar4) {
        iVar4 = *(int *)(uVar3 + 0x10);
      }
      *(int *)(param_1 + 0x88) = iVar4;
    }
    else {
      iVar4 = *(int *)(uVar3 + 0x1c) + -1;
      if (iVar4 == 0) {
        iVar7 = *(int *)(param_1 + 0x88) + 1;
        *(int *)(param_1 + 0x88) = iVar7;
        iVar4 = *(int *)(uVar3 + 0x10);
        *(int *)(param_1 + 0x88) = iVar7 % iVar4;
        return CONCAT31((int3)((uint)(iVar7 / iVar4) >> 8),1);
      }
    }
    uVar8 = 1;
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),uVar8);
}


