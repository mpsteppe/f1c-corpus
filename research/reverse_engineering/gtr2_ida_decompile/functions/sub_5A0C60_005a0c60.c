char __thiscall sub_5A0C60(_DWORD *this, int a2)
{
  int v3; // edx
  int v4; // ecx
  int v5; // edx
  _DWORD v7[4]; // [esp+8h] [ebp-10h] BYREF

  htonl(0);
  htons(0);
  v3 = this[681];
  v7[0] = this[680];
  v4 = this[682];
  v7[1] = v3;
  v5 = this[683];
  v7[2] = v4;
  v7[3] = v5;
  if ( (unsigned __int8)sub_5A6BF0(a2) )
    return sub_59D860();
  else
    return sub_5A0970(this, a2, (int)v7);
}
