// Function: FUN_0045c8b0 @ 0045c8b0
// Size (bytes): 51


void __thiscall FUN_0045c8b0(undefined4 *param_1,char param_2)

{
  int iVar1;
  
  *param_1 = 0;
  if (param_2 != '\0') {
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    param_1[4] = 0;
  }
  iVar1 = 0;
  do {
    FUN_0045c850(iVar1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x68);
  return;
}


