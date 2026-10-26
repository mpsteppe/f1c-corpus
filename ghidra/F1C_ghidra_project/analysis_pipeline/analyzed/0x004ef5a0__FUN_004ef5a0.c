// Function: FUN_004ef5a0 @ 004ef5a0
// Size (bytes): 218


void __thiscall FUN_004ef5a0(int *param_1,int param_2,char param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_30 [12];
  undefined1 local_24 [12];
  double local_18;
  double local_10;
  double local_8;
  
  iVar1 = param_1[0xcaf];
  param_1[0xcaf] = param_2;
  if (param_3 != '\0') {
    if (DAT_007c569c != 5) {
      return;
    }
    if ((param_2 != 0) || (iVar1 == 0)) goto LAB_004ef62c;
    FUN_004efb20(local_24,local_30);
    FUN_004ef7c0(local_24,local_30);
    local_18 = (double)(float)param_1[0xd3b];
    local_10 = (double)(float)param_1[0xd3c];
    local_8 = (double)(float)param_1[0xd3d];
    FUN_00447780(&local_18);
  }
  if (DAT_007c569c != 5) {
    return;
  }
LAB_004ef62c:
  if ((iVar1 != 1) && (param_1[0xcaf] == 1)) {
    uVar2 = 0;
    iVar1 = FUN_004e9630();
    if (iVar1 != 0) {
      uVar2 = *(undefined4 *)(iVar1 + 300);
    }
    FUN_0042adb0();
    FUN_0042aca0(uVar2);
    iVar1 = *param_1;
    *(undefined4 *)(iVar1 + 0x4354) = 0;
    *(undefined4 *)(iVar1 + 0x4358) = 0;
  }
  return;
}


