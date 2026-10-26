char __thiscall sub_42C150(int this, int a2, int a3, float a4)
{
  double v7; // st7
  unsigned int v8; // ecx
  double v9; // st7
  int v10; // eax
  double v11; // st7
  int v12; // eax
  int v13; // ecx
  double v14; // st7
  double v15; // st7
  double v16; // st6
  float v17; // [esp+Ch] [ebp+4h]
  float v18; // [esp+Ch] [ebp+4h]
  float v19; // [esp+14h] [ebp+Ch]

  if ( *(float *)(this + 24728) > (double)*(float *)(this + 23852) || a2 == 18 )
    return 0;
  if ( !*(_DWORD *)(*(_DWORD *)(this + 80) + 25300) )
  {
    if ( *(int *)(this + 23820) > 4 )
      return 0;
    *(_BYTE *)(this + 23712) = 0;
    if ( a2 < 15 )
    {
      v17 = sub_42B090(this, a2, 0);
      if ( sub_42B090(this, *(_DWORD *)(this + 24020), 0) <= v17 )
      {
        v18 = sub_42B090(this, a2, 0);
        if ( sub_42B090(this, *(_DWORD *)(this + 24020), 0) >= v18 && a2 > 6 )
          goto LABEL_16;
        if ( !*(_DWORD *)(this + 23804) && !LOBYTE(a4) )
          return 0;
      }
      else if ( !*(_DWORD *)(this + 23800) && !LOBYTE(a4) )
      {
        return 0;
      }
    }
  }
  if ( a2 == 6 )
  {
    v7 = sub_528B50(0);
    goto LABEL_18;
  }
LABEL_16:
  if ( a2 != 9 )
    goto LABEL_20;
  v7 = sub_528B50(1);
LABEL_18:
  if ( v7 < 400.0 )
    return 0;
LABEL_20:
  v19 = sub_529A00(2) - 3.5;
  if ( sub_529A00(0) - 1.0 > v19 && a2 == 10 && sub_528B50(0) < 400.0 )
    return 0;
  v8 = *(_DWORD *)(this + 24020);
  if ( v8 != a2 )
  {
    if ( *(float *)(this + 24712) <= 0.5 )
    {
      if ( *(float *)(this + 24712) > 0.0 )
      {
        v11 = sub_42B090(this, v8, 0);
        v12 = *(_DWORD *)(this + 24196);
        v8 = 14;
        *(float *)(this + 24188) = *(float *)(this + 23716) - v11;
        if ( v12 != 14 )
          *(_DWORD *)(this + 24196) = *(_DWORD *)(this + 24020);
      }
    }
    else
    {
      v9 = sub_42B090(this, *(_DWORD *)(this + 24708), 0);
      v10 = *(_DWORD *)(this + 24708);
      v8 = 14;
      *(float *)(this + 24188) = *(float *)(this + 23716) - v9;
      if ( v10 != 14 )
        *(_DWORD *)(this + 24196) = v10;
    }
    *(_DWORD *)(this + 24708) = v8;
    v13 = *(_DWORD *)(this + 80);
    *(_DWORD *)(this + 24020) = a2;
    if ( (unsigned __int8)sub_4EED40(v13) )
    {
      if ( *(_DWORD *)(*(_DWORD *)(this + 23432) + 328) == *(_DWORD *)(*(_DWORD *)(this
                                                                                 + 4 * *(_DWORD *)(this + 23828)
                                                                                 + 23432)
                                                                     + 328) )
      {
        v14 = *(float *)(this + 23728) - sub_42B090(this, *(_DWORD *)(this + 24708), 0);
LABEL_36:
        *(float *)(this + 24704) = v14;
      }
    }
    else if ( *(_DWORD *)(*(_DWORD *)(this + 23432) + 328) == *(_DWORD *)(*(_DWORD *)(this
                                                                                    + 4 * *(_DWORD *)(this + 23828)
                                                                                    + 23432)
                                                                        + 328) )
    {
      v14 = *(float *)(this + 23620) - sub_42B090(this, *(_DWORD *)(this + 24708), 0);
      goto LABEL_36;
    }
    v15 = *(float *)(this + 23852) + 10.5;
    *(_DWORD *)(this + 24712) = 1065353216;
    v16 = *(float *)(this + 23964);
    *(_DWORD *)(this + 24716) = 0;
    *(_DWORD *)(this + 24700) = a3;
    *(_DWORD *)(this + 36) = 1120403456;
    *(_DWORD *)(this + 23704) = 0;
    *(float *)(this + 24696) = v15 - v16 * 6.5;
  }
  return 1;
}
