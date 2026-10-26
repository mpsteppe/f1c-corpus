int __thiscall sub_489B20(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax

  v3 = sub_4ED610(&dword_7D6B74);
  v4 = this[218];
  if ( a2 )
  {
    if ( v4 == v3 - 1 )
      v5 = 0;
    else
      v5 = v4 + 1;
  }
  else if ( v4 )
  {
    v5 = v4 - 1;
  }
  else
  {
    v5 = v3 - 1;
  }
  if ( v4 == v5 )
    return 0;
  this[218] = v5;
  return 1;
}
