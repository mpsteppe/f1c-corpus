int __thiscall sub_4EB570(_DWORD *this)
{
  _DWORD *v1; // ebx
  int result; // eax
  int v3; // edi
  int i; // esi
  int v5; // edx
  int *v6; // ecx
  int v7; // ecx
  int v8; // ecx
  int v9; // edi
  int j; // esi
  int v11; // edx
  int *v12; // ecx
  int v13; // ecx
  int v14; // ecx
  int v15; // edi
  int k; // esi
  int v17; // edx
  int *v18; // ecx
  int v19; // ecx
  int v20; // ecx

  v1 = (_DWORD *)this[24];
  result = 0;
  if ( v1 )
  {
    v3 = v1[16];
    for ( i = 0; i < v3; ++i )
    {
      v5 = i;
      if ( i >= 0 && i < v1[16] )
      {
        v6 = (int *)v1[13];
        if ( i <= 0 )
        {
LABEL_8:
          if ( v6 )
          {
            v7 = *v6;
            goto LABEL_11;
          }
        }
        else
        {
          while ( v6 )
          {
            v6 = (int *)v6[1];
            if ( --v5 <= 0 )
              goto LABEL_8;
          }
        }
      }
      v7 = 0;
LABEL_11:
      v8 = *(__int16 *)(v7 + 24);
      if ( v8 > result )
        result = v8;
    }
    v9 = v1[20];
    for ( j = 0; j < v9; ++j )
    {
      v11 = j;
      if ( j >= 0 && j < v1[20] )
      {
        v12 = (int *)v1[17];
        if ( j <= 0 )
        {
LABEL_20:
          if ( v12 )
          {
            v13 = *v12;
            goto LABEL_23;
          }
        }
        else
        {
          while ( v12 )
          {
            v12 = (int *)v12[1];
            if ( --v11 <= 0 )
              goto LABEL_20;
          }
        }
      }
      v13 = 0;
LABEL_23:
      v14 = *(__int16 *)(v13 + 24);
      if ( v14 > result )
        result = v14;
    }
    v15 = v1[24];
    for ( k = 0; k < v15; ++k )
    {
      v17 = k;
      if ( k >= 0 && k < v1[24] )
      {
        v18 = (int *)v1[21];
        if ( k <= 0 )
        {
LABEL_32:
          if ( v18 )
          {
            v19 = *v18;
            goto LABEL_35;
          }
        }
        else
        {
          while ( v18 )
          {
            v18 = (int *)v18[1];
            if ( --v17 <= 0 )
              goto LABEL_32;
          }
        }
      }
      v19 = 0;
LABEL_35:
      v20 = *(__int16 *)(v19 + 40);
      if ( v20 > result )
        result = v20;
    }
  }
  return result;
}
