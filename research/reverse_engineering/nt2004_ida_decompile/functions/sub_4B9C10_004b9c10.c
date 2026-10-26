int sub_4B9C10()
{
  const char *v0; // eax
  int v1; // eax
  _DWORD *v2; // esi
  int v3; // eax
  int v4; // ebx
  int v5; // ebp
  int v6; // edi
  int v7; // eax
  int v8; // edi
  int v9; // ebx
  int v10; // ebp
  int j; // edi
  int v12; // eax
  const char *v13; // eax
  _DWORD *v14; // esi
  _DWORD *v15; // edi
  int i; // [esp+8h] [ebp-108h]
  int v18; // [esp+Ch] [ebp-104h]
  char Buffer[256]; // [esp+10h] [ebp-100h] BYREF

  sub_419110(byte_6292D0);
  sub_4CE950(&unk_7663E0);
  if ( sub_42DBA0() && *(_DWORD *)(dword_75AACC + 20884) == 1 && dword_7688E8 == 1 )
  {
    v0 = (const char *)dword_62A0A8;
    if ( !dword_62A0A8 )
      v0 = &byte_629120;
    sprintf(Buffer, "%s%s", v0, aWinraceBik);
    sub_527460(Buffer, 1);
  }
  v1 = sub_4E5DA0(&unk_76BB28);
  v2 = (_DWORD *)v1;
  if ( v1 )
  {
    sub_4E4ED0(v1);
    if ( sub_4E5CB0(&unk_76BB28) == 3 )
    {
      sub_4E6000(&unk_76BB28);
      v3 = sub_4E4C50(v2);
      v4 = v3;
      if ( v3 && !*(_DWORD *)(v3 + 612) )
      {
        v5 = 0;
        v18 = 0;
        v6 = 0;
        if ( sub_4B15C0(v2) > 0 )
        {
          do
          {
            v7 = sub_4E48E0(v6);
            if ( v7 >= 0 && *(_DWORD *)(v4 + 4 * v7 + 224) == 1 )
              ++v5;
            ++v6;
          }
          while ( v6 < sub_4B15C0(v2) );
          v18 = v5;
        }
        v8 = 0;
        for ( i = 0; v8 < sub_4E4C30(v2); i = ++v8 )
        {
          v9 = sub_4E4C60(v8);
          if ( !*(_DWORD *)(v9 + 612) )
          {
            v10 = 0;
            for ( j = 0; j < sub_4B15C0(v2); ++j )
            {
              v12 = sub_4E48E0(j);
              if ( v12 >= 0 && *(_DWORD *)(v9 + 4 * v12 + 224) == 1 )
                ++v10;
            }
            if ( v10 > v18 )
              goto LABEL_32;
            v8 = i;
          }
        }
        sub_4E61C0(&unk_76BB28);
        if ( dword_7688E8 == 1 )
        {
          v13 = (const char *)dword_62A0A8;
          if ( !dword_62A0A8 )
            v13 = &byte_629120;
          sprintf(Buffer, "%s%s", v13, aChampGordonBik);
          sub_527460(Buffer, 1);
        }
      }
    }
    else
    {
      sub_4E6000(&unk_76BB28);
      sub_4E5D60(&unk_76BB28);
    }
  }
LABEL_32:
  if ( dword_7655CC )
  {
    v14 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7655CC + 28))(dword_7655CC, 17);
    v15 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7655CC + 28))(dword_7655CC, 19);
    if ( v14 )
      sub_48E120(v14, 1);
    if ( v15 )
      sub_48E120(v15, 0);
  }
  nullsub_6(&unk_629328);
  dword_608F60 = 3;
  return 0;
}
