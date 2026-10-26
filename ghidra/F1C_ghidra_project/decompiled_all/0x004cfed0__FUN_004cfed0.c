// Function: FUN_004cfed0 @ 004cfed0
// Strings:  [D:\dev\F1_1999_2002\Source\specialfx.cpp, Entered SpecialFX::Post()]


void __fastcall FUN_004cfed0(undefined4 *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_speci_005d3624,0xd2b);
  if (cVar1 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_SpecialFX__Post___005d39f0);
  }
  iVar3 = param_1[1];
  *param_1 = 0;
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004ca280();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar3 + -4);
    param_1[1] = 0;
  }
  FUN_0044c470();
  iVar3 = param_1[3];
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_00499ae0();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar3 + -4);
  }
  iVar3 = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  if (0 < (int)param_1[4]) {
    do {
      FUN_004cb4f0();
      iVar3 = iVar3 + 1;
    } while (iVar3 < (int)param_1[4]);
  }
  iVar3 = param_1[5];
  if (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + -4);
    if (-1 < iVar2 + -1) {
      do {
        FUN_004ca410();
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    FUN_00587bcf(iVar3 + -4);
  }
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return;
}


