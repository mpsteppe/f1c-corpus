char __thiscall sub_41FC60(void *this)
{
  int v2; // eax
  int v3; // edi
  int v4; // eax
  int v5; // esi
  int v6; // eax
  int v7; // eax
  int v8; // edi
  int v9; // eax
  int v10; // ebx
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  _BYTE v16[80]; // [esp+10h] [ebp-50h] BYREF

  v2 = sub_4C2850(&unk_7D2DB0);
  sub_4C1390(v2);
  sub_4C0A20(v16, 80);
  if ( sub_566810(v16, this) && (v3 = 0, v4 = sub_4C2850(&unk_7D2DB0), sub_4C11D0(v4) > 0) )
  {
    v5 = 216;
    while ( 1 )
    {
      v6 = sub_4C2850(&unk_7D2DB0);
      if ( *(_DWORD *)(v5 + sub_4C1390(v6)) == 10 )
        break;
      ++v3;
      v5 += 4;
      v7 = sub_4C2850(&unk_7D2DB0);
      if ( v3 >= sub_4C11D0(v7) )
        goto LABEL_6;
    }
  }
  else
  {
LABEL_6:
    v8 = 0;
    v9 = sub_4C2850(&unk_7D2DB0);
    if ( sub_4C1370(v9) <= 0 )
      return 0;
    while ( 1 )
    {
      sub_4C2850(&unk_7D2DB0);
      sub_4C13A0(v8);
      sub_4C0A20(v16, 80);
      if ( sub_566810(v16, this) )
      {
        v10 = 0;
        v11 = sub_4C2850(&unk_7D2DB0);
        if ( sub_4C11D0(v11) > 0 )
          break;
      }
LABEL_12:
      ++v8;
      v14 = sub_4C2850(&unk_7D2DB0);
      if ( v8 >= sub_4C1370(v14) )
        return 0;
    }
    v12 = 216;
    while ( 1 )
    {
      sub_4C2850(&unk_7D2DB0);
      if ( *(_DWORD *)(v12 + sub_4C13A0(v8)) == 10 )
        break;
      ++v10;
      v12 += 4;
      v13 = sub_4C2850(&unk_7D2DB0);
      if ( v10 >= sub_4C11D0(v13) )
        goto LABEL_12;
    }
  }
  return 1;
}
