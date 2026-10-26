void *__thiscall sub_4E09E0(char *this)
{
  _DWORD *v2; // edi
  int v3; // ebp
  void *v4; // edx
  int v5; // edi
  int v6; // edx
  _DWORD *v7; // ecx
  _DWORD *v8; // eax
  int v9; // edx
  _DWORD *v10; // ebp
  _DWORD *v11; // edi
  int v12; // ebp
  _BYTE *v13; // ecx
  int v14; // ecx
  int v15; // edx
  void *result; // eax

  if ( dword_8AFE88 && *((_DWORD *)this + 1) )
  {
    sub_4E0DB0(this);
    sub_545150(*((_DWORD *)this + 1));
    sub_411570(dword_5EA560, *(_DWORD *)(*(_DWORD *)this + 18580), 0);
  }
  sub_4E38D0(this);
  sub_4E3050(this);
  sub_4DFA50(this + 4);
  *((_DWORD *)this + 18) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 21) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 24) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 27) = 0;
  *((_DWORD *)this + 28) = 0;
  *((_DWORD *)this + 29) = 0;
  *((_DWORD *)this + 30) = 0;
  *((_DWORD *)this + 31) = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 0;
  *((_DWORD *)this + 34) = 0;
  *((_DWORD *)this + 35) = 0;
  sub_566650(byte_5EA438);
  v2 = this + 212;
  v3 = 4;
  do
  {
    sub_4DFB60(v2);
    v2 += 74;
    --v3;
  }
  while ( v3 );
  sub_4DFA50(this + 1508);
  sub_4DFA50(this + 1576);
  v4 = this + 1644;
  v5 = 8;
  do
  {
    sub_4DFA50(v4);
    v4 = (void *)(v6 + 68);
    --v5;
  }
  while ( v5 );
  *((_DWORD *)this + 547) = 0;
  *((_DWORD *)this + 548) = 0;
  *((_DWORD *)this + 549) = 0;
  *((_DWORD *)this + 550) = 0;
  *((_DWORD *)this + 551) = 0;
  *((_DWORD *)this + 552) = 0;
  *((_DWORD *)this + 553) = 0;
  *((_DWORD *)this + 554) = 0;
  *((_DWORD *)this + 555) = 0;
  *((_DWORD *)this + 556) = 0;
  *((_DWORD *)this + 557) = 0;
  *((_DWORD *)this + 560) = 0;
  v7 = this + 2244;
  v8 = this + 2232;
  v9 = 2;
  do
  {
    *v8 = 0;
    v10 = v7;
    *v7 = 0;
    v7[1] = 0;
    v7[2] = 0;
    ++v8;
    v7 += 4;
    --v9;
    v10[3] = 0;
  }
  while ( v9 );
  *((_DWORD *)this + 569) = 0;
  *((_DWORD *)this + 573) = 0;
  *((_DWORD *)this + 574) = 0;
  *((_DWORD *)this + 575) = 0;
  *((_DWORD *)this + 576) = 0;
  *((_DWORD *)this + 577) = 0;
  *((_DWORD *)this + 578) = 0;
  *((_DWORD *)this + 579) = 0;
  *((_DWORD *)this + 580) = 0;
  *((_DWORD *)this + 581) = 0;
  *((_DWORD *)this + 589) = 0;
  *((_DWORD *)this + 590) = 0;
  *((_DWORD *)this + 591) = 0;
  *((_DWORD *)this + 592) = 0;
  *((_DWORD *)this + 593) = 0;
  *((_WORD *)this + 1188) = 0;
  *((_DWORD *)this + 595) = 0;
  *((_DWORD *)this + 596) = 0;
  *((_DWORD *)this + 597) = 0;
  *((_DWORD *)this + 601) = 0;
  *((_DWORD *)this + 602) = 0;
  this[2412] = 0;
  this[2413] = 0;
  *((_DWORD *)this + 604) = 0;
  this[2420] = 0;
  this[2421] = 0;
  this[2422] = 0;
  this[2423] = 0;
  this[2424] = 0;
  this[2425] = 0;
  *((_DWORD *)this + 607) = 0;
  *((_DWORD *)this + 609) = -8388609;
  *((_DWORD *)this + 608) = -1;
  *((_DWORD *)this + 610) = 1065353216;
  *((_DWORD *)this + 731) = 0;
  memset(this + 2928, 0, 0x38u);
  *((_DWORD *)this + 746) = 0;
  v11 = this + 2988;
  v12 = 11;
  do
  {
    sub_4DED20(v11);
    v11 += 187;
    --v12;
  }
  while ( v12 );
  this[2444] = 0;
  v13 = this + 2448;
  do
  {
    sub_4DFB90(v13);
    v13 = (_BYTE *)(v14 + 28);
  }
  while ( v15 != 1 );
  result = (void *)*((_DWORD *)this + 2805);
  *((_DWORD *)this + 2804) = 0;
  if ( result )
  {
    result = (void *)sub_587BCF(result);
    *((_DWORD *)this + 2805) = 0;
  }
  return result;
}
