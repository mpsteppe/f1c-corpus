// Address: 0x0057e860
// Size: 112 bytes
// Name: sub_57E860
// Type: int __stdcall(int)
// Source: IDA Hex-Rays decompilation

int __stdcall sub_57E860(int a1)
{
  _WORD v2[2]; // [esp+8h] [ebp-10h] BYREF
  u_long v3; // [esp+Ch] [ebp-Ch]

  v2[0] = 2;
  v3 = htonl(0);
  v2[1] = htons(0);
  sub_57B9F0(v2);
  if ( (unsigned __int8)sub_586CA0(a1) )
    return sub_57D8D0(a1, v2);
  else
    return sub_57D6C0(a1, v2);
}
