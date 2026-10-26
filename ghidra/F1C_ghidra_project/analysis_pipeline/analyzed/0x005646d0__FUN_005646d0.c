// Function: FUN_005646d0 @ 005646d0
// Size (bytes): 101


int * __fastcall
FUN_005646d0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  
  piVar1 = _malloc(0x14);
  pvVar2 = _malloc(param_2 * 4);
  iVar4 = 0;
  *piVar1 = (int)pvVar2;
  if (0 < param_2) {
    do {
      uVar3 = FUN_00564810(param_6);
      iVar4 = iVar4 + 1;
      *(undefined4 *)(*piVar1 + -4 + iVar4 * 4) = uVar3;
    } while (iVar4 < param_2);
  }
  piVar1[2] = param_6;
  piVar1[1] = param_2;
  piVar1[4] = param_5;
  piVar1[3] = param_4;
  return piVar1;
}


