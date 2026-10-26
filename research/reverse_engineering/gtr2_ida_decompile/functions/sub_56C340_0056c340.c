int __fastcall sub_56C340(int a1, float *a2, float *a3)
{
  int v3; // ebx
  int v5; // eax
  int v6; // edx
  int result; // eax
  int v8; // ecx
  float **v9; // eax
  float *v10; // edi
  float v11; // eax
  int v12; // eax
  int v13; // ebx
  int i; // esi
  float *v15; // ecx
  double v16; // st7
  double v17; // st7
  double v18; // st6
  float v19; // ecx
  int v20; // [esp+10h] [ebp-30h]
  int v22; // [esp+18h] [ebp-28h]
  int v23; // [esp+1Ch] [ebp-24h]
  double v24; // [esp+20h] [ebp-20h]
  double v25; // [esp+28h] [ebp-18h]
  double v26; // [esp+30h] [ebp-10h]
  double v27; // [esp+38h] [ebp-8h]

  v3 = a1;
  v5 = sub_56C000();
  v6 = 0;
  v24 = 0.0;
  v22 = v5;
  *a3 = 0.0;
  a3[1] = 0.0;
  a3[2] = 0.0;
  result = *(_DWORD *)(v3 + 544);
  v25 = *a2;
  v27 = a2[1];
  v23 = result;
  v20 = 0;
  v26 = a2[2];
  if ( result > 0 )
  {
    do
    {
      v8 = v6;
      if ( v6 >= 0 && v6 < *(_DWORD *)(v3 + 544) )
      {
        v9 = *(float ***)(v3 + 532);
        if ( v6 <= 0 )
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
      if ( v12 >= v22 )
      {
        v13 = sub_5EA5B0(v10);
        for ( i = 0; i < v13; ++i )
        {
          v15 = (float *)sub_5EB140(i, 1);
          v16 = *v15 * v25 + v15[2] * v26 + v15[1] * v27;
          if ( v16 > v24 )
          {
            v24 = v16;
            v17 = v15[2];
            v18 = v15[1];
            v19 = *v15;
            a3[1] = v18;
            *a3 = v19;
            a3[2] = v17;
          }
        }
        v3 = a1;
        v6 = v20;
      }
      result = v23;
      v20 = ++v6;
    }
    while ( v6 < v23 );
  }
  return result;
}
