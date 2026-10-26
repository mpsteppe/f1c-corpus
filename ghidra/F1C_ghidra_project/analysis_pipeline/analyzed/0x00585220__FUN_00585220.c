// Function: FUN_00585220 @ 00585220
// Size (bytes): 69


undefined4 __thiscall FUN_00585220(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = *(undefined1 *)((int)param_1 + 0x5d);
  }
  iVar2 = (**(code **)(*param_1 + 0xa4))();
  iVar1 = param_1[0x18];
  if (param_3 != 0) {
    *(bool *)param_3 = iVar2 < iVar1;
  }
  if ((*(char *)((int)param_1 + 0x5d) != '\0') && (iVar2 < iVar1)) {
    return 1;
  }
  return 0;
}


