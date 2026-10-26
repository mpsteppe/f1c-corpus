// Function: FUN_004c1370 @ 004c1370
// Size (bytes): 32


int __fastcall FUN_004c1370(int param_1)

{
  int iVar1;
  char *pcVar2;
  int iVar3;
  
  iVar1 = 0;
  pcVar2 = (char *)(param_1 + 0x1b0);
  iVar3 = 0x67;
  do {
    if (*pcVar2 != '\0') {
      iVar1 = iVar1 + 1;
    }
    pcVar2 = pcVar2 + 0x1b4;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return iVar1;
}


