// Function: FUN_00566940 @ 00566940
// Size (bytes): 293


bool __thiscall FUN_00566940(int *param_1,undefined4 param_2,int param_3,int param_4,char param_5)

{
  char cVar1;
  int iVar2;
  undefined4 local_408;
  undefined4 local_404;
  undefined1 local_400 [1024];
  
  if ((param_5 != '\0') && (cVar1 = FUN_005668f0(param_2), cVar1 == '\0')) {
    return false;
  }
  param_1[4] = param_3;
  param_1[3] = param_4;
  FUN_00568620(0x400);
  if (param_3 == 0) {
    if (param_1[3] == 0) {
      iVar2 = FUN_00587db0(local_400,&DAT_005e5178);
      *param_1 = iVar2;
    }
    else {
      iVar2 = FUN_00587db0(local_400,&DAT_005e5174);
      *param_1 = iVar2;
    }
  }
  else {
    local_404 = 0;
    local_408 = DAT_005e5170;
    iVar2 = param_1[4];
    if (iVar2 == 2) {
      iVar2 = 0;
      do {
        cVar1 = (&DAT_005e5164)[iVar2];
        *(char *)((int)&local_408 + iVar2) = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
    }
    else if (iVar2 == 3) {
      iVar2 = 0;
      do {
        cVar1 = (&DAT_005e5168)[iVar2];
        *(char *)((int)&local_408 + iVar2) = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
    }
    else if (iVar2 == 4) {
      iVar2 = 0;
      do {
        cVar1 = (&DAT_005e516c)[iVar2];
        *(char *)((int)&local_408 + iVar2) = cVar1;
        iVar2 = iVar2 + 1;
      } while (cVar1 != '\0');
    }
    if (param_1[3] == 1) {
      local_408._0_2_ = CONCAT11(0x74,(undefined1)local_408);
    }
    iVar2 = FUN_00534b00();
    *param_1 = iVar2;
  }
  if (iVar2 != 0) {
    *(undefined1 *)(param_1 + 6) = 0;
    FUN_00566650(local_400);
  }
  return iVar2 != 0;
}


