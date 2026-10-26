// Function: FUN_00541500 @ 00541500
// Size (bytes): 353


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall FUN_00541500(int *param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_68 [5];
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (param_1[0x4f6] == 0) {
    return 0;
  }
  puVar2 = local_68;
  for (iVar1 = 0x1a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  if (param_2 == 1) {
    local_68[0] = 3;
    local_1c = 1e+12;
  }
  else if ((param_2 == 2) || (param_2 == 4)) {
    local_68[0] = 1;
    local_1c = SQRT((float)_DAT_005ad208);
  }
  local_2c = 0;
  local_20 = 0;
  local_34 = 0;
  local_30 = 0;
  local_28 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_68[1] = 0x3f800000;
  local_68[2] = 0x3f800000;
  local_68[3] = 0x3f800000;
  local_54 = 0x3f800000;
  local_50 = 0x3f800000;
  local_4c = 0x3f800000;
  local_24 = 0xbf800000;
  local_14 = 0x3f800000;
  local_10 = 0;
  local_c = 0;
  iVar1 = (**(code **)(*(int *)param_1[0x440] + 0xb0))
                    ((int *)param_1[0x440],param_1[0x4ed],local_68);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return -1;
  }
  iVar1 = param_1[0x4ed];
  param_1[0x4ed] = iVar1 + 1;
  return iVar1;
}


