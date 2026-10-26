// Function: FUN_0043af50 @ 0043af50
// Strings:  [D:\dev\F1_1999_2002\Source\hdvehicle.cpp, Could not find suspension bar %s]


void FUN_0043af50(undefined4 param_1,int param_2,double *param_3)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  char cVar13;
  int iVar14;
  double *pdVar15;
  
  iVar14 = FUN_0056eb30(param_1);
  if (iVar14 == 0) {
    if (DAT_007c569c != 5) {
      cVar13 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_hdveh_005c421c,0xaa6);
      if (cVar13 != '\0') {
        FUN_004d7aa0(&DAT_008ad25c,s_Could_not_find_suspension_bar__s_005c4248,param_1);
      }
    }
    *(undefined4 *)param_3 = 0;
    *(undefined4 *)((int)param_3 + 4) = 0;
    *(undefined4 *)(param_3 + 1) = 0;
    *(undefined4 *)((int)param_3 + 0xc) = 0;
    *(undefined4 *)(param_3 + 2) = 0;
    *(undefined4 *)((int)param_3 + 0x14) = 0;
    return;
  }
  if (*(int *)(iVar14 + 4) == param_2) {
    pdVar15 = *(double **)(iVar14 + 8);
  }
  else {
    pdVar15 = *(double **)(iVar14 + 0x10);
  }
  dVar1 = *(double *)(param_2 + 0x34);
  dVar2 = *pdVar15;
  dVar3 = *(double *)(param_2 + 0x44);
  dVar4 = pdVar15[2];
  dVar5 = *(double *)(param_2 + 0x3c);
  dVar6 = pdVar15[1];
  dVar7 = *(double *)(param_2 + 0x4c);
  dVar8 = *pdVar15;
  dVar9 = *(double *)(param_2 + 0x5c);
  dVar10 = pdVar15[2];
  dVar11 = *(double *)(param_2 + 0x54);
  dVar12 = pdVar15[1];
  *param_3 = *pdVar15 * *(double *)(param_2 + 0x1c) +
             *(double *)(param_2 + 0x24) * pdVar15[1] + *(double *)(param_2 + 0x2c) * pdVar15[2] +
             *(double *)(param_2 + 4);
  param_3[1] = dVar5 * dVar6 + dVar3 * dVar4 + dVar1 * dVar2 + *(double *)(param_2 + 0xc);
  param_3[2] = dVar11 * dVar12 + dVar9 * dVar10 + dVar7 * dVar8 + *(double *)(param_2 + 0x14);
  return;
}


