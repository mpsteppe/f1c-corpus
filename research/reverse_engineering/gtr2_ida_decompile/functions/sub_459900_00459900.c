void __thiscall sub_459900(int *this)
{
  float *v2; // edi
  int v3; // ebp
  float *v4; // edi
  int v5; // eax
  float *v6; // edx
  float *v7; // esi
  float *v8; // ecx
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  double v13; // st7
  double v14; // st7
  int v15; // eax
  int v16; // ebx
  float *v17; // edi
  int v18; // ebp
  float *v19; // esi
  int v20; // [esp+10h] [ebp-Ch]
  float v21; // [esp+10h] [ebp-Ch]
  float *v23; // [esp+18h] [ebp-4h]

  v2 = (float *)operator new(20 * *this);
  v3 = 0;
  v23 = v2;
  v20 = 0;
  if ( *this > 0 )
  {
    v4 = v2 + 2;
    while ( 1 )
    {
      v5 = v3 + this[2];
      *(_BYTE *)(v5 + 24) = 0;
      v6 = *(float **)v5;
      v7 = *(float **)(v5 + 8);
      v8 = *(float **)(v5 + 16);
      *((_DWORD *)v4 - 2) = v5;
      if ( *v6 <= (double)*v7 )
      {
        if ( *v6 >= (double)*v8 )
          v11 = *v8;
        else
          v11 = *v6;
        *(v4 - 1) = v11;
        if ( *v7 > (double)*v8 )
        {
          v10 = *v7;
          goto LABEL_15;
        }
      }
      else
      {
        if ( *v7 >= (double)*v8 )
          v9 = *v8;
        else
          v9 = *v7;
        *(v4 - 1) = v9;
        if ( *v6 > (double)*v8 )
        {
          v10 = *v6;
          goto LABEL_15;
        }
      }
      v10 = *v8;
LABEL_15:
      *v4 = v10;
      if ( v6[4] <= (double)v7[4] )
      {
        if ( v6[4] >= (double)v8[4] )
          v14 = v8[4];
        else
          v14 = v6[4];
        v4[1] = v14;
        if ( v7[4] <= (double)v8[4] )
        {
LABEL_26:
          v13 = v8[4];
          goto LABEL_27;
        }
        v13 = v7[4];
      }
      else
      {
        if ( v7[4] >= (double)v8[4] )
          v12 = v8[4];
        else
          v12 = v7[4];
        v4[1] = v12;
        if ( v6[4] <= (double)v8[4] )
          goto LABEL_26;
        v13 = v6[4];
      }
LABEL_27:
      v4[2] = v13;
      v3 += 32;
      v4 += 5;
      if ( ++v20 >= *this )
      {
        v2 = v23;
        break;
      }
    }
  }
  sub_632C60(v2, *this);
  v15 = *this;
  if ( *this > 0 )
  {
    v16 = 1;
    v17 = v2 + 2;
    do
    {
      v21 = *v17;
      v18 = v16;
      if ( v16 < v15 )
      {
        v19 = v17 + 6;
        do
        {
          if ( *(v19 - 2) > (double)v21 )
            break;
          if ( v17[2] > (double)*v19
            && v17[1] < (double)v19[1]
            && sub_459140(*((_DWORD **)v17 - 2), *((_DWORD **)v19 - 3)) )
          {
            *(_BYTE *)(*((_DWORD *)v17 - 2) + 24) = 1;
            *(_BYTE *)(*((_DWORD *)v19 - 3) + 24) = 1;
          }
          ++v18;
          v19 += 5;
        }
        while ( v18 < *this );
      }
      v15 = *this;
      v17 += 5;
      ++v16;
    }
    while ( v16 - 1 < *this );
    v2 = v23;
  }
  if ( v2 )
    j_j__free(v2);
}
