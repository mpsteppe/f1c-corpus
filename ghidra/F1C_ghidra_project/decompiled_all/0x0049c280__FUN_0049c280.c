// Function: FUN_0049c280 @ 0049c280
// Strings:  [ --:--.---,  --:--.---,  %.2d:%06.3f]


undefined4 FUN_0049c280(float param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined4 local_4;
  
  iVar2 = (int)param_1;
  iVar4 = *(int *)(DAT_007c54e0 + 0x4040) + 1;
  if (iVar4 == 3) {
    iVar4 = 0;
  }
  pcVar3 = &DAT_005cce18;
  do {
    cVar1 = *pcVar3;
    pcVar3[(int)param_1 + -0x5cce18] = cVar1;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  param_1 = *(float *)(DAT_007c54e0 + 0x40a8 + iVar4 * 4);
  if (DAT_0059e440 < param_1) {
    FUN_0049b630(param_1,&local_4,&param_1);
    FUN_0058815f(iVar2,s___2d__06_3f_005cce24,local_4,(double)param_1);
  }
  return 0;
}


