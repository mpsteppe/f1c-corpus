// Function: FUN_004d5880 @ 004d5880
// Strings:  ["%s" %s]


void FUN_004d5880(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  _STARTUPINFOA *p_Var4;
  _PROCESS_INFORMATION local_154;
  _STARTUPINFOA local_144;
  CHAR local_100 [256];
  
  puVar2 = DAT_007cea34;
  if (DAT_007cea34 == (undefined1 *)0x0) {
    puVar2 = &DAT_005ea438;
  }
  puVar1 = DAT_007cea18;
  if (DAT_007cea18 == (undefined1 *)0x0) {
    puVar1 = &DAT_005ea438;
  }
  FUN_0058815f(local_100,s___s___s_005d45b8,puVar1,puVar2);
  p_Var4 = &local_144;
  for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
    p_Var4->cb = 0;
    p_Var4 = (_STARTUPINFOA *)&p_Var4->lpReserved;
  }
  local_144.cb = 0x44;
  CreateProcessA((LPCSTR)0x0,local_100,(LPSECURITY_ATTRIBUTES)0x0,(LPSECURITY_ATTRIBUTES)0x0,0,0x20,
                 (LPVOID)0x0,(LPCSTR)0x0,&local_144,&local_154);
  return;
}


