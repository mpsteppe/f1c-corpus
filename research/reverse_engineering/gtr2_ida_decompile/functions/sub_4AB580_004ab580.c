int __thiscall sub_4AB580(int this)
{
  int v2; // eax
  int v3; // edi
  const char *v4; // eax
  int v5; // eax

  v2 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(this + 48) + 28))(*(_DWORD *)(this + 48), 53);
  v3 = v2;
  if ( !v2 || !sub_4CE170(v2) )
    return 0;
  v4 = *(const char **)(this + 596);
  if ( !v4 )
    v4 = WindowName;
  if ( strcmp((const char *)sub_4CE170(v3), v4) )
  {
    v5 = sub_4CE170(v3);
    sub_615860(v5);
    sub_497510(this, this);
  }
  return 0;
}
