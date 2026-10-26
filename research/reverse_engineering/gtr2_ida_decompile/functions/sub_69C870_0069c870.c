_DWORD *__thiscall sub_69C870(int this, _DWORD *a2)
{
  _DWORD *v4; // eax
  _DWORD *v5; // edi
  int v6; // eax
  _DWORD *v7; // eax

  if ( !*(_DWORD *)(this + 24) )
    return 0;
  v4 = (_DWORD *)sub_65B229(36);
  if ( v4 )
    v5 = sub_67F53B(v4);
  else
    v5 = 0;
  if ( !v5 )
    return 0;
  v5[4] = 1;
  v6 = *(_DWORD *)(this + 24);
  if ( a2 )
  {
    if ( *(_DWORD *)(v6 + 32) )
      v5[5] = sub_69C457((char *)this, 21, *(_DWORD **)(v6 + 44), a2, 1);
    else
      sub_694B97(
        this,
        this + 32,
        3079,
        "'%s': void functions cannot return a value",
        *(_DWORD *)(*(_DWORD *)(this + 16) + 20));
  }
  else if ( *(_DWORD *)(v6 + 32) )
  {
    sub_694B97(this, this + 32, 3080, "'%s': function must return a value", *(_DWORD *)(*(_DWORD *)(this + 16) + 20));
  }
  v7 = (_DWORD *)sub_65B229(20);
  if ( v7 )
    return sub_67ED1B(v7, (int)v5, 0, (int)"Stmts");
  else
    return 0;
}
