int __usercall sub_46DE10@<eax>(int a1@<ecx>, int a2@<esi>)
{
  char v3; // bl
  int v4; // esi
  int v5; // eax
  int v6; // eax
  char *v7; // esi
  int v9; // eax
  int *v10; // esi
  _BYTE v12[125]; // [esp+Ch] [ebp-80h] BYREF
  __int16 v13; // [esp+89h] [ebp-3h]
  char v14; // [esp+8Bh] [ebp-1h]

  v3 = 0;
  v4 = -1;
  if ( *(float *)(a1 + 228) > 0.0 )
  {
    v3 = 1;
    *(float *)(a1 + 228) = *(float *)(a1 + 228) - sub_498730(*(_DWORD *)(a1 + 64));
  }
  v5 = (*(int (__thiscall **)(_DWORD, int, int))(**(_DWORD **)(a1 + 64) + 28))(*(_DWORD *)(a1 + 64), 34, a2);
  if ( v5 && sub_489940(v5) < 0 )
  {
    v3 = 1;
    v12[0] = 1;
  }
  (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a1 + 56))(a1, *(_DWORD *)v12);
  if ( v3
    && (v12[0] = byte_5EA438[0],
        memset(&v12[1], 0, 0x7Cu),
        v13 = 0,
        v14 = 0,
        (v6 = sub_462D30(dword_7CD25C, (int)v12)) != 0) )
  {
    v7 = sub_462DA0(v6);
    if ( sub_423A00(byte_5EC4C0, v7, byte_5EC4CC) )
    {
      if ( v7 )
        strcpy(byte_5EC4CC, v7);
      else
        byte_5EC4CC[0] = 0;
    }
    sub_566650(byte_5EC4CC);
    sub_497940(aJoinFailurePag, -1);
    *(_DWORD *)(a1 + 228) = 0;
    return -1;
  }
  else
  {
    if ( sub_461CD0(dword_7CD25C) == 3 )
    {
      sub_461550(v12);
      if ( sub_4630D0(dword_7CD25C, (int)v12) )
      {
        if ( dword_7C569C != 5 )
        {
          if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_28, 6802) )
            sub_4D7AA0(&unk_8AD25C, aJoinSessionWas);
          if ( dword_7C569C != 5 )
          {
            if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_28, 6803) )
              sub_4D7AA0(&unk_8AD25C, aSessionNameS);
            if ( dword_7C569C != 5 )
            {
              if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_28, 6804) )
                sub_4D7AA0(&unk_8AD25C, aSceneBaseS);
              if ( dword_7C569C != 5 )
              {
                if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_28, 6805) )
                  sub_4D7AA0(&unk_8AD25C, aAiOppD);
                if ( dword_7C569C != 5 )
                {
                  if ( (unsigned __int8)sub_4D7A50(2, aDDevF119992002_28, 6806) )
                    sub_4D7AA0(&unk_8AD25C, aHumanOppD);
                  if ( dword_7C569C != 5 && (unsigned __int8)sub_4D7A50(2, aDDevF119992002_28, 6807) )
                    sub_4D7AA0(&unk_8AD25C, aMaxPlayersD);
                }
              }
            }
          }
        }
        v9 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 64) + 28))(*(_DWORD *)(a1 + 64), 34);
        if ( v9 )
          sub_489CB0(v9);
        sub_46E170();
        sub_4B1600(&unk_7CE498);
        sub_461900((int)v12);
        sub_4A0AF0(&unk_7CE24C);
        v10 = (int *)&unk_5EC6E4;
        do
        {
          sub_4EF5A0(-1, 0);
          v10 += 4656;
        }
        while ( (int)v10 < (int)&dword_7C54E4 );
        v4 = 0;
        dword_5C329C = 0;
        sub_42BC80();
        byte_7C5690 = 1;
        dword_7C56A0 = 2;
        sub_497940(aClientTeamSele, -1);
        *(_DWORD *)(a1 + 228) = 0;
      }
      nullsub_3(v12);
    }
    return v4;
  }
}
