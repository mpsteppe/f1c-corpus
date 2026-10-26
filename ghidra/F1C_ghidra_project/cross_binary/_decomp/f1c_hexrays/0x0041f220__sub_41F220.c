// f1c  0x0041f220  size=288
int __fastcall sub_41F220(int a1, int a2)
{
  int v4; // eax
  int v5; // ebp
  int i; // edi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int j; // esi
  int v12; // eax
  int v13; // [esp+Ch] [ebp-58h]
  _BYTE v15[80]; // [esp+14h] [ebp-50h] BYREF

  v4 = sub_4C2850(&unk_7D2DB0);
  v5 = 0;
  v13 = sub_4C1370(v4);
  if ( !a1 )
    return -1;
  if ( a2 == -1 )
  {
    sub_4C2850(&unk_7D2DB0);
    return sub_4C13C0(a1);
  }
  else
  {
    for ( i = 0; i < a2; ++i )
    {
      v8 = sub_4C2850(&unk_7D2DB0);
      sub_4C1390(v8);
      sub_4C0A20(v15, 80);
      if ( sub_566810(v15, a1) )
      {
        v9 = sub_4C2850(&unk_7D2DB0);
        v10 = sub_4C1390(v9);
        v5 += sub_41ED20(v10, i);
      }
      for ( j = 0; j < v13; ++j )
      {
        sub_4C2850(&unk_7D2DB0);
        sub_4C13A0(j);
        sub_4C0A20(v15, 80);
        if ( sub_566810(v15, a1) )
        {
          sub_4C2850(&unk_7D2DB0);
          v12 = sub_4C13A0(j);
          v5 += sub_41ED20(v12, i);
        }
      }
    }
    return v5;
  }
}
