// Function: FUN_00463710 @ 00463710
// Size (bytes): 49


void __thiscall FUN_00463710(int *param_1,char *param_2)

{
  int iVar1;
  
  if (param_2 == (char *)0x0) {
    *(undefined1 *)(*param_1 + 0x1b0) = 0;
    return;
  }
  iVar1 = *param_1;
  _strncpy((char *)(iVar1 + 0x1b0),param_2,0x1f);
  *(undefined1 *)(iVar1 + 0x1cf) = 0;
  return;
}


