// Function: FUN_00463c40 @ 00463c40
// Size (bytes): 31


uint __fastcall FUN_00463c40(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = -1;
  pcVar3 = (char *)(*param_1 + 0x11cU);
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  return -(uint)(iVar2 != -2) & *param_1 + 0x11cU;
}


