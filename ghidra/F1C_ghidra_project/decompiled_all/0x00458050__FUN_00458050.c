// Function: FUN_00458050 @ 00458050
// Strings:  [CONTROLPOINT]


undefined4 FUN_00458050(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_418;
  undefined4 local_414;
  undefined4 local_410 [98];
  undefined4 local_288;
  undefined1 local_284;
  undefined4 local_27c;
  undefined4 local_278;
  undefined4 local_274;
  undefined4 local_270 [96];
  undefined4 local_f0 [60];
  
  puVar3 = local_270;
  for (iVar2 = 0x60; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_288 = 0;
  local_274 = 0;
  local_27c = 0;
  local_278 = 0;
  local_284 = 1;
  iVar4 = 0;
  iVar2 = FUN_00566cc0(local_270,0x180);
  if (iVar2 == 0) {
    return 1;
  }
  puVar3 = local_f0;
  do {
    iVar2 = FUN_005651b0();
    if (iVar2 == 0) {
      iVar2 = FUN_00565870(s_CONTROLPOINT_005c5a70,&local_418,&local_414,local_410,0,0,0,0,0);
      if ((iVar2 != 0) && (iVar4 < 0x14)) {
        *puVar3 = local_418;
        puVar3[1] = local_414;
        iVar4 = iVar4 + 1;
        puVar3[2] = local_410[0];
        puVar3 = puVar3 + 3;
      }
    }
    else if ((iVar2 == 2) || (iVar2 == 4)) break;
    iVar2 = FUN_00566cc0(local_270,0x180);
  } while (iVar2 != 0);
  if (iVar4 < 4) {
    return 1;
  }
  uVar1 = FUN_00457f90(local_f0,iVar4);
  return uVar1;
}


