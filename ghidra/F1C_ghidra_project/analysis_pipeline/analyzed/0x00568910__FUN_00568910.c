// Function: FUN_00568910 @ 00568910
// Size (bytes): 328


undefined1 __fastcall FUN_00568910(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 local_14;
  undefined1 local_10;
  char local_f;
  char local_e;
  char local_d;
  undefined1 local_c;
  char local_8 [8];
  
  if ((param_1 == (char *)0x0) || (param_2 == (char *)0x0)) {
    return 0;
  }
  *param_2 = '\0';
  cVar1 = *param_1;
  if (cVar1 == '\0') {
    return 1;
  }
  do {
    if (cVar1 == '+') {
      uVar3 = 0xffffffff;
      pcVar5 = param_1;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      if (~uVar3 - 1 < 4) goto LAB_005689c8;
      local_f = param_1[1];
      local_e = param_1[2];
      local_d = param_1[3];
      local_10 = 0x2b;
      local_c = 0;
      if (((local_f != '~') || (iVar2 = FUN_00589bc6((int)local_e), iVar2 == 0)) ||
         (iVar2 = FUN_00589bc6((int)local_d), iVar2 == 0)) goto LAB_005689c8;
      local_14 = 0;
      FUN_005887ed(&local_e,&DAT_005e5234,&local_14);
      local_8[0] = (char)local_14;
      param_1 = param_1 + 4;
    }
    else {
LAB_005689c8:
      local_8[0] = *param_1;
      param_1 = param_1 + 1;
    }
    uVar3 = 0xffffffff;
    local_8[1] = 0;
    pcVar5 = param_2;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    uVar4 = 0xffffffff;
    pcVar5 = local_8;
    do {
      if (uVar4 == 0) break;
      uVar4 = uVar4 - 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    if (param_3 <= (int)(~uVar3 + (~uVar4 - 2))) {
      return 0;
    }
    uVar3 = 0xffffffff;
    pcVar5 = local_8;
    do {
      pcVar7 = pcVar5;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar7 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar7;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    iVar2 = -1;
    pcVar5 = param_2;
    do {
      pcVar6 = pcVar5;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      pcVar6 = pcVar5 + 1;
      cVar1 = *pcVar5;
      pcVar5 = pcVar6;
    } while (cVar1 != '\0');
    pcVar5 = pcVar7 + -uVar3;
    pcVar7 = pcVar6 + -1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar7 = pcVar7 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar7 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar7 = pcVar7 + 1;
    }
    cVar1 = *param_1;
    if (cVar1 == '\0') {
      return 1;
    }
  } while( true );
}


