int __thiscall sub_467E40(_DWORD *this)
{
  const char *v2; // eax
  _BYTE *v3; // eax
  _DWORD *v4; // eax
  _DWORD *v5; // esi
  int v6; // eax
  _BYTE v8[28]; // [esp+8h] [ebp-13Ch] BYREF
  _BYTE v9[32]; // [esp+24h] [ebp-120h] BYREF
  _BYTE v10[256]; // [esp+44h] [ebp-100h] BYREF

  v9[0] = byte_5EA438[0];
  memset(&v9[1], 0, 29);
  ZeroInitSmallStruct(v8);
  v2 = (const char *)dword_5EC408;
  v10[0] = 0;
  if ( !dword_5EC408 )
    v2 = byte_5EA438;
  StringFormatWithBufferOverflowCheck(v9, "%s%s", v2, aCreditsTxt);
  if ( (unsigned __int8)AudioStreamOpen(v9, 1) && ConditionalDispatchBasedOnFlag(v10, 256) )
  {
    do
    {
      v3 = (_BYTE *)sub_587C20(v10, asc_5C30B0);
      if ( v3 )
        *v3 = 0;
      v4 = (_DWORD *)OperatorNewNhMallocWrapper(8);
      v5 = v4;
      if ( v4 )
      {
        *v4 = 0;
        v4[1] = -1;
        StringCopyWithBufferRealloc(v10);
        v6 = OperatorNewNhMallocWrapper(12);
        if ( v6 )
        {
          *(_DWORD *)v6 = v5;
          *(_DWORD *)(v6 + 4) = 0;
          *(_BYTE *)(v6 + 8) = 1;
        }
        else
        {
          v6 = 0;
        }
        if ( this[62] )
        {
          *(_DWORD *)(this[63] + 4) = v6;
        }
        else
        {
          this[62] = v6;
          this[64] = v6;
        }
        this[63] = v6;
        ++this[65];
      }
    }
    while ( ConditionalDispatchBasedOnFlag(v10, 256) );
  }
  return SubCallWithConditionalFieldFree(v8);
}

