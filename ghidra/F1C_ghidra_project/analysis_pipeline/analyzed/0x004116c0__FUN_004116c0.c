// Function: FUN_004116c0 @ 004116c0
// Size (bytes): 127


int FUN_004116c0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_008ac4c4;
  iVar2 = 1;
  if (DAT_008ac4c4 != (int *)0x0) {
    local_10 = 0xffffffff;
    local_8 = 0xffffffff;
    local_c = 0;
    local_4 = 0;
    iVar2 = FUN_004117b0(param_1,&local_10,&local_8,&local_c,&local_4);
    if (iVar2 == 0) {
      (**(code **)(*piVar1 + 0x48))(local_c,local_10);
      (**(code **)(*piVar1 + 0x48))(local_c,local_10);
    }
  }
  return iVar2;
}


