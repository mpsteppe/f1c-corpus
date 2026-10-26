int __stdcall sub_45E800(const void *a1, int a2)
{
  void *v3; // edi
  _BYTE v4[580]; // [esp+Ch] [ebp-244h] BYREF

  if ( a2 == 18 )
    return 1;
  if ( a2 == 19 )
  {
    qmemcpy(v4, a1, sizeof(v4));
    dword_B698E4 = 19;
    qmemcpy(&unk_B69674, v4, 0x244u);
    return 1;
  }
  if ( a2 != 20 )
    return 0;
  if ( dword_B6A3F0 )
  {
    if ( dword_B6A3F0 == 1 )
    {
      qmemcpy(v4, a1, sizeof(v4));
      dword_B6AAEC = 20;
      v3 = &unk_B6A87C;
    }
    else
    {
      if ( dword_B6A3F0 != 2 )
        return 1;
      qmemcpy(v4, a1, sizeof(v4));
      dword_B6AEF0 = 20;
      v3 = &unk_B6AC80;
    }
  }
  else
  {
    qmemcpy(v4, a1, sizeof(v4));
    dword_B6A6E8 = 20;
    v3 = &unk_B6A478;
  }
  qmemcpy(v3, v4, 0x244u);
  ++dword_B6A3F0;
  return 1;
}
