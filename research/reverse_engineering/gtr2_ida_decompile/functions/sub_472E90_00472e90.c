char __thiscall sub_472E90(int *this, const char *a2, int a3, int a4, int a5)
{
  char result; // al
  int v8; // esi
  int *v9; // esi
  unsigned int v10; // [esp+Ch] [ebp+4h]

  result = 0;
  if ( a2 )
  {
    v10 = strlen(a2);
    if ( v10 )
    {
      if ( sub_472680((const char *)this, a2) )
      {
        return 1;
      }
      else
      {
        v8 = sub_472700(this, a5);
        if ( v8 < 0 )
        {
          return 0;
        }
        else
        {
          sub_472630();
          v9 = &this[23 * v8];
          sub_630FE0(v9 + 17, a2, 79);
          *((_BYTE *)v9 + 147) = 0;
          v9[37] = v10;
          v9[39] = a5;
          v9[38] = a3;
          return 1;
        }
      }
    }
    else
    {
      return 0;
    }
  }
  return result;
}
