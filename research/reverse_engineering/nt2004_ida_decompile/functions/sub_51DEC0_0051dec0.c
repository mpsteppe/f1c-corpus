void __thiscall sub_51DEC0(int this, float a2)
{
  int v3; // ebx
  int v4; // ebp
  int v5; // esi
  int v6; // edx
  int i; // eax
  int j; // eax
  int v9; // esi
  int m; // esi
  double v11; // st6
  double v12; // st5
  double v13; // st3
  long double v14; // st7
  int v15; // eax
  int v16; // [esp+0h] [ebp-3Ch]
  float k; // [esp+Ch] [ebp-30h]
  int v18[11]; // [esp+10h] [ebp-2Ch]
  int v19; // [esp+40h] [ebp+4h]
  float v20; // [esp+40h] [ebp+4h]
  float v21; // [esp+40h] [ebp+4h]

  if ( LOBYTE(a2) )
  {
    v3 = 0;
    v4 = 0;
    v5 = this + 17924;
    v19 = 4;
    do
    {
      if ( *(_DWORD *)v5 )
      {
        v6 = *(_DWORD *)(*(_DWORD *)v5 + 84);
        for ( i = 0; i < v3; ++i )
        {
          if ( v18[i + 5] == *(_DWORD *)(v6 + 48) )
            break;
        }
        if ( i == v3 )
          v18[v3++ + 5] = *(_DWORD *)(v6 + 48);
        for ( j = 0; j < v4; ++j )
        {
          if ( v18[j] == *(_DWORD *)(v6 + 44) )
            break;
        }
        if ( j == v4 )
          v18[v4++] = *(_DWORD *)(v6 + 44);
      }
      v5 += 248;
      --v19;
    }
    while ( v19 );
    v9 = 0;
    for ( k = sqrt(
                *(float *)(this + 17544) * *(float *)(this + 17544)
              + *(float *)(this + 17548) * *(float *)(this + 17548)
              + *(float *)(this + 17552) * *(float *)(this + 17552)); v9 < v3; ++v9 )
      sub_51DAE0(this, v18[v9 + 5]);
    for ( m = 0; m < v4; ++m )
      sub_51DD00((char *)this, v18[m], k);
    v11 = *(float *)(this + 18936) - *(float *)(this + 17548);
    v12 = *(float *)(this + 18940) - *(float *)(this + 17552);
    v13 = *(float *)(this + 18932) - *(float *)(this + 17544);
    v14 = (sqrt(v12 * v12 + v11 * v11 + v13 * v13) - 2.0) * 0.010204081;
    v20 = v14;
    if ( v14 > 0.0 )
    {
      if ( v20 <= 1.0 )
        v21 = v20 * v20;
      else
        v21 = 1.0;
      *(float *)&v16 = k * 0.00390625 + 0.89999998;
      sub_526050(5, 1, v21, v16);
    }
  }
  if ( *(float *)(this + 2008) <= 0.0 )
  {
    *(_BYTE *)(this + 1608) = 0;
    *(_BYTE *)(this + 228) = 1;
  }
  else
  {
    sub_526050(43, 2, *(float *)(this + 2008), 1065353216);
  }
  v15 = *(_DWORD *)(this + 16500);
  if ( !v15 )
  {
    if ( dbl_7608E4 <= dbl_7608FC )
      return;
    goto LABEL_32;
  }
  if ( v15 == 1 && *(float *)(this + 18772) > (double)*(float *)(this + 18784) )
LABEL_32:
    sub_526050(39, 2, 1.0, 1065353216);
}
