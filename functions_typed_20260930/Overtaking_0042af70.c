int __thiscall sub_42AF70(float *this, float *a2, int a3)
{
  int v4; // ebp
  double v6; // st7
  float v7; // ecx
  int v8; // edx
  float v9; // eax
  int v10; // edi

  v4 = 0;
  if ( (unsigned __int8)ReplayAIStateCheck(this + 3) )
    return 0;
  if ( a2[4401] >= (double)this[4419] )
    v6 = a2[4401];
  else
    v6 = this[4419];
  this[4419] = v6;
  if ( dword_7C56A4 != 7 )
  {
    if ( dword_7C56A4 == 5 )
    {
      if ( ServerSessionGateCheck(this) || !ServerSessionGateCheck(a2) )
        return v4;
    }
    else if ( a2[4135] >= (double)this[4135] )
    {
      return v4;
    }
    goto LABEL_26;
  }
  v7 = *a2;
  v8 = *((_DWORD *)this + 4111);
  if ( *(_DWORD *)(*(_DWORD *)a2 + 16444) > v8 )
  {
LABEL_26:
    v10 = a3;
LABEL_27:
    v4 = v10;
    goto LABEL_28;
  }
  if ( *((float **)this + 4478) != a2 )
    return v4;
  v9 = *this;
  v10 = a3;
  if ( *(_DWORD *)(*(_DWORD *)this + 18600) > *(_DWORD *)(LODWORD(v7) + 18600) && v8 > 3 )
    v4 = a3;
  if ( (*(_DWORD *)(LODWORD(v9) + 3284) && !*(_BYTE *)(LODWORD(v9) + 3348)
     || *(_DWORD *)(LODWORD(v9) + 3352) && !*(_BYTE *)(LODWORD(v9) + 3416))
    && (!*(_DWORD *)(LODWORD(v7) + 3284) || *(_BYTE *)(LODWORD(v7) + 3348))
    && *(_DWORD *)(LODWORD(v7) + 3352)
    && !*(_BYTE *)(LODWORD(v7) + 3416) )
  {
    goto LABEL_27;
  }
LABEL_28:
  if ( v4 && *((_DWORD *)this + 3931) != 2 && this[3681] > 0.001 )
  {
    *((_DWORD *)this + 4479) = a2;
    if ( v10 == 2 )
    {
      this[4360] = 3.0;
      return v4;
    }
    this[4360] = -3.0;
  }
  return v4;
}

