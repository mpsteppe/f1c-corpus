void __thiscall sub_4210D0(int this)
{
  int v1; // eax
  int v2; // eax
  int v3; // edx
  int v4; // ecx
  int v5; // eax

  if ( *(float *)(this + 17340) <= 0.0 )
  {
    v3 = *(_DWORD *)(this + 17320);
    if ( *(_DWORD *)(this + 20768) == 6 )
    {
      if ( v3 != -1 )
        sub_573480(-1);
    }
    else if ( *(_DWORD *)(this + 18428) == 2 )
    {
      sub_573480(0);
    }
    else if ( !v3 || v3 == -1 )
    {
      v5 = *(_DWORD *)(this + 17320);
      if ( v5 < *(_DWORD *)(this + 17328) )
        sub_573480(v5 + 1);
    }
    else if ( *(float *)(this + 17228) <= (double)*(float *)(this + 17348) )
    {
      if ( v3 > 1
        && *(float *)(this + 17228) < (double)*(float *)(this + 4 * v3 + 17352)
        && *(float *)(this + 16748) > 0.80000001
        && *(float *)(this + 17000) > 0.80000001 )
      {
        v2 = *(_DWORD *)(this + 17320);
        if ( v2 > 0 )
          sub_573480(v2 - 1);
      }
    }
    else if ( *(float *)(this + 16748) > 0.80000001 && *(float *)(this + 17000) > 0.80000001 )
    {
      v4 = this + 16;
      v1 = *(_DWORD *)(v4 + 17304);
      if ( v1 < *(_DWORD *)(v4 + 17312) )
        sub_573480(v1 + 1);
    }
  }
}
