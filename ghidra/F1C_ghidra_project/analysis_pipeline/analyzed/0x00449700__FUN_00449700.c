// Function: FUN_00449700 @ 00449700
// Size (bytes): 218


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00449700(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  
  if (param_1[3] != 0) {
    FUN_00448da0();
  }
  if (param_1[4] != 0) {
    FUN_00448da0();
  }
  iVar6 = 0;
  if (0 < *param_1) {
    iVar7 = 0;
    do {
      iVar4 = param_1[2];
      piVar1 = (int *)(iVar4 + iVar7);
      piVar2 = (int *)(iVar4 + 8 + iVar7);
      piVar3 = (int *)(iVar4 + 4 + iVar7);
      piVar5 = (int *)(iVar4 + iVar7);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x20;
      *(double *)(*piVar3 + 4) =
           (*(double *)(*piVar1 + 0x10) + *(double *)(*piVar2 + 0x10)) * _DAT_0059e880;
      *(double *)(piVar5[3] + 4) =
           (*(double *)(piVar5[4] + 0x10) + *(double *)(piVar5[2] + 0x10)) * _DAT_0059e880;
      *(double *)(piVar5[5] + 4) =
           (*(double *)(piVar5[4] + 0x10) + *(double *)(*piVar5 + 0x10)) * _DAT_0059e880;
    } while (iVar6 < *param_1);
  }
  if (param_1[4] != 0) {
    FUN_00448de0();
  }
  iVar6 = 0;
  if (0 < *param_1) {
    iVar7 = 0;
    do {
      iVar4 = param_1[2];
      puVar8 = (undefined4 *)(iVar4 + iVar7);
      FUN_00448480(*(undefined4 *)(iVar4 + iVar7),*(undefined4 *)(iVar4 + 8 + iVar7));
      FUN_00448480(puVar8[2],puVar8[4]);
      FUN_00448480(puVar8[4],*puVar8);
      iVar6 = iVar6 + 1;
      iVar7 = iVar7 + 0x20;
    } while (iVar6 < *param_1);
  }
  return;
}


