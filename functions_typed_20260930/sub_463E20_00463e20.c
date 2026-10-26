int __thiscall sub_463E20(void *this)
{
  _DWORD v3[2]; // [esp+4h] [ebp-30h] BYREF
  __int16 v4; // [esp+Ch] [ebp-28h]
  HINSTANCE v5; // [esp+10h] [ebp-24h]
  _BYTE v6[32]; // [esp+14h] [ebp-20h] BYREF

  AudioStreamStructInitWithDefaults(v3);
  v3[1] = *(_DWORD *)this + 16316;
  v3[0] = 0;
  v5 = hinst;
  v4 = word_7D1004;
  StringFormatWithBufferOverflowCheck(v6, "%s %.3f", aF1Challenge990, 1.026000022888184);
  if ( (unsigned __int8)StackBufferCopyPredicateCall(v3, *(_DWORD *)this + 16312) )
  {
    *(_DWORD *)(*(_DWORD *)this + 464) = 1;
    *(_DWORD *)(*(_DWORD *)this + 16320) = *(_DWORD *)this;
    *(_DWORD *)(*(_DWORD *)this + 16764) = VTableQueryWithStackBufferResult(*(_DWORD *)(*(_DWORD *)this + 16312));
  }
  else
  {
    *(_DWORD *)(*(_DWORD *)this + 464) = 0;
  }
  return NetworkReplayBufferInit((_DWORD *)(*(_DWORD *)this + 112528));
}

