// Function: FUN_00584ff0 @ 00584ff0
// Size (bytes): 35


void __thiscall FUN_00584ff0(int param_1,char *param_2)

{
  *(char *)(param_1 + 100) = '\0';
  if (param_2 != (char *)0x0) {
    _strncpy((char *)(param_1 + 100),param_2,0x10);
    *(undefined1 *)(param_1 + 0x74) = 0;
  }
  return;
}


