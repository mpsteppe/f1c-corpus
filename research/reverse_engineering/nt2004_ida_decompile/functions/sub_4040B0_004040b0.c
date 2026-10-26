int __thiscall sub_4040B0(_DWORD *this, float *a2, _DWORD *a3, int a4, float a5, _DWORD *a6)
{
  _DWORD *v6; // ebx
  int v7; // esi
  char i; // cl
  int v9; // eax
  int v10; // edx
  double v11; // st7
  double v12; // st6
  double v13; // st5
  double v14; // st6
  double v15; // st5
  double v16; // st3
  double j; // st7
  double v18; // st6
  double v19; // st5
  double v20; // st3
  int v21; // edx
  double v22; // st6
  double v23; // st5
  double v24; // st3
  double v25; // st7
  double v26; // st6
  double v27; // st5
  double v28; // st3
  float v31; // [esp+24h] [ebp+10h]
  float v32; // [esp+24h] [ebp+10h]

  v6 = a3;
  v7 = (int)a3;
  if ( a3 )
  {
    for ( i = LOBYTE(a5); ; i = 0 )
    {
      if ( v6[82] != a4 )
      {
        v9 = v6[75];
        if ( v9 )
        {
          if ( *(_DWORD *)(v9 + 328) == a4 )
            v7 = v6[75];
        }
      }
      v10 = *(_DWORD *)(v7 + 292);
      v11 = *a2 - *(float *)(v7 + 196);
      v12 = a2[1] - *(float *)(v7 + 200);
      v13 = a2[2] - *(float *)(v7 + 204);
      v31 = v13 * v13 + v12 * v12 + v11 * v11;
      if ( v10 )
      {
        v14 = a2[1] - *(float *)(v10 + 200);
        v15 = a2[2] - *(float *)(v10 + 204);
        v16 = *a2 - *(float *)(v10 + 196);
        for ( j = v15 * v15 + v14 * v14 + v16 * v16; j < v31; j = v19 * v19 + v18 * v18 + v20 * v20 )
        {
          if ( a4 != *(_DWORD *)(v10 + 328) )
            break;
          v7 = v10;
          v31 = j;
          v10 = *(_DWORD *)(v10 + 292);
          if ( !v10 )
            return sub_403FD0(this, a2, a4);
          v18 = a2[1] - *(float *)(v10 + 200);
          v19 = a2[2] - *(float *)(v10 + 204);
          v20 = *a2 - *(float *)(v10 + 196);
        }
      }
      v21 = v6[74];
      if ( v21 )
      {
        v22 = a2[1] - *(float *)(v21 + 200);
        v23 = a2[2] - *(float *)(v21 + 204);
        v24 = *a2 - *(float *)(v21 + 196);
        v25 = v23 * v23 + v22 * v22 + v24 * v24;
        if ( v25 < v31 )
        {
          do
          {
            v7 = v21;
            v32 = v25;
            v21 = *(_DWORD *)(v21 + 296);
            if ( !v21 )
              return sub_403FD0(this, a2, a4);
            v26 = a2[1] - *(float *)(v21 + 200);
            v27 = a2[2] - *(float *)(v21 + 204);
            v28 = *a2 - *(float *)(v21 + 196);
            v25 = v27 * v27 + v26 * v26 + v28 * v28;
          }
          while ( v25 < v32 );
        }
      }
      if ( i )
      {
        if ( !v7 )
          goto LABEL_22;
        if ( *(float *)(v7 + 220) * (*(float *)(v7 + 204) - a2[2]) + *(float *)(v7 + 212) * (*(float *)(v7 + 196) - *a2) < 0.0 )
          v7 = *(_DWORD *)(v7 + 296);
      }
      if ( v7 && a4 == *(_DWORD *)(v7 + 328) )
        return v7;
LABEL_22:
      v6 = a6;
      if ( !a6 )
        return sub_403FD0(this, a2, a4);
      a6 = 0;
      v7 = (int)v6;
    }
  }
  return sub_403FD0(this, a2, a4);
}
