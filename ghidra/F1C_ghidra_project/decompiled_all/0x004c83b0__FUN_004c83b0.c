// Function: FUN_004c83b0 @ 004c83b0
// Strings:  [Phd3], Ph\3], *.mp3, *.wav]


int __fastcall FUN_004c83b0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  
  piVar3 = (int *)*param_1;
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (*piVar3 != 0)) {
      FUN_00404f70(1);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  puVar4 = DAT_005ec448;
  if (DAT_005ec448 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  FUN_004c84a0(s___wav_005d3364,puVar4);
  puVar4 = DAT_005ec448;
  if (DAT_005ec448 == (undefined1 *)0x0) {
    puVar4 = &DAT_005ea438;
  }
  iVar5 = FUN_004c84a0(s___mp3_005d335c,puVar4);
  iVar2 = param_1[3];
  if (0 < iVar2) {
    iVar6 = _rand();
    iVar5 = iVar6 / iVar2;
    iVar6 = iVar6 % iVar2;
    if ((iVar6 < 0) || (param_1[3] <= iVar6)) {
      param_1[2] = 0;
    }
    else {
      iVar5 = *param_1;
      param_1[2] = iVar5;
      while ((0 < iVar6 && (iVar5 = param_1[2], iVar5 != 0))) {
        iVar6 = iVar6 + -1;
        param_1[2] = *(int *)(iVar5 + 4);
      }
    }
  }
  if ((param_1[3] == 0) && (DAT_008ac4c4 != (int *)0x0)) {
    PTR_s_Audio_Music__005d325c = DAT_005ec448;
    if (DAT_005ec448 == (undefined1 *)0x0) {
      PTR_s_Audio_Music__005d325c = &DAT_005ea438;
    }
    iVar5 = (**(code **)(*DAT_008ac4c4 + 0x48))(&PTR_s_Audio_Music__005d325c,DAT_005d3254);
  }
  return iVar5;
}


