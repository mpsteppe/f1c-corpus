// Function: FUN_004a5d10 @ 004a5d10
// Size (bytes): 247


void __thiscall FUN_004a5d10(int *param_1,int param_2)

{
  int iVar1;
  char cVar2;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  if (param_1[0x61] != (int)*(char *)(param_2 + 8)) {
    param_1[0x61] = (int)*(char *)(param_2 + 8);
    FUN_0041a200(*param_1);
  }
  param_1[0x62] = *(int *)(param_2 + 4);
  if ((*(int *)(*param_1 + 13000) == 2) || (*(int *)(*param_1 + 13000) == 3)) {
    if (param_1[0x61] == 0) {
      FUN_004a5f20();
    }
    else if (param_1[0x61] == 2) {
      FUN_004a5ea0();
    }
  }
  FUN_004a55e0();
  iVar1 = param_1[0x61];
  if (iVar1 == 0) {
    if (param_1[2] != 0) {
      FUN_004a3440();
      return;
    }
  }
  else if ((iVar1 == 1) || (iVar1 == 2)) {
    cVar2 = FUN_004a6db0();
    if (param_1[2] != 0) {
      FUN_004a3390(cVar2 == '\0');
    }
    FUN_004d1100(*param_1,local_c,local_18);
    if (param_1[4] != 0) {
      FUN_004a3320(local_c,local_18);
    }
    if (param_1[3] != 0) {
      FUN_004a3320(local_c,local_18);
    }
  }
  return;
}


