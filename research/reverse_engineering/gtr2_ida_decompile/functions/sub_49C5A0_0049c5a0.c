int sub_49C5A0()
{
  int v0; // eax
  signed int v1; // kr00_4
  bool v2; // cc
  _DWORD *v3; // eax
  char *v4; // eax
  char *v5; // eax
  _DWORD *v6; // eax
  char *v7; // eax
  char *v8; // esi
  char *v10; // [esp+8h] [ebp-1E0h]
  int v11; // [esp+8h] [ebp-1E0h]
  float v12; // [esp+18h] [ebp-1D0h]
  float v13; // [esp+1Ch] [ebp-1CCh]
  char v14[31]; // [esp+24h] [ebp-1C4h] BYREF
  char v15; // [esp+43h] [ebp-1A5h]
  char v16; // [esp+99h] [ebp-14Fh]
  int v17; // [esp+B0h] [ebp-138h]
  int v18; // [esp+B4h] [ebp-134h]
  int v19[4]; // [esp+B8h] [ebp-130h] BYREF
  _BYTE v20[61]; // [esp+C8h] [ebp-120h] BYREF
  __int16 v21; // [esp+105h] [ebp-E3h]
  char v22; // [esp+107h] [ebp-E1h]
  char v23[4]; // [esp+108h] [ebp-E0h] BYREF
  char v24[60]; // [esp+10Ch] [ebp-DCh] BYREF
  char v25[32]; // [esp+148h] [ebp-A0h] BYREF
  float v26; // [esp+168h] [ebp-80h]
  char v27; // [esp+172h] [ebp-76h]
  char v28; // [esp+17Ch] [ebp-6Ch]
  int v29; // [esp+198h] [ebp-50h]
  char v30; // [esp+1D0h] [ebp-18h]
  int v31; // [esp+1E4h] [ebp-4h]

  sub_4744E0(v14);
  v31 = 0;
  if ( dword_B640C0 == 5 )
  {
    if ( sub_478700(&dword_B6CBA8) )
      sub_4E1810("MONITOR_MPHOST", 0);
    goto LABEL_30;
  }
  sub_48B9C0();
  v0 = sub_473AE0(&dword_B6CBA8);
  v1 = strlen(&byte_B6DC34);
  if ( !v0 )
  {
    v2 = v1 <= 0;
LABEL_12:
    if ( v2 )
    {
      sub_501490(&v20[24], 64);
      sub_630FE0(v14, &v20[24], 31);
    }
    else
    {
      sub_630FE0(v14, &byte_B6DC34, 31);
    }
    v15 = 0;
    if ( byte_B6CBC3 && CINet::RoomExists((CINet *)dword_B6CBB0, v14) )
    {
      v5 = sub_41D840(&byte_91CC38, "A Game with that name already exists. Please specify different name.");
      sub_615860(v5);
      sub_4CD6D0("JOIN FAILURE PAGE");
      goto LABEL_30;
    }
    goto LABEL_7;
  }
  v2 = v1 <= 0;
  if ( v1 )
    goto LABEL_12;
  sub_630FE0(v14, v0, 31);
  v15 = 0;
LABEL_7:
  sub_477E20();
  v16 = byte_B73264;
  v18 = 0;
  v17 = 0;
  if ( byte_B729E8 )
  {
    v12 = *(&flt_B728A4 + 9 * *(_DWORD *)dword_B72314);
    if ( sub_53A250(0) )
    {
      v3 = (_DWORD *)sub_616630("RaceLaps");
      if ( v3 )
      {
        v4 = sub_48D380(v3);
        v18 = (unsigned __int64)((double)atol(v4) * v12);
      }
    }
  }
  else
  {
    v13 = *(&flt_B728A4 + 9 * *(_DWORD *)dword_B72314);
    if ( sub_53A250(0) )
    {
      v6 = (_DWORD *)sub_616630("RaceTime");
      if ( v6 )
      {
        v7 = sub_48D380(v6);
        v17 = (unsigned __int64)((double)atol(v7) * v13);
      }
    }
  }
  *(_DWORD *)&v20[12] = dword_B6FF58;
  v19[0] = dword_B7000C;
  v10 = sub_41D840(&byte_91CC38, "Starting Session...");
  sub_4EB900(off_16C9974, v10);
  if ( !strlen(byte_B6DC50) )
    sub_473A80(0);
  if ( (unsigned __int8)sub_47BC30() )
  {
    v8 = (char *)&unk_9204A0;
    do
    {
      sub_53E6A0(v8, -1);
      v8 += 22616;
    }
    while ( (int)v8 < (int)dword_B5E860 );
    dword_757C10 = 0;
    sub_42CC30(&unk_920488);
    byte_91E234 = 1;
    dword_75B17C = 1;
    sub_4E1810("MONITOR_MPHOST", 0);
    if ( byte_B6CBC3 )
    {
      sub_4744E0(v24);
      v30 = 1;
      if ( (unsigned __int8)sub_473900() )
      {
        memset(v20, 0, sizeof(v20));
        v21 = 0;
        v22 = 0;
        sub_53A410(&unk_BE1CFD, v20, 63);
        CINet::CreateRoom(
          (CINet *)dword_B6CBB0,
          0,
          v23,
          v20,
          (unsigned __int64)(v26 * 180.0),
          v29,
          byte_B73264,
          v25,
          v27,
          &byte_B6DC50[strlen(byte_B6DC50) + 1] != algn_B6DC51,
          v11,
          dword_B73294,
          dword_B706CC,
          dword_B73000,
          dword_B72EBC,
          dword_B70588,
          dword_B6FE20,
          dword_B73348,
          0,
          0,
          0);
      }
      v28 = 0;
      nullsub_7(v19);
    }
  }
LABEL_30:
  v31 = -1;
  nullsub_7(v14);
  return -1;
}
