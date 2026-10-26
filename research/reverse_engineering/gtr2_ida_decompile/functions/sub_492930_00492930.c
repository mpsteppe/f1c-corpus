int __thiscall sub_492930(float *this)
{
  double v2; // st7
  int v3; // ecx
  char v4; // bl
  double v5; // st7
  int v6; // ecx
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // edi
  _BYTE *v12; // edx
  char v13; // cl
  _BYTE *v14; // eax
  const char *v15; // eax
  int v16; // eax
  const char *v17; // eax
  char *v18; // eax
  int result; // eax
  char *v20; // eax
  char v21; // bl
  const char *v22; // eax
  int v23; // ecx
  int v24; // eax
  int v25; // eax
  char v26; // cl
  _BYTE *v27; // edx
  int v28; // eax
  char *v29; // eax
  char *v30; // edi
  char *v31; // eax
  int v32; // eax
  char *v33; // eax
  char *v34; // [esp-14h] [ebp-39Ch]
  int v35; // [esp-8h] [ebp-390h]
  int v36; // [esp-4h] [ebp-38Ch]
  char *v37; // [esp+0h] [ebp-388h]
  const char *v38; // [esp+8h] [ebp-380h]
  char *v39; // [esp+Ch] [ebp-37Ch] BYREF
  char v40[8]; // [esp+10h] [ebp-378h] BYREF
  char v41[4]; // [esp+18h] [ebp-370h] BYREF
  int v42; // [esp+1Ch] [ebp-36Ch]
  int v43; // [esp+24h] [ebp-364h] BYREF
  char ArgList[12]; // [esp+28h] [ebp-360h] BYREF
  int v45; // [esp+34h] [ebp-354h]
  char v46[12]; // [esp+38h] [ebp-350h] BYREF
  char v47; // [esp+44h] [ebp-344h] BYREF
  char v48[116]; // [esp+64h] [ebp-324h] BYREF
  char Buffer[141]; // [esp+D8h] [ebp-2B0h] BYREF
  __int16 v50; // [esp+165h] [ebp-223h]
  char v51; // [esp+167h] [ebp-221h]
  _BYTE v52[504]; // [esp+168h] [ebp-220h] BYREF
  __int16 v53; // [esp+360h] [ebp-28h]
  char v54; // [esp+362h] [ebp-26h]
  int v55; // [esp+370h] [ebp-18h]
  int v56; // [esp+374h] [ebp-14h]

  v2 = this[69];
  v3 = *((_DWORD *)this + 12);
  v4 = 0;
  v45 = -1;
  ArgList[8] = 0;
  if ( v2 <= 0.0 )
  {
    v8 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v3 + 28))(v3, 36);
    if ( v8 )
      (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)v8 + 36))(v8, 0);
  }
  else
  {
    v5 = this[69] - sub_4DE460(v3);
    v6 = *((_DWORD *)this + 12);
    v42 = 36;
    this[69] = v5;
    v7 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v6 + 28))(v6, v42);
    if ( v7 )
      (*(void (__thiscall **)(int, int))(*(_DWORD *)v7 + 36))(v7, 1);
    v4 = 1;
    ArgList[0] = 1;
  }
  v9 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 12) + 28))(*((_DWORD *)this + 12), 36);
  if ( v9 && sub_4CE1B0(v9) < 0 )
  {
    v4 = 1;
    LOBYTE(v43) = 1;
  }
  else if ( !v4 && *((int *)this + 70) >= 0 )
  {
    v10 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 12) + 28))(*((_DWORD *)this + 12), 36);
    v11 = v10;
    if ( v10 )
    {
      if ( sub_4CE1B0(v10) >= 0 )
      {
        v12 = (_BYTE *)sub_4CE170(v11);
        if ( v12 )
        {
          memset(v52, 0, 255);
          v13 = *v12;
          if ( *v12 != 9 )
          {
            v14 = v12;
            do
            {
              v14[v52 - v12] = v13;
              v13 = *++v14;
            }
            while ( v13 != 9 );
          }
          if ( CINet::RoomIPCount((CINet *)dword_B6CBB0, v52) <= *((_DWORD *)this + 70) )
          {
            this[70] = NAN;
          }
          else
          {
            memset(&Buffer[12], 0, 80);
            CINet::RoomPort((CINet *)dword_B6CBB0, &Buffer[140]);
            v15 = CINet::RoomIPAddress((CINet *)dword_B6CBB0, &Buffer[136], *((_DWORD *)this + 70));
            sprintf(Buffer, "%s:%d", v15, v36);
            ++*((_DWORD *)this + 70);
            if ( (unsigned __int8)sub_46B000() )
            {
              v4 = 1;
              LOBYTE(v38) = 1;
              this[69] = 4.0;
            }
          }
        }
      }
    }
  }
  (*(void (__thiscall **)(float *, int))(*(_DWORD *)this + 36))(this, v43);
  if ( v4 )
  {
    memset(&Buffer[16], 0, 125);
    v50 = 0;
    v51 = 0;
    v16 = sub_473800(&dword_B6CBA8, (int)&Buffer[16]);
    if ( v16 )
    {
      v17 = sub_473870(v16);
      v18 = sub_41D840(&byte_91CC38, v17);
      sub_615860(v18);
      sub_4E1810("Join Failure Page", 0);
      result = -1;
      this[69] = 0.0;
      this[70] = NAN;
      return result;
    }
  }
  if ( sub_473550() != 3 )
    return (int)v38;
  this[70] = NAN;
  sub_4744E0(ArgList);
  v39 = ArgList;
  v56 = 0;
  if ( !(unsigned __int8)sub_473900() )
  {
LABEL_68:
    *(_DWORD *)&v52[496] = -1;
    nullsub_7(&v39);
    return (int)v38;
  }
  if ( dword_B640C0 != 5 )
  {
    if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp", 29805) )
      sub_561210((int)byte_FAE910, "Join Session was successful, setting local session description:", (char)v39);
    if ( dword_B640C0 != 5 )
    {
      if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp", 29806) )
        sub_561210((int)byte_FAE910, " ** Session Name:  %s", (char)&v43);
      if ( dword_B640C0 != 5 )
      {
        if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp", 29807) )
          sub_561210((int)byte_FAE910, " ** Scene Base:    %s", (char)&v47);
        if ( dword_B640C0 != 5 )
        {
          if ( (unsigned __int8)sub_5612D0(
                                  (int)byte_FAE910,
                                  2,
                                  "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                  29808) )
            sub_561210((int)byte_FAE910, " ** AI Opp:        %d", v48[40]);
          if ( dword_B640C0 != 5 )
          {
            if ( (unsigned __int8)sub_5612D0(
                                    (int)byte_FAE910,
                                    2,
                                    "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                    29809) )
              sub_561210((int)byte_FAE910, " ** Human Opp:     %d", v48[41]);
            if ( dword_B640C0 != 5
              && (unsigned __int8)sub_5612D0(
                                    (int)byte_FAE910,
                                    2,
                                    "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                    29810) )
            {
              sub_561210((int)byte_FAE910, " ** Max Players:   %d", v48[42]);
            }
          }
        }
      }
    }
  }
  v20 = *(char **)dword_91CA70;
  v21 = 0;
  if ( !*(_DWORD *)dword_91CA70 )
    v20 = (char *)WindowName;
  sub_615FE0("*.GDB", 0, v20, 1);
  v22 = (const char *)sub_615D40(&unk_FAECBC);
  if ( v22 )
  {
    while ( strcmp(v48, v22) )
    {
      sub_615CE0(&unk_FAECBC);
      v22 = (const char *)sub_615D40(&unk_FAECBC);
      if ( !v22 )
        goto LABEL_52;
    }
    v21 = 1;
  }
LABEL_52:
  sub_615FC0(&unk_FAECBC);
  if ( v21 )
  {
    memset(&v52[252], 0, 0xFCu);
    v23 = *((_DWORD *)this + 12);
    v53 = 0;
    v54 = 0;
    v38 = (const char *)36;
    v24 = (*(int (__thiscall **)(int))(*(_DWORD *)v23 + 28))(v23);
    if ( v24 )
    {
      v25 = sub_4CE170(v24);
      if ( v25 )
      {
        v26 = *(_BYTE *)v25;
        if ( *(_BYTE *)v25 != 9 )
        {
          v27 = &v52[-v25 + 248];
          do
          {
            v27[v25] = v26;
            v26 = *(_BYTE *)++v25;
          }
          while ( v26 != 9 );
        }
      }
    }
    if ( CINet::GetRoomSubscription((CINet *)dword_B6CBB0, &v52[248]) )
    {
      v37 = sub_41D840(&byte_91CC38, "Please Wait...");
      sub_4EB900(off_16C9AD8, v37);
    }
    v28 = sub_53A220(v46);
    if ( v28 )
      v29 = (char *)(v28 + 4);
    else
      v29 = 0;
    switch ( CINet::JoinRoom((CINet *)dword_B6CBB0, v41, v29) )
    {
      case 0:
        sub_4D0AC0(v35);
        sub_4DF020(*((_DWORD *)this + 12));
        sub_48B9C0();
        sub_50EF80(&byte_B6F530);
        sub_4781A0((int)v40, (int)this);
        nullsub_7(&unk_B6F135);
        v30 = (char *)&unk_9204A0;
        do
        {
          sub_53E6A0(v30, -1);
          v30 += 22616;
        }
        while ( (int)v30 < (int)dword_B5E860 );
        dword_757C10 = 0;
        sub_42CC30(&unk_920488);
        byte_91E234 = 1;
        dword_B640C4 = 2;
        sub_4E1810("CLIENT TEAM SELECT", 0);
        this[69] = 0.0;
        v38 = 0;
        goto LABEL_68;
      case 0xF:
      case 0x13:
        sub_4DF020(*((_DWORD *)this + 12));
        sub_473970();
        goto LABEL_83;
      case 0x10:
        sub_4DF020(*((_DWORD *)this + 12));
        sub_473970();
        CINet::UpdateExecuteNow((CINet *)dword_B6CBB0, 1);
        if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 33) )
        {
          switch ( *(_DWORD *)(dword_B6CBB0 + 2112) )
          {
            case 0x9CA6:
              v31 = sub_41D840(&byte_91CC38, "Subscription Locked. Renew ?");
              break;
            case 0x9CA7:
              v31 = sub_41D840(&byte_91CC38, "Subscription Suspended. Renew ?");
              break;
            case 0x9CA8:
              v31 = sub_41D840(&byte_91CC38, "Subscripiton Ended. Renew ?");
              break;
            case 0x9CAA:
              v31 = sub_41D840(&byte_91CC38, "Subscripiton Closed. Renew ?");
              break;
            case 0x9CAB:
              v31 = sub_41D840(&byte_91CC38, "Subscripiton Terminated. Renew ?");
              break;
            default:
              v31 = sub_41D840(&byte_91CC38, "Subscription Required. Proceed ?");
              break;
          }
          v34 = v31;
          sub_407620();
        }
        v32 = (*(int (__thiscall **)(int, int, char *))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 753, v34);
        if ( v32 )
          *(_DWORD *)(v32 + 276) = 1;
        sub_4CD6D0("OK CANCEL POPUP");
        goto LABEL_84;
      default:
        goto LABEL_68;
    }
  }
  sub_473970();
  v38 = "Game not available.  Host may be running an updated or modified game";
LABEL_83:
  v33 = sub_41D840(&byte_91CC38, v38);
  sub_615860(v33);
  sub_4E1810("Join Failure Page", 0);
LABEL_84:
  this[69] = 0.0;
  v55 = -1;
  nullsub_7(&v43);
  return -1;
}
