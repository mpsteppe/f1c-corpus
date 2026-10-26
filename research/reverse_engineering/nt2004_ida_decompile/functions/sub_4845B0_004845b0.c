int __thiscall sub_4845B0(_DWORD *this, int a2)
{
  int v3; // ecx
  int v4; // eax
  int v5; // eax
  int *v6; // eax
  int v7; // eax
  char *v8; // eax

  v3 = a2;
  v4 = this[219];
  if ( a2 < v4 )
  {
    if ( a2 < 0 || a2 >= v4 )
    {
      this[218] = 0;
    }
    else
    {
      this[218] = this[216];
      if ( a2 > 0 )
      {
        do
        {
          v5 = this[218];
          if ( !v5 )
            break;
          --v3;
          this[218] = *(_DWORD *)(v5 + 4);
        }
        while ( v3 > 0 );
      }
    }
    v6 = (int *)this[218];
    if ( v6 )
    {
      v7 = *v6;
      if ( v7 )
      {
        v8 = *(char **)(v7 + 64);
        if ( !v8 )
          v8 = &byte_629120;
        sub_4A1AC0(v8);
      }
    }
  }
  return sub_484640(this);
}
