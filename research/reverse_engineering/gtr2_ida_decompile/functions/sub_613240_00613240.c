BOOL __thiscall sub_613240(int this, char *String2, bool *a3, bool *a4, bool *a5, bool *a6)
{
  bool *v7; // ebx
  bool *v8; // ebp
  bool *v9; // edi
  int v10; // eax
  BOOL result; // eax

  if ( !sub_613120((const char **)this, String2) )
    return 0;
  v7 = a4;
  v8 = a6;
  v9 = a3;
  if ( a6 )
  {
    v10 = sscanf(*(const char *const *)(this + 512), "(%d,%d,%d,%d)", &String2, &a6, &a3, &a4) - 4;
  }
  else if ( a5 )
  {
    v10 = sscanf(*(const char *const *)(this + 512), "(%d,%d,%d)", &String2, &a6, &a3) - 3;
  }
  else if ( a4 )
  {
    v10 = sscanf(*(const char *const *)(this + 512), "(%d,%d)", &String2, &a6) - 2;
  }
  else
  {
    if ( !a3 )
      return 0;
    result = sscanf(*(const char *const *)(this + 512), "(%d)", &String2) == 1;
    if ( result )
      goto LABEL_5;
    v10 = sscanf(*(const char *const *)(this + 512), "%d", &String2) - 1;
  }
  result = v10 == 0;
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
