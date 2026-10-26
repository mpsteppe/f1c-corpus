void __thiscall sub_476FC0(_DWORD *this)
{
  _BYTE v1[4]; // [esp+4h] [ebp-214h] BYREF
  _BYTE v2[524]; // [esp+8h] [ebp-210h] BYREF
  char v3; // [esp+214h] [ebp-4h]

  if ( this[28332] != 1 )
  {
    sub_4733E0(v2);
    if ( !sub_59B5C0(v2, 528, v1) )
    {
      v3 |= 4u;
      if ( !sub_59B5A0(v2, 528) )
        sub_42CB90();
    }
  }
}
