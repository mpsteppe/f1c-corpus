// Function: FUN_00418ac0 @ 00418ac0
// Size (bytes): 174


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00418ac0(int param_1)

{
  int iVar1;
  int *extraout_ECX;
  int *piVar2;
  int iVar3;
  int extraout_EDX;
  int iVar4;
  int iVar5;
  int *piVar6;
  float10 fVar7;
  
  fVar7 = (float10)_DAT_008afea8;
  piVar6 = (int *)(param_1 + 0x864);
  iVar5 = -1;
  iVar3 = 0;
  piVar2 = piVar6;
  iVar1 = -1;
  do {
    if ((piVar2[3] != -0x40800000) && ((float10)(float)piVar2[3] < fVar7)) {
      fVar7 = (float10)FUN_004144d0();
      piVar2 = extraout_ECX;
      iVar3 = extraout_EDX;
    }
    iVar4 = iVar3;
    if ((*piVar2 == -1) && (iVar4 = iVar1, iVar5 == -1)) {
      iVar5 = iVar3;
    }
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 8;
    iVar1 = iVar4;
  } while (iVar3 < 0x14);
  if ((iVar4 != -1) && (iVar5 < iVar4)) {
    iVar3 = 1;
    do {
      if (*piVar6 == -1) {
        iVar1 = iVar3;
        piVar2 = piVar6;
        if (0x13 < iVar3) {
          return;
        }
        while (piVar2[8] == -1) {
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 8;
          if (0x13 < iVar1) {
            return;
          }
        }
        FUN_004145c0(iVar1 * 0x20 + 0x864 + param_1);
        FUN_004144d0();
      }
      iVar3 = iVar3 + 1;
      piVar6 = piVar6 + 8;
    } while (iVar3 < 0x14);
  }
  return;
}


