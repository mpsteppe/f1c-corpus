char *__thiscall sub_4FCC30(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  const char *v4; // eax
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  int v7; // ecx
  int v8; // eax
  double v9; // st7
  int v10; // edx
  double v11; // st7
  char *result; // eax
  int v13; // [esp+10h] [ebp-11Ch]
  _BYTE v14[24]; // [esp+14h] [ebp-118h] BYREF
  _BYTE v15[256]; // [esp+2Ch] [ebp-100h] BYREF

  ((void (*)(void))DualLinkedListDestruction)();
  this[7] = 0;
  if ( (dword_7C56A0 & 1) == 0 || dword_8AB6E4 == 2 )
  {
    result = (char *)DisplayModeSetter(0x20000);
    this[5] = 0;
    return result;
  }
  if ( byte_7CF17C )
    *(float *)this = flt_8ACF9C;
  else
    *this = 1065353216;
  if ( dword_7CF080 )
  {
    if ( dword_7CF080 != 1 || !SeasonRacesSectionFinder(0) || (v2 = StringKeyedLinkedListSearch(aWeather_1)) == 0 )
    {
LABEL_15:
      switch ( dword_7CF080 )
      {
        case 3:
          v13 = 1059481190;
          break;
        case 4:
          v13 = 1062333317;
          break;
        case 5:
          v13 = 1064346583;
          break;
        default:
          v13 = 1050253722;
          break;
      }
      DualLinkedListDestruction(this);
      v5 = (_DWORD *)OperatorNewNhMallocWrapper(16);
      if ( v5 )
        v6 = FloatArrayInitializer(v5);
      else
        v6 = 0;
      this[15] = v6;
      *v6 = 0;
      *(_DWORD *)(this[15] + 4) = 1101004800;
      *(_DWORD *)(this[15] + 8) = v13;
      *(_DWORD *)(this[15] + 12) = 0;
      sub_4FDE00(*(float *)(this[15] + 8));
      v7 = this[15];
      v8 = this[9];
      this[10] = v8;
      this[11] = v8;
      v9 = *(float *)(v7 + 4);
      *((float *)this + 12) = *(float *)(v7 + 4);
      *((float *)this + 13) = v9;
      goto LABEL_26;
    }
    v3 = sub_4FE350(v2);
  }
  else
  {
    v4 = dword_5EC438;
    if ( !dword_5EC438 )
      v4 = byte_5EA438;
    StringFormatWithBufferOverflowCheck(v15, "%sweather.txt", v4);
    v3 = sub_4FE7C0(v15);
  }
  if ( v3 )
    goto LABEL_15;
LABEL_26:
  qmemcpy(v14, this + 8, sizeof(v14));
  AudioEventRingBufferProcessing(this);
  v10 = this[15];
  qmemcpy(this + 8, v14, 0x18u);
  this[2] = this[8];
  this[14] = v10;
  *((_BYTE *)this + 64) = 1;
  this[17] = -8388609;
  this[1] = 0;
  *((_WORD *)this + 36) = 0;
  *((_WORD *)this + 37) = -1;
  *((_WORD *)this + 38) = -1;
  *((_WORD *)this + 39) = 0;
  *((_WORD *)this + 40) = 0x7FFF;
  *((_WORD *)this + 41) = 0x8000;
  DisplayModeSetter(0x20000);
  this[5] = *((float *)this + 11) > 0.0;
  v11 = flt_8AB274[(unsigned __int8)dword_8AAE70++] * 0.050000001;
  *((float *)this + 65) = v11;
  result = (char *)RangeInterpolationTable(this);
  if ( (dword_7C56A0 & 1) != 0 && dword_8AB6E4 != 2 )
  {
    result = (char *)strcmp((const char *)this + 452, byte_8ACFA3);
    if ( result )
    {
      sub_587DD0(this + 113, byte_8ACFA3, 11);
      *((_BYTE *)this + 463) = 0;
      return sub_4FC550((int)(this + 66), 1);
    }
  }
  return result;
}

