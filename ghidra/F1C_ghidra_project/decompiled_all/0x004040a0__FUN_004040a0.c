// Function: FUN_004040a0 @ 004040a0
// Strings:  [D:\dev\F1_1999_2002\Source\ai_db.cpp, AI Database File, Entered AIDatabase::Init()]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004040a0(undefined4 *param_1)

{
  char *_Dest;
  float fVar1;
  char cVar2;
  int iVar3;
  char *_Source;
  int local_4;
  
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_ai_db_005be41c,0x7e6);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_AIDatabase__Init___005be6a8);
  }
  local_4 = 0;
  do {
    fVar1 = _DAT_0059e478;
    if (local_4 != 0) {
      fVar1 = (float)local_4;
    }
    param_1[local_4 + 0x4f] = fVar1;
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  _Dest = (char *)(param_1 + 6);
  param_1[0x4c] = 0;
  param_1[0x4d] = 0;
  param_1[0x4e] = 0;
  param_1[0x47] = 0x3f000000;
  param_1[0x48] = 0x3f800000;
  param_1[0x49] = 0x3fa66666;
  param_1[0x58] = 0x68;
  param_1[0x59] = 0x34;
  param_1[0x5a] = 3;
  param_1[0x57] = 1;
  *param_1 = 0x40980000;
  param_1[1] = 0x408a0000;
  param_1[0x52] = 0xbf800000;
  iVar3 = FUN_004c58a0(_Dest,0x100,s_AI_Database_File_005be694,0);
  if (iVar3 != 0) {
    _Source = DAT_007ce608;
    if (DAT_007ce608 == (char *)0x0) {
      _Source = &DAT_005ea438;
    }
    _strncpy(_Dest,_Source,200);
  }
  iVar3 = FUN_00587db0(_Dest,&DAT_005be690);
  if (iVar3 != 0) {
    FUN_00402690(iVar3);
    FUN_00587d02(iVar3);
  }
  if (100 < DAT_007d01a0) {
    fVar1 = (float)(DAT_007d01a0 + -100) * _DAT_0059e448;
    param_1[0x46] = fVar1 * (float)param_1[0x49] + (_DAT_0059e43c - fVar1) * (float)param_1[0x48];
    return;
  }
  fVar1 = (float)(DAT_007d01a0 + -0x46) * _DAT_0059e474;
  param_1[0x46] = fVar1 * (float)param_1[0x48] + (_DAT_0059e43c - fVar1) * (float)param_1[0x47];
  return;
}


