int __fastcall sub_41EB30(int a1, char a2)
{
  int v2; // eax
  int v3; // esi
  int v4; // eax
  int v5; // ebp
  int result; // eax
  int v7; // ebx
  int i; // edi
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // esi
  int v13; // eax
  int v14; // eax
  char *v15; // eax
  int v16; // ebx
  int v17; // eax
  int j; // esi
  int v19; // edi
  char *v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // ecx
  int v24; // esi
  int v25; // eax
  int v27; // [esp+14h] [ebp-74h]
  _DWORD v29[26]; // [esp+20h] [ebp-68h] BYREF

  v27 = 0;
  if ( sub_4C2850(&unk_7D2DB0) )
  {
    v2 = sub_4C2850(&unk_7D2DB0);
    v3 = sub_4C11D0(v2);
    v4 = sub_4C2850(&unk_7D2DB0);
    v5 = sub_4C1370(v4);
    result = 0;
    memset(v29, 0, sizeof(v29));
    if ( v3 < 2 )
      return result;
    v7 = v3 - 1;
    for ( i = 0; i < v7; ++i )
    {
      v9 = sub_4C2850(&unk_7D2DB0);
      v10 = sub_4C1390(v9);
      v11 = sub_41ED20(v10, i);
      v12 = 0;
      v29[0] += v11;
      if ( v5 > 0 )
      {
        do
        {
          sub_4C2850(&unk_7D2DB0);
          v13 = sub_4C13A0(v12);
          v29[++v12] += sub_41ED20(v13, i);
        }
        while ( v12 < v5 );
      }
    }
    if ( !a1 )
      goto LABEL_11;
    v14 = sub_4C2850(&unk_7D2DB0);
    v15 = *(char **)sub_4C1390(v14);
    if ( !v15 )
      v15 = &byte_5EA438;
    if ( !sub_588410(v15, a1) )
    {
      v16 = 0;
    }
    else
    {
LABEL_11:
      v16 = v29[0];
      v17 = sub_4C2850(&unk_7D2DB0);
      v27 = sub_4C1390(v17);
    }
    for ( j = 0; j < v5; ++j )
    {
      v19 = v29[j + 1];
      if ( v19 > v16 )
      {
        if ( !a1 )
          goto LABEL_19;
        sub_4C2850(&unk_7D2DB0);
        v20 = *(char **)sub_4C13A0(j);
        if ( !v20 )
          v20 = &byte_5EA438;
        if ( sub_588410(v20, a1) )
        {
LABEL_19:
          sub_4C2850(&unk_7D2DB0);
          v27 = sub_4C13A0(j);
          v16 = v19;
        }
      }
    }
    v21 = sub_4C2850(&unk_7D2DB0);
    v22 = sub_4C1390(v21);
    v23 = v27;
    if ( v27 != v22 && v16 == v29[0] )
      return a2 != 0 ? v23 : 0;
    v24 = 0;
    if ( v5 > 0 )
    {
      while ( 1 )
      {
        sub_4C2850(&unk_7D2DB0);
        v25 = sub_4C13A0(v24);
        v23 = v27;
        if ( v27 != v25 && v16 == v29[v24 + 1] )
          break;
        if ( ++v24 >= v5 )
          return v27;
      }
      return a2 != 0 ? v23 : 0;
    }
  }
  return v27;
}
