// Function: FUN_004d8a30 @ 004d8a30
// Size (bytes): 97


undefined4 FUN_004d8a30(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = DAT_008ad3a8;
  uVar2 = 1;
  switch(param_1) {
  case 0:
    goto switchD_004d8a40_caseD_0;
  case 1:
    iVar1 = DAT_008ad398;
    break;
  case 2:
    iVar1 = DAT_008ad39c;
    break;
  case 3:
    iVar1 = DAT_008ad3a0;
    break;
  case 4:
    iVar1 = DAT_008ad3a4;
    break;
  case 5:
    FUN_004d90d0(DAT_008ad3a8);
    break;
  default:
    goto switchD_004d8a40_default;
  }
  if ((iVar1 != 0) && (DAT_008b8dc8 != 0)) {
    FUN_00553700(DAT_008b8dc8);
switchD_004d8a40_caseD_0:
    uVar2 = 0;
  }
switchD_004d8a40_default:
  return uVar2;
}


