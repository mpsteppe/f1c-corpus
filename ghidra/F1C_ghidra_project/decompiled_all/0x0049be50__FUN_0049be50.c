// Function: FUN_0049be50 @ 0049be50
// Strings:  [ --:--.---,  --:--.---, -%.2d:%06.3f, +%.2d:%06.3f]


undefined4 FUN_0049be50(float param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  bool bVar4;
  float fVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  undefined4 local_4;
  
  fVar5 = param_1;
  pcVar6 = &DAT_005cce18;
  do {
    cVar3 = *pcVar6;
    pcVar6[(int)param_1 + -0x5cce18] = cVar3;
    pcVar6 = pcVar6 + 1;
  } while (cVar3 != '\0');
  if (*(int *)(DAT_007c54e0 + 0x4094) == 2) {
    if ((DAT_007cfff0 & 2) == 0) {
      iVar8 = *(int *)(DAT_007c54e0 + 0x4040);
      fVar1 = *(float *)(DAT_007c54e0 + 0x40a8 + iVar8 * 4);
    }
    else {
      iVar7 = FUN_004d1b50();
      if (iVar7 == 0xff) {
        return 0;
      }
      iVar8 = *(int *)(DAT_007c54e0 + 0x4040);
      fVar1 = *(float *)(&DAT_005f0780 + (iVar7 * 0x1230 + iVar8) * 4);
    }
    if ((DAT_0059e440 < fVar1) &&
       (fVar2 = *(float *)(DAT_007c54e0 + 0x404c + iVar8 * 4), DAT_0059e440 < fVar2)) {
      fVar2 = fVar2 - fVar1;
      bVar4 = fVar2 < DAT_0059e440;
      FUN_0049b630(ABS(fVar2),&local_4,&param_1);
      if (bVar4) {
        FUN_0058815f(fVar5,s____2d__06_3f_005cce34,local_4,(double)param_1);
        return 0;
      }
      FUN_0058815f(fVar5,s____2d__06_3f_005cce44,local_4,(double)param_1);
      return 0;
    }
  }
  return 0;
}


