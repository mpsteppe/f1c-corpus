char __thiscall sub_4979F0(_DWORD *this, const char *a2)
{
  const char *v2; // eax
  int v4; // esi
  int v5; // eax
  int v7; // [esp+Ch] [ebp-204h] BYREF
  _BYTE v8[512]; // [esp+10h] [ebp-200h] BYREF

  v2 = (const char *)dword_5EC408;
  v8[0] = 0;
  if ( !dword_5EC408 )
    v2 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v8, "%s%s", v2, a2);
  if ( ConditionalFieldClear((int)v8, &v7) )
    return 0;
  if ( OperatorNewNhMallocWrapper(12) )
    v4 = StructInitPathRegistry(a2, v7);
  else
    v4 = 0;
  if ( v4 )
  {
    v5 = OperatorNewNhMallocWrapper(12);
    if ( v5 )
    {
      *(_DWORD *)v5 = v4;
      *(_DWORD *)(v5 + 4) = 0;
      *(_BYTE *)(v5 + 8) = 1;
    }
    else
    {
      v5 = 0;
    }
    if ( this[60] )
    {
      *(_DWORD *)(this[61] + 4) = v5;
    }
    else
    {
      this[60] = v5;
      this[62] = v5;
    }
    this[61] = v5;
    ++this[63];
  }
  return 1;
}

