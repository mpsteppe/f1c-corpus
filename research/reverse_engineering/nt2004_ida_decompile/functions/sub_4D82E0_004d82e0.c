void __thiscall sub_4D82E0(int this, float a2)
{
  char v3; // al
  double v4; // st7
  float v5; // [esp+0h] [ebp-8h]

  *(_DWORD *)(this + 2080) = *(_DWORD *)(this + 2076);
  v3 = *(_BYTE *)(this + 2149);
  *(float *)(this + 2076) = a2;
  if ( v3 )
  {
    if ( a2 <= (double)*(float *)(this + 2064) )
    {
      if ( a2 < (double)*(float *)(this + 2060) )
        *(_DWORD *)(this + 2076) = *(_DWORD *)(this + 2060);
    }
    else
    {
      *(_DWORD *)(this + 2076) = *(_DWORD *)(this + 2064);
    }
  }
  else
  {
    while ( *(float *)(this + 2076) <= (double)*(float *)(this + 2064) )
    {
      if ( *(float *)(this + 2076) >= (double)*(float *)(this + 2060) )
        return;
      v4 = *(float *)(this + 2064) - *(float *)(this + 2060);
      *(_DWORD *)(this + 2080) = *(_DWORD *)(this + 2076);
      *(float *)(this + 2076) = v4 + *(float *)(this + 2076);
    }
    v5 = *(float *)(this + 2076) - (*(float *)(this + 2064) - *(float *)(this + 2060));
    sub_4D82E0(LODWORD(v5));
    ++*(_DWORD *)(this + 2160);
  }
}
