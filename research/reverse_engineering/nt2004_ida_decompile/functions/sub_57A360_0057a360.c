bool __thiscall sub_57A360(int this)
{
  bool result; // al
  bool v3; // zf
  FILE *v4; // ecx
  int v5; // eax
  int v6; // eax

  result = 0;
  v3 = *(_DWORD *)(this + 16) == 0;
  v4 = *(FILE **)this;
  if ( v3 )
  {
    if ( v4 )
    {
      v5 = fclose(*(FILE **)this);
      *(_DWORD *)this = 0;
      return v5 == 0;
    }
  }
  else if ( v4 )
  {
    v6 = sub_536BE0((int)v4);
    *(_DWORD *)this = 0;
    return v6 == 0;
  }
  return result;
}
