// Function: FUN_0051664f @ 0051664f
// Size (bytes): 291


int FUN_0051664f(int *param_1,int *param_2,uint param_3,uint param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = param_3 + param_4;
  if ((((uint)param_2[1] < uVar1) || ((uint)param_2[3] < param_4)) || (*param_2 == 0)) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    (**(code **)*param_1)(param_1);
  }
  if ((param_3 < (uint)param_2[6]) || ((uint)(param_2[4] + param_2[6]) < uVar1)) {
    if (*(char *)((int)param_2 + 0x22) == '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x44;
      (**(code **)*param_1)(param_1);
    }
    if (*(char *)((int)param_2 + 0x21) != '\0') {
      FUN_005164a6(param_1,1);
      *(undefined1 *)((int)param_2 + 0x21) = 0;
    }
    if ((uint)param_2[6] < param_3) {
      param_2[6] = param_3;
    }
    else {
      iVar3 = uVar1 - param_2[4];
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      param_2[6] = iVar3;
    }
    FUN_005164a6(param_1,0);
  }
  uVar4 = param_2[7];
  if (uVar4 < uVar1) {
    if ((uVar4 < param_3) && (uVar4 = param_3, param_5 != '\0')) {
      *(undefined4 *)(*param_1 + 0x14) = 0x14;
      (**(code **)*param_1)(param_1);
    }
    if (param_5 != '\0') {
      param_2[7] = uVar1;
    }
    if ((char)param_2[8] != '\0') {
      iVar3 = param_2[6];
      iVar2 = param_2[2];
      for (uVar4 = uVar4 - iVar3; uVar4 < uVar1 - iVar3; uVar4 = uVar4 + 1) {
        FUN_005159a8(*(undefined4 *)(*param_2 + uVar4 * 4),iVar2 << 7);
      }
      goto LAB_00516758;
    }
    if (param_5 == '\0') {
      *(undefined4 *)(*param_1 + 0x14) = 0x14;
      (**(code **)*param_1)(param_1);
      goto LAB_00516758;
    }
  }
  else {
LAB_00516758:
    if (param_5 == '\0') goto LAB_00516762;
  }
  *(undefined1 *)((int)param_2 + 0x21) = 1;
LAB_00516762:
  return *param_2 + (param_3 - param_2[6]) * 4;
}


