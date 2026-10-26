char __thiscall sub_57E860(_DWORD *this, unsigned int a2)
{
  _DWORD v4[4]; // [esp+8h] [ebp-10h] BYREF

  LOWORD(v4[0]) = 2;
  v4[1] = htonl(0);
  HIWORD(v4[0]) = htons(0);
  Copy4DwordsStructToStruct(this + 673, v4);
  if ( (unsigned __int8)sub_586CA0(a2) )
    return NetworkPacketSendWithQueryMatching(this, a2, v4);
  else
    return sub_57D6C0(this, a2, v4);
}
