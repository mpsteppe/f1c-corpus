int __fastcall sub_41E920(int a1, char a2)
{
  int v3; // edi
  int v4; // ebp
  int v5; // eax
  char *v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // eax
  int v10; // esi
  int v11; // eax
  char *v12; // eax
  int v13; // eax
  int v15; // eax
  int v16; // esi
  int v17; // eax
  int v18; // esi
  int v19; // eax
  int v20; // edi
  int v21; // eax

  v3 = -1;
  v4 = 0;
  if ( sub_4C2850(&unk_7D2DB0) )
  {
    if ( !a1 )
      goto LABEL_6;
    v5 = sub_4C2850(&unk_7D2DB0);
    v6 = *(char **)sub_4C1390(v5);
    if ( !v6 )
      v6 = &byte_5EA438;
    if ( sub_588410(a1, v6) )
    {
LABEL_6:
      v7 = sub_4C2850(&unk_7D2DB0);
      if ( *(int *)(sub_4C1390(v7) + 408) > -1 )
      {
        v8 = sub_4C2850(&unk_7D2DB0);
        v4 = sub_4C1390(v8);
        v9 = sub_4C2850(&unk_7D2DB0);
        v3 = *(_DWORD *)(sub_4C1390(v9) + 408);
      }
    }
    v10 = 0;
    v11 = sub_4C2850(&unk_7D2DB0);
    if ( sub_4C1370(v11) > 0 )
    {
      do
      {
        sub_4C2850(&unk_7D2DB0);
        if ( *(_DWORD *)(sub_4C13A0(v10) + 408) > v3 )
        {
          if ( !a1 )
            goto LABEL_14;
          sub_4C2850(&unk_7D2DB0);
          v12 = *(char **)sub_4C13A0(v10);
          if ( !v12 )
            v12 = &byte_5EA438;
          if ( sub_588410(a1, v12) )
          {
LABEL_14:
            sub_4C2850(&unk_7D2DB0);
            v4 = sub_4C13A0(v10);
            sub_4C2850(&unk_7D2DB0);
            v3 = *(_DWORD *)(sub_4C13A0(v10) + 408);
          }
        }
        ++v10;
        v13 = sub_4C2850(&unk_7D2DB0);
      }
      while ( v10 < sub_4C1370(v13) );
    }
    if ( !a2 )
    {
      if ( !v4 )
        return 0;
      v15 = sub_4C2850(&unk_7D2DB0);
      if ( v4 != sub_4C1390(v15) )
      {
        v16 = *(_DWORD *)(v4 + 408);
        v17 = sub_4C2850(&unk_7D2DB0);
        if ( v16 == *(_DWORD *)(sub_4C1390(v17) + 408) )
          return 0;
      }
      v18 = 0;
      v19 = sub_4C2850(&unk_7D2DB0);
      if ( sub_4C1370(v19) > 0 )
      {
        while ( 1 )
        {
          sub_4C2850(&unk_7D2DB0);
          if ( v4 != sub_4C13A0(v18) )
          {
            v20 = *(_DWORD *)(v4 + 408);
            sub_4C2850(&unk_7D2DB0);
            if ( v20 == *(_DWORD *)(sub_4C13A0(v18) + 408) )
              break;
          }
          ++v18;
          v21 = sub_4C2850(&unk_7D2DB0);
          if ( v18 >= sub_4C1370(v21) )
            return v4;
        }
        return 0;
      }
    }
  }
  return v4;
}
