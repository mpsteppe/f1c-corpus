// Function: FUN_00461610 @ 00461610
// Size (bytes): 674


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00461610(int param_1)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  float local_28;
  undefined4 local_24;
  char local_20 [31];
  undefined1 local_1;
  
  uVar4 = FUN_00415c30();
  FUN_004c5690(uVar4);
  pcVar5 = (char *)(DAT_008ac48c * 0x18c + 4 + DAT_008ac490);
  uVar7 = 0xffffffff;
  pcVar8 = pcVar5;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  for (pcVar8 = pcVar5 + (~uVar7 - 1); pcVar5 < pcVar8; pcVar8 = pcVar8 + -1) {
    if (*pcVar8 == '\\') {
      pcVar8 = pcVar8 + 1;
      break;
    }
  }
  _strncpy(local_20,pcVar8,0x1f);
  uVar7 = 0xffffffff;
  local_1 = 0;
  pcVar5 = local_20;
  do {
    if (uVar7 == 0) break;
    uVar7 = uVar7 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  pcVar5 = local_20 + (~uVar7 - 1);
  if (local_20 < pcVar5) {
    do {
      if (*pcVar5 == '.') {
        *pcVar5 = '\0';
        break;
      }
      pcVar5 = pcVar5 + -1;
    } while (local_20 < pcVar5);
  }
  FUN_004336d0(0x1f);
  FUN_00415c30();
  uVar4 = 0x1f;
  FUN_004618d0(0x1f);
  FUN_004336d0(uVar4);
  *(undefined1 *)(param_1 + 100) = DAT_007d0a44;
  *(undefined1 *)(param_1 + 0x65) = 0;
  *(undefined1 *)(param_1 + 0x66) = DAT_007d0fc4;
  *(undefined1 *)(param_1 + 0x67) = (undefined1)DAT_007d0c18;
  *(undefined1 *)(param_1 + 0x68) = (undefined1)DAT_007d0d14;
  *(undefined1 *)(param_1 + 0x69) = (undefined1)DAT_007d0014;
  *(undefined1 *)(param_1 + 0x6a) = (undefined1)DAT_007ceb10;
  uVar2 = (ushort)DAT_007d0f70 & 0x3f;
  *(ushort *)(param_1 + 0x76) = uVar2;
  sVar3 = uVar2 + (DAT_007ce874 & 1) * 0x40;
  *(short *)(param_1 + 0x76) = sVar3;
  sVar3 = sVar3 + (DAT_007ce88c & 0xff01) * 0x80;
  *(short *)(param_1 + 0x76) = sVar3;
  sVar3 = sVar3 + ((byte)DAT_007ce958 & 1) * 0x100;
  *(short *)(param_1 + 0x76) = sVar3;
  sVar3 = sVar3 + (DAT_007ce97c & 0xff01) * 0x200;
  *(short *)(param_1 + 0x76) = sVar3;
  sVar3 = sVar3 + (DAT_007ced44 & 1) * 0x400;
  *(short *)(param_1 + 0x76) = sVar3;
  sVar3 = sVar3 + (DAT_007cee40 & 1) * 0x800;
  *(short *)(param_1 + 0x76) = sVar3;
  *(ushort *)(param_1 + 0x76) = (DAT_007cef3c & 1) * 0x1000 + sVar3;
  *(undefined2 *)(param_1 + 0x78) = DAT_007cec30;
  *(undefined2 *)(param_1 + 0x7a) = DAT_007cec54;
  local_28 = DAT_007d108c * _DAT_0059e874;
  if (DAT_0059e440 <= local_28) {
    if (_DAT_0059f120 < local_28) {
      local_28 = 65535.0;
    }
  }
  else {
    local_28 = 0.0;
  }
  local_24 = (int)ROUND(local_28);
  *(undefined2 *)(param_1 + 0x7c) = (undefined2)local_24;
  switch(DAT_007d0e50) {
  case 1:
    DAT_007d0e98 = 8;
    break;
  case 2:
    DAT_007d0e98 = 0xc;
    break;
  case 3:
    DAT_007d0e98 = 0xe;
    break;
  case 4:
    DAT_007d0e98 = 0x20;
    break;
  default:
    DAT_007d0e98 = 6;
  }
  iVar6 = DAT_007d0ea0;
  if ((DAT_007d0e98 < DAT_007d0ea0) || (iVar6 = DAT_007d0ea4, DAT_007d0ea4 < DAT_007d0e98)) {
    DAT_007d0e98 = iVar6;
  }
  *(char *)(param_1 + 0x6b) = (char)DAT_007d0e98;
  *(undefined1 *)(param_1 + 0x6c) = (undefined1)DAT_007cf134;
  *(undefined1 *)(param_1 + 0x6d) = (undefined1)DAT_007cf038;
  *(undefined4 *)(param_1 + 0x60) = DAT_007d084c;
  *(undefined2 *)(param_1 + 0x74) = (undefined2)DAT_007d0f4c;
  FUN_004615c0(0,0);
  FUN_004615c0(1,DAT_007d0134 != 0);
  return;
}


