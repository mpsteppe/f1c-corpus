// Function: FUN_00581d40 @ 00581d40
// Size (bytes): 314


undefined4 * __fastcall FUN_00581d40(undefined4 *param_1)

{
  undefined4 *puVar1;
  HANDLE pvVar2;
  int iVar3;
  int *local_28;
  _SECURITY_ATTRIBUTES local_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_0059cba9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  local_4 = 1;
  uStack_3 = 0;
  local_28 = operator_new(4);
  local_4 = 2;
  if (local_28 == (int *)0x0) {
    local_28 = (int *)0x0;
  }
  else {
    puVar1 = operator_new(0x26c);
    local_4 = 3;
    if (puVar1 == (undefined4 *)0x0) {
      *local_28 = 0;
    }
    else {
      *puVar1 = 2;
      FUN_0058a6eb(puVar1 + 1,0x134,2,FUN_00581e80,FUN_0057bc70);
      *local_28 = (int)(puVar1 + 1);
    }
  }
  _local_4 = CONCAT31(uStack_3,1);
  FUN_00586000(local_28,1);
  iVar3 = 0;
  do {
    FUN_00583210(*local_28 + iVar3,0);
    iVar3 = iVar3 + 0x134;
  } while (iVar3 < 0x268);
  param_1[8] = 0;
  *(undefined1 *)(param_1 + 10) = 0;
  param_1[9] = 0xffffffff;
  local_18.nLength = 0xc;
  local_18.lpSecurityDescriptor = (LPVOID)0x0;
  local_18.bInheritHandle = 1;
  pvVar2 = CreateMutexA(&local_18,0,(LPCSTR)0x0);
  param_1[8] = pvVar2;
  if (pvVar2 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 10) = 1;
  }
  ExceptionList = local_c;
  return param_1;
}


