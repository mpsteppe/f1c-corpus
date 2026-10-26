// Function: FUN_004b9b80 @ 004b9b80
// Size (bytes): 256


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004b9b80(int *param_1,float param_2)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *extraout_EDX;
  float10 fVar5;
  float local_c;
  float local_8;
  
  if (param_2 == _DAT_005acd04) {
    fVar5 = (float10)FUN_004b8790();
    param_2 = (float)fVar5;
    param_1 = extraout_EDX;
  }
  fVar1 = *(float *)(*param_1 + 0xf3c);
  local_8 = param_2;
  local_c = fVar1;
  if (param_2 < fVar1) {
    local_c = param_2;
    local_8 = fVar1;
  }
  FUN_004b9510(local_c,local_8,param_2 >= fVar1);
  FUN_004b3b40();
  FUN_005895a2((double)(local_c * _DAT_0059e86c));
  iVar3 = __ftol();
  FUN_005895a2((double)(local_8 * _DAT_0059e86c));
  iVar4 = __ftol();
  iVar2 = DAT_005c329c;
  if ((iVar3 != iVar4) && (iVar3 = 0, 0 < DAT_005c329c)) {
    do {
      FUN_004ee2d0();
      FUN_004e3a50(param_2);
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar2);
  }
  return;
}


