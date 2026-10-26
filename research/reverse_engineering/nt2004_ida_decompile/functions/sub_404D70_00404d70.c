int __thiscall sub_404D70(_DWORD *this)
{
  int result; // eax
  int v3; // ebp
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // [esp+4h] [ebp-4h]

  result = this[89];
  v12 = 0;
  if ( result > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this[90];
      v5 = *(_DWORD *)(v4 + v3 + 300);
      v6 = v3 + v4;
      if ( v5 )
      {
        v7 = *(_DWORD *)(v5 + 328);
        if ( v7 < this[18] )
        {
          if ( v7 < this[17] && !*(_DWORD *)(v6 + 328) )
          {
            v10 = *(_DWORD *)(v5 + 296);
            *(_DWORD *)(v5 + 120) = 0;
            if ( v10 )
            {
              while ( 1 )
              {
                v11 = *(_DWORD *)(v10 + 296);
                if ( !v11 || v10 == v5 || *(_DWORD *)(v11 + 292) != v10 )
                  break;
                *(float *)(v10 + 120) = *(float *)(*(_DWORD *)(v10 + 292) + 120)
                                      + *(float *)(*(_DWORD *)(v10 + 292) + 104);
                v10 = v11;
              }
            }
          }
        }
        else
        {
          v8 = sub_403FD0(this, (float *)v5, *(_DWORD *)(v5 + 100));
          if ( v8 )
          {
            v9 = *(_DWORD *)(v8 + 292);
            if ( v9 )
              *(float *)(v5 + 120) = (*(float *)(v9 + 120) + *(float *)(v8 + 120)) * 0.5;
          }
        }
      }
      result = v12 + 1;
      v3 += 348;
      ++v12;
    }
    while ( v12 < this[89] );
  }
  return result;
}
