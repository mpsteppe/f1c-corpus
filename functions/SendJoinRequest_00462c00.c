char __thiscall sub_462C00(void *this, int a2, int a3)
{
  int v4; // esi
  int v5; // eax
  const char *v6; // eax
  int v8; // [esp-8h] [ebp-60h]
  _BYTE v9[77]; // [esp+8h] [ebp-50h] BYREF
  __int16 v10; // [esp+55h] [ebp-3h]
  char v11; // [esp+57h] [ebp-1h]

  v4 = IndexBoundsCheckedArrayRead(*(_DWORD *)(*(_DWORD *)this + 112540), a2);
  if ( !v4 )
    return 0;
  v9[0] = byte_5EA438[0];
  memset(&v9[1], 0, 0x4Cu);
  v10 = 0;
  v11 = 0;
  v5 = StringComparisonWithConstantDispatch(0);
  v6 = (const char *)IPAddressToString(v4, v5);
  StringFormatWithBufferOverflowCheck(v9, "%s:%d", v6, v8);
  if ( dword_7C569C != 5 )
  {
    if ( (unsigned __int8)StringSplitLoop(1, aDDevF119992002_1, 6657) )
      DebugLogWrite(&dword_8AD25C, aSendingJoinReq);
  }
  *(_DWORD *)(*(_DWORD *)this + 888) = 0;
  return CollisionSpatialQuery(v9, a3);
}
