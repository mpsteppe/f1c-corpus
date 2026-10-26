// Function: FUN_004bf6a0 @ 004bf6a0
// Strings:  [QualifyingAbility]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004bf6a0(char *param_1)

{
  char cVar1;
  float fVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  float10 fVar7;
  
  fVar2 = _DAT_0059e43c;
  if (param_1 != (char *)0x0) {
    iVar4 = -1;
    pcVar6 = param_1;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    if (((iVar4 != -2) && (iVar4 = FUN_00568210(param_1), iVar4 != 0)) &&
       (iVar4 = FUN_005679c0(PTR_s_QualifyingAbility_005d263c), iVar4 != 0)) {
      uVar3 = FUN_00567970();
      fVar7 = (float10)FUN_0058850f(uVar3);
      uVar5 = DAT_008aae70 & 0xff;
      DAT_008aae70 = DAT_008aae70 + 1;
      return ((float10)*(float *)(&DAT_008aae74 + uVar5 * 4) * (float10)_DAT_0059e8c8 -
             (float10)_DAT_0059e7e8) + fVar7 / (float10)_DAT_005acdbc;
    }
  }
  return (float10)fVar2;
}


