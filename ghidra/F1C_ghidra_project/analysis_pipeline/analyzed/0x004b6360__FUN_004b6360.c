// Function: FUN_004b6360 @ 004b6360
// Size (bytes): 861


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall FUN_004b6360(int param_1,uint *param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float local_21c;
  float local_218;
  float local_214;
  float local_210;
  float local_20c;
  float local_208;
  float local_204;
  float local_200;
  float local_1fc;
  float local_1f8;
  float local_1f4;
  float local_1f0;
  float local_1ec;
  int local_1e8;
  float local_1e4;
  float local_1e0 [6];
  float local_1c8 [3];
  float local_1bc [3];
  undefined1 local_1b0 [432];
  
  switch((*param_2 >> 0x1d) - 1) {
  case 0:
    break;
  default:
    return 0;
  }
  if ((*param_2 & 0xfc0000) != 0) {
    return 0;
  }
  if ((2 < *(int *)(param_1 + 0x9ac)) && (*(int *)(param_1 + 0x9ac) < 5)) {
    iVar6 = 0;
    do {
      iVar4 = FUN_004b2ad0(iVar6);
      iVar5 = FUN_004b2ad0(iVar6);
      if (iVar5 != iVar4) {
        return 0;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xe);
  }
  FUN_004b3a90(param_2);
  FUN_004b3a90(param_4);
  FUN_004b2420(local_1e0 + 9,&local_1f4);
  FUN_004b2420(local_1e0,&local_200);
  FUN_00500210(*(undefined4 *)(param_3 + 4),local_1b0);
  FUN_004b2420(local_1e0 + 6,&local_20c);
  FUN_004b2420(local_1e0 + 3,&local_218);
  local_1e8 = 0;
  do {
    iVar4 = local_1e8;
    bVar1 = true;
    iVar6 = 0;
    if (local_1e8 == 0) {
      do {
        local_1e4 = local_1e0[iVar6] - local_1e0[iVar6 + 9];
        local_21c = local_1e0[iVar6 + 3] - local_1e0[iVar6 + 6];
        if (iVar6 == 1) {
          local_21c = local_21c + local_21c;
        }
        cVar3 = FUN_004b66e0(local_21c,local_1e4);
        if (cVar3 == '\0') break;
        if (iVar6 == 2) {
          bVar1 = false;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 3);
      if (bVar1) {
        return 0;
      }
    }
    else {
      if (local_200 <= local_1f4) {
        local_21c = local_1f4 - local_200;
      }
      else {
        local_21c = local_200 - local_1f4;
      }
      if ((float)_DAT_0059e890 < local_21c) {
        local_21c = local_21c - (local_21c - (float)_DAT_0059e890);
      }
      if (local_20c <= local_218) {
        fVar2 = local_218 - local_20c;
      }
      else {
        fVar2 = local_20c - local_218;
      }
      if ((float)_DAT_0059e890 < fVar2) {
        fVar2 = fVar2 - (fVar2 - (float)_DAT_0059e890);
      }
      cVar3 = FUN_004b67d0(fVar2,local_21c);
      if (cVar3 == '\0') {
        return 0;
      }
      if (local_1fc <= local_1f0) {
        local_21c = local_1f0 - local_1fc;
      }
      else {
        local_21c = local_1fc - local_1f0;
      }
      if ((float)_DAT_0059e890 < local_21c) {
        local_21c = local_21c - (local_21c - (float)_DAT_0059e890);
      }
      if (local_208 <= local_214) {
        fVar2 = local_214 - local_208;
      }
      else {
        fVar2 = local_208 - local_214;
      }
      if ((float)_DAT_0059e890 < fVar2) {
        fVar2 = fVar2 - (fVar2 - (float)_DAT_0059e890);
      }
      cVar3 = FUN_004b67d0(fVar2,local_21c);
      if (cVar3 == '\0') {
        return 0;
      }
      if (local_1f8 <= local_1ec) {
        local_21c = local_1ec - local_1f8;
      }
      else {
        local_21c = local_1f8 - local_1ec;
      }
      if ((float)_DAT_0059e890 < local_21c) {
        local_21c = local_21c - (local_21c - (float)_DAT_0059e890);
      }
      if (local_204 <= local_210) {
        fVar2 = local_210 - local_204;
      }
      else {
        fVar2 = local_204 - local_210;
      }
      if ((float)_DAT_0059e890 < fVar2) {
        fVar2 = fVar2 - (fVar2 - (float)_DAT_0059e890);
      }
      cVar3 = FUN_004b67d0(fVar2,local_21c);
      local_1e8 = iVar4;
      if (cVar3 == '\0') {
        return 0;
      }
    }
    local_1e8 = local_1e8 + 1;
    if (1 < local_1e8) {
      return 1;
    }
  } while( true );
}


