// f1c  0x00490b00  size=135
_DWORD *__thiscall sub_490B00(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  _DWORD *v4; // edx
  _DWORD *v5; // eax
  int v6; // ecx

  this[3] = 0;
  this[4] = 0;
  this[5] = 0;
  this[6] = 0;
  this[7] = 0;
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  this[12] = 0;
  this[13] = 0;
  this[14] = 0;
  sub_4912F0(this + 15);
  *this = a2;
  this[1] = 0;
  v3 = (_DWORD *)sub_587C03(16 * a2 + 4);
  if ( v3 )
  {
    v4 = v3 + 1;
    *v3 = a2;
    v5 = v3 + 1;
    if ( a2 - 1 >= 0 )
    {
      v6 = a2;
      do
      {
        *v5 = 0;
        v5[1] = 0;
        v5[2] = 0;
        v5[3] = 0;
        v5 += 4;
        --v6;
      }
      while ( v6 );
    }
    this[2] = v4;
    return this;
  }
  else
  {
    this[2] = 0;
    return this;
  }
}
