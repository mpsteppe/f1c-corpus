// Function: FUN_005351d0 @ 005351d0
// Size (bytes): 79


char * __fastcall FUN_005351d0(undefined4 param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if ((param_2 != (char *)0x0) && (pcVar3 = param_2, 0 < param_3)) {
    while (param_3 = param_3 + -1, 0 < param_3) {
      iVar2 = FUN_00534f90(1);
      if ((iVar2 != 1) || (cVar1 = *pcVar3, pcVar3 = pcVar3 + 1, cVar1 == '\n')) break;
    }
    *pcVar3 = '\0';
    if ((param_2 != pcVar3) || (param_3 < 1)) {
      return param_2;
    }
  }
  return (char *)0x0;
}


