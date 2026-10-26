// Function: FUN_00589901 @ 00589901
// Size (bytes): 308


char * FUN_00589901(char *param_1)

{
  char cVar1;
  size_t _Size;
  int iVar2;
  char *pcVar3;
  bool bVar4;
  void *local_c;
  
  local_c = (void *)0x0;
  if (DAT_008d3f38 == 0) {
    cVar1 = *param_1;
    pcVar3 = param_1;
    while (cVar1 != '\0') {
      cVar1 = *pcVar3;
      if (('`' < cVar1) && (cVar1 < '{')) {
        *pcVar3 = cVar1 + -0x20;
      }
      pcVar3 = pcVar3 + 1;
      cVar1 = *pcVar3;
    }
  }
  else {
    InterlockedIncrement(&DAT_008d5a5c);
    bVar4 = DAT_008d5a58 == 0;
    if (!bVar4) {
      InterlockedDecrement(&DAT_008d5a5c);
      FUN_0058dfea(0x13);
    }
    if (DAT_008d3f38 == 0) {
      if (bVar4) {
        InterlockedDecrement(&DAT_008d5a5c);
      }
      else {
        FUN_0058e04b(0x13);
      }
      cVar1 = *param_1;
      pcVar3 = param_1;
      while (cVar1 != '\0') {
        cVar1 = *pcVar3;
        if (('`' < cVar1) && (cVar1 < '{')) {
          *pcVar3 = cVar1 + -0x20;
        }
        pcVar3 = pcVar3 + 1;
        cVar1 = *pcVar3;
      }
    }
    else {
      _Size = FUN_00591fa1(DAT_008d3f38,0x200,param_1,0xffffffff,0,0,0,1);
      if (((_Size != 0) && (local_c = _malloc(_Size), local_c != (void *)0x0)) &&
         (iVar2 = FUN_00591fa1(DAT_008d3f38,0x200,param_1,0xffffffff,local_c,_Size,0,1), iVar2 != 0)
         ) {
        FUN_0058fca0(param_1,local_c);
      }
      if (bVar4) {
        InterlockedDecrement(&DAT_008d5a5c);
      }
      else {
        FUN_0058e04b(0x13);
      }
      FUN_0058aa6f(local_c);
    }
  }
  return param_1;
}


