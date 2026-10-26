// Function: FUN_004a3220 @ 004a3220
// Strings:  [PITANIMS.MAS]


undefined4 FUN_004a3220(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  int local_c;
  char *local_8;
  undefined4 local_4;
  
  FUN_004a29a0();
  local_8 = (char *)0x0;
  local_4 = 0xffffffff;
  FUN_00566650(param_1);
  pcVar5 = local_8;
  if (local_8 == (char *)0x0) {
    pcVar5 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  pcVar2 = pcVar5;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar4 - 1)) {
    for (pcVar2 = pcVar5 + (~uVar4 - 2); (pcVar5 < pcVar2 && (*pcVar2 != '\\'));
        pcVar2 = pcVar2 + -1) {
    }
    *pcVar2 = '\0';
  }
  pcVar5 = local_8;
  if (local_8 == (char *)0x0) {
    pcVar5 = &DAT_005ea438;
  }
  FUN_0053c800(pcVar5);
  local_c = 0;
  FUN_0053cbc0(&local_c,s_PITANIMS_MAS_005cd480);
  uVar3 = FUN_004a2a90(param_1,param_2,param_3);
  if (local_c != 0) {
    FUN_0053ce40(local_c);
  }
  pcVar5 = local_8;
  if (local_8 == (char *)0x0) {
    pcVar5 = &DAT_005ea438;
  }
  FUN_0053c900(pcVar5);
  if (local_8 != (char *)0x0) {
    FUN_00587bcf(local_8);
  }
  return uVar3;
}


