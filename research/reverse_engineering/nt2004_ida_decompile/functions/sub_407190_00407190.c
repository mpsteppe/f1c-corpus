int __thiscall sub_407190(_DWORD *this)
{
  _DWORD *v2; // esi
  int v3; // edi

  if ( this[3] )
    sub_4074F0(this);
  v2 = this + 7;
  v3 = 3;
  do
  {
    sub_578600(&byte_629120);
    *(v2 - 1) = -1;
    *v2 = -1;
    *((_BYTE *)v2 + 4) = 0;
    v2 += 5;
    --v3;
  }
  while ( v3 );
  return sub_4074A0(0);
}
