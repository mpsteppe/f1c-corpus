int __thiscall sub_493060(_DWORD *this, const char *a2)
{
  int v3; // edi
  int v4; // eax
  int v5; // eax
  int v6; // eax
  _BYTE *v7; // eax
  _BYTE *v8; // eax
  _BYTE *v9; // eax
  int v11; // [esp-4h] [ebp-A8h]
  int v12; // [esp-4h] [ebp-A8h]
  int v13; // [esp-4h] [ebp-A8h]
  float v14; // [esp+Ch] [ebp-98h] BYREF
  float v15; // [esp+10h] [ebp-94h] BYREF
  float v16; // [esp+14h] [ebp-90h] BYREF
  int v17; // [esp+18h] [ebp-8Ch] BYREF
  int v18; // [esp+1Ch] [ebp-88h] BYREF
  float v19; // [esp+20h] [ebp-84h] BYREF
  CHAR v20[125]; // [esp+24h] [ebp-80h] BYREF
  __int16 v21; // [esp+A1h] [ebp-3h]
  char v22; // [esp+A3h] [ebp-1h]

  v20[0] = byte_5EA438[0];
  memset(&v20[1], 0, 0x7Cu);
  v21 = 0;
  v22 = 0;
  v18 = 0;
  v17 = 0;
  v15 = 0.0;
  v14 = 0.0;
  v16 = 0.0;
  v19 = 0.0;
  if ( !a2 || !strlen(a2) || sub_49A210(a2) )
    return -1;
  if ( sub_587C03(124) )
    v3 = sub_499C50(this[105]);
  else
    v3 = 0;
  sub_499E10(a2);
  while ( sub_491FB0(this) )
  {
    if ( sub_587C20(&unk_7CDB70, asc_5CC4F4) )
      return sub_49A1C0(v3);
    if ( sub_5654A0(aSoundClick, v20) )
    {
      sub_499E30(v20);
    }
    else if ( sub_5654A0(aSoundRelease, v20) )
    {
      sub_499E40(v20);
    }
    else if ( sub_5654A0(aSoundFocus, v20) )
    {
      sub_499E50(v20);
    }
    else if ( sub_5654A0(aSoundLostfocus, v20) )
    {
      sub_499E60(v20);
    }
    else
    {
      if ( !sub_5654A0(aSoundDrag, v20) )
      {
        if ( sub_565870(aSize, &v15, &v14, 0, 0, 0, 0, 0, 0) )
        {
          v11 = sub_587BDC(v14);
          v4 = sub_587BDC(v15);
          sub_499EB0(v4, v11);
        }
        else if ( sub_565870(aSecondaryoffse, &v15, &v14, &v16, &v19, 0, 0, 0, 0) )
        {
          v12 = sub_587BDC(v14);
          v5 = sub_587BDC(v15);
          sub_49AE40(0, v5, v12);
          v13 = sub_587BDC(v19);
          v6 = sub_587BDC(v16);
          sub_49AE40(1, v6, v13);
        }
        else if ( sub_565760(aOffsetPair, &v18, &v17, 0, 0) )
        {
          sub_49ADC0(v18, v17);
        }
        else if ( sub_5654A0(aFont, v20) || sub_5654A0(aFont1, v20) )
        {
          sub_497EC0(v20);
          v9 = (_BYTE *)sub_587C20(v20, &dword_5CC79C);
          if ( v9 )
            *v9 = 0;
          sub_499E80(v20);
        }
        else if ( sub_5654A0(aFont2, v20) )
        {
          sub_497EC0(v20);
          v7 = (_BYTE *)sub_587C20(v20, &dword_5CC79C);
          if ( v7 )
            *v7 = 0;
          sub_499E90(v20);
        }
        else if ( sub_5654A0(aFont3, v20) )
        {
          sub_497EC0(v20);
          v8 = (_BYTE *)sub_587C20(v20, &dword_5CC79C);
          if ( v8 )
            *v8 = 0;
          sub_499EA0(v20);
        }
        else if ( sub_565520(aFrame, v20, 0) )
        {
          sub_493990(v3, 0);
        }
        continue;
      }
      sub_499E70(v20);
    }
    sub_497D20(v20);
  }
  return sub_49A1C0(v3);
}
