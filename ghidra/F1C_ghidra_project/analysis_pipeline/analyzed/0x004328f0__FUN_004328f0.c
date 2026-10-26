// Function: FUN_004328f0 @ 004328f0
// Size (bytes): 39


char __fastcall FUN_004328f0(int *param_1)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = *(char **)(*param_1 + 8);
  if (pcVar2 == (char *)0x0) {
    pcVar2 = &DAT_005ea438;
  }
  iVar3 = -1;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  return '\x01' - (iVar3 != -2);
}


