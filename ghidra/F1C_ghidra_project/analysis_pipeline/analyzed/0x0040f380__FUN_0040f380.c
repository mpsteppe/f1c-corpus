// Function: FUN_0040f380 @ 0040f380
// Size (bytes): 257


void __fastcall FUN_0040f380(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  float *pfVar3;
  int iVar4;
  float local_c;
  float local_8;
  float local_4;
  
  switch(*(undefined4 *)(param_1 + 0x1c)) {
  case 0:
  case 1:
  case 3:
  case 4:
  case 5:
    FUN_004ea040(param_1,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0xd0),
                 *(int *)(param_1 + 0x20) + 0xd4);
    return;
  case 2:
    iVar1 = *(int *)(param_1 + 0x20);
    iVar4 = *(int *)(iVar1 + 0xd0);
    local_c = (float)*(double *)(iVar1 + 0x138);
    local_8 = (float)*(double *)(iVar1 + 0x140);
    local_4 = (float)*(double *)(iVar1 + 0x148);
    FUN_0054fb40(1);
    pfVar3 = &local_c;
    break;
  case 6:
    if ((*(byte *)(**(int **)(param_1 + 0x20) + 0x48bc) & 1) == 0) {
      return;
    }
    iVar4 = (*(int **)(param_1 + 0x20))[0x1ba];
    FUN_0054fb40(1);
    pfVar3 = (float *)(*(int *)(param_1 + 0x20) + 0x34ec);
    break;
  case 7:
    uVar2 = *(undefined4 *)(param_1 + 0x20);
    FUN_0054fb40(1);
    FUN_004e9a40(0);
    FUN_0054f7a0(uVar2,1);
    FUN_0054fb40(0);
  default:
    return;
  }
  FUN_004e9a40(pfVar3);
  FUN_0054f7a0(iVar4,1);
  FUN_0054fb40(0);
  return;
}


