_DWORD *__thiscall sub_4C11E0(_DWORD *this, int a2)
{
  _DWORD *v3; // eax
  char *v4; // eax
  _DWORD *v5; // eax
  char *v6; // eax
  int v7; // esi
  int v8; // eax
  int v9; // eax
  int v10; // eax
  int v11; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  _DWORD *result; // eax

  if ( !sub_568210(aSceneorder) )
    return 0;
  v3 = (_DWORD *)sub_5679A0(a2);
  if ( !v3 )
    return 0;
  v4 = sub_499E20(v3);
  v5 = (_DWORD *)sub_4C5840(v4);
  if ( !v5 )
    return 0;
  v6 = sub_499E20(v5);
  sub_4C55B0(v6);
  v7 = dword_8AC490 + 396 * dword_8AC48C;
  sub_566650(v7 + 260);
  sub_566650(v7 + 4);
  v8 = sub_5679C0(aQualifylaps);
  if ( v8 )
  {
    v9 = sub_567970(v8);
    this[11340] = sub_587ECE(v9);
  }
  else
  {
    this[11340] = -1;
  }
  v10 = sub_5679C0(aQualifytime);
  if ( v10 )
  {
    v11 = sub_567970(v10);
    this[11341] = sub_587ECE(v11);
  }
  else
  {
    this[11341] = -1;
  }
  v12 = sub_5679C0(aRacelaps);
  if ( v12 )
  {
    v13 = sub_567970(v12);
    this[11342] = sub_587ECE(v13);
  }
  else
  {
    this[11342] = -1;
  }
  v14 = sub_5679C0(aRacetime);
  if ( v14 )
  {
    v15 = sub_567970(v14);
    this[11343] = sub_587ECE(v15);
  }
  else
  {
    this[11343] = -1;
  }
  if ( a2 >= this[11346] )
  {
    result = this + 11336;
    this[11344] = -1;
  }
  else
  {
    this[11344] = this[a2 + 11233];
    return this + 11336;
  }
  return result;
}
