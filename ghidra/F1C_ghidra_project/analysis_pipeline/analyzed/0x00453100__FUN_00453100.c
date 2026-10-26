// Function: FUN_00453100 @ 00453100
// Size (bytes): 150


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00453100(int *param_1)

{
  float fVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  
  cVar3 = FUN_00404f10();
  if ((cVar3 != '\0') && (DAT_007c569c == 5)) {
    param_1[9] = 0;
    param_1[10] = 0;
    return;
  }
  iVar2 = *param_1;
  if (iVar2 == 0) {
    uVar4 = FUN_0044f460(param_1[1]);
    uVar4 = uVar4 & 0xff;
  }
  else {
    if (iVar2 != 1) {
      if (iVar2 != 2) {
        return;
      }
      fVar1 = *(float *)(param_1[8] + 4);
      param_1[10] = (int)ABS(fVar1);
      if (ABS(fVar1) <= (float)_DAT_0059e880) {
        param_1[9] = 0;
        return;
      }
      param_1[9] = 1;
      return;
    }
    uVar4 = *(uint *)(param_1[7] + 0x10);
  }
  param_1[9] = uVar4;
  if (uVar4 == 0) {
    param_1[10] = DAT_0059e440;
    return;
  }
  param_1[10] = _DAT_0059e43c;
  return;
}


