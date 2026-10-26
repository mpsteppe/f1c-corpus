// Function: FUN_0044657d @ 0044657d
// Size (bytes): 2637


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0044657d(void)

{
  double *pdVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  float fVar6;
  bool bVar7;
  char cVar8;
  int iVar9;
  int extraout_EDX;
  double *pdVar10;
  int unaff_EBX;
  double *unaff_EBP;
  int unaff_ESI;
  undefined4 unaff_EDI;
  undefined2 in_FPUStatusWord;
  float10 fVar11;
  undefined4 uStack0000001c;
  undefined4 in_stack_00000024;
  double in_stack_00000028;
  char cStack0000004c;
  char cStack0000004d;
  char cStack0000004e;
  undefined1 uStack0000004f;
  char in_stack_00000050;
  undefined4 in_stack_00000064;
  float in_stack_0000006c;
  double in_stack_00000090;
  double in_stack_00000098;
  double in_stack_000000a0;
  double in_stack_000000a8;
  double in_stack_000000c4;
  double in_stack_000000d4;
  int in_stack_00000100;
  float in_stack_00000110;
  
  if (((POPCOUNT((byte)((ushort)in_FPUStatusWord >> 8) & 5) & 1U) != 0) &&
     (cVar8 = FUN_00443af0(*(undefined4 *)(unaff_EBP + 0x29),*(undefined4 *)((int)unaff_EBP + 0x14c)
                          ), cVar8 != '\0')) {
    FUN_00447e00(extraout_EDX + -1,4);
  }
  if ((in_stack_00000100 < -1) || (in_stack_00000100 == *(int *)(unaff_EBP + 6))) {
    if (unaff_EBX != unaff_ESI) {
      if ((DAT_007cc1b8 == unaff_ESI) && (DAT_007cc1bc == 0x59)) {
        bVar7 = false;
      }
      else {
        bVar7 = true;
      }
      if (unaff_EBX == 1) {
        iVar9 = *(int *)((int)unaff_EBP + 0x1ef4);
        if (((!bVar7) || (-1 < iVar9)) && (iVar9 < *(int *)((int)unaff_EBP + 0x1eac))) {
          iVar9 = iVar9 + 1;
LAB_0044662b:
          FUN_00447e00(iVar9,unaff_ESI);
        }
      }
      else if (unaff_EBX == -1) {
        iVar9 = *(int *)((int)unaff_EBP + 0x1ef4);
        if (bVar7) {
          if ((-1 < iVar9) && (iVar9 != 1)) {
LAB_0044662a:
            iVar9 = iVar9 + -1;
            goto LAB_0044662b;
          }
        }
        else if (-1 < iVar9) goto LAB_0044662a;
      }
    }
  }
  else {
    FUN_00447e00(in_stack_00000100,1);
    *(int *)(unaff_EBP + 6) = in_stack_00000100;
  }
  if (in_stack_00000024._3_1_ != '\0') {
    FUN_00447e00(unaff_ESI,1);
    *(int *)(unaff_EBP + 6) = unaff_ESI;
  }
  **(double **)(unaff_EBP + 0x2c6) =
       *(double *)((int)unaff_EBP + 0x163c) * *unaff_EBP + *(double *)((int)unaff_EBP + 0x1634);
  **(double **)((int)unaff_EBP + 0x1644) = unaff_EBP[0x2ca] * *unaff_EBP + unaff_EBP[0x2c9];
  *(int *)(unaff_EBP + 0x2e) = unaff_ESI;
  *(int *)((int)unaff_EBP + 0x174) = unaff_ESI;
  if ((cStack0000004c != '\0') && (in_stack_00000064._2_1_ == '\0')) {
    iVar9 = *(int *)((int)unaff_EBP + 0x1e14) - unaff_ESI;
    if (*(int *)((int)unaff_EBP + 0x1e14) == unaff_ESI) {
      in_stack_00000028 = (*(double *)((int)unaff_EBP + 0x10fc) + unaff_EBP[0x193]) * _DAT_0059e880;
    }
    else if (iVar9 == 1) {
      in_stack_00000028 =
           (*(double *)((int)unaff_EBP + 0x10fc) + unaff_EBP[0x193] +
            *(double *)((int)unaff_EBP + 0x834) + unaff_EBP[0x7a]) * _DAT_0059eb50;
    }
    else if (iVar9 == 2) {
      in_stack_00000028 = (*(double *)((int)unaff_EBP + 0x834) + unaff_EBP[0x7a]) * _DAT_0059e880;
    }
    dVar2 = in_stack_00000028 * unaff_EBP[0x2a] + unaff_EBP[0x2b];
    dVar3 = _DAT_0059e430;
    if ((_DAT_0059e430 <= dVar2) && (dVar3 = dVar2, _DAT_0059e420 < dVar2)) {
      dVar3 = _DAT_0059e420;
    }
    in_stack_00000028 = unaff_EBP[1];
    if (cStack0000004c == '\x01') {
      dVar2 = unaff_EBP[0x2c];
    }
    else {
      dVar2 = unaff_EBP[0x2d];
    }
    unaff_EBP[1] = ((dVar3 - _DAT_0059e420) * dVar2 + _DAT_0059e420) * unaff_EBP[1];
    unaff_EBP[0x2e] = in_stack_00000028 - unaff_EBP[1];
  }
  if (*(int *)(unaff_EBP + 0x3a6) == unaff_ESI) {
    if (in_stack_00000050 != '\0') {
      if (*(double *)((int)unaff_EBP + 0x1c84) <= *(double *)((int)unaff_EBP + 0x1c5c)) {
        if (*(double *)((int)unaff_EBP + 0x1c5c) < *(double *)((int)unaff_EBP + 0x1c8c)) {
          in_stack_0000006c = _DAT_0059e43c - in_stack_0000006c;
          dVar2 = (*(double *)((int)unaff_EBP + 0x1c8c) - *(double *)((int)unaff_EBP + 0x1c5c)) /
                  (*(double *)((int)unaff_EBP + 0x1c8c) - *(double *)((int)unaff_EBP + 0x1c84));
          if (in_stack_0000006c <= (float)dVar2) {
            in_stack_0000006c = (float)dVar2;
          }
          unaff_EBP[4] = (double)in_stack_0000006c;
          goto LAB_00446a0f;
        }
        *(int *)((int)unaff_EBP + 0x24) = unaff_ESI;
      }
      else {
        *(undefined4 *)((int)unaff_EBP + 0x24) = unaff_EDI;
      }
      *(int *)(unaff_EBP + 4) = unaff_ESI;
    }
LAB_00446a0f:
    if (_DAT_0059eba0 <= unaff_EBP[4]) {
      if (unaff_EBP[4] <= _DAT_0059eb38) {
        unaff_EBP[4] = (unaff_EBP[4] - _DAT_0059eba0) * _DAT_0059e930;
      }
      else {
        *(int *)(unaff_EBP + 4) = unaff_ESI;
        *(undefined4 *)((int)unaff_EBP + 0x24) = unaff_EDI;
      }
    }
    else {
      *(int *)(unaff_EBP + 4) = unaff_ESI;
      *(int *)((int)unaff_EBP + 0x24) = unaff_ESI;
    }
  }
  else {
    *(int *)(unaff_EBP + 4) = unaff_ESI;
    if (*(int *)(unaff_EBP + 0x3a6) == 1) {
      *(undefined4 *)((int)unaff_EBP + 0x24) = unaff_EDI;
      if (*(double *)((int)unaff_EBP + 0x1d3c) < *(double *)((int)unaff_EBP + 0x1c5c)) {
        if (*(double *)((int)unaff_EBP + 0x1d44) <= *(double *)((int)unaff_EBP + 0x1c5c)) {
          *(int *)(unaff_EBP + 1) = unaff_ESI;
          *(int *)((int)unaff_EBP + 0xc) = unaff_ESI;
        }
        else {
          dVar2 = (*(double *)((int)unaff_EBP + 0x1d44) - *(double *)((int)unaff_EBP + 0x1c5c)) /
                  (*(double *)((int)unaff_EBP + 0x1d44) - *(double *)((int)unaff_EBP + 0x1d3c));
          if (dVar2 < unaff_EBP[1]) {
            unaff_EBP[1] = dVar2;
          }
        }
      }
    }
    else {
      *(int *)((int)unaff_EBP + 0x24) = unaff_ESI;
      if ((*(int *)(unaff_EBP + 0x3de) == 1) &&
         (unaff_EBP[0x3c7] < *(double *)((int)unaff_EBP + 0x1c5c))) {
        iVar9 = *(int *)((int)unaff_EBP + 0x1e14) - unaff_ESI;
        if (*(int *)((int)unaff_EBP + 0x1e14) == unaff_ESI) {
          in_stack_00000028 =
               (unaff_EBP[0x1ac] - unaff_EBP[0x1cf]) * unaff_EBP[0x192] +
               (*(double *)((int)unaff_EBP + 0x11c4) - *(double *)((int)unaff_EBP + 0x12dc)) *
               *(double *)((int)unaff_EBP + 0x10f4);
        }
        else if (iVar9 == 1) {
          in_stack_00000028 =
               (unaff_EBP[0x93] - unaff_EBP[0xb6]) * unaff_EBP[0x79] +
               (*(double *)((int)unaff_EBP + 0x8fc) - *(double *)((int)unaff_EBP + 0xa14)) *
               *(double *)((int)unaff_EBP + 0x82c) +
               (unaff_EBP[0x1ac] - unaff_EBP[0x1cf]) * unaff_EBP[0x192] +
               (*(double *)((int)unaff_EBP + 0x11c4) - *(double *)((int)unaff_EBP + 0x12dc)) *
               *(double *)((int)unaff_EBP + 0x10f4);
        }
        else if (iVar9 == 2) {
          in_stack_00000028 =
               (unaff_EBP[0x93] - unaff_EBP[0xb6]) * unaff_EBP[0x79] +
               (*(double *)((int)unaff_EBP + 0x8fc) - *(double *)((int)unaff_EBP + 0xa14)) *
               *(double *)((int)unaff_EBP + 0x82c);
        }
        unaff_EBP[4] = _DAT_0059e420 -
                       ((*(double *)((int)unaff_EBP + 0x1d34) / unaff_EBP[0x3d7]) *
                       in_stack_00000028) / unaff_EBP[0x3cb];
        if (_DAT_0059e430 <= unaff_EBP[4]) {
          if (_DAT_0059e420 < unaff_EBP[4]) {
            *(undefined4 *)((int)unaff_EBP + 0x24) = unaff_EDI;
            goto LAB_0044691a;
          }
        }
        else {
          *(int *)((int)unaff_EBP + 0x24) = unaff_ESI;
LAB_0044691a:
          *(int *)(unaff_EBP + 4) = unaff_ESI;
        }
        if (*(double *)((int)unaff_EBP + 0x1d3c) < *(double *)((int)unaff_EBP + 0x1c5c)) {
          if (*(double *)((int)unaff_EBP + 0x1d44) <= *(double *)((int)unaff_EBP + 0x1c5c)) {
            *(int *)(unaff_EBP + 1) = unaff_ESI;
            *(int *)((int)unaff_EBP + 0xc) = unaff_ESI;
          }
          else {
            dVar2 = (*(double *)((int)unaff_EBP + 0x1d44) - *(double *)((int)unaff_EBP + 0x1c5c)) /
                    (*(double *)((int)unaff_EBP + 0x1d44) - *(double *)((int)unaff_EBP + 0x1d3c));
            if (dVar2 < unaff_EBP[1]) {
              unaff_EBP[1] = dVar2;
            }
          }
        }
      }
      if (*(double *)((int)unaff_EBP + 0x1c5c) < *(double *)((int)unaff_EBP + 0x1c84)) {
        *(int *)(unaff_EBP + 4) = unaff_ESI;
        *(undefined4 *)((int)unaff_EBP + 0x24) = unaff_EDI;
      }
    }
  }
  if (*(int *)(unaff_EBP + 0x1a) != unaff_ESI) {
    if (*(int *)(unaff_EBP + 0x1a) == 1) {
      if ((*(int *)(unaff_EBP + 0x3de) != unaff_ESI) && (*(int *)(unaff_EBP + 0x3a6) != 1)) {
        *(int *)(unaff_EBP + 0x1a) = unaff_ESI;
        goto LAB_00446a89;
      }
    }
    else {
      *(int *)(unaff_EBP + 4) = unaff_ESI;
      *(undefined4 *)((int)unaff_EBP + 0x24) = unaff_EDI;
    }
    *(int *)(unaff_EBP + 2) = unaff_ESI;
    *(undefined4 *)((int)unaff_EBP + 0x14) = unaff_EDI;
  }
LAB_00446a89:
  in_stack_000000a8 = *(double *)((int)unaff_EBP + 0x155c) * unaff_EBP[2];
  in_stack_00000098 = (_DAT_0059e420 - *(double *)((int)unaff_EBP + 0x1564)) * in_stack_000000a8;
  in_stack_00000090 = in_stack_00000098;
  in_stack_000000a8 = in_stack_000000a8 * *(double *)((int)unaff_EBP + 0x1564);
  in_stack_000000a0 = in_stack_000000a8;
  if (cStack0000004e != '\0') {
    if (cStack0000004e == '\x01') {
      uStack0000001c = 0x3fdccccc;
      in_stack_00000028 = 0.15;
      dVar2 = _DAT_0059edd8;
    }
    else {
      uStack0000001c = 0x3feccccc;
      in_stack_00000028 = 0.3;
      dVar2 = _DAT_0059ea68;
    }
    iVar9 = *(int *)(unaff_EBP + 0x2be);
    in_stack_000000c4 =
         *(double *)(iVar9 + 0x1c) * *(double *)(iVar9 + 100) +
         *(double *)(iVar9 + 0x34) * *(double *)(iVar9 + 0x6c) +
         *(double *)(iVar9 + 0x4c) * *(double *)(iVar9 + 0x74);
    in_stack_000000d4 =
         *(double *)(iVar9 + 0x44) * *(double *)(iVar9 + 0x6c) +
         *(double *)(iVar9 + 0x5c) * *(double *)(iVar9 + 0x74) +
         *(double *)(iVar9 + 0x2c) * *(double *)(iVar9 + 100);
    if ((_DAT_0059eea8 <
         in_stack_000000c4 * in_stack_000000c4 + in_stack_000000d4 * in_stack_000000d4) &&
       (in_stack_000000d4 < _DAT_0059e430)) {
      fVar11 = (float10)fpatan(-(float10)in_stack_000000c4,-(float10)in_stack_000000d4);
      fVar11 = (fVar11 - (float10)*(double *)((int)unaff_EBP + 0x94) * (float10)*unaff_EBP) -
               ((float10)*(double *)(iVar9 + 0x24) * (float10)*(double *)(iVar9 + 0x7c) +
               (float10)*(double *)(iVar9 + 0x3c) * (float10)*(double *)(iVar9 + 0x84) +
               (float10)*(double *)(iVar9 + 0x54) * (float10)*(double *)(iVar9 + 0x8c)) *
               (float10)_DAT_0059eba0;
      if (fVar11 <= (float10)_DAT_0059e430) {
        fVar11 = fVar11 + (float10)dVar2;
        if ((float10)_DAT_0059e430 < fVar11) goto LAB_00446c1f;
      }
      else {
        fVar11 = fVar11 - (float10)dVar2;
        if (fVar11 < (float10)_DAT_0059e430) goto LAB_00446c1f;
      }
      if (fVar11 != (float10)_DAT_0059e430) {
        fVar11 = fVar11 * (float10)(double)CONCAT44(uStack0000001c,0xcccccccd);
        if (fVar11 <= (float10)in_stack_00000028) {
          if (fVar11 < (float10)-in_stack_00000028) {
            fVar11 = (float10)-in_stack_00000028;
          }
        }
        else {
          fVar11 = (float10)in_stack_00000028;
        }
        iVar9 = 0;
        in_stack_00000090 = (double)((float10)in_stack_00000098 - fVar11);
        in_stack_00000098 = (double)((float10)in_stack_00000098 + fVar11);
        in_stack_000000a0 = (double)((float10)in_stack_000000a8 - fVar11);
        in_stack_000000a8 = (double)((float10)in_stack_000000a8 + fVar11);
        do {
          if (_DAT_0059e430 <= (&stack0x00000090)[iVar9]) {
            if (_DAT_0059e420 < (&stack0x00000090)[iVar9]) {
              *(undefined4 *)((int)&stack0x00000090 + iVar9 * 8 + 4) = unaff_EDI;
              goto LAB_00446d7e;
            }
          }
          else {
            *(int *)((int)&stack0x00000090 + iVar9 * 8 + 4) = unaff_ESI;
LAB_00446d7e:
            *(int *)(&stack0x00000090 + iVar9) = unaff_ESI;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < 4);
        fVar11 = ABS(fVar11) * (float10)_DAT_0059edd0;
        if ((float10)_DAT_0059edc8 < fVar11) {
          fVar11 = (float10)_DAT_0059edc8;
        }
        if ((float10)unaff_EBP[1] < fVar11) {
          unaff_EBP[1] = (double)fVar11;
        }
      }
    }
  }
LAB_00446c1f:
  fVar6 = in_stack_00000110 * (float)*(double *)((int)unaff_EBP + 0x1554);
  in_stack_000000a0 = (double)((float)in_stack_000000a0 + fVar6);
  in_stack_000000a8 = (double)((float)in_stack_000000a8 + fVar6);
  if (cStack0000004d != '\0') {
    if (*(char *)(unaff_EBP + 0x2f) == '\0') {
      pdVar10 = unaff_EBP + 0x7a;
      iVar9 = 4;
      dVar2 = _DAT_0059e420;
      do {
        if (*pdVar10 < dVar2) {
          dVar2 = *pdVar10;
        }
        pdVar10 = (double *)((int)pdVar10 + 0x464);
        iVar9 = iVar9 + -1;
      } while (iVar9 != 0);
      dVar3 = *(double *)((int)unaff_EBP + 0x17c);
      dVar4 = *(double *)((int)unaff_EBP + 0x184);
      if (cStack0000004d == '\x01') {
        dVar5 = *(double *)((int)unaff_EBP + 0x18c);
      }
      else {
        dVar5 = *(double *)((int)unaff_EBP + 0x194);
      }
      iVar9 = 0;
      do {
        iVar9 = iVar9 + 1;
        *(double *)(&stack0x00000088 + iVar9 * 8) =
             (((dVar2 * dVar3 + dVar4) - _DAT_0059e420) * dVar5 + _DAT_0059e420) *
             *(double *)(&stack0x00000088 + iVar9 * 8);
      } while (iVar9 < 4);
    }
    else {
      iVar9 = 0;
      pdVar10 = unaff_EBP + 0x7a;
      if (cStack0000004d == '\x01') {
        do {
          dVar2 = *pdVar10 * *(double *)((int)unaff_EBP + 0x17c) +
                  *(double *)((int)unaff_EBP + 0x184);
          dVar3 = _DAT_0059e430;
          if ((_DAT_0059e430 <= dVar2) && (dVar3 = dVar2, _DAT_0059e420 < dVar2)) {
            dVar3 = _DAT_0059e420;
          }
          iVar9 = iVar9 + 1;
          pdVar10 = (double *)((int)pdVar10 + 0x464);
          *(double *)(&stack0x00000088 + iVar9 * 8) =
               ((dVar3 - _DAT_0059e420) * *(double *)((int)unaff_EBP + 0x18c) + _DAT_0059e420) *
               *(double *)(&stack0x00000088 + iVar9 * 8);
        } while (iVar9 < 4);
      }
      else {
        do {
          dVar2 = *pdVar10 * *(double *)((int)unaff_EBP + 0x17c) +
                  *(double *)((int)unaff_EBP + 0x184);
          dVar3 = _DAT_0059e430;
          if ((_DAT_0059e430 <= dVar2) && (dVar3 = dVar2, _DAT_0059e420 < dVar2)) {
            dVar3 = _DAT_0059e420;
          }
          iVar9 = iVar9 + 1;
          pdVar10 = (double *)((int)pdVar10 + 0x464);
          *(double *)(&stack0x00000088 + iVar9 * 8) =
               ((dVar3 - _DAT_0059e420) * *(double *)((int)unaff_EBP + 0x194) + _DAT_0059e420) *
               *(double *)(&stack0x00000088 + iVar9 * 8);
        } while (iVar9 < 4);
      }
    }
  }
  iVar9 = *(int *)(unaff_EBP + 0x3e0);
  if ((((*(int *)(iVar9 + 0x834) == unaff_ESI) || (*(char *)(iVar9 + 0x874) == '\0')) ||
      (*(int *)(iVar9 + 0x95c) == unaff_ESI)) || (*(char *)(iVar9 + 0x99c) == '\0')) {
    in_stack_00000090 = 0.0;
    in_stack_00000098 = 0.0;
  }
  if (((*(int *)(iVar9 + 0xa84) == unaff_ESI) || (*(char *)(iVar9 + 0xac4) == '\0')) ||
     ((*(int *)(iVar9 + 0xbac) == unaff_ESI || (*(char *)(iVar9 + 0xbec) == '\0')))) {
    in_stack_000000a0 = 0.0;
    in_stack_000000a8 = 0.0;
  }
  iVar9 = 0;
  pdVar10 = unaff_EBP + 0xcd;
  do {
    pdVar1 = &stack0x00000090 + iVar9;
    iVar9 = iVar9 + 1;
    pdVar10[-0x60] = *pdVar1 * pdVar10[1] + *pdVar10;
    pdVar10 = (double *)((int)pdVar10 + 0x464);
  } while (iVar9 < 4);
  FUN_00443b70(uStack0000004f,in_stack_00000050);
  return;
}


