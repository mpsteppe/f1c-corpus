// Function: FUN_00491ee0 @ 00491ee0
// Size (bytes): 120


undefined4 __fastcall FUN_00491ee0(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_00534b00();
  *param_1 = iVar1;
  if (*(char *)((int)param_1 + 0x19a) != '\0') {
    iVar1 = FUN_00587db0(param_1 + 0x23,&DAT_005c302c);
    param_1[1] = iVar1;
  }
  if ((param_1[1] == 0) && (*(char *)((int)param_1 + 0x19a) != '\0')) {
    *(undefined1 *)((int)param_1 + 0x19a) = 0;
  }
  if (*param_1 != 0) {
    FUN_00535390(0);
  }
  if (*(char *)((int)param_1 + 0x19a) != '\0') {
    FUN_00587f64(param_1[1],0,0);
  }
  return 0;
}


