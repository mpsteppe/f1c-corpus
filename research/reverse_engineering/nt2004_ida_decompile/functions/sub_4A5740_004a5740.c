int __thiscall sub_4A5740(_DWORD *this, int a2)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax

  v2 = this[76];
  if ( v2 )
  {
    if ( v2 != 1 )
      goto LABEL_10;
    v3 = this[75];
    if ( !v3 )
    {
      this[102] += this[96] + this[100];
      goto LABEL_10;
    }
    if ( v3 != 1 )
      goto LABEL_10;
    v4 = this[97] + this[101];
  }
  else
  {
    v4 = a2;
    if ( a2 < 0 )
      v4 = this[106];
  }
  this[102] += v4;
LABEL_10:
  v5 = this[103];
  if ( this[102] > v5 )
    this[102] = v5;
  return ((int (*)(void))loc_4A5420)();
}
