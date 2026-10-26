int __thiscall sub_555230(int this)
{
  int v2; // ebp
  int i; // eax
  int j; // eax
  _DWORD *v5; // eax
  int v6; // ecx

  sub_415860((_DWORD *)this);
  *(_DWORD *)(this + 184) = 0;
  *(_DWORD *)(this + 188) = -1;
  *(_DWORD *)(this + 192) = 0;
  *(_DWORD *)(this + 196) = -1;
  *(_DWORD *)(this + 200) = 0;
  *(_DWORD *)(this + 204) = -1;
  *(_DWORD *)(this + 292) = 0;
  *(_DWORD *)(this + 296) = 0;
  *(_DWORD *)(this + 304) = 0;
  *(_DWORD *)(this + 308) = 0;
  *(_DWORD *)(this + 316) = 0;
  *(_DWORD *)(this + 320) = 0;
  *(_DWORD *)(this + 336) = sub_408610();
  *(_DWORD *)(this + 340) = 0;
  v2 = this + 480;
  sub_54B780();
  *(_DWORD *)(this + 176) = 0;
  *(_DWORD *)(this + 180) = 0;
  *(_DWORD *)(this + 3008) = 0;
  *(_DWORD *)(this + 3012) = 0;
  *(_DWORD *)(this + 216) = 0x7FFFFFFF;
  *(_DWORD *)(this + 220) = 0;
  *(_DWORD *)(this + 224) = 0;
  *(_DWORD *)(this + 228) = 1172373504;
  *(_DWORD *)(this + 232) = 1065353216;
  *(_BYTE *)(this + 252) = 0;
  *(_DWORD *)(this + 272) = 0;
  *(_DWORD *)(this + 276) = 0;
  *(_BYTE *)(this + 254) = 0;
  *(_DWORD *)(this + 268) = 0;
  *(_BYTE *)(this + 280) = 0;
  *(_DWORD *)(this + 344) = 0;
  *(_DWORD *)(this + 348) = 0;
  *(_DWORD *)(this + 352) = 5;
  *(_DWORD *)(this + 356) = 0;
  *(_DWORD *)(this + 360) = 0;
  *(_DWORD *)(this + 364) = 0;
  memset((void *)(this + 368), 0xFFu, 0x68u);
  *(_WORD *)(this + 472) = -1;
  *(_BYTE *)(this + 474) = -1;
  *(_BYTE *)(this + 480) = 0;
  for ( i = 0; i < 104; ++i )
  {
    *(_DWORD *)(v2 + 8 * i + 4) = -2;
    *(_DWORD *)(v2 + 8 * i + 8) = -1082130432;
  }
  *(_DWORD *)(this + 1316) = 0;
  for ( j = 0; j < 104; ++j )
  {
    *(_DWORD *)(v2 + 8 * j + 840) = -2;
    *(_DWORD *)(v2 + 8 * j + 844) = -1082130432;
  }
  *(_DWORD *)(this + 2152) = 0;
  *(_DWORD *)(this + 2156) = 0;
  *(_DWORD *)(this + 2264) = 0;
  memset((void *)(this + 2160), 0xFFu, 0x68u);
  *(_DWORD *)(this + 2276) = 0;
  *(_DWORD *)(this + 2280) = 0;
  *(_DWORD *)(this + 2284) = 0;
  *(_DWORD *)(this + 2288) = 0;
  *(_DWORD *)(this + 2292) = 0;
  *(_DWORD *)(this + 2296) = 0;
  *(_DWORD *)(this + 2300) = 0;
  *(_DWORD *)(this + 2304) = 0;
  *(_DWORD *)(this + 2308) = 0;
  *(_DWORD *)(this + 2312) = 0;
  *(_DWORD *)(this + 2316) = 0;
  *(_DWORD *)(this + 2320) = 0;
  *(_DWORD *)(this + 2324) = 0;
  *(_DWORD *)(this + 2328) = 0;
  *(_DWORD *)(this + 2332) = 0;
  *(_DWORD *)(this + 2336) = 0;
  *(_DWORD *)(this + 2340) = 0;
  *(_DWORD *)(this + 2344) = 0;
  *(_DWORD *)(this + 2348) = 0;
  *(_DWORD *)(this + 2352) = 0;
  *(_DWORD *)(this + 2356) = 0;
  *(_DWORD *)(this + 2360) = 0;
  *(_DWORD *)(this + 2364) = 0;
  *(_DWORD *)(this + 2368) = 0;
  *(_DWORD *)(this + 2372) = 0;
  *(_DWORD *)(this + 2376) = 0;
  v5 = (_DWORD *)(this + 2588);
  v6 = 52;
  do
  {
    *(v5 - 52) = 0;
    *v5 = 0;
    v5[52] = 0;
    ++v5;
    --v6;
  }
  while ( v6 );
  return this;
}
