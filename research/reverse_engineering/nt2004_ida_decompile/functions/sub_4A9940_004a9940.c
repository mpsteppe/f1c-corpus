int __thiscall sub_4A9940(_DWORD *this, char *String1)
{
  int v3; // edi
  char *v4; // eax
  char *v5; // eax
  char *v6; // eax
  char *v7; // eax
  int v9; // [esp+Ch] [ebp-98h] BYREF
  int v10; // [esp+10h] [ebp-94h] BYREF
  int v11; // [esp+14h] [ebp-90h] BYREF
  int v12; // [esp+18h] [ebp-8Ch] BYREF
  int v13; // [esp+1Ch] [ebp-88h] BYREF
  int v14; // [esp+20h] [ebp-84h] BYREF
  char Str[125]; // [esp+24h] [ebp-80h] BYREF
  __int16 v16; // [esp+A1h] [ebp-3h]
  char v17; // [esp+A3h] [ebp-1h]

  Str[0] = byte_629120;
  memset(&Str[1], 0, 0x7Cu);
  v16 = 0;
  v17 = 0;
  v13 = 0;
  v12 = 0;
  *(float *)&v10 = 0.0;
  *(float *)&v9 = 0.0;
  *(float *)&v11 = 0.0;
  *(float *)&v14 = 0.0;
  if ( !String1 || !strlen(String1) || sub_4B1220(String1) )
    return -1;
  if ( operator new(0x7Cu) )
    v3 = sub_4B0C70(this[123]);
  else
    v3 = 0;
  sub_4B0E20(String1);
  while ( sub_4A84A0(this) )
  {
    if ( strstr(::Str, asc_608AB4) )
      return sub_4B11D0(v3);
    if ( sub_577E50(byte_7656E8, aSoundClick, (int)Str) )
    {
      sub_4B0E40(Str);
    }
    else if ( sub_577E50(byte_7656E8, aSoundRelease, (int)Str) )
    {
      sub_4B0E50(Str);
    }
    else if ( sub_577E50(byte_7656E8, aSoundFocus, (int)Str) )
    {
      sub_4B0E60(Str);
    }
    else if ( sub_577E50(byte_7656E8, aSoundLostfocus, (int)Str) )
    {
      sub_4B0E70(Str);
    }
    else
    {
      if ( !sub_577E50(byte_7656E8, aSoundDrag, (int)Str) )
      {
        if ( sub_578220(aSize, (int)&v10, (int)&v9, 0, 0, 0, 0, 0, 0) )
        {
          sub_4B0ED0((__int64)*(float *)&v10, (__int64)*(float *)&v9);
        }
        else if ( sub_578220(aSecondaryoffse, (int)&v10, (int)&v9, (int)&v11, (int)&v14, 0, 0, 0, 0) )
        {
          sub_4B1650(0, (__int64)*(float *)&v10, (__int64)*(float *)&v9);
          sub_4B1650(1, (__int64)*(float *)&v11, (__int64)*(float *)&v14);
        }
        else if ( sub_578110(aOffsetPair, (int)&v13, (int)&v12, 0, 0) )
        {
          sub_4B15D0(v13, v12);
        }
        else if ( sub_577E50(byte_7656E8, aFont, (int)Str) || sub_577E50(byte_7656E8, aFont1, (int)Str) )
        {
          sub_4ADDF0(Str);
          v7 = strstr(Str, aBmp);
          if ( v7 )
            *v7 = 0;
          sub_4B0E90(Str);
        }
        else if ( sub_577E50(byte_7656E8, aFont2, (int)Str) )
        {
          sub_4ADDF0(Str);
          v4 = strstr(Str, aBmp);
          if ( v4 )
            *v4 = 0;
          sub_4B0EA0(Str);
        }
        else if ( sub_577E50(byte_7656E8, aFont3, (int)Str) )
        {
          sub_4ADDF0(Str);
          v5 = strstr(Str, aBmp);
          if ( v5 )
            *v5 = 0;
          sub_4B0EB0(Str);
        }
        else if ( sub_577E50(byte_7656E8, aFont4, (int)Str) )
        {
          sub_4ADDF0(Str);
          v6 = strstr(Str, aBmp);
          if ( v6 )
            *v6 = 0;
          sub_4B0EC0(Str);
        }
        else if ( sub_577ED0(byte_7656E8, aFrame, Str, 0) )
        {
          sub_4AA0A0(v3, 0);
        }
        continue;
      }
      sub_4B0E80(Str);
    }
    sub_4ADC50(Str);
  }
  return sub_4B11D0(v3);
}
