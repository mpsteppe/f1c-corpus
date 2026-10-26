char __thiscall sub_4C0190(_DWORD *this, int a2)
{
  int v3; // eax
  int v4; // ecx
  int v5; // edi
  int v6; // esi
  bool v7; // zf
  char v8; // al
  int v9; // ecx
  int v10; // eax
  int v11; // ecx
  int v12; // eax
  int v13; // eax
  int v14; // edx
  __int64 v15; // rax
  int v16; // ecx
  __int64 v17; // rax
  int v18; // ecx
  int v19; // edi
  int v20; // ecx
  char result; // al
  char v22[28]; // [esp+1Ch] [ebp-25Ch] BYREF
  char String1[64]; // [esp+38h] [ebp-240h] BYREF
  char Destination[512]; // [esp+78h] [ebp-200h] BYREF

  if ( *((_BYTE *)this + 788) && !*(_DWORD *)dword_76BB84 && (unsigned __int8)sub_4EED40(*this) && byte_7697A8 )
  {
    sub_57A080(v22);
    sub_4C0670(Destination, 512);
    if ( (unsigned __int8)sub_57A110(Destination, 4, 0, 1) )
    {
      sub_4C0700(v22);
      sub_57A360(v22);
    }
    sub_57A0A0(v22);
  }
  qmemcpy(this + 19, (const void *)(a2 + 3248), 0x40u);
  this[19] = 0;
  this[20] = 0;
  this[21] = 1431655765;
  this[22] = 1069897045;
  this[23] = 6;
  this[24] = 5;
  this[25] = 5;
  *((_BYTE *)this + 104) = 1;
  v3 = sub_500DC0((char *)(a2 + 112));
  v4 = this[196];
  this[195] = v3;
  if ( v4 >= 0 || dword_75CBB0 < 5 || dword_75CBB0 > 7 )
  {
    v5 = a2;
  }
  else
  {
    v5 = a2;
    v6 = *(_DWORD *)(a2 + 3012);
    if ( !*(_BYTE *)(sub_5009C0(v6) + 20) )
      this[196] = v6;
  }
  this[235] = -1082130432;
  this[40] = 3;
  this[39] = 4;
  sub_4C0AD0(0);
  sub_4C0B10(0);
  if ( sub_4E8E50(String1, 64, aTrackType, 0) || (v7 = _strcmpi(String1, aRoadCourse) == 0, v8 = 1, !v7) )
    v8 = 0;
  this[72] = *(_DWORD *)(v5 + 3012);
  if ( v8 )
    this[71] = *(_DWORD *)(this[195] + 16);
  else
    this[71] = 1;
  v9 = this[72];
  v10 = this[71] - 1;
  if ( v9 >= 0 )
  {
    if ( v9 > v10 )
      this[72] = v10;
  }
  else
  {
    this[72] = 0;
  }
  qmemcpy(this + 83, (const void *)(v5 + 240), 0x40u);
  this[89] = this[88];
  *((_BYTE *)this + 361) = 0;
  qmemcpy(this + 99, (const void *)(a2 + 944), 0x40u);
  this[105] = this[104];
  *((_BYTE *)this + 425) = 0;
  qmemcpy(this + 115, (const void *)(a2 + 1648), 0x40u);
  this[121] = this[120];
  *((_BYTE *)this + 489) = 0;
  qmemcpy(this + 131, (const void *)(a2 + 2352), 0x40u);
  this[137] = this[136];
  *((_BYTE *)this + 553) = 0;
  qmemcpy(this + 147, (const void *)(a2 + 3184), 0x40u);
  this[153] = this[152];
  *((_BYTE *)this + 617) = 0;
  qmemcpy(this + 163, (const void *)(a2 + 3888), 0x40u);
  this[169] = this[168];
  *((_BYTE *)this + 681) = 0;
  qmemcpy(this + 179, (const void *)(a2 + 4848), 0x40u);
  v11 = this[184];
  *((_BYTE *)this + 745) = 0;
  this[185] = v11;
  this[198] = *(_DWORD *)(a2 + 6276);
  *((float *)this + 205) = *(double *)(a2 + 6548);
  if ( *(double *)(a2 + 6548) == 0.0 )
  {
    v12 = *(_DWORD *)(a2 + 6340);
    this[199] = 100;
    this[200] = v12;
    v13 = *(_DWORD *)(a2 + 6404);
    this[201] = 200;
    this[202] = v13;
    v14 = *(_DWORD *)(a2 + 6468);
    this[203] = 300;
    this[204] = v14;
  }
  else
  {
    v15 = (__int64)(((double)*(int *)(a2 + 3268) * *(double *)(a2 + 3256) + *(double *)(a2 + 3248))
                  * *(double *)(a2 + 6548));
    v16 = *(_DWORD *)(a2 + 6340);
    this[199] = v15;
    this[200] = v16;
    v17 = (__int64)((double)(int)(__int64)((double)*(int *)(a2 + 6340) * *(double *)(a2 + 6328) + *(double *)(a2 + 6320))
                  * *(double *)(a2 + 6548)
                  + (double)(int)v15);
    v18 = *(_DWORD *)(a2 + 6404);
    this[201] = v17;
    this[202] = v18;
    v19 = *(_DWORD *)(a2 + 6468);
    this[203] = (__int64)((double)(int)(__int64)((double)*(int *)(a2 + 6404) * *(double *)(a2 + 6392)
                                               + *(double *)(a2 + 6384))
                        * *(double *)(a2 + 6548)
                        + (double)(int)v17);
    this[204] = v19;
  }
  v20 = *this;
  this[207] = 0;
  this[208] = 0;
  if ( (unsigned __int8)sub_4EED40(v20) )
  {
    sub_4C0A80(-1);
    sub_4BEC30(dword_766238);
  }
  result = *((_BYTE *)this + 788);
  this[236] = 0;
  this[237] = 0;
  if ( result )
  {
    if ( !*(_DWORD *)dword_76BB84 )
    {
      result = sub_4EED40(*this);
      if ( result )
      {
        result = byte_7697A8;
        if ( byte_7697A8 )
        {
          sub_57A080(v22);
          sub_4C0670(Destination, 512);
          if ( (unsigned __int8)sub_57A2F0(Destination, 0) )
          {
            sub_4C0740(v22);
            sub_57A360(v22);
          }
          result = sub_57A0A0(v22);
        }
      }
    }
  }
  *((_BYTE *)this + 788) = 1;
  return result;
}
