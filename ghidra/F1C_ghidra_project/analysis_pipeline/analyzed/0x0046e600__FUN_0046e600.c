// Function: FUN_0046e600 @ 0046e600
// Size (bytes): 238


void __thiscall FUN_0046e600(char *param_1,undefined4 param_2)

{
  char cVar1;
  char *pcVar2;
  undefined4 uVar3;
  uint uVar4;
  char *pcVar5;
  char local_80 [127];
  undefined1 local_1;
  
  pcVar2 = operator_new(0x80);
  *pcVar2 = '\0';
  uVar3 = FUN_00432870();
  FUN_00566650(uVar3);
  pcVar5 = pcVar2;
  if (pcVar2 == (char *)0x0) {
    pcVar5 = &DAT_005ea438;
  }
  uVar4 = 0xffffffff;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  if (0 < (int)(~uVar4 - 1)) {
    pcVar5 = pcVar2;
    if (pcVar2 == (char *)0x0) {
      pcVar5 = &DAT_005ea438;
    }
    if (pcVar5[~uVar4 - 2] != '\\') {
      FUN_005665b0(&DAT_005c2aac);
    }
  }
  _strncpy(local_80,param_1,0x7f);
  local_1 = 0;
  FUN_00568560();
  FUN_005665b0(local_80);
  FUN_005665b0(&DAT_005c403c);
  FUN_00568620(param_2);
  if (pcVar2 != (char *)0x0) {
    FUN_00587bcf(pcVar2);
  }
  return;
}


