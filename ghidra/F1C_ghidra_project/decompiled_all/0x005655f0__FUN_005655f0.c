// Function: FUN_005655f0 @ 005655f0
// Strings:  [(%d,%d), (%d,%d,%d), (%d,%d,%d,%d)]


bool __thiscall
FUN_005655f0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = FUN_00565400(param_2);
  iVar3 = param_6;
  iVar2 = param_4;
  iVar1 = param_3;
  if (iVar4 == 0) {
    return false;
  }
  if (param_6 == 0) {
    if (param_5 == 0) {
      if (param_4 == 0) {
        if (param_3 == 0) {
          return false;
        }
        iVar4 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&DAT_005e5074,&param_2);
        bVar5 = iVar4 == 1;
        if (!bVar5) {
          iVar4 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),&DAT_005c3280,&param_2);
          bVar5 = iVar4 == 1;
        }
      }
      else {
        iVar4 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___d__d__005e507c,&param_2,&param_6);
        bVar5 = iVar4 == 2;
      }
    }
    else {
      iVar4 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___d__d__d__005e5084,&param_2,&param_6,
                           &param_3);
      bVar5 = iVar4 == 3;
    }
  }
  else {
    iVar4 = FUN_005887ed(*(undefined4 *)(param_1 + 0x180),s___d__d__d__d__005e5090,&param_2,&param_6
                         ,&param_3,&param_4);
    bVar5 = iVar4 == 4;
  }
  if (iVar1 != 0) {
    *(bool *)iVar1 = param_2 != 0;
  }
  if (iVar2 != 0) {
    *(bool *)iVar2 = param_6 != 0;
  }
  if (param_5 != 0) {
    *(bool *)param_5 = param_3 != 0;
  }
  if (iVar3 != 0) {
    *(bool *)iVar3 = param_4 != 0;
  }
  return bVar5;
}


