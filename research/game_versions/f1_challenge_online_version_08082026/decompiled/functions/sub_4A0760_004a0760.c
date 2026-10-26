int sub_4A0760()
{
  const char *v0; // eax
  int v1; // eax
  int v2; // esi
  int v3; // eax
  const char *v4; // eax
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  _BYTE v8[256]; // [esp+0h] [ebp-100h] BYREF

  if ( dword_5EB10C )
    (*(void (__thiscall **)(int))(*(_DWORD *)dword_5EB10C + 12))(dword_5EB10C);
  sub_4186A0(flt_5EA618);
  sub_4B17B0(&unk_7CE498);
  if ( sub_42BC10() && *(_DWORD *)(dword_7C54E8 + 16480) == 1 && dword_7D032C == 1 )
  {
    v0 = (const char *)dword_5EC418;
    if ( !dword_5EC418 )
      v0 = byte_5EA438;
    sub_58815F(v8, "%s%s", v0, aWinraceBik);
    sub_4F9B70(v8, 1);
  }
  v1 = sub_4C2850(&unk_7D2DB0);
  v2 = v1;
  if ( v1 )
  {
    sub_4C15A0(v1);
    if ( sub_4C2760(&unk_7D2DB0) == 3 )
    {
      v3 = sub_4C1390(v2);
      if ( v3 )
      {
        if ( !*(_DWORD *)(v3 + 412) )
        {
          sub_4C2C10(&unk_7D2DB0);
          if ( dword_7D032C == 1 )
          {
            v4 = (const char *)dword_5EC418;
            if ( !dword_5EC418 )
              v4 = byte_5EA438;
            sub_58815F(v8, "%s%s", v4, aWindriversBik);
            sub_4F9B70(v8, 1);
          }
        }
      }
    }
    else
    {
      sub_4C2A80(&unk_7D2DB0);
      sub_4C2810(&unk_7D2DB0);
    }
  }
  v5 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 40);
  v6 = (_DWORD *)(*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 42);
  if ( v5 )
    sub_47C360(v5, 1);
  if ( v6 )
    sub_47C360(v6, 0);
  sub_41DAF0();
  dword_5CC9E8 = 3;
  return 0;
}
