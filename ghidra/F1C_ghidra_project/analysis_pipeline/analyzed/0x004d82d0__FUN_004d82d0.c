// Function: FUN_004d82d0 @ 004d82d0
// Size (bytes): 374


void __fastcall FUN_004d82d0(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  undefined1 local_c [12];
  
  if (DAT_007cfea0 == 0) {
    return;
  }
  cVar3 = FUN_00404f10();
  if (cVar3 != '\0') {
    return;
  }
  if (DAT_008ab6e4 == 2) {
    return;
  }
  if (*(int *)(param_1 + 8) != -1) {
    return;
  }
  cVar3 = FUN_0049bad0();
  if (cVar3 != '\0') {
    local_c[0] = 0x3e;
  }
  uVar5 = (uint)(cVar3 != '\0');
  cVar3 = FUN_0049bb20();
  if (cVar3 != '\0') {
    local_c[uVar5] = 0x41;
    uVar5 = uVar5 + 1;
  }
  cVar3 = FUN_0049bab0();
  if (cVar3 != '\0') {
    local_c[uVar5] = 0x3f;
    uVar5 = uVar5 + 1;
  }
  cVar3 = FUN_0049ba90();
  if (cVar3 != '\0') {
    local_c[uVar5] = 0x66;
    uVar5 = uVar5 + 1;
  }
  if (DAT_007c56a8 == 8) {
    local_c[uVar5] = 0x42;
    uVar5 = uVar5 + 1;
  }
  if (DAT_007cfea0 == 2) {
    cVar3 = FUN_0049b9a0();
    if (cVar3 != '\0') {
      local_c[uVar5] = 0x82;
      uVar5 = uVar5 + 1;
    }
    cVar3 = FUN_0049ba50();
    if (cVar3 != '\0') {
      local_c[uVar5] = 0x44;
      uVar5 = uVar5 + 1;
    }
    iVar4 = FUN_0049ba30();
    if (iVar4 == 1) {
      local_c[uVar5] = 0x8c;
    }
    else {
      iVar4 = FUN_0049ba30();
      if (iVar4 != 2) goto LAB_004d83cd;
      local_c[uVar5] = 0x8d;
    }
    uVar5 = uVar5 + 1;
  }
LAB_004d83cd:
  if ((uVar5 != 0) && (local_c[uVar5] = 0, DAT_008ad394 != 0)) {
    uVar1 = *(undefined4 *)(DAT_008ad394 + 0x5c);
    uVar2 = *(undefined4 *)(DAT_008ad394 + 0x60);
    *(undefined4 *)(DAT_008ad394 + 0x5c) = 0x3fc00000;
    *(undefined4 *)(DAT_008ad394 + 0x60) = 0x3fc00000;
    FUN_00552fc0(0xffffff);
    FUN_00553070(local_c,10,0,DAT_008b8dc8);
    *(undefined4 *)(DAT_008ad394 + 0x5c) = uVar1;
    *(undefined4 *)(DAT_008ad394 + 0x60) = uVar2;
  }
  return;
}


