// Function: FUN_00598323 @ 00598323
// Size (bytes): 391


undefined4 FUN_00598323(char *param_1,int param_2)

{
  char *pcVar1;
  int iVar2;
  int *piVar3;
  size_t sVar4;
  LPCSTR lpName;
  int *piVar5;
  bool bVar6;
  
  if (param_1 == (char *)0x0) {
    return 0xffffffff;
  }
  pcVar1 = (char *)FUN_00598569(param_1,0x3d);
  if (pcVar1 == (char *)0x0) {
    return 0xffffffff;
  }
  if (param_1 == pcVar1) {
    return 0xffffffff;
  }
  bVar6 = pcVar1[1] == '\0';
  if (DAT_008d3e90 == DAT_008d3e94) {
    DAT_008d3e90 = (int *)FUN_00598502(DAT_008d3e90);
  }
  if (DAT_008d3e90 == (int *)0x0) {
    if ((param_2 == 0) || (DAT_008d3e98 == (undefined4 *)0x0)) {
      if (bVar6) {
        return 0;
      }
      DAT_008d3e90 = _malloc(4);
      if (DAT_008d3e90 == (int *)0x0) {
        return 0xffffffff;
      }
      *DAT_008d3e90 = 0;
      if (DAT_008d3e98 == (undefined4 *)0x0) {
        DAT_008d3e98 = _malloc(4);
        if (DAT_008d3e98 == (undefined4 *)0x0) {
          return 0xffffffff;
        }
        *DAT_008d3e98 = 0;
      }
    }
    else {
      iVar2 = FUN_00597fac();
      if (iVar2 != 0) {
        return 0xffffffff;
      }
    }
  }
  piVar3 = DAT_008d3e90;
  iVar2 = FUN_005984aa(param_1,(int)pcVar1 - (int)param_1);
  if ((iVar2 < 0) || (*piVar3 == 0)) {
    if (bVar6) {
      return 0;
    }
    if (iVar2 < 0) {
      iVar2 = -iVar2;
    }
    piVar3 = (int *)FUN_0058b5d4(piVar3,iVar2 * 4 + 8);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    piVar3[iVar2] = (int)param_1;
    piVar3[iVar2 + 1] = 0;
  }
  else {
    if (!bVar6) {
      piVar3[iVar2] = (int)param_1;
      goto LAB_00598457;
    }
    piVar5 = piVar3 + iVar2;
    FUN_0058aa6f(piVar3[iVar2]);
    for (; *piVar5 != 0; piVar5 = piVar5 + 1) {
      iVar2 = iVar2 + 1;
      *piVar5 = piVar5[1];
    }
    piVar3 = (int *)FUN_0058b5d4(piVar3,iVar2 << 2);
    if (piVar3 == (int *)0x0) goto LAB_00598457;
  }
  DAT_008d3e90 = piVar3;
LAB_00598457:
  if (param_2 != 0) {
    sVar4 = _strlen(param_1);
    lpName = _malloc(sVar4 + 2);
    if (lpName != (LPCSTR)0x0) {
      FUN_0058fca0(lpName,param_1);
      pcVar1[(int)lpName - (int)param_1] = '\0';
      SetEnvironmentVariableA
                (lpName,(LPCSTR)(~-(uint)bVar6 & (uint)(pcVar1 + ((int)lpName - (int)param_1) + 1)))
      ;
      FUN_0058aa6f(lpName);
    }
  }
  return 0;
}


