int __thiscall sub_4AA520(_BYTE *this, int a2, int a3)
{
  char v4; // al
  int v5; // eax
  int v6; // eax

  v4 = this[64];
  if ( v4 )
  {
    if ( v4 != 1 )
      goto LABEL_8;
    v5 = sub_4CD450(7);
  }
  else
  {
    v5 = sub_4CD450(6);
  }
  if ( v5 )
  {
    v6 = *(_DWORD *)(v5 + 28);
    if ( v6 )
      sub_4D2F20(v6);
  }
LABEL_8:
  sub_4D8010(this, a2, a3);
  return sub_496BF0((int)this, (int)this, a2, a3);
}
