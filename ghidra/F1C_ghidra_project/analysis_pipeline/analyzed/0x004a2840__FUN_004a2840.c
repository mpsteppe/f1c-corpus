// Function: FUN_004a2840 @ 004a2840
// Size (bytes): 312


void __thiscall FUN_004a2840(int param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  float *pfVar8;
  
  if (*(int *)(param_1 + 0x6c) != 0) {
    iVar7 = *(int *)(param_1 + 0x70);
    iVar6 = 0;
    if (0 < iVar7) {
      pfVar8 = *(float **)(param_1 + 0x74);
      while( true ) {
        if (param_2 < *pfVar8 != (param_2 == *pfVar8)) {
          if (*(float *)(param_1 + 0x44) == *pfVar8) {
            return;
          }
          *(float *)(param_1 + 0x44) = *pfVar8;
          iVar7 = 0;
          if (*(int *)(param_1 + 0x68) < 1) {
            return;
          }
          do {
            FUN_00551210(*(undefined4 *)(*(int *)(param_1 + 0x6c) + iVar7 * 4),pfVar8[3]);
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(param_1 + 0x68));
          return;
        }
        if (param_2 < pfVar8[1] != (param_2 == pfVar8[1])) break;
        iVar6 = iVar6 + 1;
        if (iVar6 == iVar7) {
          if (*(float *)(param_1 + 0x44) == pfVar8[1]) {
            return;
          }
          *(float *)(param_1 + 0x44) = pfVar8[1];
          iVar7 = 0;
          if (*(int *)(param_1 + 0x68) < 1) {
            return;
          }
          do {
            FUN_00551210(*(undefined4 *)(*(int *)(param_1 + 0x6c) + iVar7 * 4),pfVar8[4]);
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(param_1 + 0x68));
          return;
        }
        pfVar8 = pfVar8 + 7;
        if (iVar7 <= iVar6) {
          return;
        }
      }
      if (*(float *)(param_1 + 0x44) != param_2) {
        *(float *)(param_1 + 0x44) = param_2;
        fVar1 = *pfVar8;
        iVar7 = 0;
        fVar2 = pfVar8[2];
        fVar3 = pfVar8[4];
        fVar4 = pfVar8[3];
        fVar5 = pfVar8[3];
        if (0 < *(int *)(param_1 + 0x68)) {
          do {
            FUN_00551210(*(undefined4 *)(*(int *)(param_1 + 0x6c) + iVar7 * 4),
                         (fVar3 - fVar4) * (param_2 - fVar1) * fVar2 + fVar5);
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(param_1 + 0x68));
          return;
        }
      }
    }
  }
  return;
}


