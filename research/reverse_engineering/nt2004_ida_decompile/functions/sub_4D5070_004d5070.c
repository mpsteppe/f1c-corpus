_DWORD *__thiscall sub_4D5070(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // ecx

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  sub_414400(this + 4);
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  sub_414400(this + 12);
  if ( operator new(4u) )
    v2 = sub_4DB0B0(1);
  else
    v2 = 0;
  sub_4DBA10(v2, 1);
  v3 = this + 16;
  v4 = 49;
  do
  {
    *v3 = 0;
    v3[1] = 0;
    v3[2] = 0;
    v3[3] = 0;
    v3 += 4;
    --v4;
  }
  while ( v4 );
  this[212] = 0;
  this[213] = 0;
  this[214] = 0;
  this[215] = 0;
  this[217] = 0;
  this[218] = 0;
  this[219] = 0;
  this[220] = 0;
  sub_57A080(this + 221);
  this[229] = 0;
  this[230] = -1;
  this[231] = 0;
  this[232] = -1;
  this[233] = 0;
  this[234] = 0;
  this[235] = 0;
  this[236] = 0;
  this[237] = 0;
  this[238] = -1;
  this[239] = 0;
  this[240] = -1;
  sub_52D820(this + 334);
  sub_57B5D0(this + 441);
  this[522] = 0;
  this[523] = 0;
  this[524] = 0;
  this[525] = 0;
  sub_414400(this + 526);
  this[530] = 0;
  this[531] = 0;
  this[532] = 0;
  this[533] = 0;
  this[534] = -51331646;
  this[543] = 0;
  this[544] = -1;
  *((_BYTE *)this + 864) = 0;
  this[228] = 0;
  this[327] = 4;
  this[328] = 2;
  this[329] = 2;
  this[330] = 0;
  this[331] = 0;
  this[332] = 0;
  this[333] = 0;
  this[440] = 0;
  sub_57B610(1);
  sub_57B690(this + 441);
  this[460] = -23693671;
  memset(this + 461, 0, 0xC4u);
  this[512] = 0;
  this[513] = 0;
  this[514] = 0;
  this[515] = 0;
  this[516] = 0;
  *((_BYTE *)this + 2068) = 0;
  this[518] = 0;
  *((_BYTE *)this + 2140) = 0;
  *((_BYTE *)this + 2141) = 1;
  *((_BYTE *)this + 2142) = 1;
  *((_BYTE *)this + 2149) = 0;
  this[540] = 0;
  this[541] = 5;
  this[542] = 1147207680;
  *((float *)this + 536) = 1.0 / 8.0;
  this[519] = 0;
  this[520] = 0;
  this[521] = -1;
  return this;
}
