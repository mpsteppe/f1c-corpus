void __thiscall sub_484680(_DWORD *this)
{
  int v1; // esi
  int i; // edi
  int v3; // edx
  int *v4; // eax
  int v5; // eax
  int v6; // eax
  const char *v7; // esi

  v1 = this[219];
  for ( i = 0; i < v1; ++i )
  {
    v3 = i;
    if ( i >= 0 && i < this[219] )
    {
      v4 = (int *)this[216];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v4 )
        {
          v5 = *v4;
          if ( v5 )
          {
            v6 = *(_DWORD *)(v5 + 84);
            if ( v6 )
            {
              v7 = dword_766594;
              if ( !dword_766594 )
                v7 = &byte_629120;
              if ( !strcmp((const char *)(v6 + 260), v7) )
              {
                sub_4845B0(this, i);
                return;
              }
              v1 = this[219];
            }
          }
        }
      }
      else
      {
        while ( v4 )
        {
          v4 = (int *)v4[1];
          if ( --v3 <= 0 )
            goto LABEL_7;
        }
      }
    }
  }
}
