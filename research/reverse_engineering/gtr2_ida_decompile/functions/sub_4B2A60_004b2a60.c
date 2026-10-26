int __thiscall sub_4B2A60(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax
  int v6; // eax

  v3 = this[217];
  v4 = v3;
  if ( a2 )
  {
    if ( a2 != 1 )
      goto LABEL_6;
    v5 = v3 + 1;
  }
  else
  {
    v5 = v3 - 1;
  }
  this[217] = v5;
LABEL_6:
  v6 = this[217];
  if ( v6 >= 0 )
  {
    if ( v6 >= this[221] )
      this[217] = 0;
  }
  else
  {
    this[217] = this[221] - 1;
  }
  sub_47F6E0(this + 218, this[217]);
  if ( v4 != this[217] )
    sub_4DED90();
  sub_4A0870(this);
  return sub_5400D0(a2);
}
