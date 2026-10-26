// f1c  0x0043e360  size=325
_DWORD *__thiscall sub_43E360(_DWORD *this)
{
  int v2; // eax
  int v3; // ebp
  _DWORD *result; // eax
  int v5; // ecx
  int v6; // [esp+14h] [ebp-1Ch]
  _DWORD v7[6]; // [esp+18h] [ebp-18h] BYREF

  v2 = this[1387];
  v3 = 0;
  memset(v7, 0, sizeof(v7));
  if ( v2 > 0 )
  {
    v6 = 0;
    do
    {
      qmemcpy((void *)(v6 + this[1388] + 100), v7, 0x18u);
      sub_569280(v7);
      ++v3;
      v6 += 580;
    }
    while ( v3 < this[1387] );
  }
  result = this + 210;
  v5 = 4;
  do
  {
    *result = 0;
    result[1] = 0;
    result += 281;
    --v5;
  }
  while ( v5 );
  this[1985] = 0;
  this[1986] = 0;
  this[1987] = 0;
  this[1988] = 0;
  this[1989] = 0;
  this[1990] = 0;
  this[1991] = 0;
  this[1992] = 0;
  this[1993] = 0;
  this[1994] = 0;
  this[1995] = 0;
  this[1996] = 0;
  this[59] = 0;
  this[60] = 0;
  this[61] = 0;
  this[62] = 0;
  this[63] = 0;
  this[64] = 0;
  this[65] = 0;
  this[66] = 0;
  this[67] = 0;
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  return result;
}
