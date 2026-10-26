void __thiscall sub_488970(_DWORD *this)
{
  int v2; // ecx
  int *v3; // eax
  int v4; // eax
  int v5; // eax
  int *v6; // eax
  int v7; // eax
  char *v8; // eax

  v2 = this[220];
  if ( v2 >= 0 && v2 < this[219] )
  {
    v3 = (int *)this[216];
    if ( v2 <= 0 )
    {
LABEL_6:
      if ( v3 )
      {
        v4 = *v3;
        if ( v4 )
        {
          v5 = *(_DWORD *)(v4 + 84);
          if ( v5 )
          {
            sub_4E8C80(v5 + 260);
            sub_4E8A30(&byte_7D6A30);
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
        }
      }
    }
    else
    {
      while ( v3 )
      {
        v3 = (int *)v3[1];
        if ( --v2 <= 0 )
          goto LABEL_6;
      }
    }
  }
}
