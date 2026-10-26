// Function: FUN_00406130 @ 00406130
// Size (bytes): 223


undefined4 * __thiscall FUN_00406130(undefined4 *param_1,int param_2)

{
  HANDLE pvVar1;
  undefined4 *puVar2;
  int local_10;
  _SECURITY_ATTRIBUTES local_c;
  
  *param_1 = &PTR_LAB_0059e50c;
  puVar2 = param_1 + 4;
  local_10 = 3;
  do {
    *puVar2 = 0;
    puVar2[1] = 0xffffffff;
    FUN_00566650(&DAT_005ea438);
    puVar2[2] = 0xffffffff;
    puVar2[3] = 0xffffffff;
    *(undefined1 *)(puVar2 + 4) = 0;
    puVar2 = puVar2 + 5;
    local_10 = local_10 + -1;
  } while (local_10 != 0);
  param_1[0x14] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  param_1[0x15] = 0xffffffff;
  local_c.nLength = 0xc;
  local_c.lpSecurityDescriptor = (LPVOID)0x0;
  local_c.bInheritHandle = 1;
  pvVar1 = CreateMutexA(&local_c,0,(LPCSTR)0x0);
  param_1[0x14] = pvVar1;
  if (pvVar1 != (HANDLE)0x0) {
    *(undefined1 *)(param_1 + 0x16) = 1;
  }
  *param_1 = &PTR_FUN_0059e4ec;
  param_1[1] = 0x3f800000;
  param_1[2] = param_2;
  param_1[3] = 0;
  puVar2 = param_1 + 7;
  param_2 = 3;
  do {
    FUN_00566650(&DAT_005ea438);
    puVar2[-1] = 0xffffffff;
    *puVar2 = 0xffffffff;
    *(undefined1 *)(puVar2 + 1) = 0;
    puVar2 = puVar2 + 5;
    param_2 = param_2 + -1;
  } while (param_2 != 0);
  if (*(char *)(param_1 + 0x16) != '\0') {
    FUN_00406700(0);
  }
  param_1[0x17] = 0xffffffff;
  return param_1;
}


