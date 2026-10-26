int __thiscall sub_4CAD30(const char *this)
{
  int v2; // esi
  int v3; // edi
  int v4; // ebx
  int v5; // ecx
  char *v6; // edx
  char v7; // al
  int v8; // eax
  int v9; // eax

  v2 = 0;
  v3 = strlen(this);
  v4 = 0;
  if ( v3 > 0 )
  {
    v5 = 0;
    v6 = (char *)&this[v3 - 1];
    do
    {
      v7 = *v6;
      if ( *v6 < 97 || v7 > 102 )
      {
        if ( v7 < 65 || v7 > 70 )
        {
          if ( v7 < 48 || v7 > 57 )
            return v2;
          v8 = v7 - 48;
        }
        else
        {
          v8 = v7 - 55;
        }
      }
      else
      {
        v8 = v7 - 87;
      }
      v9 = v8 << v5;
      v5 += 4;
      v2 += v9;
      ++v4;
      --v6;
    }
    while ( v4 < v3 );
  }
  return v2;
}
