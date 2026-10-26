char __thiscall sub_59BA90(void ***this)
{
  void **v2; // esi
  int v3; // eax

  v2 = *this;
  v3 = sub_5A3CE0(**this);
  (*(void (__thiscall **)(int))(*(_DWORD *)v3 + 4))(v3);
  nullsub_7(*v2);
  if ( !(unsigned __int8)sub_59B980() )
    return 0;
  *this = 0;
  return 1;
}
