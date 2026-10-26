// Function: FUN_004c6b60 @ 004c6b60
// Size (bytes): 216


void __thiscall FUN_004c6b60(int param_1,char param_2)

{
  char cVar1;
  char cVar2;
  undefined1 local_18 [12];
  undefined1 local_c [12];
  
  FUN_004bb8e0();
  cVar1 = FUN_004d1180(param_1,local_c,local_18);
  if (param_2 == '\0') {
    cVar2 = FUN_004bc9b0(0,0);
    if (cVar2 != '\0') goto LAB_004c6c06;
  }
  FUN_004ef7c0(local_c,local_18);
  FUN_004e9600();
  FUN_004f1c00(cVar1 == '\0');
  if (cVar1 == '\0') {
    FUN_004a5e60();
    if (*(int *)(param_1 + 0x4894) == *(int *)((&DAT_007c54f0)[DAT_007c54e4] + 0x4894)) {
      FUN_0040d100();
    }
  }
  else {
    FUN_004a5e80();
  }
LAB_004c6c06:
  FUN_00424b20();
  if ((DAT_007c56a4 == 7) && ((DAT_007c56a8 == 3 || (DAT_007c56a8 == 4)))) {
    FUN_004efa40(1);
  }
  return;
}


