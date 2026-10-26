// Function: FUN_0047beb0 @ 0047beb0
// Size (bytes): 118


void FUN_0047beb0(int param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 local_80 [128];
  
  if ((param_1 != 0) && (param_2 != (char *)0x0)) {
    *param_2 = '\0';
    FUN_00568910(0x80);
    FUN_0058815f(param_2,&DAT_005c2c18,local_80);
    uVar2 = 0xffffffff;
    pcVar3 = param_2;
    do {
      if (uVar2 == 0) break;
      uVar2 = uVar2 - 1;
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    pcVar3 = param_2 + (~uVar2 - 1);
    if (param_2 < pcVar3) {
      while (*pcVar3 != '.') {
        pcVar3 = pcVar3 + -1;
        if (pcVar3 <= param_2) {
          return;
        }
      }
      *pcVar3 = '\0';
    }
  }
  return;
}


