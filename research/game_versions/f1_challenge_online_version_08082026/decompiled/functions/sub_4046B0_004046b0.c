int __thiscall sub_4046B0(_DWORD *this)
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

  result = this[76];
  v12 = 0;
  if ( result > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this[77];
      v5 = *(_DWORD *)(v4 + v3 + 276);
      v6 = v3 + v4;
      if ( v5 )
      {
        v7 = *(_DWORD *)(v5 + 300);
        if ( v7 < this[4] )
        {
          if ( v7 == 1 && !*(_DWORD *)(v6 + 300) )
          {
            v10 = *(_DWORD *)(v5 + 272);
            *(_DWORD *)(v5 + 76) = 0;
            if ( v10 )
            {
              while ( 1 )
              {
                v11 = *(_DWORD *)(v10 + 272);
                if ( !v11 || v10 == v5 || *(_DWORD *)(v11 + 268) != v10 )
                  break;
                *(float *)(v10 + 76) = *(float *)(*(_DWORD *)(v10 + 268) + 76) + *(float *)(*(_DWORD *)(v10 + 268) + 60);
                v10 = v11;
              }
            }
          }
        }
        else
        {
          v8 = sub_4038E0(this, (float *)v5, 1);
          if ( v8 )
          {
            v9 = *(_DWORD *)(v8 + 268);
            if ( v9 )
              *(float *)(v5 + 76) = (*(float *)(v9 + 76) + *(float *)(v8 + 76)) * 0.5;
          }
        }
      }
      result = v12 + 1;
      v3 += 316;
      ++v12;
    }
    while ( v12 < this[76] );
  }
  return result;
}
