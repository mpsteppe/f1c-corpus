int __thiscall sub_614300(int this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int result; // eax
  int v8; // ecx

  sub_613EC0(this, "//[[gM");
  if ( *(_DWORD *)(this + 16) == 1 )
    sub_613EC0(this, "a");
  else
    sub_613EC0(this, "b");
  sub_613EC0(this, (char *)(this + 32));
  if ( *(_BYTE *)(this + 64) )
    sub_613EC0(this, "b");
  else
    sub_613EC0(this, "f");
  sub_613EC0(this, " (c)2004    ]] [[");
  v2 = *(_DWORD *)(this + 20);
  if ( v2 )
  {
    if ( v2 == 5 )
      sub_613900(*(_DWORD *)(this + 4), this + 72, 4);
    else
      sub_62A860(4);
  }
  else
  {
    sub_631E50(this + 72, 1, 4, *(_DWORD *)(this + 4));
  }
  v3 = *(_DWORD *)(this + 20);
  if ( v3 )
  {
    if ( v3 == 5 )
      sub_613900(*(_DWORD *)(this + 4), this + 68, 4);
    else
      sub_62A860(4);
  }
  else
  {
    sub_631E50(this + 68, 1, 4, *(_DWORD *)(this + 4));
  }
  v4 = *(_DWORD *)(this + 20);
  if ( v4 )
  {
    if ( v4 == 5 )
      sub_613900(*(_DWORD *)(this + 4), this + 80, 4);
    else
      sub_62A860(4);
  }
  else
  {
    sub_631E50(this + 80, 1, 4, *(_DWORD *)(this + 4));
  }
  v5 = *(_DWORD *)(this + 20);
  if ( v5 )
  {
    if ( v5 == 5 )
      sub_613900(*(_DWORD *)(this + 4), (int)"]]\n", 3);
    else
      sub_62A860(3);
  }
  else
  {
    sub_631E50("]]\n", 1, 3, *(_DWORD *)(this + 4));
  }
  v6 = *(_DWORD *)(this + 20);
  if ( v6 )
  {
    v8 = *(_DWORD *)(this + 4);
    if ( v6 == 5 )
      result = *(_DWORD *)(v8 + 24);
    else
      result = sub_62B120(v8);
    *(_DWORD *)(this + 84) = result;
  }
  else
  {
    result = sub_634320(*(_DWORD *)(this + 4));
    *(_DWORD *)(this + 84) = result;
  }
  return result;
}
