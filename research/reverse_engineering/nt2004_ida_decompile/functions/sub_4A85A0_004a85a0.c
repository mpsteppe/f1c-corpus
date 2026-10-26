int __thiscall sub_4A85A0(_DWORD *this)
{
  int v2; // edi
  char v4[256]; // [esp+8h] [ebp-100h] BYREF

  sub_57A5B0(0);
  v2 = 32;
  if ( sub_4A84A0(this) )
  {
    do
    {
      if ( sub_577E50(byte_7656E8, aSourceMas, (int)v4) && !(unsigned __int8)sub_4AD890(v4) )
      {
        sprintf(Buffer, "Could Not Load MAS file %s (line %d)", v4, this[117]);
        sub_4AA390(1, Buffer);
      }
      --v2;
    }
    while ( v2 >= 0 && sub_4A84A0(this) );
  }
  sub_57A5B0(0);
  return 0;
}
