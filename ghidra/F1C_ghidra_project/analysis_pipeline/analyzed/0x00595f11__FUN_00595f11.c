// Function: FUN_00595f11 @ 00595f11
// Size (bytes): 113


undefined8 FUN_00595f11(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined8 uVar2;
  
  if ((param_1 < DAT_008d4a20) &&
     ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00595a61(param_1);
    uVar2 = FUN_00595f82(param_1,param_2,param_3,param_4);
    FUN_00595ac0(param_1);
    return uVar2;
  }
  puVar1 = (undefined4 *)FUN_0058afcf();
  *puVar1 = 9;
  puVar1 = (undefined4 *)FUN_0058afd8();
  *puVar1 = 0;
  return 0xffffffffffffffff;
}


