int __thiscall sub_47BC70(_DWORD **this)
{
  int v2; // edi
  int v3; // eax
  _DWORD *v4; // eax

  v2 = 0;
  v3 = sub_4E5DA0(&unk_76BB28);
  if ( v3 && *(_DWORD *)(v3 + 30964) == 2 )
  {
    sub_4AD720(aChampionshipSt, 1);
    v2 = -1;
  }
  v4 = (_DWORD *)(*(int (__thiscall **)(_DWORD *, int))(*this[12] + 28))(this[12], 3);
  if ( v4 )
    sub_473010(v4);
  return v2;
}
