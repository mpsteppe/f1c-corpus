// Function: FUN_00432980 @ 00432980
// Size (bytes): 131


undefined4 __fastcall FUN_00432980(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 local_100 [256];
  
  FUN_00568620(0x100);
  FUN_005665b0(local_100);
  pcVar3 = *(char **)(*param_1 + 8);
  pcVar4 = pcVar3;
  if (pcVar3 == (char *)0x0) {
    pcVar4 = &DAT_005ea438;
  }
  uVar2 = 0xffffffff;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar2 - 1)) {
    if (pcVar3 == (char *)0x0) {
      pcVar3 = &DAT_005ea438;
    }
    if (pcVar3[~uVar2 - 2] != '\\') {
      FUN_005665b0(&DAT_005c2aac);
    }
  }
  FUN_00431db0(0);
  return 1;
}


