// Function: FUN_0059249b @ 0059249b
// Size (bytes): 428


bool FUN_0059249b(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  
  if (DAT_005e775c != 0) {
    iVar2 = param_1[5];
    if ((iVar2 != DAT_005e77f0) || (iVar2 != DAT_005e7800)) {
      if (DAT_008d3fc0 == 0) {
        FUN_00592647(1,1,iVar2,4,1,0,0,2,0,0,0);
        FUN_00592647(0,1,param_1[5],10,5,0,0,2,0,0,0);
      }
      else {
        if (DAT_008d4060 != 0) {
          uVar4 = 0;
          uVar3 = 0;
          uVar5 = DAT_008d4066;
        }
        else {
          uVar4 = DAT_008d4064;
          uVar3 = DAT_008d4066;
          uVar5 = 0;
        }
        FUN_00592647(1,DAT_008d4060 == 0,iVar2,DAT_008d4062,uVar3,uVar4,uVar5,DAT_008d4068,
                     DAT_008d406a,DAT_008d406c,DAT_008d406e);
        if (DAT_008d400c != 0) {
          uVar4 = 0;
          uVar3 = 0;
          iVar2 = param_1[5];
          uVar5 = DAT_008d4012;
        }
        else {
          iVar2 = param_1[5];
          uVar4 = DAT_008d4010;
          uVar3 = DAT_008d4012;
          uVar5 = 0;
        }
        FUN_00592647(0,DAT_008d400c == 0,iVar2,DAT_008d400e,uVar3,uVar4,uVar5,DAT_008d4014,
                     DAT_008d4016,DAT_008d4018,DAT_008d401a);
      }
    }
    iVar2 = param_1[7];
    if (DAT_005e77f4 < DAT_005e7804) {
      if ((DAT_005e77f4 <= iVar2) && (iVar2 <= DAT_005e7804)) {
        if ((DAT_005e77f4 < iVar2) && (iVar2 < DAT_005e7804)) {
          return true;
        }
LAB_00592613:
        iVar1 = ((param_1[2] * 0x3c + param_1[1]) * 0x3c + *param_1) * 1000;
        if (iVar2 == DAT_005e77f4) {
          return DAT_005e77f8 <= iVar1;
        }
        return iVar1 < DAT_005e7808;
      }
    }
    else {
      if (iVar2 < DAT_005e7804) {
        return true;
      }
      if (DAT_005e77f4 < iVar2) {
        return true;
      }
      if ((iVar2 <= DAT_005e7804) || (DAT_005e77f4 <= iVar2)) goto LAB_00592613;
    }
  }
  return false;
}


