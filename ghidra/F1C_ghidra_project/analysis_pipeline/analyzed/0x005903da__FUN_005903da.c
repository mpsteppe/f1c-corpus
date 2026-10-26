// Function: FUN_005903da @ 005903da
// Size (bytes): 102


void FUN_005903da(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_c [8];
  
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = _strcmp(param_1,"ACP"), iVar1 == 0)) {
    uVar2 = 0x1004;
  }
  else {
    iVar1 = _strcmp(param_1,"OCP");
    if (iVar1 != 0) goto LAB_00590436;
    uVar2 = 0xb;
  }
  iVar1 = (*DAT_008d3fb8)(DAT_008d3fb4,uVar2,local_c,8);
  if (iVar1 == 0) {
    return;
  }
  param_1 = local_c;
LAB_00590436:
  FUN_00587ece(param_1);
  return;
}


