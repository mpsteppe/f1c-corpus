void __stdcall sub_56FC30(_DWORD *a1, float a2, int a3)
{
  int v3; // esi
  int i; // ecx
  int v5; // edx
  int *v6; // eax
  int v7; // eax
  int j; // esi
  int v9; // eax
  int v10; // ecx
  int *v11; // eax
  int v12; // eax

  v3 = a1[136];
  for ( i = 0; i < v3; ++i )
  {
    v5 = i;
    if ( i >= 0 && i < a1[136] )
    {
      v6 = (int *)a1[133];
      if ( i <= 0 )
      {
LABEL_7:
        if ( v6 )
        {
          v7 = *v6;
          goto LABEL_10;
        }
      }
      else
      {
        while ( v6 )
        {
          v6 = (int *)v6[1];
          if ( --v5 <= 0 )
            goto LABEL_7;
        }
      }
    }
    v7 = 0;
LABEL_10:
    *(float *)(v7 + 240) = a2 * *(float *)(v7 + 240);
    *(float *)(v7 + 244) = a2 * *(float *)(v7 + 244);
  }
  if ( (_BYTE)a3 )
  {
    for ( j = 0; ; ++j )
    {
      v9 = a1[160];
      if ( j >= v9 )
        break;
      v10 = j;
      if ( j < 0 || j >= v9 )
        break;
      v11 = (int *)a1[157];
      if ( j > 0 )
      {
        while ( v11 )
        {
          v11 = (int *)v11[1];
          if ( --v10 <= 0 )
            goto LABEL_19;
        }
        return;
      }
LABEL_19:
      if ( !v11 )
        return;
      v12 = *v11;
      if ( !v12 )
        return;
      sub_56FC30(v12, a2, a3);
    }
  }
}
