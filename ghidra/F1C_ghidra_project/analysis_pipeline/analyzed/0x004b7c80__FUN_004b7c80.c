// Function: FUN_004b7c80 @ 004b7c80
// Size (bytes): 339


int __thiscall
FUN_004b7c80(int param_1,undefined4 param_2,undefined4 param_3,float param_4,float param_5)

{
  float fVar1;
  undefined4 *puVar2;
  float *pfVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int iVar9;
  int local_408;
  undefined1 local_400 [1024];
  
  puVar2 = *(undefined4 **)(param_1 + 0x714);
  iVar6 = 0;
  local_408 = 0;
  *(undefined4 **)(param_1 + 0x71c) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    pfVar7 = (float *)*puVar2;
    while (pfVar3 = pfVar7, pfVar3 != (float *)0x0) {
      fVar1 = *pfVar3;
      if (param_5 < fVar1) {
        return iVar6;
      }
      if (*(int *)(param_1 + 0x71c) != 0) {
        *(undefined4 *)(param_1 + 0x71c) = *(undefined4 *)(*(int *)(param_1 + 0x71c) + 4);
      }
      if (*(undefined4 **)(param_1 + 0x71c) == (undefined4 *)0x0) {
        pfVar7 = (float *)0x0;
      }
      else {
        pfVar7 = (float *)**(undefined4 **)(param_1 + 0x71c);
      }
      if (param_4 <= fVar1) {
        FUN_00566db0(pfVar3[1]);
        iVar6 = local_408;
        if (pfVar7 == (float *)0x0) {
          cVar4 = FUN_00566d70();
          if (cVar4 == '\0') {
            return local_408;
          }
          iVar9 = FUN_00566e20();
          iVar9 = iVar9 - (int)pfVar3[1];
          FUN_00566db0(pfVar3[1]);
        }
        else {
          iVar9 = (int)pfVar7[1] - (int)pfVar3[1];
        }
        while (local_408 = iVar6, 0 < iVar9) {
          iVar8 = 0x400;
          if (iVar9 < 0x401) {
            iVar8 = iVar9;
          }
          FUN_00566c00(local_400,iVar8);
          iVar5 = FUN_00566bd0(local_400,iVar8);
          if (iVar5 == iVar8) {
            iVar9 = iVar9 - iVar8;
            iVar6 = iVar6 + iVar8;
          }
        }
      }
    }
  }
  return iVar6;
}


