// Function: FUN_004985d0 @ 004985d0
// Size (bytes): 128


void FUN_004985d0(int param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *pcVar4;
  undefined4 local_4;
  
  pcVar2 = param_2;
  if (param_2 != (char *)0x0) {
    param_2 = (char *)0x0;
    local_4 = 0;
    FUN_004983b0(pcVar2,&param_2,&local_4,param_3);
    if (param_1 < (int)param_2) {
      uVar3 = 0xffffffff;
      pcVar4 = pcVar2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = pcVar2 + ~uVar3;
      do {
        if (pcVar2 == pcVar4) {
          return;
        }
        pcVar4 = pcVar4 + -1;
        *pcVar4 = '\0';
        FUN_004983b0(pcVar2,&param_2,&local_4,param_3);
      } while (param_1 < (int)param_2);
    }
  }
  return;
}


