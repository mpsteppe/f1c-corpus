// Function: FUN_004cada0 @ 004cada0
// Strings:  [D:\dev\F1_1999_2002\Source\specialfx.cpp, Unknown blend mode %s in terrain.ini, INVDSTALPHA, DSTALPHA, INVDSTCOLOR, DSTCOLOR, INVSRCALPHA, SRCALPHA]


undefined4 __fastcall FUN_004cada0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = FUN_00588410(param_1,&DAT_005d3770);
  if (iVar2 != 0) {
    iVar2 = FUN_00588410(param_1,&DAT_005d376c);
    if (iVar2 == 0) {
      return 2;
    }
    iVar2 = FUN_00588410(param_1,s_SRCCOLOR_005d3760);
    if (iVar2 == 0) {
      return 3;
    }
    iVar2 = FUN_00588410(param_1,s_INVSRCCOLOR_005d3754);
    if (iVar2 == 0) {
      return 4;
    }
    iVar2 = FUN_00588410(param_1,s_SRCALPHA_005d3748);
    if (iVar2 == 0) {
      return 5;
    }
    iVar2 = FUN_00588410(param_1,s_INVSRCALPHA_005d373c);
    if (iVar2 == 0) {
      return 6;
    }
    iVar2 = FUN_00588410(param_1,s_DSTCOLOR_005d3730);
    if (iVar2 == 0) {
      return 9;
    }
    iVar2 = FUN_00588410(param_1,s_INVDSTCOLOR_005d3724);
    if (iVar2 == 0) {
      return 10;
    }
    iVar2 = FUN_00588410(param_1,s_DSTALPHA_005d3718);
    if (iVar2 == 0) {
      return 7;
    }
    iVar2 = FUN_00588410(param_1,s_INVDSTALPHA_005d370c);
    if (iVar2 == 0) {
      return 8;
    }
    cVar1 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_speci_005d3624,0xa2);
    if (cVar1 != '\0') {
      FUN_004d7aa0(&DAT_008ad25c,s_Unknown_blend_mode__s_in_terrain_005d36e4,param_1);
    }
  }
  return 1;
}


