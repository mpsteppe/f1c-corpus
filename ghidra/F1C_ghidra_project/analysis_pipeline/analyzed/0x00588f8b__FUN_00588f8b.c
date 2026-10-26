// Function: FUN_00588f8b @ 00588f8b
// Size (bytes): 204


undefined4 FUN_00588f8b(char *param_1,char *param_2)

{
  char cVar1;
  size_t _Count;
  char *_Source;
  char *_Dest;
  
  _Source = param_2;
  _memset(param_1,0,0x88);
  if (*param_2 != '\0') {
    if ((*param_2 != '.') || (param_2[1] == '\0')) {
      param_2 = (char *)0x0;
      while( true ) {
        _Count = FUN_0058fc20(_Source,&DAT_005b8c7c);
        if (_Count == 0) {
          return 0xffffffff;
        }
        cVar1 = _Source[_Count];
        if (param_2 == (char *)0x0) {
          if (0x3f < (int)_Count) {
            return 0xffffffff;
          }
          _Dest = param_1;
          if (cVar1 == '.') {
            return 0xffffffff;
          }
        }
        else if (param_2 == (char *)0x1) {
          if (0x3f < (int)_Count) {
            return 0xffffffff;
          }
          if (cVar1 == '_') {
            return 0xffffffff;
          }
          _Dest = param_1 + 0x40;
        }
        else {
          if (param_2 != (char *)0x2) {
            return 0xffffffff;
          }
          if ((cVar1 != '\0') && (cVar1 != ',')) {
            return 0xffffffff;
          }
          _Dest = param_1 + 0x80;
        }
        _strncpy(_Dest,_Source,_Count);
        if (cVar1 == ',') {
          return 0;
        }
        if (cVar1 == '\0') break;
        param_2 = (char *)((int)param_2 + 1);
        _Source = _Source + _Count + 1;
      }
      return 0;
    }
    FUN_0058fca0(param_1 + 0x80,param_2 + 1);
  }
  return 0;
}


