_DWORD *__thiscall sub_4057F0(_DWORD *this, int a2, int a3, int a4, int a5)
{
  _DWORD *v6; // ecx
  char *v7; // eax

  v6 = this + 1;
  *v6 = 0;
  v6[1] = -1;
  *this = &off_59E490;
  v7 = *(char **)a2;
  if ( !*(_DWORD *)a2 )
    v7 = &byte_5EA438;
  StringCopyWithBufferRealloc(v7);
  this[3] = *(_DWORD *)(a2 + 8);
  this[4] = *(_DWORD *)(a2 + 12);
  this[6] = a4;
  this[19] = 0;
  this[22] = 0;
  this[23] = 0;
  this[25] = 0;
  this[26] = 0;
  this[5] = a3;
  this[7] = 1008981770;
  this[8] = 1064933786;
  this[9] = 1056964608;
  this[17] = 1194083328;
  this[21] = a5;
  this[24] = -1;
  return this;
}

