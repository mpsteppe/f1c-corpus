// Function: FUN_00553650 @ 00553650
// Strings:  [Wrong vertex format, Too many vertices for polygon]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __thiscall
FUN_00553650(uint *param_1,int param_2,float param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  if (0xf < param_2) {
    FUN_0053c590(0xffffffff,s_Too_many_vertices_for_polygon_005dc140);
    return 0xffffffff;
  }
  if ((*param_1 & 2) == 0) {
    FUN_0053c590(0xffffffff,s_Wrong_vertex_format_005dc12c);
    return 0xffffffff;
  }
  if ((int)(param_1[1] - 1) < param_2) {
    param_1[1] = param_2 + 1;
  }
  param_2 = param_2 * 0x1c;
  *(float *)(param_2 + param_1[6]) = _DAT_008b8cf4 * param_3 + _DAT_008b8cf0 * (float)DAT_008b8dd4;
  *(undefined4 *)(param_2 + 4 + param_1[6]) = param_4;
  *(undefined4 *)(param_2 + 8 + param_1[6]) = param_5;
  *(undefined4 *)(param_2 + 0xc + param_1[6]) = 0x3f800000;
  *(undefined4 *)(param_2 + 0x14 + param_1[6]) = param_6;
  *(undefined4 *)(param_2 + 0x18 + param_1[6]) = param_7;
  *(undefined4 *)(param_2 + 0x10 + param_1[6]) = param_8;
  *param_1 = *param_1 | 0x8000;
  return 0;
}


