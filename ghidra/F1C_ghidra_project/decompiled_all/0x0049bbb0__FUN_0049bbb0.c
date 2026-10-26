// Function: FUN_0049bbb0 @ 0049bbb0
// Strings:  [ --:--.---,  --:--.---,  %.2d:%06.3f,  %.2d:%06.3f]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0049bbb0(int param_1)

{
  char cVar1;
  char *pcVar2;
  float10 fVar3;
  float local_8;
  float local_4;
  
  local_8 = (float)_DAT_008afea0 - *(float *)(DAT_007c54e0 + 0x4098);
  if ((local_8 < _DAT_005ccc0c) && (0 < *(int *)(DAT_007c54e0 + 0x403c))) {
    fVar3 = (float10)FUN_004bc2a0();
    local_4 = (float)fVar3;
    if ((float10)DAT_0059e440 < fVar3) {
      FUN_0049b630(local_4,&local_4,&local_8);
      FUN_0058815f(param_1,s___2d__06_3f_005cce24,local_4,(double)local_8);
      return 0;
    }
  }
  if (((*(int *)(DAT_007c54e0 + 0x4094) == 2) && (DAT_0059e440 <= local_8)) &&
     (*(int *)(DAT_007c54e0 + 0x4064) == 0)) {
    FUN_0049b630(local_8,&local_4,&local_8);
    FUN_0058815f(param_1,s___2d__06_3f_005cce24,local_4,(double)local_8);
    return 0;
  }
  pcVar2 = &DAT_005cce18;
  do {
    cVar1 = *pcVar2;
    pcVar2[param_1 + -0x5cce18] = cVar1;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return 0;
}


