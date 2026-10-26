// Function: FUN_00564220 @ 00564220
// Size (bytes): 75


char * __fastcall FUN_00564220(char *param_1,char param_2)

{
  char cVar1;
  char *pcVar2;
  
  if (param_1 != (char *)0x0) {
    DAT_008cfae4 = param_1;
  }
  pcVar2 = DAT_008cfae4;
  cVar1 = *DAT_008cfae4;
  if (cVar1 != '\0') {
    do {
      if (cVar1 == param_2) break;
      DAT_008cfae4 = DAT_008cfae4 + 1;
      cVar1 = *DAT_008cfae4;
    } while (cVar1 != '\0');
    if (DAT_008cfae4 != pcVar2) goto LAB_00564253;
  }
  pcVar2 = (char *)0x0;
LAB_00564253:
  if (*DAT_008cfae4 != '\0') {
    *DAT_008cfae4 = '\0';
    DAT_008cfae4 = DAT_008cfae4 + 1;
  }
  return pcVar2;
}


