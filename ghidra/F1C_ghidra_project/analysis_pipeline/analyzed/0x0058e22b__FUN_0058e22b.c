// Function: FUN_0058e22b @ 0058e22b
// Size (bytes): 101


undefined4 FUN_0058e22b(uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((param_1 < DAT_008d4a20) &&
     ((*(byte *)((&DAT_008d4920)[(int)param_1 >> 5] + 4 + (param_1 & 0x1f) * 0x24) & 1) != 0)) {
    FUN_00595a61(param_1);
    uVar1 = FUN_0058e290(param_1,param_2,param_3);
    FUN_00595ac0(param_1);
    return uVar1;
  }
  puVar2 = (undefined4 *)FUN_0058afcf();
  *puVar2 = 9;
  puVar2 = (undefined4 *)FUN_0058afd8();
  *puVar2 = 0;
  return 0xffffffff;
}


