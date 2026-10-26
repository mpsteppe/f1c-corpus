int __usercall sub_4EBCE0@<eax>(int a1@<esi>)
{
  int v1; // eax
  char *v2; // eax
  int v3; // eax
  const CHAR **v5; // eax
  const CHAR **v6; // esi
  const CHAR *v7; // eax
  int v8; // eax
  _DWORD *v9; // ecx
  const char *v10; // eax
  char *v11; // eax
  _BYTE v12[4]; // [esp+0h] [ebp-1A0h] BYREF
  const char *v13; // [esp+4h] [ebp-19Ch]
  int *v14; // [esp+8h] [ebp-198h]
  const char *v15; // [esp+Ch] [ebp-194h] BYREF
  int v16; // [esp+10h] [ebp-190h] BYREF
  int v17; // [esp+14h] [ebp-18Ch]
  int v18; // [esp+18h] [ebp-188h]
  _BYTE v19[4]; // [esp+C4h] [ebp-DCh] BYREF
  char v20[4]; // [esp+C8h] [ebp-D8h] BYREF
  _BYTE v21[172]; // [esp+CCh] [ebp-D4h] BYREF
  int v22; // [esp+180h] [ebp-20h]
  int v23; // [esp+188h] [ebp-18h]
  int v24; // [esp+190h] [ebp-10h]

  if ( dword_B640C0 == 5 )
  {
    v18 = 0;
    dword_75B17C = 3;
    sub_4304C0();
  }
  v17 = a1;
  switch ( *(_DWORD *)dword_B72314 )
  {
    case 4:
      sub_510770(&byte_B6F530, 0);
      if ( dword_B6F6EC )
      {
        if ( *dword_B6F6EC )
        {
          v5 = (const CHAR **)sub_539670(dword_B6F6EC);
          v6 = v5;
          if ( v5 )
          {
            v7 = *v5;
            if ( !*v6 )
              v7 = WindowName;
            sub_615860(v7);
            sub_615860(v6 + 463);
          }
        }
      }
      goto LABEL_6;
    case 5:
      sub_473970();
      goto LABEL_6;
    case 6:
      v8 = dword_B7231C;
      *(_DWORD *)dword_B72314 = 1;
      if ( dword_B7231C > 1 || (v8 = dword_B72320, dword_B72320 < 1) )
        *(_DWORD *)dword_B72314 = v8;
      v16 = 0;
      v15 = "REPLAY_STUDIO_SIMMAIN";
      goto LABEL_39;
    case 7:
      if ( (*(int (__thiscall **)(int, int, int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 857, v17, v18) )
        sub_4D0AC0();
      goto LABEL_6;
    default:
LABEL_6:
      v1 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 578);
      if ( v1 && *(_BYTE *)(v1 + 280) )
      {
        sub_4744E0(&v16);
        v14 = &v16;
        v24 = 0;
        if ( (unsigned __int8)sub_473900() )
          CINet::LeaveRoom((CINet *)dword_B6CBB0, (char *)&v15);
        if ( (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 33) )
        {
          v2 = sub_41D840(&byte_91CC38, "Return to MoRe Website ?");
          sub_615860(v2);
        }
        v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 753);
        if ( v3 )
          *(_DWORD *)(v3 + 276) = 4;
        sub_4E1810((_DWORD *)dword_B6E090, (int)"MULTIPLAYER_MORE_AUTOLAUNCH", 0);
        v22 = -1;
        nullsub_7(v12);
        return 0;
      }
      else if ( byte_B6CBC3 )
      {
        sub_4744E0(v21);
        v14 = (int *)v21;
        v24 = 1;
        if ( (unsigned __int8)sub_473900() )
          CINet::LeaveRoom((CINet *)dword_B6CBB0, v20);
        sub_4E1810((_DWORD *)dword_B6E090, (int)"GTR_ONLINE_LOBBY", 0);
        v23 = -1;
        nullsub_7(v19);
        return 0;
      }
      else
      {
        if ( *(_DWORD *)dword_B72314 == 4 )
        {
          v10 = Str;
          if ( !Str )
            v10 = WindowName;
          v11 = strstr(v10, "Custom");
          v14 = 0;
          if ( v11 )
            v13 = "CUSTOM_CHAMP";
          else
            v13 = "RESUMEORNEW_CHAMP";
LABEL_39:
          v9 = (_DWORD *)dword_B6E090;
        }
        else
        {
          v9 = (_DWORD *)dword_B6E090;
          v14 = 0;
          if ( *(_DWORD *)dword_B72314 == 8 )
            v13 = "DRIVERSTANDING_SCHOOL";
          else
            v13 = "MAIN MENU";
        }
        sub_4E1810(v9, (int)v13, (int)v14);
        return 0;
      }
  }
}
