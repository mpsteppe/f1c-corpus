// Function: FUN_0052d8d0 @ 0052d8d0
// Size (bytes): 156


undefined4 __thiscall
FUN_0052d8d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0059c73b;
  local_c = ExceptionList;
  if (*param_1 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x2d40);
    local_4 = 0;
    if (pvVar1 == (void *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)FUN_0052e170(param_2,param_3);
    }
    *param_1 = (int)piVar2;
    local_4 = 0xffffffff;
    iVar3 = (**(code **)(*piVar2 + 4))(0,param_4);
    if (iVar3 != -1) {
      ExceptionList = local_c;
      return 1;
    }
    FUN_0052d990();
  }
  ExceptionList = local_c;
  return 0;
}


