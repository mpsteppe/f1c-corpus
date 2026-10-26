int __thiscall sub_4985D0(const char *this, int a2, const char *a3, char a4)
{
  const char *v4; // ebp
  int result; // eax
  const char *v7; // esi
  char v8; // [esp-4h] [ebp-14h]
  int v9; // [esp+Ch] [ebp-4h] BYREF

  v4 = a3;
  result = 0;
  if ( a3 )
  {
    a3 = 0;
    v9 = 0;
    sub_4983B0(this, v4, &a3, &v9, a4);
    result = a2;
    if ( (int)a3 > a2 )
    {
      result = 0;
      v7 = &v4[strlen(v4) + 1];
      do
      {
        if ( v4 == v7 )
          break;
        v8 = a4;
        *--v7 = 0;
        result = sub_4983B0(this, v4, &a3, &v9, v8);
      }
      while ( (int)a3 > a2 );
    }
  }
  return result;
}
