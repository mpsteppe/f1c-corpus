// Function: FUN_005685b0 @ 005685b0
// Size (bytes): 98


undefined4 __fastcall FUN_005685b0(char *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = param_1;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  if (3 < ~uVar3 - 1) {
    cVar1 = param_1[3];
    if ((*param_1 == '+') && (param_1[1] == '~')) {
      iVar2 = FUN_00589bc6((int)param_1[2]);
      if (iVar2 != 0) {
        iVar2 = FUN_00589bc6((int)cVar1);
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}


