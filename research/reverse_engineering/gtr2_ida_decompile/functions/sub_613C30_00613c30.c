char __thiscall sub_613C30(int this)
{
  int v2; // ecx
  char result; // al
  bool v4; // zf
  _BYTE *v5; // ecx
  int v6; // eax

  v2 = *(_DWORD *)(this + 20);
  result = 0;
  if ( v2 )
  {
    v4 = v2 == 5;
    v5 = *(_BYTE **)(this + 4);
    if ( v4 )
    {
      if ( v5 )
      {
        *v5 = 0;
        result = 1;
        *(_DWORD *)(this + 4) = 0;
      }
    }
    else if ( v5 )
    {
      v6 = sub_62AAB0(v5);
      *(_DWORD *)(this + 4) = 0;
      return v6 == 0;
    }
  }
  else if ( *(_DWORD *)(this + 4) )
  {
    fclose(*(FILE **)(this + 4));
    return off_16C9654();
  }
  return result;
}
