// Function: FUN_005995e5 @ 005995e5
// Size (bytes): 48


void __fastcall FUN_005995e5(int param_1)

{
  char *_Str;
  size_t sVar1;
  
  _Str = *(char **)(param_1 + 4);
  if (((_Str != (char *)0x0) && (_Str[-1] != '\0')) && (_Str[-1] != -1)) {
    FUN_005993af(1);
    sVar1 = _strlen(_Str);
    FUN_00599615(_Str,sVar1);
  }
  return;
}


