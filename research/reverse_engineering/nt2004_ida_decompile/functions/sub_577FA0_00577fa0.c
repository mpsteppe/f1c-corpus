BOOL __thiscall sub_577FA0(int this, char *String2, bool *a3, bool *a4, bool *a5, bool *a6)
{
  bool *v7; // ebx
  bool *v8; // ebp
  bool *v9; // edi
  int v10; // eax
  BOOL v11; // ecx
  bool v12; // zf
  BOOL result; // eax
  int v14; // eax

  if ( !sub_577DB0((char *)this, String2) )
    return 0;
  v7 = a4;
  v8 = a6;
  v9 = a3;
  if ( a6 )
  {
    v10 = sscanf(*(const char *const *)(this + 384), "(%d,%d,%d,%d)", &String2, &a6, &a3, &a4);
    v11 = 0;
    v12 = v10 == 4;
  }
  else
  {
    if ( !a5 )
    {
      if ( a4 )
      {
        result = sscanf(*(const char *const *)(this + 384), "(%d,%d)", &String2, &a6) == 2;
      }
      else
      {
        if ( !a3 )
          return 0;
        result = sscanf(*(const char *const *)(this + 384), "(%d)", &String2) == 1;
        if ( !result )
          result = sscanf(*(const char *const *)(this + 384), "%d", &String2) == 1;
      }
      goto LABEL_5;
    }
    v14 = sscanf(*(const char *const *)(this + 384), "(%d,%d,%d)", &String2, &a6, &a3);
    v11 = 0;
    v12 = v14 == 3;
  }
  LOBYTE(v11) = v12;
  result = v11;
LABEL_5:
  if ( v9 )
    *v9 = String2 != 0;
  if ( v7 )
    *v7 = a6 != 0;
  if ( a5 )
    *a5 = a3 != 0;
  if ( v8 )
    *v8 = a4 != 0;
  return result;
}
