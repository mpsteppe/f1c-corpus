// Function: FUN_004e2ca0 @ 004e2ca0
// Size (bytes): 91


void __thiscall FUN_004e2ca0(int param_1,float param_2)

{
  int iVar1;
  float fVar2;
  
  if (param_2 != *(float *)(param_1 + 0x970)) {
    fVar2 = param_2 / *(float *)(param_1 + 0x970);
    *(float *)(param_1 + 0x970) = param_2;
    FUN_004e2a00(*(undefined4 *)(param_1 + 4),fVar2,0);
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x44);
    if (iVar1 != 0) {
      FUN_004e2a00(iVar1,fVar2,1);
    }
  }
  return;
}


