int __thiscall sub_405CA0(_DWORD *this, int a2)
{
  int result; // eax
  int v5; // esi
  int v6; // edi
  float *v7; // eax
  double v8; // st7
  double v9; // st6
  int v10; // ecx
  int v11; // ebx
  int v12; // edi
  int v13; // ecx
  int v14; // edx
  int v15; // eax
  double v16; // st5
  float v17; // esi
  float *v18; // eax
  int v19; // [esp+Ch] [ebp-14h]
  int v21[3]; // [esp+14h] [ebp-Ch] BYREF
  int i; // [esp+24h] [ebp+4h]

  result = *(_DWORD *)(a2 + 24);
  v5 = 0;
  if ( result > 0 )
  {
    do
    {
      v6 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v5);
      result = _stricmp(*(const char **)(v6 + 4), "Bip01");
      if ( !result )
        break;
      result = *(_DWORD *)(a2 + 24);
      ++v5;
    }
    while ( v5 < result );
    if ( v5 != *(_DWORD *)(a2 + 24) )
    {
      if ( *(int *)(v6 + 48) <= 0 )
      {
        v8 = *(float *)(v6 + 128);
        v9 = *(float *)(v6 + 136);
      }
      else
      {
        v7 = (float *)sub_4058B0(v6 + 48, v21, 0.0);
        v8 = *v7;
        v9 = v7[2];
      }
      result = this[2];
      v10 = 0;
      for ( i = 0; v10 < *(_DWORD *)(result + 336); i = v10 )
      {
        v11 = 0;
        v19 = *(_DWORD *)(*(_DWORD *)(result + 344) + 4 * v10);
        if ( *(int *)(a2 + 24) > 0 )
        {
          do
          {
            v12 = *(_DWORD *)(*(_DWORD *)(a2 + 32) + 4 * v11);
            if ( !strcmp(*(const char **)(v19 + 376), *(const char **)(v12 + 4)) )
            {
              v13 = 0;
              if ( *(int *)(v12 + 48) > 0 )
              {
                v14 = 0;
                do
                {
                  v15 = *(_DWORD *)(v12 + 56);
                  v16 = *(float *)(v15 + v14);
                  v17 = *(float *)(v15 + v14 + 8);
                  v18 = (float *)(v14 + v15);
                  *(float *)&v21[2] = v17;
                  ++v13;
                  v14 += 16;
                  *v18 = v16 - v8;
                  v18[2] = v17 - v9;
                }
                while ( v13 < *(_DWORD *)(v12 + 48) );
              }
            }
            ++v11;
          }
          while ( v11 < *(_DWORD *)(a2 + 24) );
          v10 = i;
        }
        result = this[2];
        ++v10;
      }
    }
  }
  return result;
}
