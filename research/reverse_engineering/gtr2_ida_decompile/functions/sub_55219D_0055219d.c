void __userpurge sub_55219D(int a1@<ecx>, int a2@<ebp>, char a3@<dil>, int a4, int a5, int a6)
{
  const CHAR *v7; // esi
  unsigned int v8; // esi
  const char *v9; // eax
  float *v10; // edi
  char *v11; // eax
  int i; // esi
  double v13; // st7
  double ArgList; // [esp+10h] [ebp-98h]
  double ArgLista; // [esp+10h] [ebp-98h]
  double ArgListb; // [esp+10h] [ebp-98h]
  char v17; // [esp+18h] [ebp-90h]
  int v18; // [esp+24h] [ebp-84h] BYREF
  char v19[4]; // [esp+28h] [ebp-80h]
  float v20; // [esp+2Ch] [ebp-7Ch]
  float v21; // [esp+30h] [ebp-78h]
  char v22[4]; // [esp+34h] [ebp-74h]
  void *Block; // [esp+38h] [ebp-70h]
  int v24; // [esp+3Ch] [ebp-6Ch]
  int v25[26]; // [esp+40h] [ebp-68h] BYREF

  v25[25] = (int)NtCurrentTeb()->NtTib.ExceptionList;
  v17 = a3;
  Block = operator new(0x100u);
  *(_BYTE *)Block = 0;
  v24 = 256;
  if ( *(_BYTE *)(a2 + 12) )
    v7 = *(const CHAR **)(a1 + 192);
  else
    v7 = *(const CHAR **)(a1 + 184);
  if ( !v7 )
    v7 = WindowName;
  sub_615860(v7);
  v8 = 22616 * *(_DWORD *)(a2 + 8);
  if ( dword_923E84[v8 / 4] != -1 )
  {
    v9 = (const char *)Block;
    if ( !Block )
      v9 = WindowName;
    v21 = COERCE_FLOAT(strlen(v9));
    if ( v21 == 0.0
      || (v10 = (float *)((char *)&unk_924FE8 + v8), !*(_BYTE *)(a2 + 12)) && v10[41] <= 0.0 && !*(_BYTE *)(a2 + 16) )
    {
      if ( Block )
        j_j__free(Block);
      return;
    }
    sub_613B30(v25);
    v11 = (char *)Block;
    if ( !Block )
      v11 = (char *)WindowName;
    if ( (unsigned __int8)sub_614810(v11, 0, 1, 1) == 1 )
    {
      sub_613D30((int)v25, "[Slot%03d]\n", *(_DWORD *)(a2 + 8));
      sub_613D30((int)v25, "Driver=%s\n", (char)&unk_9258E0 + 108 * dword_9259BC[v8 / 4] + v8);
      if ( byte_B6CBC3 )
        sub_613D30((int)v25, "Lobby Username=%s\n", (char)&unk_925C74 + v8);
      sub_613D30((int)v25, "Vehicle=%s\n", (char)&unk_9259D0 + v8);
      sub_613D30((int)v25, "Team=%s\n", (char)&unk_925A10 + v8);
      if ( !(unsigned __int8)sub_4735A0() || !(unsigned __int8)sub_4745A0(&dword_B6CBA8) && !sub_473630(&dword_B6CBA8) )
      {
        ArgList = *(float *)(v8 + 9585524);
        sub_613D30((int)v25, "Penalty=%.f\n", SLOBYTE(ArgList));
      }
      if ( v10[12] > 0.0 )
      {
        sub_6153C0(v10[12]);
        sub_613D30((int)v25, "QualTime=%d:%06.3f\n", v19[0]);
      }
      sub_613D30((int)v25, "Laps=%d\n", *((_DWORD *)v10 + 3));
      if ( byte_B72D9C || sub_473630(&dword_B6CBA8) )
      {
        for ( i = 0; i < *((_DWORD *)v10 + 3); ++i )
        {
          v13 = sub_52B860(v10, i);
          v20 = v13;
          if ( v13 > 0.0 )
          {
            sub_52B830();
            v21 = v13;
            sub_6153C0(v20);
            sub_613D30((int)v25, "Lap=(%d, %.3f, %d:%06.3f)\n", i);
          }
        }
      }
      ArgLista = v10[7];
      sub_613D30((int)v25, "LapDistanceTravelled=%f\n", SLOBYTE(ArgLista));
      if ( v10[41] > 0.0 )
      {
        sub_6153C0(v10[41]);
        sub_613D30((int)v25, "BestLap=%d:%06.3f\n", v19[0]);
      }
      switch ( *((_DWORD *)v10 + 27) )
      {
        case 0:
        case 2:
          sub_613D30((int)v25, "RaceTime=DNF\n", v17);
          sub_613D30((int)v25, "Reason=%d\n", *((_DWORD *)v10 + 28));
          break;
        case 1:
          sub_615400(v10[48], (int)&v18);
          sub_613D30((int)v25, "RaceTime=%d:%02d:%06.3f\n", v22[0]);
          break;
        case 3:
          sub_613D30((int)v25, "RaceTime=DQ\n", v17);
          break;
        default:
          break;
      }
      if ( v10[58] > 0.0 )
      {
        ArgListb = v10[58];
        sub_613D30((int)v25, "Total Fines=%.1f\n", SLOBYTE(ArgListb));
      }
      sub_613D30((int)v25, (char *)word_6F2E64, v17);
      sub_613C30(v25);
    }
    sub_614140(v25);
  }
  if ( Block )
    j_j__free(Block);
}
