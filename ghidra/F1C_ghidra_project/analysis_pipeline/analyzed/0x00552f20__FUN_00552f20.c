// Function: FUN_00552f20 @ 00552f20
// Size (bytes): 137


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_00552f20(float *param_1,char *param_2)

{
  int iVar1;
  char cVar2;
  float fVar3;
  char *pcVar4;
  int iVar5;
  
  switch(*(undefined4 *)((int)param_1[0x19] + 0x30)) {
  case 5:
  case 6:
    FUN_00552ba0();
    break;
  case 7:
  case 8:
    FUN_00552d70();
  }
  pcVar4 = _strrchr(param_2,0x5c);
  if (pcVar4 != (char *)0x0) {
    param_2 = pcVar4 + 1;
  }
  iVar5 = 0;
  cVar2 = *param_2;
  while (cVar2 != '.') {
    *(char *)((int)param_1 + iVar5 + 0x14) = cVar2;
    iVar1 = iVar5 + 1;
    iVar5 = iVar5 + 1;
    cVar2 = param_2[iVar1];
  }
  *(undefined1 *)(iVar5 + 0x14 + (int)param_1) = 0;
  fVar3 = param_1[0x19];
  *param_1 = _DAT_0059e43c / (float)*(int *)((int)fVar3 + 0x1c);
  param_1[1] = _DAT_0059e43c / (float)*(int *)((int)fVar3 + 0x20);
  *(float *)((int)fVar3 + 0x34) = param_1[0xb];
  return 0;
}


