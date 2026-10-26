// Function: FUN_00461ed0 @ 00461ed0
// Size (bytes): 152


undefined4 __thiscall FUN_00461ed0(int *param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  char local_40 [63];
  undefined1 local_1;
  
  if (*(int *)(*param_1 + 0x1b79c) != 0) {
    uVar2 = (uint)DAT_007d0fe8;
    local_40[0] = '\0';
    _strncpy(local_40,param_2,0x3f);
    local_1 = 0;
    iVar1 = FUN_00587c20(local_40,&DAT_005c3f6c);
    if (iVar1 != 0) {
      FUN_005897ca(local_40,&DAT_005c3f6c);
      iVar1 = FUN_005897ca(0,&DAT_005c3f6c);
      if (iVar1 != 0) {
        uVar2 = FUN_00587ece(iVar1);
      }
    }
    FUN_00563260(uVar2,1,5);
  }
  return 1;
}


