// Function: FUN_00457a00 @ 00457a00
// Size (bytes): 248


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_00457a00(int param_1,float param_2,float param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  bool bVar4;
  float fStack_14;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  FUN_00457b00(1);
  local_c = *(float *)(param_1 + 0x90);
  local_8 = *(float *)(param_1 + 0x94);
  local_4 = *(float *)(param_1 + 0x98);
  uVar3 = FUN_00456010();
  uVar3 = uVar3 & 0x80000001;
  bVar4 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar4 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
  }
  fStack_14 = 1.0;
  if (!bVar4) {
    fStack_14 = -1.0;
  }
  uVar3 = FUN_00456010();
  uVar3 = uVar3 & 0x80000001;
  bVar4 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar4 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
  }
  fStack_10 = 1.0;
  if (!bVar4) {
    fStack_10 = -1.0;
  }
  uVar3 = FUN_00456010();
  uVar3 = uVar3 & 0x80000001;
  bVar4 = uVar3 == 0;
  if ((int)uVar3 < 0) {
    bVar4 = (uVar3 - 1 | 0xfffffffe) == 0xffffffff;
  }
  fVar1 = _DAT_0059e670;
  if (bVar4) {
    fVar1 = _DAT_0059e43c;
  }
  fVar2 = param_2 * param_3 * _DAT_0059e450;
  if (_DAT_0059e450 < fVar2) {
    fVar2 = _DAT_0059e450;
  }
  local_c = fStack_14 * fVar2 * param_3 + local_c;
  local_8 = fStack_10 * fVar2 * param_3 + local_8;
  local_4 = fVar2 * fVar1 * param_3 + local_4;
  FUN_00456130(&local_c);
  return;
}


