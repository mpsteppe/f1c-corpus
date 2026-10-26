int __thiscall sub_613FE0(int this, int Offset)
{
  int v2; // eax
  int v4; // ecx
  int v5; // eax

  v2 = *(_DWORD *)(this + 20);
  if ( v2 )
  {
    v4 = *(_DWORD *)(this + 4);
    if ( v2 == 5 )
    {
      v5 = *(_DWORD *)(v4 + 20);
      if ( v5 >= Offset )
        v5 = Offset;
      *(_DWORD *)(v4 + 24) = v5;
      return 0;
    }
    else
    {
      return sub_62AFD0(v4, Offset, 0);
    }
  }
  else if ( fseek(*(FILE **)(this + 4), Offset, 0) )
  {
    return -1;
  }
  else
  {
    return Offset;
  }
}
