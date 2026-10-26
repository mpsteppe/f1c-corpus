// Function: FUN_004dc450 @ 004dc450
// Size (bytes): 420


/* WARNING: Removing unreachable block (ram,0x004dc5b4) */
/* WARNING: Removing unreachable block (ram,0x004dc5e0) */

undefined4 __fastcall FUN_004dc450(int param_1,undefined4 param_2,char *param_3,char param_4)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 local_18;
  
  local_18 = 1;
  uVar4 = 1;
  if ((param_1 != 0) && (param_3 != (char *)0x0)) {
    FUN_00566650(param_3);
    uVar5 = 0xffffffff;
    pcVar2 = &DAT_005ea438;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    if (0 < (int)(~uVar5 - 1)) {
      pcVar2 = &DAT_005ea436 + ~uVar5;
      if (&DAT_005ea438 < pcVar2) {
        do {
          if (*pcVar2 == '\\') break;
          pcVar2 = pcVar2 + -1;
        } while (&DAT_005ea438 < pcVar2);
      }
      *pcVar2 = '\0';
    }
    FUN_0053c800(&DAT_005ea438);
    uVar5 = 0xffffffff;
    pcVar2 = param_3;
    do {
      if (uVar5 == 0) break;
      uVar5 = uVar5 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    for (pcVar2 = param_3 + (~uVar5 - 1); param_3 < pcVar2; pcVar2 = pcVar2 + -1) {
      if (*pcVar2 == '\\') {
        pcVar2 = pcVar2 + 1;
        break;
      }
    }
    iVar3 = FUN_00546aa0(param_2,pcVar2);
    if ((iVar3 == 0) && (local_18 = 0, param_4 != '\0')) {
      FUN_00566650(pcVar2);
      uVar5 = 0xffffffff;
      pcVar2 = &DAT_005ea438;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
      pcVar2 = &DAT_005ea437 + ~uVar5;
      if (&DAT_005ea438 < pcVar2) {
        do {
          if (*pcVar2 == '.') {
            *pcVar2 = '\0';
            break;
          }
          pcVar2 = pcVar2 + -1;
        } while (&DAT_005ea438 < pcVar2);
      }
      FUN_00589901(&DAT_005ea438);
      FUN_005472b0(&DAT_005ea438);
    }
    FUN_0053c900(&DAT_005ea438);
    uVar4 = local_18;
  }
  return uVar4;
}


