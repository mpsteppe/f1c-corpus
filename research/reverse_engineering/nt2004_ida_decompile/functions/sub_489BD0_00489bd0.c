int __thiscall sub_489BD0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  char *v5; // eax

  v2 = sub_4ED610(&dword_7D6B74);
  v3 = this[218];
  v4 = v2 - 1;
  if ( v3 >= 0 )
  {
    if ( v3 > v4 )
      this[218] = v4;
  }
  else
  {
    this[218] = 0;
  }
  v5 = (char *)sub_4ED620(this[218]);
  return sub_4ED7B0(v5);
}
