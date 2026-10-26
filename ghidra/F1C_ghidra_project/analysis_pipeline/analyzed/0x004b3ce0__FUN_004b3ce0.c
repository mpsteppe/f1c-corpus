// Function: FUN_004b3ce0 @ 004b3ce0
// Size (bytes): 78


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_004b3ce0(uint *param_1)

{
  float fVar1;
  float10 fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar3 = FUN_004b3c60();
  iVar5 = 0;
  iVar4 = 0;
  do {
    iVar5 = iVar5 + (iVar3 >> ((byte)iVar4 & 0x1f) & 1U);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x20);
  fVar1 = (float)param_1[(*param_1 & 0xff) + 0x101];
  fVar2 = (float10)_DAT_0059e450;
  *param_1 = *param_1 + 1;
  return ((float10)fVar1 * fVar2 + (float10)(iVar5 + -0x10)) * (float10)_DAT_005accf8;
}


