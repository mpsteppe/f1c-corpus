// Function: FUN_004c2700 @ 004c2700
// Strings:  [[CAREER]]


undefined1 FUN_004c2700(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 local_1c [28];
  
  uVar2 = 0;
  if (param_1 != 0) {
    FUN_005668b0();
    cVar1 = FUN_00566940(param_1,0,1,1);
    uVar2 = 0;
    if (cVar1 != '\0') {
      uVar2 = FUN_004c2420(local_1c,s__CAREER__005d2e88);
      FUN_00566b90();
    }
    FUN_005668d0();
  }
  return uVar2;
}


