// Function: FUN_005687f0 @ 005687f0
// Strings:  [CLOCK$]


uint __fastcall FUN_005687f0(char *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char local_64 [8];
  undefined **local_5c [3];
  char *local_50;
  undefined *local_4c;
  undefined *local_48;
  undefined *local_44;
  undefined *local_40;
  undefined *local_3c;
  undefined *local_38;
  undefined *local_34;
  undefined *local_30;
  undefined *local_2c;
  undefined *local_28;
  undefined *local_24;
  undefined *local_20;
  undefined *local_1c;
  undefined *local_18;
  undefined *local_14;
  undefined *local_10;
  undefined *local_c;
  undefined *local_8;
  undefined *local_4;
  
  local_5c[0] = (undefined **)&DAT_005e5230;
  local_5c[1] = (undefined **)&DAT_005e522c;
  local_5c[2] = &PTR_LAB_005d4d10;
  local_50 = s_CLOCK__005e5224;
  local_4c = &DAT_005e521c;
  local_48 = &DAT_005e5214;
  local_44 = &DAT_005e520c;
  local_40 = &DAT_005e5204;
  local_3c = &DAT_005e51fc;
  local_38 = &DAT_005e51f4;
  local_34 = &DAT_005e51ec;
  local_30 = &DAT_005e51e4;
  local_2c = &DAT_005e51dc;
  local_28 = &DAT_005e51d4;
  local_24 = &DAT_005e51cc;
  local_20 = &DAT_005e51c4;
  local_1c = &DAT_005e51bc;
  local_18 = &DAT_005e51b4;
  local_14 = &DAT_005e51ac;
  local_10 = &DAT_005e51a4;
  local_c = &DAT_005e519c;
  local_8 = &DAT_005e5194;
  local_4 = &DAT_005e5190;
  _strncpy(local_64,param_1,7);
  local_64[7] = 0;
  uVar2 = 0;
  while ((((cVar1 = local_64[uVar2], cVar1 != '\\' && (cVar1 != '/')) && (cVar1 != ':')) &&
         (cVar1 != '.'))) {
    uVar2 = uVar2 + 1;
    if (7 < uVar2) {
LAB_005688e3:
      iVar3 = 0;
      do {
        uVar2 = FUN_00588410(local_64,local_5c[iVar3]);
        if (uVar2 == 0) {
          return 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < 0x17);
      return uVar2 & 0xffffff00;
    }
  }
  local_64[uVar2] = '\0';
  goto LAB_005688e3;
}


