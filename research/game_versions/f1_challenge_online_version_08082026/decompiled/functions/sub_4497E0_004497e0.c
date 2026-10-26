int __thiscall sub_4497E0(int *this)
{
  int *v1; // ebx
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
  int result; // eax
  int v16; // ebp
  float *v17; // edi
  float *v18; // esi
  int v19; // [esp+10h] [ebp-10h]
  int v20; // [esp+10h] [ebp-10h]
  float *v22; // [esp+18h] [ebp-8h]
  float v23; // [esp+1Ch] [ebp-4h]

  v1 = this;
  v2 = (float *)sub_587C03(20 * *this);
  v3 = 0;
  v22 = v2;
  v19 = 0;
  if ( *v1 > 0 )
  {
    v4 = v2 + 2;
    while ( 1 )
    {
      v5 = v3 + v1[2];
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
      if ( v6[3] <= (double)v7[3] )
      {
        if ( v8[3] <= (double)v6[3] )
          v14 = v8[3];
        else
          v14 = v6[3];
        v4[1] = v14;
        if ( v8[3] >= (double)v7[3] )
        {
LABEL_26:
          v13 = v8[3];
          goto LABEL_27;
        }
        v13 = v7[3];
      }
      else
      {
        if ( v8[3] <= (double)v7[3] )
          v12 = v8[3];
        else
          v12 = v7[3];
        v4[1] = v12;
        if ( v8[3] >= (double)v6[3] )
          goto LABEL_26;
        v13 = v6[3];
      }
LABEL_27:
      v4[2] = v13;
      v3 += 32;
      v4 += 5;
      if ( ++v19 >= *v1 )
      {
        v2 = v22;
        break;
      }
    }
  }
  sub_5890AA(v2, *v1, 20, sub_448440);
  result = *v1;
  if ( *v1 > 0 )
  {
    v16 = 1;
    v20 = 1;
    v17 = v2 + 2;
    do
    {
      v23 = *v17;
      if ( v16 < result )
      {
        v18 = v17 + 6;
        do
        {
          if ( *(v18 - 2) > (double)v23 )
            break;
          if ( v17[2] > (double)*v18 && v17[1] < (double)v18[1] )
          {
            v1 = this;
            if ( sub_4491C0(*((_DWORD **)v17 - 2), *((_DWORD **)v18 - 3)) )
            {
              *(_BYTE *)(*((_DWORD *)v17 - 2) + 24) = 1;
              *(_BYTE *)(*((_DWORD *)v18 - 3) + 24) = 1;
            }
          }
          ++v16;
          v18 += 5;
        }
        while ( v16 < *v1 );
        v16 = v20;
      }
      result = *v1;
      v17 += 5;
      v20 = ++v16;
    }
    while ( v16 - 1 < *v1 );
    v2 = v22;
  }
  if ( v2 )
    return sub_587BCF(v2);
  return result;
}
