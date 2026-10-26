int __thiscall sub_48FA60(int this, int a2, int a3, int a4, int a5)
{
  int v5; // eax
  const CHAR *v6; // eax
  void *retaddr; // [esp+4h] [ebp+0h]

  v5 = *(_DWORD *)(this + 244);
  if ( v5 )
  {
    if ( *(_BYTE *)(this + 280) )
      v6 = *(const CHAR **)(v5 + 72);
    else
      v6 = *(const CHAR **)(v5 + 64);
    if ( !v6 )
      v6 = WindowName;
    sub_4DF1B0(*(_DWORD *)(this + 48), v6);
  }
  return sub_4D0610(retaddr, a2, a3, a4);
}
