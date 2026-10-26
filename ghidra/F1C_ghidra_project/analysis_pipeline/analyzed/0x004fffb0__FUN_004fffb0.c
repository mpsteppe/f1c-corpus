// Function: FUN_004fffb0 @ 004fffb0
// Size (bytes): 94


void __thiscall FUN_004fffb0(int param_1,float param_2,int param_3)

{
  float fVar1;
  
  fVar1 = *(float *)(param_3 + 4);
  if ((fVar1 < param_2 != (fVar1 == param_2)) && (*(float *)(param_1 + 0x1bc) < fVar1)) {
    FUN_004b3a90(param_3);
    return;
  }
  if ((param_2 < fVar1) && (fVar1 < *(float *)(param_1 + 0xc))) {
    FUN_004b3a90(param_3);
    return;
  }
  return;
}


