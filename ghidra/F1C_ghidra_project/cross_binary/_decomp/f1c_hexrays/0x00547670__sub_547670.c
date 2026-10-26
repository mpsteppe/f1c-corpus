// f1c  0x00547670  size=150
int __thiscall sub_547670(_DWORD *this, _DWORD *a2)
{
  int v2; // edx
  int v3; // eax
  _DWORD *v4; // edx
  int i; // edx
  int v6; // edx
  int v7; // eax
  int result; // eax

  v2 = this[9];
  v3 = 0;
  if ( v2 )
  {
    v3 = this[9];
    for ( i = *(_DWORD *)(v2 + 192); i; i = *(_DWORD *)(i + 192) )
      v3 = i;
    v4 = a2;
    *(_DWORD *)(v3 + 192) = a2;
  }
  else
  {
    v4 = a2;
    this[9] = a2;
  }
  v4[47] = v3;
  v4[48] = 0;
  v6 = v4[39];
  v7 = this[4];
  if ( (v6 & 0x20) != 0 )
  {
    result = v7 + 1;
    if ( (v6 & 0x100) != 0 )
      ++this[7];
    else
      ++this[8];
    this[4] = result;
  }
  else
  {
    result = v7 + 1;
    if ( (v6 & 0x100) != 0 )
      ++this[5];
    else
      ++this[6];
    this[4] = result;
  }
  return result;
}
