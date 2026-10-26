// Function: FUN_00583ae0 @ 00583ae0
// Size (bytes): 602


void __fastcall FUN_00583ae0(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  BOOL BVar3;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0059d046;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = &PTR_LAB_005b8b60;
  piVar1 = (int *)param_1[0x47];
  local_4 = 0xc;
  param_1[0x49] = piVar1;
  if ((piVar1 != (int *)0x0) && (iVar2 = *piVar1, iVar2 != 0)) {
    while( true ) {
      FUN_00583210(iVar2,0);
      if (param_1[0x49] == 0) break;
      piVar1 = *(int **)(param_1[0x49] + 4);
      param_1[0x49] = piVar1;
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) break;
    }
  }
  local_4 = CONCAT31(local_4._1_3_,0xb);
  if ((*(char *)(param_1 + 0x192) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[400]), BVar3 != 0)) {
    param_1[400] = 0;
  }
  FUN_005870d0();
  if ((*(char *)(param_1 + 0x188) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x186]), BVar3 != 0)) {
    param_1[0x186] = 0;
  }
  if ((*(char *)(param_1 + 0x170) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x16e]), BVar3 != 0)) {
    param_1[0x16e] = 0;
  }
  local_4._0_1_ = 8;
  if ((*(char *)(param_1 + 0x16c) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x16a]), BVar3 != 0)) {
    param_1[0x16a] = 0;
  }
  FUN_005833e0();
  local_4._0_1_ = 7;
  if ((*(char *)(param_1 + 0x165) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x163]), BVar3 != 0)) {
    param_1[0x163] = 0;
  }
  FUN_005833e0();
  local_4._0_1_ = 6;
  if ((*(char *)(param_1 + 0x15e) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x15c]), BVar3 != 0)) {
    param_1[0x15c] = 0;
  }
  FUN_005833e0();
  local_4._0_1_ = 0xd;
  FUN_00582310();
  local_4._0_1_ = 5;
  FUN_005833e0();
  local_4._0_1_ = 4;
  FUN_004b0170();
  local_4._0_1_ = 3;
  FUN_00585fb0();
  local_4._0_1_ = 0xf;
  FUN_00585fb0();
  local_4._0_1_ = 0xe;
  FUN_00585fb0();
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00586460();
  if ((*(char *)(param_1 + 0x3e) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x3c]), BVar3 != 0)) {
    param_1[0x3c] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  if ((*(char *)(param_1 + 0x37) != '\0') &&
     (BVar3 = CloseHandle((HANDLE)param_1[0x35]), BVar3 != 0)) {
    param_1[0x35] = 0;
  }
  FUN_00583650();
  local_4 = 0xffffffff;
  FUN_0058a5f7(param_1 + 1,0x28,1,FUN_00583aa0);
  ExceptionList = local_c;
  return;
}


