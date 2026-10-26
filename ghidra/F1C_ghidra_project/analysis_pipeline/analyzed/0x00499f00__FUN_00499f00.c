// Function: FUN_00499f00 @ 00499f00
// Size (bytes): 112


void FUN_00499f00(int *param_1,int *param_2,int *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  undefined4 local_4;
  
  iVar2 = FUN_0049adb0();
  if (2 < iVar2) {
    cVar1 = FUN_0049aec0(0,&local_4,(int)&local_4 + 2);
    if (cVar1 != '\0') {
      *param_1 = (int)(short)local_4;
      *param_2 = (int)local_4._2_2_;
    }
    cVar1 = FUN_0049aec0(1,&local_4,(int)&local_4 + 2);
    if (cVar1 != '\0') {
      *param_3 = (int)(short)local_4;
      *param_4 = (int)local_4._2_2_;
    }
  }
  return;
}


