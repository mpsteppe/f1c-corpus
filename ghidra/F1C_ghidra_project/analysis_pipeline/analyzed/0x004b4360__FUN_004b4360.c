// Function: FUN_004b4360 @ 004b4360
// Size (bytes): 124


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_004b4360(undefined4 param_1,float param_2,uint *param_3)

{
  uint *puVar1;
  uint uVar2;
  
  puVar1 = param_3;
  FUN_00566c00(param_3,4);
  if (((*puVar1 & 0xe0000000) == 0x20000000) && ((*puVar1 & 0xfc0000) == 0)) {
    FUN_00566c00(&param_3,1);
    param_3 = (uint *)((uint)param_3 & 0xff);
    puVar1[1] = (uint)((float)(int)param_3 * (float)_DAT_005acd28 + param_2);
  }
  else {
    puVar1[1] = (uint)param_2;
  }
  uVar2 = FUN_00566c00(puVar1 + 2,*puVar1 >> 8 & 0x3ff);
  return uVar2 & 0xffffff00;
}


