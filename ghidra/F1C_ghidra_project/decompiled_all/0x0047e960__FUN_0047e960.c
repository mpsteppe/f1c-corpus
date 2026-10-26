// Function: FUN_0047e960 @ 0047e960
// Strings:  [Disallowed, Selected Season, Time Scaled, Normal, Normal, Allowed]


undefined4 * __thiscall FUN_0047e960(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  
  FUN_00488b00(1,0xffffffff);
  param_1[0x3b] = 0;
  param_1[0x3c] = 0xffffffff;
  *param_1 = &PTR_FUN_005a6c78;
  piVar3 = (int *)param_1[0x11];
  while (piVar3 != (int *)0x0) {
    piVar1 = (int *)piVar3[1];
    if (((char)piVar3[2] != '\0') && (piVar2 = (int *)*piVar3, piVar2 != (int *)0x0)) {
      if (*piVar2 != 0) {
        FUN_00587bcf(*piVar2);
      }
      FUN_00587bcf(piVar2);
    }
    FUN_00587bcf(piVar3);
    piVar3 = piVar1;
  }
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x3d] = param_2;
  switch(param_2) {
  case 0x1e4:
  case 0x1e5:
  case 0x1e6:
  case 0x1e7:
  case 0x1e8:
  case 0x1e9:
  case 0x1ea:
  case 0x1eb:
  case 0x1ec:
  case 0x1ed:
  case 0x1ee:
    FUN_00486f30(s_Allowed_005c70e0,0xffffffff);
    FUN_00486f30(s_Disallowed_005c32cc,0xffffffff);
    return param_1;
  case 0x1f2:
    FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
    FUN_00486f30(&DAT_005c32c8,0xffffffff);
    return param_1;
  case 499:
  case 500:
    FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
    FUN_00486f30(s_Normal_005c6e74,0xffffffff);
    FUN_00486f30(&DAT_005c6fc0,0xffffffff);
    FUN_00486f30(&DAT_005c6fbc,0xffffffff);
    FUN_00486f30(&DAT_005c6fb8,0xffffffff);
    FUN_00486f30(&DAT_005c6fb4,0xffffffff);
    FUN_00486f30(&DAT_005c6fb0,0xffffffff);
    FUN_00486f30(&DAT_005c6fac,0xffffffff);
    return param_1;
  case 0x1f5:
    FUN_00486f30(&PTR_DAT_005be704,0xffffffff);
    FUN_00486f30(s_Normal_005c6e74,0xffffffff);
    FUN_00486f30(s_Time_Scaled_005c6e68,0xffffffff);
    FUN_00486f30(s_Selected_Season_005c6e58,0xffffffff);
  }
  return param_1;
}


