unsigned int setSBUpLow()
{
  unsigned int i; // eax
  BYTE v1; // al
  BYTE *v2; // edx
  unsigned int v3; // ecx
  BYTE *v4; // edx
  unsigned int result; // eax
  __int16 v6; // cx
  char v7; // cl
  char v8; // cl
  _WORD v9[256]; // [esp+4h] [ebp-518h] BYREF
  _BYTE v10[256]; // [esp+204h] [ebp-318h] BYREF
  _BYTE v11[256]; // [esp+304h] [ebp-218h] BYREF
  _BYTE v12[256]; // [esp+404h] [ebp-118h] BYREF
  _cpinfo CPInfo; // [esp+504h] [ebp-18h] BYREF
  int v14; // [esp+518h] [ebp-4h]

  v14 = dword_912B08;
  if ( GetCPInfo(dword_FBB384, &CPInfo) )
  {
    for ( i = 0; i < 0x100; ++i )
      v12[i] = i;
    v1 = CPInfo.LeadByte[0];
    v12[0] = 32;
    if ( CPInfo.LeadByte[0] )
    {
      v2 = &CPInfo.LeadByte[1];
      do
      {
        v3 = *v2;
        if ( v1 <= v3 )
          memset(&v12[v1], 0x20u, v3 - v1 + 1);
        v4 = v2 + 1;
        v1 = *v4;
        v2 = v4 + 1;
      }
      while ( v1 );
    }
    __crtGetStringTypeA(1, v12, 256, v9, dword_FBB384, dword_FBB25C, 0);
    __crtLCMapStringA(dword_FBB25C, 256, v12, 256, v11, 256, dword_FBB384, 0);
    __crtLCMapStringA(dword_FBB25C, 512, v12, 256, v10, 256, dword_FBB384, 0);
    result = 0;
    while ( 1 )
    {
      v6 = v9[result];
      if ( (v6 & 1) != 0 )
      {
        byte_FBB281[result] |= 0x10u;
        v7 = v11[result];
      }
      else
      {
        if ( (v6 & 2) == 0 )
        {
          byte_FBB3A0[result] = 0;
          goto LABEL_16;
        }
        byte_FBB281[result] |= 0x20u;
        v7 = v10[result];
      }
      byte_FBB3A0[result] = v7;
LABEL_16:
      if ( ++result >= 0x100 )
        return result;
    }
  }
  for ( result = 0; result < 0x100; ++result )
  {
    if ( result >= 0x41 && result <= 0x5A )
    {
      byte_FBB281[result] |= 0x10u;
      v8 = result + 32;
LABEL_22:
      byte_FBB3A0[result] = v8;
      continue;
    }
    if ( result >= 0x61 && result <= 0x7A )
    {
      byte_FBB281[result] |= 0x20u;
      v8 = result - 32;
      goto LABEL_22;
    }
    byte_FBB3A0[result] = 0;
  }
  return result;
}
