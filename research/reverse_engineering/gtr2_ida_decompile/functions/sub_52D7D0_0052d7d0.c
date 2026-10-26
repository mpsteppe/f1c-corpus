int __thiscall sub_52D7D0(_DWORD *this)
{
  int v2; // eax
  void *v3; // eax
  void *v4; // eax
  void *v5; // eax
  int v6; // ecx
  int result; // eax
  size_t v8; // [esp-Ch] [ebp-14h]
  size_t v9; // [esp-8h] [ebp-10h]

  sub_52B980();
  this[15] = 0;
  this[16] = -1;
  this[21] = -1;
  this[17] = -1;
  this[22] = -1;
  this[18] = -1;
  this[23] = -1;
  this[19] = -1;
  this[24] = -1;
  this[20] = -1;
  this[25] = -1;
  this[27] = 0;
  if ( *(_DWORD *)dword_B640C8 == 6 )
  {
    this[2] = 3;
    this[4] = 2;
    this[39] = 0;
  }
  else
  {
    this[2] = 5;
    this[4] = 0;
    this[39] = 1;
  }
  if ( *(_DWORD *)dword_B72314 == 7 )
    this[39] = 0;
  v2 = dword_FADE18;
  if ( dword_FADE18 >= 333 )
    v2 = 333;
  this[51] = v2;
  v3 = operator new(4 * v2);
  v9 = 4 * this[51];
  this[52] = v3;
  v4 = operator new(v9);
  v8 = this[51];
  this[53] = v4;
  v5 = operator new(v8);
  v6 = this[51];
  this[54] = v5;
  result = 0;
  this[55] = 0;
  if ( v6 > 0 )
  {
    do
    {
      *(_DWORD *)(this[52] + 4 * result) = -1082130432;
      *(_DWORD *)(this[53] + 4 * result) = -1082130432;
      *(_BYTE *)(result + this[54]) = 0;
      ++result;
    }
    while ( result < this[51] );
  }
  if ( *(_DWORD *)dword_B640C8 == 6 && *(_DWORD *)dword_B72314 == 4 )
    this[3] = this[26];
  else
    this[3] = 0;
  return result;
}
