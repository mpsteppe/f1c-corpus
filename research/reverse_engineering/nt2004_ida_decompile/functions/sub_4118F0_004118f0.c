char *__thiscall sub_4118F0(void *this)
{
  int v2; // esi
  unsigned __int8 v3; // al
  unsigned int v4; // edx
  int v5; // edi
  int v6; // eax

  (**(void (__thiscall ***)(int))dword_76BB24)(dword_76BB24);
  v2 = sub_57AE50(aReputationlabe);
  if ( !v2 )
    return aGood;
  v3 = (*(int (__thiscall **)(void *))(*(_DWORD *)this + 68))(this);
  v4 = v3;
  if ( v3 )
  {
    if ( v3 > 0x64u )
      v4 = 100;
  }
  else
  {
    v4 = 1;
  }
  v5 = sub_40C570(v2, v4);
  if ( v5 < 0 || v5 >= sub_57A6E0(v2) )
    return aGood;
  v6 = sub_57A700(v5);
  return (char *)sub_57A6D0(v6);
}
