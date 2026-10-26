// Function: FUN_004bdc10 @ 004bdc10
// Strings:  [Could not get extents of scene ... numInstances=%d, D:\dev\F1_1999_2002\Source\searchgrid.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_004bdc10(int param_1)

{
  float fVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_30 = 3.4028235e+38;
  local_2c = 3.4028235e+38;
  local_28 = 3.4028235e+38;
  local_24 = -3.4028235e+38;
  local_20 = -3.4028235e+38;
  local_1c = -3.4028235e+38;
  iVar3 = FUN_005452f0();
  iVar6 = 0;
  if (0 < iVar3) {
    do {
      iVar4 = FUN_00545340(iVar6);
      iVar5 = FUN_0054fb70();
      if ((iVar5 != 0) && (((byte)*(undefined4 *)(iVar4 + 0x3c) & 0x10) != 0x10)) {
        FUN_004dd550(&local_c);
        if (local_18 < local_30) {
          local_30 = local_18;
        }
        if (local_14 < local_2c) {
          local_2c = local_14;
        }
        if (local_10 < local_28) {
          local_28 = local_10;
        }
        if (local_24 < local_c) {
          local_24 = local_c;
        }
        if (local_20 < local_8) {
          local_20 = local_8;
        }
        if (local_1c < local_4) {
          local_1c = local_4;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar3);
    if (((local_24 < local_30 == (local_24 == local_30)) &&
        (local_20 < local_2c == (local_20 == local_2c))) &&
       (local_1c < local_28 == (local_1c == local_28))) {
      fVar1 = _DAT_0059e4dc / (local_24 - local_30);
      *(float *)(param_1 + 0x924) = local_30;
      *(float *)(param_1 + 0x92c) = local_28;
      *(float *)(param_1 + 0x928) = fVar1;
      *(float *)(param_1 + 0x930) = _DAT_0059e4dc / (local_1c - local_28);
      return;
    }
  }
  cVar2 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_searc_005d2604,0x141);
  if (cVar2 != '\0') {
    FUN_004d7aa0(&DAT_008ad25c,s_Could_not_get_extents_of_scene___005d25d0,iVar3);
  }
  return;
}


