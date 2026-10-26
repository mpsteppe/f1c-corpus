// Function: FUN_0045f4a0 @ 0045f4a0
// Size (bytes): 617


void __fastcall FUN_0045f4a0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  int local_24c;
  int local_248;
  int local_244;
  undefined4 *local_240;
  uint local_23c [143];
  
  FUN_004b3b30();
  iVar3 = FUN_004b3af0(local_23c);
  while (iVar3 != 0) {
    if ((local_23c[0] & 0x10000000) == 0) {
      cVar2 = FUN_00461440();
      if (cVar2 == '\0') {
        local_244 = FUN_00462310();
        local_24c = 0;
        if (0 < *(int *)(param_1 + 0x3e14)) {
          local_240 = (undefined4 *)(param_1 + 0x3c74);
          iVar3 = param_1 + 0x394;
          do {
            if (((local_24c != local_244) &&
                ((local_248 = iVar3, *(int *)(param_1 + 0x3fc4) != 3 ||
                 (cVar2 = FUN_00461530(1), cVar2 != '\0')))) &&
               (((local_23c[0] >> 0x1b & 1) != 0 || (cVar2 = FUN_004614c0(), cVar2 != '\0')))) {
              iVar3 = local_244 * 0x8c;
              uVar1 = *local_240;
              cVar2 = FUN_004614c0();
              if ((cVar2 != '\0') && ((local_23c[0] & 0xff) < 0x68)) {
                local_23c[0] = (int)*(char *)(iVar3 + param_1 + 0x410) | local_23c[0] & 0xffffff00;
              }
              FUN_00462250(local_23c,1,uVar1,2000);
              iVar3 = local_248;
            }
            local_24c = local_24c + 1;
            local_240 = local_240 + 1;
            iVar3 = iVar3 + 0x8c;
            local_248 = iVar3;
          } while (local_24c < *(int *)(param_1 + 0x3e14));
        }
      }
      else {
        FUN_00465300(local_23c);
      }
    }
    iVar3 = FUN_004b3af0(local_23c);
  }
  cVar2 = FUN_00461440();
  if (cVar2 != '\0') {
    local_244 = FUN_00462310();
    FUN_00461470();
    FUN_00462300();
    local_24c = 0;
    if (0 < *(int *)(param_1 + 0x3e14)) {
      pcVar4 = (char *)(param_1 + 0x410);
      do {
        if ((local_24c != local_244) &&
           (((*(int *)(param_1 + 0x3fc4) != 3 || (cVar2 = FUN_00461530(1), cVar2 != '\0')) &&
            (cVar2 = FUN_004614c0(), cVar2 != '\0')))) {
          uVar1 = *(undefined4 *)(param_1 + 0x3e18 + *pcVar4 * 4);
          FUN_00465460((int)*pcVar4,uVar1);
          cVar2 = FUN_00465c30(&local_248);
          while (cVar2 != '\0') {
            FUN_00462250(local_248,1,uVar1,500);
            cVar2 = FUN_00465c30(&local_248);
          }
        }
        local_24c = local_24c + 1;
        pcVar4 = pcVar4 + 0x8c;
      } while (local_24c < *(int *)(param_1 + 0x3e14));
    }
    FUN_004b0170();
  }
  FUN_0057a730(0);
  return;
}


