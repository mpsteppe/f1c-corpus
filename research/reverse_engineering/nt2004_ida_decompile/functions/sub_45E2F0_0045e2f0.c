char __thiscall sub_45E2F0(_DWORD *this)
{
  int v2; // eax
  int v3; // eax
  char v4; // di
  BOOL v6; // [esp-24h] [ebp-2Ch]

  sub_45E840();
  v6 = byte_769968 != 0;
  v2 = sub_45E390();
  v3 = sub_5BA8B0(
         this[1],
         off_5FFAB8,
         v2,
         v6,
         0,
         sub_45E3D0,
         sub_45E6F0,
         nullsub_3,
         byte_45E750,
         sub_45E7E0,
         sub_45E7F0,
         0);
  v4 = v3;
  if ( v3 )
  {
    if ( dword_75CBA8 != 5 )
    {
      if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 1, (int)aDDevNascar2004_6, 2365) )
        sub_500FE0((int)&unk_7D7920, aCouldnTInitGam, v4);
    }
    *(_BYTE *)this = 0;
    return *(_BYTE *)this;
  }
  else
  {
    *(_BYTE *)this = 1;
    return *(_BYTE *)this;
  }
}
