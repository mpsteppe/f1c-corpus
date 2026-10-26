int __thiscall sub_4038E0(_DWORD *this)
{
  int result; // eax
  int v3; // ebp
  int v4; // eax
  float *v5; // esi
  int v6; // eax
  int v7; // ecx
  int v8; // eax
  int v9; // ecx
  int v10; // eax
  int v11; // edx
  int v12; // [esp+4h] [ebp-4h]

  result = this[78];
  v12 = 0;
  if ( result > 0 )
  {
    v3 = 0;
    do
    {
      v4 = this[79];
      v5 = *(float **)(v4 + v3 + 280);
      v6 = v3 + v4;
      if ( v5 )
      {
        v7 = *((_DWORD *)v5 + 76);
        if ( v7 < this[5] )
        {
          if ( v7 == 1 && !*(_DWORD *)(v6 + 304) )
          {
            v10 = *((_DWORD *)v5 + 69);
            v5[20] = 0.0;
            if ( v10 )
            {
              while ( 1 )
              {
                v11 = *(_DWORD *)(v10 + 276);
                if ( !v11 || (float *)v10 == v5 || *(_DWORD *)(v11 + 272) != v10 )
                  break;
                *(float *)(v10 + 80) = *(float *)(*(_DWORD *)(v10 + 272) + 80) + *(float *)(*(_DWORD *)(v10 + 272) + 64);
                v10 = v11;
              }
            }
          }
        }
        else
        {
          v8 = sub_4031C0();
          if ( v8 )
          {
            v9 = *(_DWORD *)(v8 + 272);
            if ( v9 )
              v5[20] = (*(float *)(v9 + 80) + *(float *)(v8 + 80)) * 0.5;
          }
        }
      }
      result = v12 + 1;
      v3 += 320;
      ++v12;
    }
    while ( v12 < this[78] );
  }
  return result;
}
