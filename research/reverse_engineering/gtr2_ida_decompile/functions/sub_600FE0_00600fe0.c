_DWORD *__thiscall sub_600FE0(_DWORD *this)
{
  int v2; // eax
  int v3; // ecx
  _DWORD *v4; // eax

  sub_606840(this);
  *this = &off_72D6F8;
  this[2386] = 0;
  this[2387] = 0;
  memset(this + 2388, 0, 0x38u);
  *((_BYTE *)this + 124) = 1;
  memset((char *)this + 125, 0, 0x100u);
  strcpy((char *)this + 125, "CORESHADERS.MAS");
  memset((char *)this + 381, 0, 0x100u);
  _getcwd((char *)this + 381, 256);
  this[167] = 0x8000;
  this[177] = 0x8000;
  this[182] = 0x8000;
  this[187] = 0x8000;
  this[2411] = 0x7FFFFFFF;
  this[2412] = 0x7FFFFFFF;
  v2 = this[1475];
  this[172] = 0x2000;
  this[192] = 0;
  this[165] = 0;
  this[164] = 0;
  this[166] = 0;
  this[2413] = 0;
  this[2414] = 0;
  this[2402] = 0;
  this[2403] = 0;
  this[2404] = 0;
  this[2405] = 0;
  this[2410] = 0;
  *((_BYTE *)this + 4804) = 1;
  this[1202] = 3;
  this[1218] = 0;
  this[1209] = 0;
  this[1210] = 0;
  *((_BYTE *)this + 4844) = 1;
  *((_BYTE *)this + 4812) = 0;
  *((_BYTE *)this + 4813) = 0;
  *((_BYTE *)this + 4814) = 0;
  *((_BYTE *)this + 4815) = 0;
  this[2360] = 0x80000000;
  this[2361] = 512;
  this[2362] = 6;
  this[2363] = 0;
  this[2364] = 0;
  this[1206] = 1;
  this[1208] = 1;
  this[1214] = 0;
  this[1212] = -1;
  this[1476] = 0;
  if ( !v2 )
    this[1475] = sub_5F5CE0((__int32)this, 1);
  this[1213] = 0;
  this[2253] = 0;
  this[2254] = 0;
  this[2255] = 0;
  this[2256] = 0;
  this[2257] = 0;
  this[2258] = 0;
  this[2245] = 1;
  this[2246] = 0;
  this[2247] = 1065353216;
  this[2259] = 800;
  this[2260] = 600;
  this[2261] = 16000;
  this[2262] = 12000;
  this[27] = 8;
  this[28] = 1024;
  this[30] = 1032;
  this[2415] = 22;
  v3 = 0;
  v4 = this + 2271;
  do
  {
    *((_BYTE *)this + v3 + 9052) = 1;
    v4[6] = 0;
    *v4 = 0;
    *(v4 - 6) = 0;
    ++v3;
    ++v4;
  }
  while ( v3 < 6 );
  this[2283] = 0;
  this[2284] = 0;
  this[2376] = 0;
  return this;
}
