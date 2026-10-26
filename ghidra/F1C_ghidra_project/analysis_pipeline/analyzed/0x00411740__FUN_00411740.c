// Function: FUN_00411740 @ 00411740
// Size (bytes): 100


void FUN_00411740(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  piVar1 = DAT_008ac4c4;
  if (DAT_008ac4c4 != (int *)0x0) {
    local_10 = 0xffffffff;
    local_c = 0xffffffff;
    local_4 = 0;
    local_8 = 0;
    iVar2 = FUN_004117b0(param_1,&local_10,&local_c,&local_4,&local_8);
    if (iVar2 == 0) {
      (**(code **)(*piVar1 + 0x4c))(local_10);
      (**(code **)(*piVar1 + 0x4c))(local_10);
    }
  }
  return;
}


