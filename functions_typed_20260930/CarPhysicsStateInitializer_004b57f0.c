_DWORD *__thiscall sub_4B57F0(_DWORD *this)
{
  int v2; // eax
  _DWORD *v3; // eax
  int v4; // ecx
  _DWORD *result; // eax

  *this = 0;
  this[1] = 0;
  this[2] = 0;
  this[3] = 0;
  QuadZeroInit(this + 4);
  this[8] = 0;
  this[9] = 0;
  this[10] = 0;
  this[11] = 0;
  QuadZeroInit(this + 12);
  if ( OperatorNewNhMallocWrapper(4) )
    v2 = ConditionalArrayAlloc(1);
  else
    v2 = 0;
  ListAppendWithSubListGeneration(v2, 1);
  v3 = this + 16;
  v4 = 104;
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
  this[432] = 0;
  this[433] = 0;
  this[434] = 0;
  this[435] = 0;
  this[437] = 0;
  this[438] = 0;
  this[439] = 0;
  this[440] = 0;
  ZeroInitSmallStruct(this + 441);
  this[449] = 0;
  this[450] = -1;
  this[451] = 0;
  this[452] = -1;
  this[453] = 0;
  this[454] = 0;
  this[455] = 0;
  this[456] = 0;
  this[457] = 0;
  this[458] = -1;
  this[459] = 0;
  this[460] = -1;
  PassthroughWrapper_f670(this + 624);
  StructZeroInit_8ba0(this + 843);
  this[977] = 0;
  this[978] = 0;
  this[979] = 0;
  this[980] = 0;
  QuadZeroInit(this + 981);
  this[985] = 0;
  this[986] = 0;
  this[987] = 0;
  this[988] = 0;
  this[989] = -51331646;
  this[997] = 0;
  this[998] = -1;
  this[448] = 0;
  this[617] = 4;
  this[618] = 2;
  this[619] = 2;
  this[620] = 0;
  this[621] = 0;
  this[622] = 0;
  this[623] = 0;
  this[842] = 0;
  QPCTimerInitialization(1);
  TimerResetUsingQueryPerformanceCounter(this + 843);
  this[862] = -23693671;
  memset(this + 863, 0, 0x1A0u);
  this[969] = 0;
  this[970] = 0;
  this[971] = 0;
  this[972] = 0;
  this[973] = 0;
  *((_BYTE *)this + 3960) = 0;
  *((_BYTE *)this + 3961) = 1;
  *((_BYTE *)this + 3962) = 1;
  result = this;
  *((_BYTE *)this + 3969) = 0;
  this[995] = 5;
  this[996] = 1147207680;
  this[974] = 0;
  this[975] = 0;
  this[976] = -1;
  *((float *)this + 991) = 1.0 / 8.0;
  return result;
}

