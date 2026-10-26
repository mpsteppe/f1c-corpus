void __thiscall sub_5D1A30(_DWORD *this, double a2)
{
  int v2; // esi
  int v3; // edi
  long double v4; // st7
  bool v5; // c0
  bool v6; // c3
  long double v7; // [esp+10h] [ebp-18h]
  double v8; // [esp+20h] [ebp-8h]

  v2 = this[1];
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 44);
    v7 = *(float *)(*(_DWORD *)(v2 + 60) + 20);
    v8 = *(float *)(v2 + 24) * a2;
    v4 = v8 + *(double *)v2;
    if ( v7 == 0.0 )
      goto LABEL_14;
    v5 = v4 < v7;
    v6 = v4 == v7;
    if ( *(_DWORD *)(v2 + 48) == -1 )
    {
      if ( !v5 && !v6 )
      {
        v3 += (unsigned __int64)(v4 / v7);
        v4 = fmod(v4, v7);
      }
      if ( v4 >= 0.0 )
        goto LABEL_15;
      do
        v4 = v4 + v7;
      while ( v4 < 0.0 );
    }
    else if ( !v5 && !v6 )
    {
      v3 += (unsigned __int64)(v4 / v7);
      if ( v3 < *(_DWORD *)(v2 + 48) )
      {
        v4 = fmod(v4, v7);
      }
      else
      {
        v4 = *(float *)(*(_DWORD *)(v2 + 60) + 20);
        v3 = *(_DWORD *)(v2 + 48);
      }
    }
    if ( v4 < 0.0 )
LABEL_14:
      v4 = 0.0;
LABEL_15:
    *(long double *)v2 = v4;
    *(double *)(this[1] + 8) = v8;
    *(_DWORD *)(this[1] + 44) = v3;
  }
}
