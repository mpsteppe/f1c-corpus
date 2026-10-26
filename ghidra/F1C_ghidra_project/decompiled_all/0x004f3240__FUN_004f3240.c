// Function: FUN_004f3240 @ 004f3240
// Strings:  [-z force applied when moving in -z direction, +z force applied when moving in +z direction, -y force applied when moving in -y direction, +y force applied when moving in +y direction, -x force applied when moving in -x direction, +x force applied when moving in +x direction, D:\dev\F1_1999_2002\Source\vehload.cpp, D:\dev\F1_1999_2002\Source\vehload.cpp]


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall FUN_004f3240(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  double *pdVar1;
  double *pdVar2;
  double *pdVar3;
  char cVar4;
  int iVar5;
  
  pdVar3 = (double *)(param_1 + param_3 * 0x18);
  pdVar1 = pdVar3 + 2;
  pdVar2 = pdVar3 + 1;
  iVar5 = FUN_00565aa0(param_4,pdVar3,pdVar2,pdVar1,0);
  if (iVar5 != 0) {
    switch(param_3) {
    case 0:
      if (((_DAT_0059e430 < *pdVar3) && (DAT_007c569c != 5)) &&
         (cVar4 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x15f), cVar4 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s__x_force_applied_when_moving_in___005d545c);
        return;
      }
      break;
    case 1:
      if (((*pdVar3 < _DAT_0059e430) && (DAT_007c569c != 5)) &&
         (cVar4 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x164), cVar4 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s__x_force_applied_when_moving_in___005d542c);
        return;
      }
      break;
    case 2:
      if (((_DAT_0059e430 < *pdVar2) && (DAT_007c569c != 5)) &&
         (cVar4 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x169), cVar4 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s__y_force_applied_when_moving_in___005d53fc);
        return;
      }
      break;
    case 3:
      if (((*pdVar2 < _DAT_0059e430) && (DAT_007c569c != 5)) &&
         (cVar4 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x16e), cVar4 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s__y_force_applied_when_moving_in___005d53cc);
        return;
      }
      break;
    case 4:
      if (((_DAT_0059e430 < *pdVar1) && (DAT_007c569c != 5)) &&
         (cVar4 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x173), cVar4 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s__z_force_applied_when_moving_in___005d539c);
        return;
      }
      break;
    case 5:
      if (((*pdVar1 < _DAT_0059e430) && (DAT_007c569c != 5)) &&
         (cVar4 = FUN_004d7a50(1,s_D__dev_F1_1999_2002_Source_vehlo_005d548c,0x178), cVar4 != '\0'))
      {
        FUN_004d7aa0(&DAT_008ad25c,s__z_force_applied_when_moving_in___005d536c);
      }
    }
  }
  return;
}


