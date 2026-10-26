// Function: FUN_004986d0 @ 004986d0
// Strings:  [Options Error]


void FUN_004986d0(char *param_1)

{
  char local_80 [127];
  undefined1 local_1;
  
  if (param_1 != (char *)0x0) {
    _strncpy(local_80,param_1,0x7f);
    local_1 = 0;
    MessageBoxA((HWND)0x0,local_80,s_Options_Error_005ccae4,0);
    FUN_00589ca4(1);
  }
  return;
}


