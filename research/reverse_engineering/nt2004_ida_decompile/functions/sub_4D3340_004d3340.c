int __stdcall sub_4D3340(int a1)
{
  int Buffer; // [esp+4h] [ebp-D0h] BYREF

  sub_57A3D0(&Buffer, 4u);
  if ( (Buffer & 0xF0000000) != 0x10000000 || (Buffer & 0x3F0000) != 0 )
    return sub_57A5F0((unsigned __int16)Buffer >> 6);
  else
    return sub_57A5F0(((unsigned __int16)Buffer >> 6) + 1);
}
