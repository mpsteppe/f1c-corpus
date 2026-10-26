// Function: FUN_004b9e40 @ 004b9e40
// Size (bytes): 263


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004b9e40(int *param_1)

{
  float fVar1;
  float local_8;
  undefined1 local_4 [4];
  
  switch(*(undefined4 *)(*param_1 + 0xf8c)) {
  case 0:
    FUN_004b87a0(&local_8,local_4);
    local_8 = local_8 + _DAT_0059e600;
    goto LAB_004b9e97;
  case 1:
    FUN_004b87a0(local_4,&local_8);
    local_8 = local_8 - _DAT_0059e600;
LAB_004b9e97:
    FUN_004b86e0(local_8);
    *(undefined4 *)(*param_1 + 0xf8c) = 5;
    return;
  case 2:
    fVar1 = -(float)_DAT_008afe90;
    break;
  case 3:
    FUN_004b9d00(-(float)_DAT_008afe90 * _DAT_005acd14);
    return;
  case 4:
    FUN_004b9d00(-(float)_DAT_008afe90);
    return;
  default:
    goto switchD_004b9e58_caseD_5;
  case 6:
    FUN_004b9d00((float)_DAT_008afe90);
    return;
  case 7:
    FUN_004b9d00((float)_DAT_008afe90 * _DAT_005acd14);
    return;
  case 8:
    fVar1 = (float)_DAT_008afe90;
  }
  FUN_004b9d00(fVar1 * _DAT_005acd18);
switchD_004b9e58_caseD_5:
  return;
}


