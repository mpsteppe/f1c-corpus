int __fastcall sub_56C0A0(int a1, float *a2, float *a3)
{
  int v3; // edi
  int result; // eax
  int v7; // edx
  int v8; // ecx
  float **v9; // eax
  float *v10; // ebp
  float v11; // eax
  int v12; // eax
  int v13; // edi
  float *v14; // ecx
  int v16; // [esp+10h] [ebp-Ch]
  int v17; // [esp+14h] [ebp-8h]
  int v18; // [esp+18h] [ebp-4h]
  int v19; // [esp+20h] [ebp+4h]

  v3 = a1;
  v16 = sub_56C000();
  *a2 = 3.4028235e38;
  a2[1] = 3.4028235e38;
  a2[2] = 3.4028235e38;
  *a3 = -3.4028235e38;
  a3[1] = -3.4028235e38;
  a3[2] = -3.4028235e38;
  result = *(_DWORD *)(v3 + 544);
  v7 = 0;
  v18 = result;
  v19 = 0;
  while ( v7 < v18 )
  {
    v8 = v7;
    if ( v7 >= 0 && v7 < *(_DWORD *)(v3 + 544) )
    {
      v9 = *(float ***)(v3 + 532);
      if ( v7 <= 0 )
      {
LABEL_7:
        if ( v9 )
        {
          v10 = *v9;
          goto LABEL_10;
        }
      }
      else
      {
        while ( v9 )
        {
          v9 = (float **)v9[1];
          if ( --v8 <= 0 )
            goto LABEL_7;
        }
      }
    }
    v10 = 0;
LABEL_10:
    if ( v10[60] == 0.0 )
    {
      v11 = *v10;
      if ( (*(_DWORD *)v10 & 0x200) != 0 )
        v12 = 2 - ((LODWORD(v11) & 0x100000) != 0);
      else
        v12 = 4 - ((LODWORD(v11) & 0x100000) != 0);
    }
    else
    {
      v12 = 0;
    }
    if ( v12 >= v16 )
    {
      v13 = 0;
      v17 = sub_5EA5B0(v10);
      if ( v17 > 0 )
      {
        do
        {
          v14 = (float *)sub_5EB140(v13, 1);
          if ( *v14 < (double)*a2 )
            *a2 = *v14;
          if ( v14[1] < (double)a2[1] )
            a2[1] = v14[1];
          if ( v14[2] < (double)a2[2] )
            a2[2] = v14[2];
          if ( *v14 > (double)*a3 )
            *a3 = *v14;
          if ( v14[1] > (double)a3[1] )
            a3[1] = v14[1];
          if ( v14[2] > (double)a3[2] )
            a3[2] = v14[2];
          ++v13;
        }
        while ( v13 < v17 );
      }
      v3 = a1;
      v7 = v19;
    }
    result = v18;
    v19 = ++v7;
  }
  return result;
}
