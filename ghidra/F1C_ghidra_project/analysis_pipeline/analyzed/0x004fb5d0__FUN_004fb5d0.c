// Function: FUN_004fb5d0 @ 004fb5d0
// Size (bytes): 250


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004fb5d0(int param_1)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar4 = *(int *)(param_1 + 0x110);
  if (iVar4 != 0) {
    fVar1 = *(float *)(param_1 + 0x3c);
    iVar7 = 7;
    iVar5 = 7;
    if (fVar1 < _DAT_0059e91c) {
      iVar6 = 7;
      do {
        iVar7 = iVar6;
        if (-1 < iVar6) {
          pfVar3 = (float *)(param_1 + 0xcc + iVar6 * 4);
          do {
            if ((float)(iVar6 + 1) < *(float *)(iVar4 + 0x50)) break;
            *pfVar3 = fVar1;
            iVar7 = iVar7 + -1;
            pfVar3 = pfVar3 + -1;
            iVar6 = iVar6 + -1;
          } while (-1 < iVar6);
        }
        if (-1 < iVar5) {
          pfVar3 = (float *)(param_1 + 0xec + iVar5 * 4);
          iVar6 = iVar5;
          do {
            if ((float)(iVar6 + 1) < *(float *)(iVar4 + 0x54)) break;
            *pfVar3 = fVar1;
            iVar5 = iVar5 + -1;
            pfVar3 = pfVar3 + -1;
            iVar6 = iVar6 + -1;
          } while (-1 < iVar6);
        }
        fVar1 = fVar1 + *(float *)(iVar4 + 0x3c);
        iVar4 = *(int *)(iVar4 + 0x110);
        if (iVar4 == 0) {
          return;
        }
        if (iVar4 == *(int *)(iVar4 + 0x110)) {
          return;
        }
        iVar6 = iVar7;
      } while (fVar1 < _DAT_0059e91c);
    }
    if (-1 < iVar7) {
      puVar2 = (undefined4 *)(param_1 + 0xcc + iVar7 * 4);
      iVar7 = iVar7 + 1;
      do {
        *puVar2 = 0x43fa0000;
        puVar2 = puVar2 + -1;
        iVar7 = iVar7 + -1;
      } while (iVar7 != 0);
    }
    if (-1 < iVar5) {
      puVar2 = (undefined4 *)(param_1 + 0xec + iVar5 * 4);
      iVar5 = iVar5 + 1;
      do {
        *puVar2 = 0x43fa0000;
        puVar2 = puVar2 + -1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      return;
    }
  }
  return;
}


