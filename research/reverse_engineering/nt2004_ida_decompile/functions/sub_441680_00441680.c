_DWORD *__thiscall sub_441680(_DWORD *this)
{
  int v2; // eax
  int v3; // ebp
  _DWORD *result; // eax
  int v5; // ecx
  int v6; // [esp+14h] [ebp-1Ch]
  _DWORD v7[6]; // [esp+18h] [ebp-18h] BYREF

  v2 = this[1524];
  v3 = 0;
  memset(v7, 0, sizeof(v7));
  if ( v2 > 0 )
  {
    v6 = 0;
    do
    {
      qmemcpy((void *)(v6 + this[1525] + 100), v7, 0x18u);
      sub_57C010(v7);
      ++v3;
      v6 += 580;
    }
    while ( v3 < this[1524] );
  }
  result = this + 214;
  v5 = 4;
  do
  {
    *result = 0;
    result[1] = 0;
    result += 314;
    --v5;
  }
  while ( v5 );
  this[2156] = 0;
  this[2157] = 0;
  this[2158] = 0;
  this[2159] = 0;
  this[2160] = 0;
  this[2161] = 0;
  this[2162] = 0;
  this[2163] = 0;
  this[2164] = 0;
  this[2165] = 0;
  this[2166] = 0;
  this[2167] = 0;
  this[63] = 0;
  this[64] = 0;
  this[65] = 0;
  this[66] = 0;
  this[67] = 0;
  this[68] = 0;
  this[69] = 0;
  this[70] = 0;
  this[71] = 0;
  this[72] = 0;
  this[73] = 0;
  this[74] = 0;
  return result;
}
