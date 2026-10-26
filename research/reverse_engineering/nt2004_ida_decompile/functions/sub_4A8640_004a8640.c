int __thiscall sub_4A8640(int this)
{
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  char String2[125]; // [esp+8h] [ebp-80h] BYREF
  __int16 v8; // [esp+85h] [ebp-3h]
  char v9; // [esp+87h] [ebp-1h]

  if ( *(_DWORD *)(this + 492) )
  {
    if ( *(_BYTE *)(this + 482) )
      sub_4AA510(aOptionsScreens);
    while ( sub_4A84A0((_DWORD *)this) )
    {
      String2[0] = byte_629120;
      memset(&String2[1], 0, 0x7Cu);
      v8 = 0;
      v9 = 0;
      if ( sub_577E50(byte_7656E8, aOptionsfont, (int)String2) )
      {
        sub_4A9700(String2);
      }
      else if ( sub_577E50(byte_7656E8, aAttributeset, (int)String2) )
      {
        sub_4A9940(String2);
      }
      else if ( sub_577E50(byte_7656E8, aLayer, (int)String2) )
      {
        sub_4A8870(String2);
      }
      else if ( sub_577E50(byte_7656E8, aGizmo, (int)String2) )
      {
        v3 = sub_4A8E80(String2);
        if ( v3 )
          sub_4AD3A0(v3, 0);
      }
      else if ( sub_577E50(byte_7656E8, aDopage, (int)String2) )
      {
        v4 = sub_4AD490(String2);
        sub_4AD5B0(v4, 1, 0);
      }
      else if ( sub_577E50(byte_7656E8, aLoadingscreenp, (int)String2) )
      {
        v5 = sub_4AD490(String2);
        if ( v5 )
          sub_4ADFA0(v5);
      }
      else if ( sub_577E50(byte_7656E8, aSystemfont, (int)String2) )
      {
        sub_4AE2C0(String2);
      }
      else if ( sub_577E50(byte_7656E8, aDisableGizmo, (int)String2) )
      {
        v6 = sub_4AD520(String2);
        if ( v6 )
          (*(void (__thiscall **)(int, int))(*(_DWORD *)v6 + 36))(v6, 1);
      }
    }
    return 0;
  }
  else
  {
    strcpy(String2, "Invalid Options Pointer in Options_OSC_Reader::ReadOptionsObject()");
    sub_4AA390(3, String2);
    return 0;
  }
}
