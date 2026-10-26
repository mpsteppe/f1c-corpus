// Function: FUN_00580190 @ 00580190
// Size (bytes): 782


undefined1 __fastcall FUN_00580190(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  u_short uVar4;
  int iVar5;
  SOCKET s;
  undefined4 uVar6;
  sockaddr *name;
  DWORD DVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined1 local_13d;
  undefined4 local_138;
  undefined4 *local_134;
  undefined4 *local_130;
  int local_12c;
  undefined4 local_128;
  int local_124;
  int local_120;
  timeval local_11c;
  void *local_114;
  fd_set local_110;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059ca69;
  local_c = ExceptionList;
  local_110.fd_array[0] = *(SOCKET *)(param_1 + 0x938);
  local_13d = 0;
  local_11c.tv_sec = 0;
  local_11c.tv_usec = 0;
  local_110.fd_count = 1;
  ExceptionList = &local_c;
  iVar5 = select(0,&local_110,(fd_set *)0x0,(fd_set *)0x0,&local_11c);
  if ((iVar5 < -1) || (0 < iVar5)) {
    local_138._0_2_ = 2;
    local_134 = (undefined4 *)htonl(0);
    uVar4 = htons(0);
    local_138._2_1_ = (char)uVar4;
    local_138._3_1_ = (char)(uVar4 >> 8);
    local_120 = 0x10;
    s = accept(*(SOCKET *)(param_1 + 0x938),(sockaddr *)&local_138,&local_120);
    if (s != 0xffffffff) {
      if (*(HANDLE *)(param_1 + 0xbec) != (HANDLE)0x0) {
        WaitForSingleObject(*(HANDLE *)(param_1 + 0xbec),*(DWORD *)(param_1 + 0xbf0));
      }
      iVar5 = FUN_00582eb0();
      if (iVar5 == 0) {
        local_114 = operator_new(4);
        if (local_114 == (void *)0x0) {
          uVar6 = 0;
        }
        else {
          local_4 = iVar5;
          uVar6 = FUN_005830c0(0);
        }
        local_4 = 0xffffffff;
        FUN_00583530(uVar6,0);
        iVar5 = FUN_00582eb0();
      }
      if (*(HANDLE *)(param_1 + 0xbec) != (HANDLE)0x0) {
        ReleaseMutex(*(HANDLE *)(param_1 + 0xbec));
      }
      FUN_004979c0(s);
      name = (sockaddr *)FUN_0057b6a0();
      local_124 = 0x10;
      getpeername(s,name,&local_124);
      FUN_0057dc10(iVar5);
      local_128 = 1;
      setsockopt(s,6,1,(char *)&local_128,4);
      local_13d = 1;
    }
  }
  cVar3 = FUN_0057cb50(*(undefined4 *)(param_1 + 0x93c),1);
  if (cVar3 != '\0') {
    local_13d = 1;
  }
  local_134 = (undefined4 *)0x0;
  local_138 = (undefined4 *)0x0;
  local_130 = (undefined4 *)0x0;
  local_12c = 0;
  piVar10 = (int *)(param_1 + 0xaac);
  local_4 = 1;
  if ((*(HANDLE *)(param_1 + 0xabc) == (HANDLE)0x0) ||
     ((DVar7 = WaitForSingleObject(*(HANDLE *)(param_1 + 0xabc),*(DWORD *)(param_1 + 0xac0)),
      DVar7 != 0 && (DVar7 != 0x80)))) {
    piVar10 = (int *)0x0;
  }
  piVar8 = (int *)*piVar10;
  piVar10[2] = (int)piVar8;
  puVar9 = (undefined4 *)0x0;
  if ((piVar8 != (int *)0x0) && (*piVar8 != 0)) {
    while( true ) {
      piVar8 = (int *)FUN_0057b6b0();
      iVar5 = *piVar8;
      if (iVar5 != -1) {
        piVar8 = operator_new(4);
        *piVar8 = iVar5;
        puVar9 = operator_new(0xc);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          *puVar9 = piVar8;
          puVar9[1] = 0;
          *(undefined1 *)(puVar9 + 2) = 1;
        }
        puVar1 = puVar9;
        puVar2 = puVar9;
        if (local_138 != (undefined4 *)0x0) {
          local_134[1] = puVar9;
          puVar1 = local_138;
          puVar2 = local_130;
        }
        local_130 = puVar2;
        local_138 = puVar1;
        local_12c = local_12c + 1;
        local_134 = puVar9;
      }
      puVar9 = local_138;
      if (piVar10[2] == 0) break;
      piVar8 = *(int **)(piVar10[2] + 4);
      piVar10[2] = (int)piVar8;
      if ((piVar8 == (int *)0x0) || (*piVar8 == 0)) break;
    }
  }
  if (*(HANDLE *)(param_1 + 0xabc) != (HANDLE)0x0) {
    ReleaseMutex(*(HANDLE *)(param_1 + 0xabc));
  }
  local_130 = puVar9;
  if (puVar9 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar9;
    puVar2 = puVar9;
    while (local_130 = puVar2, puVar1 != (undefined4 *)0x0) {
      cVar3 = FUN_0057cb50(*puVar1,0);
      if (cVar3 != '\0') {
        local_13d = 1;
      }
      puVar2 = (undefined4 *)puVar2[1];
      local_130 = puVar2;
      if (puVar2 == (undefined4 *)0x0) break;
      puVar1 = (undefined4 *)*puVar2;
    }
  }
  while (puVar9 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)puVar9[1];
    if (*(char *)(puVar9 + 2) != '\0') {
      FUN_00587bcf(*puVar9);
    }
    FUN_00587bcf(puVar9);
    puVar9 = puVar1;
  }
  ExceptionList = local_c;
  return local_13d;
}


