int __thiscall sub_4DE470(int this)
{
  int v1; // eax
  double v2; // st7
  int v3; // edx
  int v4; // eax
  int v5; // eax
  int v6; // ecx

  v1 = *(_DWORD *)(this + 96);
  v2 = *(float *)(this + 268) + *(float *)(this + 276);
  *(float *)(this + 276) = v2;
  if ( v1 )
  {
    if ( *(_DWORD *)(this + 128) )
    {
      v3 = 5;
    }
    else
    {
      v3 = 1;
      if ( v2 <= 0.55000001 )
        v3 = 2;
      *(_DWORD *)(this + 276) = 0;
    }
  }
  else
  {
    v3 = 4 - (*(_DWORD *)(this + 128) != 0);
  }
  v4 = *(_DWORD *)(this + 132);
  if ( *(_DWORD *)(this + 100) )
  {
    v3 = 2 * (v4 != 0) + 9;
  }
  else if ( v4 )
  {
    v3 = 10;
  }
  v5 = *(_DWORD *)(this + 136);
  if ( *(_DWORD *)(this + 104) )
  {
    v3 = 2 * (v5 != 0) + 6;
  }
  else if ( v5 )
  {
    v3 = 7;
  }
  v6 = *(_DWORD *)(this + 108);
  if ( v6 )
    return (v6 <= 0) + 12;
  else
    return v3;
}
