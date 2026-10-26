int __thiscall sub_493170(float *this)
{
  double v2; // st7
  char v3; // bl
  double v4; // st7
  int v5; // eax
  char *v6; // eax
  char *v7; // edx
  char v8; // cl
  int v9; // eax
  int v10; // edi
  int v11; // eax
  char v12; // cl
  char *v13; // edx
  const char *v14; // eax
  int v15; // eax
  const char *v16; // eax
  int result; // eax
  char *v18; // eax
  char v19; // bl
  const char *v20; // eax
  int *v21; // ecx
  int v22; // eax
  int v23; // eax
  char *v24; // eax
  char *v25; // edx
  char v26; // cl
  int v27; // eax
  int v28; // edi
  int v29; // eax
  char v30; // cl
  char *v31; // edx
  char *v32; // eax
  int v33; // eax
  char *v34; // eax
  char *v35; // edi
  int v36; // eax
  int v37; // ecx
  int v38; // eax
  char *v39; // eax
  int v40; // eax
  char *v41; // eax
  int v42; // eax
  int v43; // edi
  char *v44; // eax
  char *v45; // [esp+20h] [ebp-290h]
  char *v46; // [esp+30h] [ebp-280h]
  int v47; // [esp+30h] [ebp-280h]
  const char *v48; // [esp+3Ch] [ebp-274h] BYREF
  char *v49; // [esp+40h] [ebp-270h] BYREF
  char v50[12]; // [esp+4Ch] [ebp-264h] BYREF
  char v51[4]; // [esp+58h] [ebp-258h] BYREF
  char ArgList[16]; // [esp+5Ch] [ebp-254h] BYREF
  char v53[12]; // [esp+6Ch] [ebp-244h] BYREF
  char v54; // [esp+78h] [ebp-238h] BYREF
  char v55[116]; // [esp+98h] [ebp-218h] BYREF
  char Buffer[141]; // [esp+10Ch] [ebp-1A4h] BYREF
  __int16 v57; // [esp+199h] [ebp-117h]
  char v58; // [esp+19Bh] [ebp-115h]
  _DWORD v59[64]; // [esp+19Ch] [ebp-114h] BYREF
  __int16 v60; // [esp+29Ch] [ebp-14h]
  char v61; // [esp+29Eh] [ebp-12h]
  int v62; // [esp+2A4h] [ebp-Ch]
  int v63; // [esp+2A8h] [ebp-8h]

  v2 = this[69];
  memset(&v59[1], 0, 0xFCu);
  v60 = 0;
  v61 = 0;
  v3 = 0;
  *(_DWORD *)v51 = -1;
  ArgList[0] = 0;
  if ( v2 <= 0.0 )
  {
    if ( *((int *)this + 70) >= 0 )
    {
      v5 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 12) + 28))(*((_DWORD *)this + 12), 578);
      if ( v5 && *(_DWORD *)(v5 + 284) == 2 )
      {
        v6 = (char *)(v5 + 1563);
        v7 = (char *)((char *)v59 - v6);
        do
        {
          v8 = *v6;
          v7[(_DWORD)v6] = *v6;
          ++v6;
        }
        while ( v8 );
      }
      else
      {
        v9 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 12) + 28))(*((_DWORD *)this + 12), 36);
        v10 = v9;
        if ( v9 )
        {
          if ( sub_4CE1B0(v9) >= 0 )
          {
            v11 = sub_4CE170(v10);
            if ( v11 )
            {
              v12 = *(_BYTE *)v11;
              if ( *(_BYTE *)v11 != 9 )
              {
                v13 = &Buffer[-v11 + 140];
                do
                {
                  v13[v11] = v12;
                  v12 = *(_BYTE *)++v11;
                }
                while ( v12 != 9 );
              }
            }
          }
        }
      }
      if ( CINet::RoomIPCount((CINet *)dword_B6CBB0, (char *)v59) <= *((_DWORD *)this + 70) )
      {
        this[70] = NAN;
      }
      else
      {
        memset(&Buffer[12], 0, 80);
        CINet::RoomPort((CINet *)dword_B6CBB0, &Buffer[140]);
        v14 = CINet::RoomIPAddress((CINet *)dword_B6CBB0, &Buffer[136], *((_DWORD *)this + 70));
        sprintf(Buffer, "%s:%d", v14, v47);
        v46 = &byte_B6DC50;
        ++*((_DWORD *)this + 70);
        if ( (unsigned __int8)sub_46B000() )
          this[69] = 4.0;
      }
    }
  }
  else
  {
    v4 = this[69] - sub_4DE460(*((_DWORD *)this + 12));
    v3 = 1;
    ArgList[0] = 1;
    this[69] = v4;
  }
  (*(void (__thiscall **)(float *, _DWORD))(*(_DWORD *)this + 36))(this, *(_DWORD *)ArgList);
  if ( v3 )
  {
    memset(&Buffer[16], 0, 125);
    v57 = 0;
    v58 = 0;
    v15 = sub_473800(&dword_B6CBA8, (int)&Buffer[16]);
    if ( v15 )
    {
      v16 = sub_473870(v15);
      v49 = sub_41D840(&byte_91CC38, v16);
      sub_615860(v49);
      sub_4E1810("Join Failure Page", 0);
      result = -1;
      this[69] = 0.0;
      this[70] = NAN;
      return result;
    }
  }
  if ( sub_473550() == 3 )
  {
    this[70] = NAN;
    sub_4744E0(ArgList);
    v49 = ArgList;
    v63 = 0;
    if ( (unsigned __int8)sub_473900() )
    {
      if ( dword_B640C0 != 5 )
      {
        if ( (unsigned __int8)sub_5612D0((int)byte_FAE910, 2, "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp", 30176) )
          sub_561210((int)byte_FAE910, "Join Session was successful, setting local session description:", (char)v49);
        if ( dword_B640C0 != 5 )
        {
          if ( (unsigned __int8)sub_5612D0(
                                  (int)byte_FAE910,
                                  2,
                                  "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                  30177) )
            sub_561210((int)byte_FAE910, " ** Session Name:  %s", (char)v51);
          if ( dword_B640C0 != 5 )
          {
            if ( (unsigned __int8)sub_5612D0(
                                    (int)byte_FAE910,
                                    2,
                                    "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                    30178) )
              sub_561210((int)byte_FAE910, " ** Scene Base:    %s", (char)&v54);
            if ( dword_B640C0 != 5 )
            {
              if ( (unsigned __int8)sub_5612D0(
                                      (int)byte_FAE910,
                                      2,
                                      "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                      30179) )
                sub_561210((int)byte_FAE910, " ** AI Opp:        %d", v55[40]);
              if ( dword_B640C0 != 5 )
              {
                if ( (unsigned __int8)sub_5612D0(
                                        (int)byte_FAE910,
                                        2,
                                        "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                        30180) )
                  sub_561210((int)byte_FAE910, " ** Human Opp:     %d", v55[41]);
                if ( dword_B640C0 != 5
                  && (unsigned __int8)sub_5612D0(
                                        (int)byte_FAE910,
                                        2,
                                        "\\Dev\\Src\\Copperhead\\App\\Source\\O_AppGz.cpp",
                                        30181) )
                {
                  sub_561210((int)byte_FAE910, " ** Max Players:   %d", v55[42]);
                }
              }
            }
          }
        }
      }
      v18 = *(char **)dword_91CA70;
      v19 = 0;
      if ( !*(_DWORD *)dword_91CA70 )
        v18 = (char *)WindowName;
      sub_615FE0("*.GDB", 0, v18, 1);
      v20 = (const char *)sub_615D40(&unk_FAECBC);
      if ( v20 )
      {
        while ( strcmp(v55, v20) )
        {
          sub_615CE0(&unk_FAECBC);
          v20 = (const char *)sub_615D40(&unk_FAECBC);
          if ( !v20 )
            goto LABEL_49;
        }
        v19 = 1;
      }
LABEL_49:
      sub_615FC0(&unk_FAECBC);
      if ( v19 )
      {
        v21 = (int *)*((_DWORD *)this + 12);
        v22 = *v21;
        v48 = (const char *)578;
        v23 = (*(int (__thiscall **)(int *))(v22 + 28))(v21);
        if ( v23 && *(_DWORD *)(v23 + 284) == 2 )
        {
          v24 = (char *)(v23 + 1563);
          v25 = (char *)(&Buffer[136] - v24);
          do
          {
            v26 = *v24;
            v25[(_DWORD)v24] = *v24;
            ++v24;
          }
          while ( v26 );
        }
        else
        {
          v27 = (*(int (__thiscall **)(_DWORD, int))(**((_DWORD **)this + 12) + 28))(*((_DWORD *)this + 12), 36);
          v28 = v27;
          if ( v27 )
          {
            if ( sub_4CE1B0(v27) >= 0 )
            {
              v29 = sub_4CE170(v28);
              if ( v29 )
              {
                v30 = *(_BYTE *)v29;
                if ( *(_BYTE *)v29 != 9 )
                {
                  v31 = &Buffer[-v29 + 132];
                  do
                  {
                    v31[v29] = v30;
                    v30 = *(_BYTE *)++v29;
                  }
                  while ( v30 != 9 );
                }
              }
            }
          }
        }
        if ( CINet::GetRoomSubscription((CINet *)dword_B6CBB0, &Buffer[136]) )
        {
          v32 = sub_41D840(&byte_91CC38, "Please Wait...");
          sub_4EB900(&unk_B6F134, v32);
        }
        v33 = sub_53A220(v53);
        if ( v33 )
          v34 = (char *)(v33 + 4);
        else
          v34 = 0;
        switch ( CINet::JoinRoom((CINet *)dword_B6CBB0, v50, v34) )
        {
          case 0:
            if ( (*(int (__thiscall **)(_DWORD))(**((_DWORD **)this + 12) + 28))(*((_DWORD *)this + 12)) )
              sub_4D0AC0(36);
            sub_4DF020(*((_DWORD *)this + 12));
            sub_48B9C0();
            sub_50EF80(&byte_B6F530);
            sub_4781A0((int)&v49, (int)this);
            nullsub_7(&unk_B6F135);
            v35 = (char *)&unk_9204A0;
            do
            {
              sub_53E6A0(v35, -1);
              v35 += 22616;
            }
            while ( (int)v35 < (int)dword_B5E860 );
            dword_757C10 = 0;
            sub_42CC30(&unk_920488);
            byte_91E234 = 1;
            dword_B640C4 = 2;
            sub_4E1810("CLIENT TEAM SELECT", 0);
            this[69] = 0.0;
            goto LABEL_73;
          case 0xF:
          case 0x13:
            sub_4DF020(*((_DWORD *)this + 12));
            sub_473970();
            goto LABEL_92;
          case 0x10:
            sub_4DF020(*((_DWORD *)this + 12));
            sub_473970();
            CINet::UpdateExecuteNow((CINet *)dword_B6CBB0, 1);
            if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 33) )
            {
              switch ( *(_DWORD *)(dword_B6CBB0 + 2112) )
              {
                case 0x9CA6:
                  v39 = sub_41D840(&byte_91CC38, "Subscription Locked. Renew ?");
                  break;
                case 0x9CA7:
                  v39 = sub_41D840(&byte_91CC38, "Subscription Suspended. Renew ?");
                  break;
                case 0x9CA8:
                  v39 = sub_41D840(&byte_91CC38, "Subscripiton Ended. Renew ?");
                  break;
                case 0x9CAA:
                  v39 = sub_41D840(&byte_91CC38, "Subscripiton Closed. Renew ?");
                  break;
                case 0x9CAB:
                  v39 = sub_41D840(&byte_91CC38, "Subscripiton Terminated. Renew ?");
                  break;
                default:
                  v39 = sub_41D840(&byte_91CC38, "Subscription Required. Proceed ?");
                  break;
              }
              v45 = v39;
              sub_407620();
            }
            v40 = (*(int (__thiscall **)(int, int, char *))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 753, v45);
            if ( v40 )
              *(_DWORD *)(v40 + 276) = 1;
            sub_4CD6D0("OK CANCEL POPUP");
            goto LABEL_93;
          default:
            goto LABEL_73;
        }
      }
      sub_473970();
      v48 = "Game not available.  Host may be running an updated or modified game";
LABEL_92:
      v41 = sub_41D840(&byte_91CC38, v48);
      sub_615860(v41);
      sub_4E1810("Join Failure Page", 0);
LABEL_93:
      this[69] = 0.0;
      v62 = -1;
      nullsub_7(v51);
      return -1;
    }
LABEL_73:
    v59[59] = -1;
    nullsub_7(&v48);
  }
  if ( *((_DWORD *)this + 70) == -1 )
  {
    v36 = sub_473550();
    v37 = *((_DWORD *)this + 12);
    if ( v36 == 3 )
    {
      v38 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v37 + 28))(v37, 578);
      if ( v38 && *(_BYTE *)(v38 + 280) )
      {
        sub_41D840(&byte_91CC38, "Server Joined. Return to MoRe");
        return off_16C9730();
      }
    }
    else
    {
      v42 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v37 + 28))(v37, 578);
      v43 = v42;
      if ( v42 && *(_BYTE *)(v42 + 280) )
      {
        v44 = sub_41D840(&byte_91CC38, "Failed to Join Server. Return to MoRe");
        sub_615860(v44);
        *(_DWORD *)(v43 + 284) = 7;
        sub_4E1850(*((_DWORD *)this + 12), 0);
      }
    }
  }
  return (int)v46;
}
