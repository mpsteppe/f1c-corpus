// Function: FUN_004fac00 @ 004fac00
// Strings:  [D:\dev\F1_1999_2002\Source\vidman.cpp, Entered VidMan::Post()]


void FUN_004fac00(void)

{
  int iVar1;
  char cVar2;
  char *pcVar3;
  uint uVar4;
  char local_200 [512];
  
  cVar2 = FUN_004d7a50(2,s_D__dev_F1_1999_2002_Source_vidma_005d6dc4,0x592);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Entered_VidMan__Post___005d6ed0);
  }
  FUN_004f8ea0();
  FUN_005461b0(DAT_008afe88);
  DAT_008afe88 = 0;
  FUN_0053d400(0);
  iVar1 = DAT_008ac48c * 0x18c + DAT_008ac490;
  if (iVar1 != 0) {
    pcVar3 = (char *)(iVar1 + 4);
    iVar1 = -(int)pcVar3;
    do {
      cVar2 = *pcVar3;
      pcVar3[(int)(local_200 + iVar1)] = cVar2;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    uVar4 = 0xffffffff;
    pcVar3 = local_200;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if ((0 < (int)(~uVar4 - 1)) && (pcVar3 = local_200 + (~uVar4 - 2), local_200 <= pcVar3)) {
      do {
        if (*pcVar3 == '\\') break;
        *pcVar3 = '\0';
        pcVar3 = pcVar3 + -1;
      } while (local_200 <= pcVar3);
    }
    uVar4 = 0xffffffff;
    pcVar3 = local_200;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar2 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar2 != '\0');
    if ((0 < (int)(~uVar4 - 1)) && (local_200[~uVar4 - 2] == '\\')) {
      local_200[~uVar4 - 2] = '\0';
    }
    FUN_0053c900(local_200);
  }
  return;
}


