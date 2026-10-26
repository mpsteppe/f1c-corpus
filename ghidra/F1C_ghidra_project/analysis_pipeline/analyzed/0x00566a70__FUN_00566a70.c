// Function: FUN_00566a70 @ 00566a70
// Size (bytes): 164


bool __thiscall FUN_00566a70(int *param_1,undefined4 param_2,int param_3,int param_4,char param_5)

{
  char cVar1;
  int iVar2;
  undefined *puVar3;
  undefined1 local_400 [1024];
  
  if (param_5 != '\0') {
    cVar1 = FUN_005668f0(param_2);
    if (cVar1 == '\0') {
      return false;
    }
  }
  param_1[3] = param_4;
  param_1[4] = param_3;
  FUN_00568620(0x400);
  if (param_1[3] == 0) {
    puVar3 = &DAT_005e5180;
  }
  else {
    puVar3 = &DAT_005e517c;
  }
  iVar2 = FUN_00587db0(local_400,puVar3);
  *param_1 = iVar2;
  *(undefined1 *)(param_1 + 6) = 0;
  if (iVar2 != 0) {
    FUN_00566650(local_400);
  }
  return iVar2 != 0;
}


