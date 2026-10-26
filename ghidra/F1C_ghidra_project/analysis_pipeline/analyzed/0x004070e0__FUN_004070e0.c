// Function: FUN_004070e0 @ 004070e0
// Size (bytes): 229


int * __thiscall FUN_004070e0(int param_1,byte param_2,float param_3,int param_4)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *local_8;
  float local_4;
  
  iVar5 = 0;
  iVar6 = 0;
  local_8 = (int *)0x0;
  _param_2 = (float)(1 << (param_2 & 0x1f));
  local_4 = param_3 * param_3;
  if (0 < *(int *)(param_1 + 0x4c)) {
    do {
      piVar1 = *(int **)(*(int *)(param_1 + 0x48) + iVar5);
      piVar7 = (int *)(*(int *)(param_1 + 0x48) + iVar5);
      if ((piVar1 == (int *)0x0) ||
         ((param_4 != 0 && (iVar4 = (**(code **)(*piVar1 + 0x1c))(), iVar4 == 2)))) break;
      fVar3 = (float)(1 << ((byte)piVar7[1] & 0x1f));
      fVar2 = (float)piVar7[2] * (float)piVar7[2];
      if (fVar3 * local_4 < fVar2 * _param_2) {
        _param_2 = fVar3;
        local_8 = piVar7;
        local_4 = fVar2;
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 0x14;
      piVar7 = local_8;
    } while (iVar6 < *(int *)(param_1 + 0x4c));
    local_8 = piVar7;
    if (local_8 != (int *)0x0) {
      if ((int *)*local_8 != (int *)0x0) {
        (**(code **)(*(int *)*local_8 + 8))();
      }
      return local_8;
    }
  }
  return (int *)0x0;
}


