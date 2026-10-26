// Function: FUN_00566810 @ 00566810
// Size (bytes): 149


char * __fastcall FUN_00566810(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  char *local_8;
  
  if ((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) {
    iVar4 = 0;
    local_8 = (char *)0x0;
    pcVar5 = param_2;
    if (*param_1 != '\0') {
      do {
        cVar2 = FUN_00589a35((int)*pcVar5);
        cVar3 = FUN_0058b465((int)*pcVar5);
        if ((*param_1 == cVar2) || (*param_1 == cVar3)) {
          if (iVar4 == 0) {
            local_8 = param_1;
          }
          pcVar1 = pcVar5 + 1;
          pcVar5 = pcVar5 + 1;
          iVar4 = iVar4 + 1;
          if (*pcVar1 == '\0') {
            return local_8;
          }
          param_1 = param_1 + 1;
        }
        else {
          iVar4 = 0;
          if (local_8 == (char *)0x0) {
            param_1 = param_1 + 1;
            local_8 = (char *)0x0;
            pcVar5 = param_2;
          }
          else {
            param_1 = local_8 + 1;
            local_8 = (char *)0x0;
            pcVar5 = param_2;
          }
        }
        if (*param_1 == '\0') {
          return (char *)0x0;
        }
      } while( true );
    }
  }
  return (char *)0x0;
}


