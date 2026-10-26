// Function: FUN_0044fcc0 @ 0044fcc0
// Size (bytes): 543


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_0044fcc0(int param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  int unaff_ESI;
  undefined4 uStack_64;
  int *piStack_60;
  int *piStack_5c;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  byte abStack_30 [48];
  
  piStack_5c = *(int **)(param_1 + 0x80);
  if (piStack_5c != (int *)0x0) {
    piStack_60 = (int *)0x44fcda;
    (**(code **)(*piStack_5c + 100))();
    piStack_60 = &iStack_54;
    uStack_64 = 0x50;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x80) + 0x24))(*(int **)(param_1 + 0x80));
    if ((iVar2 == -0x7ff8fff4) || (iVar2 == -0x7ff8ffe2)) {
      iVar2 = (**(code **)(**(int **)(param_1 + 0x80) + 0x1c))(*(int **)(param_1 + 0x80));
      if (iVar2 != 0) {
        return;
      }
      iVar2 = (**(code **)(**(int **)(param_1 + 0x80) + 0x24))
                        (*(int **)(param_1 + 0x80),0x50,&uStack_64);
    }
    if (iVar2 == 0) {
      pfVar3 = (float *)(param_1 + 0x3b8);
      iVar2 = 8;
      *(float *)(param_1 + 0x398) = (float)(int)piStack_60;
      *(float *)(param_1 + 0x39c) = (float)(int)piStack_5c;
      *(float *)(param_1 + 0x3a0) = (float)unaff_ESI;
      *(float *)(param_1 + 0x3a4) = (float)iStack_54;
      *(float *)(param_1 + 0x3a8) = (float)iStack_50;
      *(float *)(param_1 + 0x3ac) = (float)iStack_4c;
      *(float *)(param_1 + 0x3b0) = (float)iStack_48;
      *(float *)(param_1 + 0x3b4) = (float)iStack_44;
      do {
        if (pfVar3[-8] == DAT_0059e440) {
          *pfVar3 = -1.0;
        }
        else {
          fVar1 = pfVar3[-8];
          *pfVar3 = fVar1;
          if (pfVar3[-0x20] <= fVar1) {
            if ((pfVar3[-0x28] == DAT_0059e440) ||
               (*pfVar3 = fVar1 - pfVar3[-0x28], pfVar3[-0x20] <= fVar1 - pfVar3[-0x28])) {
              fVar1 = (*pfVar3 - pfVar3[-0x20]) * pfVar3[-0x10];
              *pfVar3 = fVar1;
              if (_DAT_0059e43c < fVar1) {
                *pfVar3 = 1.0;
              }
              if (pfVar3[-0x30] != 1.0) {
                fVar1 = ((_DAT_0059e43c - pfVar3[-0x30]) * *pfVar3 + pfVar3[-0x30]) * *pfVar3;
                goto LAB_0044fe8f;
              }
            }
            else {
              *pfVar3 = 0.0;
            }
          }
          else if ((pfVar3[-0x28] == DAT_0059e440) ||
                  (*pfVar3 = fVar1 + pfVar3[-0x28], fVar1 + pfVar3[-0x28] <= pfVar3[-0x20])) {
            fVar1 = (pfVar3[-0x20] - *pfVar3) * pfVar3[-0x18];
            *pfVar3 = fVar1;
            if (_DAT_0059e43c < fVar1) {
              *pfVar3 = 1.0;
            }
            if (pfVar3[-0x30] != 1.0) {
              *pfVar3 = ((_DAT_0059e43c - pfVar3[-0x30]) * *pfVar3 + pfVar3[-0x30]) * *pfVar3;
            }
            fVar1 = -*pfVar3;
LAB_0044fe8f:
            *pfVar3 = fVar1;
          }
          else {
            *pfVar3 = 0.0;
          }
        }
        pfVar3 = pfVar3 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      *(undefined4 *)(param_1 + 1000) = uStack_40;
      *(undefined4 *)(param_1 + 0x3ec) = uStack_3c;
      *(undefined4 *)(param_1 + 0x3f0) = uStack_38;
      *(undefined4 *)(param_1 + 0x3f4) = uStack_34;
      iVar2 = 0;
      do {
        *(byte *)(param_1 + 0x3d8 + iVar2) = abStack_30[iVar2] >> 7;
        iVar2 = iVar2 + 1;
      } while (iVar2 < 0x10);
    }
  }
  return;
}


