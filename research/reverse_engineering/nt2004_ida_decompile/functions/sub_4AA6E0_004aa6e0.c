int __thiscall sub_4AA6E0(_DWORD **this, char *String1)
{
  int v3; // esi
  int i; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // eax
  _DWORD *v7; // eax
  _DWORD *v8; // eax
  _DWORD *v9; // eax
  _DWORD *v10; // eax
  _DWORD *v11; // eax
  void *v12; // eax
  void *v13; // eax
  void *v14; // eax
  _DWORD *v15; // eax
  void *v16; // eax
  _DWORD *v17; // eax
  _DWORD *v18; // eax
  _DWORD *v19; // eax
  _DWORD *v20; // eax
  _DWORD *v21; // eax
  void *v22; // eax
  _DWORD *v23; // eax
  _DWORD *v24; // eax
  _DWORD *v25; // eax
  char Buffer[125]; // [esp+10h] [ebp-80h] BYREF
  __int16 v28; // [esp+8Dh] [ebp-3h]
  char v29; // [esp+8Fh] [ebp-1h]

  if ( !String1 )
    return 0;
  v3 = (*(int (__thiscall **)(_DWORD *, char *))(*this[123] + 24))(this[123], String1);
  if ( !v3 )
  {
    for ( i = 0; i < 21; ++i )
    {
      if ( !_strcmpi(String1, (&off_608878)[i]) )
      {
        switch ( i )
        {
          case 0:
            v5 = operator new(0x10Cu);
            if ( !v5 )
              return 0;
            v6 = sub_49D930(v5);
            goto LABEL_17;
          case 1:
            v7 = operator new(0x114u);
            v3 = (int)v7;
            if ( !v7 )
              return 0;
            sub_49D930(v7);
            *(_DWORD *)v3 = &off_5EA168;
            *(_BYTE *)(v3 + 268) = 0;
            *(_DWORD *)(v3 + 272) = 0;
            goto LABEL_18;
          case 2:
            v8 = operator new(0x11Cu);
            v3 = (int)v8;
            if ( !v8 )
              return 0;
            sub_49C450(v8);
            *(_DWORD *)v3 = &off_5E9A98;
            sub_49E4D0(v3);
            goto LABEL_18;
          case 3:
            v9 = operator new(0x114u);
            if ( !v9 )
              return 0;
            v6 = sub_49EC20(v9, 1, -1);
            goto LABEL_17;
          case 4:
            v10 = operator new(0x114u);
            if ( !v10 )
              return 0;
            v6 = sub_49EC20(v10, 2, -1);
            goto LABEL_17;
          case 5:
            v11 = operator new(0x114u);
            if ( !v11 )
              return 0;
            v6 = sub_49EC20(v11, 3, -1);
            goto LABEL_17;
          case 6:
            v12 = operator new(0x138u);
            if ( !v12 )
              return 0;
            v6 = (_DWORD *)sub_4A0C90((int)v12);
            goto LABEL_17;
          case 7:
            v13 = operator new(0x330u);
            if ( !v13 )
              return 0;
            v6 = (_DWORD *)sub_4A1660((int)v13, 0, 0, 0, 0, 0, 0);
            goto LABEL_17;
          case 8:
            v14 = operator new(0x1A0u);
            if ( !v14 )
              return 0;
            v6 = (_DWORD *)sub_49F530((int)v14);
            goto LABEL_17;
          case 9:
            v15 = operator new(0x118u);
            v3 = (int)v15;
            if ( !v15 )
              return 0;
            sub_49C450(v15);
            *(_DWORD *)v3 = &off_5EA0C8;
            *(_DWORD *)(v3 + 268) = &unk_7C7C7C;
            *(_DWORD *)(v3 + 272) = 3289650;
            *(_DWORD *)(v3 + 276) = 789516;
            goto LABEL_18;
          case 10:
            v16 = operator new(0x138u);
            if ( !v16 )
              return 0;
            v6 = (_DWORD *)sub_49E330((int)v16);
            goto LABEL_17;
          case 11:
            v17 = operator new(0x10Cu);
            if ( !v17 )
              return 0;
            v6 = sub_49E090(v17);
            goto LABEL_17;
          case 13:
            v18 = operator new(0x190u);
            if ( !v18 )
              return 0;
            v6 = sub_4A2F50(v18);
            goto LABEL_17;
          case 14:
            v19 = operator new(0x12Cu);
            if ( !v19 )
              return 0;
            v6 = sub_4A3980(v19);
            goto LABEL_17;
          case 15:
            v20 = operator new(0x12Cu);
            if ( !v20 )
              return 0;
            v6 = sub_4A3D80(v20);
            goto LABEL_17;
          case 16:
            v21 = operator new(0x110u);
            if ( !v21 )
              return 0;
            v6 = sub_4A4290(v21);
            goto LABEL_17;
          case 17:
            v22 = operator new(0x1B4u);
            if ( !v22 )
              return 0;
            v6 = (_DWORD *)sub_4A4730((int)v22);
            goto LABEL_17;
          case 18:
            v23 = operator new(0x114u);
            if ( !v23 )
              return 0;
            v6 = sub_4A5CE0(v23);
            goto LABEL_17;
          case 19:
            v24 = operator new(0x120u);
            if ( !v24 )
              return 0;
            v6 = sub_4A60F0(v24);
            goto LABEL_17;
          case 20:
            v25 = operator new(0x158u);
            if ( !v25 )
              return 0;
            v6 = sub_4A6520(v25);
LABEL_17:
            v3 = (int)v6;
LABEL_18:
            if ( v3 )
              goto LABEL_19;
            return v3;
          default:
            return v3;
        }
      }
    }
    return v3;
  }
LABEL_19:
  if ( !*(_DWORD *)(v3 + 140) )
    return v3;
  Buffer[0] = byte_629120;
  memset(&Buffer[1], 0, 0x7Cu);
  v28 = 0;
  v29 = 0;
  sprintf(Buffer, "Prelinked Gizmo - %s", String1);
  sub_4AA390((int)this, 1, Buffer);
  return 0;
}
