int __fastcall sub_47CA00(int a1, int a2)
{
  char v3; // bl
  int v4; // ebp
  int v5; // eax
  int v6; // eax
  char *v7; // eax
  int v9; // eax
  char *v10; // edi
  char v11; // [esp+0h] [ebp-94h]
  char v12; // [esp+10h] [ebp-84h]
  char ArgList[125]; // [esp+14h] [ebp-80h] BYREF
  __int16 v14; // [esp+91h] [ebp-3h]
  char v15; // [esp+93h] [ebp-1h]

  v3 = 0;
  v4 = -1;
  v12 = 0;
  if ( *(float *)(a1 + 268) > 0.0 )
  {
    v3 = 1;
    v12 = 1;
    *(float *)(a1 + 268) = *(float *)(a1 + 268) - sub_4AE720(*(_DWORD *)(a1 + 48), a2);
  }
  v5 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 10);
  if ( v5 && sub_49FB50(v5) < 0 )
  {
    v3 = 1;
    v12 = 1;
  }
  (*(void (__thiscall **)(int, char))(*(_DWORD *)a1 + 36))(a1, v12);
  if ( v3
    && (ArgList[0] = byte_629120,
        memset(&ArgList[1], 0, 0x7Cu),
        v14 = 0,
        v15 = 0,
        (v6 = sub_464740(dword_764D70, (int)ArgList)) != 0) )
  {
    v7 = sub_4647B0(v6);
    sub_578600(v7);
    sub_4AD720(aJoinFailurePag, 1);
    *(_DWORD *)(a1 + 268) = 0;
    return -1;
  }
  else
  {
    if ( sub_4633A0(dword_764D70) == 3 )
    {
      sub_462C80(ArgList);
      if ( sub_464BD0(dword_764D70, (int)ArgList) )
      {
        if ( dword_75CBA8 != 5 )
        {
          if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_28, 10164) )
            sub_500FE0((int)&unk_7D7920, aJoinSessionWas, v11);
          if ( dword_75CBA8 != 5 )
          {
            if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_28, 10165) )
              sub_500FE0((int)&unk_7D7920, aSessionNameS, (char)ArgList);
            if ( dword_75CBA8 != 5 )
            {
              if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_28, 10166) )
                sub_500FE0((int)&unk_7D7920, aSceneBaseS, (char)&ArgList[32]);
              if ( dword_75CBA8 != 5 )
              {
                if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_28, 10167) )
                  sub_500FE0((int)&unk_7D7920, aAiOppD, ArgList[68]);
                if ( dword_75CBA8 != 5 )
                {
                  if ( (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_28, 10168) )
                    sub_500FE0((int)&unk_7D7920, aHumanOppD, ArgList[69]);
                  if ( dword_75CBA8 != 5
                    && (unsigned __int8)sub_500F90((int)&unk_7D7920, 2, (int)aDDevNascar2004_28, 10169) )
                  {
                    sub_500FE0((int)&unk_7D7920, aMaxPlayersD, ArgList[70]);
                  }
                }
              }
            }
          }
        }
        v9 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 10);
        if ( v9 )
          sub_49FEC0(v9);
        sub_47CD10();
        byte_7654A8 = 0;
        sub_462FE0((int)ArgList);
        v10 = (char *)&unk_62BFBC;
        do
        {
          sub_51BC20(-1, 0);
          v10 += 25304;
        }
        while ( (int)v10 < (int)byte_75483C );
        v4 = 0;
        NumOfElements = 0;
        sub_42DC40();
        byte_75AB9C = 1;
        dword_75CBAC = 2;
        sub_4AD720(aClientVehicleS, 1);
        *(_DWORD *)(a1 + 268) = 0;
      }
      nullsub_6(ArgList);
    }
    return v4;
  }
}
