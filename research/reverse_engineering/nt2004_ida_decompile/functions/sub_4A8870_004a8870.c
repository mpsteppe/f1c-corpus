int __thiscall sub_4A8870(int this, const char *a2)
{
  int v3; // ebp
  bool v4; // zf
  char *v5; // eax
  char v6; // cl
  char *v7; // eax
  char v8; // cl
  int v9; // eax
  char String1[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v12; // [esp+8Dh] [ebp-3h]
  char v13; // [esp+8Fh] [ebp-1h]

  String1[0] = byte_629120;
  memset(&String1[1], 0, 0x7Cu);
  v12 = 0;
  v3 = 0;
  v13 = 0;
  if ( a2 )
  {
    strcpy(String1, a2);
    _strupr(String1);
  }
  ++*(_DWORD *)(this + 476);
  if ( !_strcmpi(String1, aNormal) )
  {
    if ( operator new(0xB0u) )
    {
      v3 = sub_4AF290(0);
      goto LABEL_11;
    }
    goto LABEL_6;
  }
  if ( _strcmpi(String1, aModal) )
  {
    sprintf(Buffer, "undefined layer type %s", a2);
    sub_4AA390(3, Buffer);
  }
  else
  {
    if ( !operator new(0xB0u) )
    {
LABEL_6:
      v3 = 0;
      goto LABEL_11;
    }
    v3 = sub_4AF290(1);
  }
LABEL_11:
  *(_DWORD *)(this + 496) = v3;
  sub_4B13F0(0, 599, 0, 799);
  sub_4AD2E0(v3);
  while ( sub_4A84A0((_DWORD *)this) )
  {
    if ( strstr(Str, asc_608AB4) )
      break;
    if ( sub_577E50(byte_7656E8, aName_0, (int)String1) )
    {
      if ( *(_BYTE *)(this + 482) && *(_DWORD *)(this + 484) < 4u )
        sub_4AA510(String1);
      sub_4B1560(String1);
    }
    else
    {
      v4 = sub_577E50(byte_7656E8, aSoundFocus, (int)String1) == 0;
      v5 = String1;
      if ( v4 )
      {
        if ( !sub_577E50(byte_7656E8, aSoundLostfocus, (int)String1) )
        {
          if ( sub_577E50(byte_7656E8, aGizmo, (int)String1) )
          {
            v9 = sub_4A8E80(String1);
            if ( v9 )
              sub_4AD380(v9, *(_DWORD *)(this + 496));
          }
          else if ( sub_577E50(byte_7656E8, aPage, (int)String1) )
          {
            sub_4A8B20(String1);
          }
          continue;
        }
        v7 = String1;
        do
        {
          v8 = *v7;
          v7[v3 - (_DWORD)String1 + 136] = *v7;
          ++v7;
        }
        while ( v8 );
      }
      else
      {
        do
        {
          v6 = *v5;
          v5[v3 - (_DWORD)String1 + 96] = *v5;
          ++v5;
        }
        while ( v6 );
      }
      sub_4ADC50(String1);
    }
  }
  --*(_DWORD *)(this + 476);
  *(_DWORD *)(this + 496) = 0;
  return 0;
}
