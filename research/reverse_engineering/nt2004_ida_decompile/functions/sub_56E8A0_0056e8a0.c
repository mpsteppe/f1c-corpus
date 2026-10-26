char __thiscall sub_56E8A0(_DWORD *this, unsigned int a2)
{
  _DWORD v4[4]; // [esp+8h] [ebp-10h] BYREF

  LOWORD(v4[0]) = 2;
  v4[1] = htonl(0);
  HIWORD(v4[0]) = htons(0);
  sub_56B5E0(this + 673, v4);
  if ( (unsigned __int8)sub_576D30(a2) )
    return sub_56D580(this, a2, v4);
  else
    return sub_56D370(this, a2, v4);
}
