int __thiscall sub_4BBF70(_DWORD *this)
{
  int v1; // eax
  int v2; // eax
  int v3; // edx
  _DWORD *v4; // eax
  int v5; // eax
  _DWORD *v6; // ecx

  v1 = this[15];
  if ( v1 > 0 )
  {
    v2 = v1 - 1;
    v3 = 0;
    this[15] = v2;
    if ( v2 > 0 )
    {
      v4 = this + 16;
      do
      {
        *v4 = v4[2];
        v4[1] = v4[3];
        ++v3;
        v4 += 2;
      }
      while ( v3 < this[15] );
    }
  }
  v5 = this[15];
  v6 = (_DWORD *)(*this + 13004);
  if ( v5 <= 0 )
    return ArithmeticComparison_5660(v6, 0);
  else
    return ArithmeticComparison_5660(v6, 1);
}

