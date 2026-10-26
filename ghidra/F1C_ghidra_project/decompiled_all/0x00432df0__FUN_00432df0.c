// Function: FUN_00432df0 @ 00432df0
// Strings:  [tempGarage.svm]


void __fastcall FUN_00432df0(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar2 = FUN_004b0b10();
  FUN_00566650(uVar2);
  pcVar5 = (char *)*param_1;
  if (pcVar5 == (char *)0x0) {
    pcVar5 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  pcVar3 = pcVar5;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar4 - 1)) {
    for (pcVar3 = pcVar5 + (~uVar4 - 2); (pcVar5 <= pcVar3 && (*pcVar3 != '\\'));
        pcVar3 = pcVar3 + -1) {
      *pcVar3 = '\0';
    }
  }
  FUN_005665b0(PTR_s_tempGarage_svm_005c3f9c);
  return;
}


