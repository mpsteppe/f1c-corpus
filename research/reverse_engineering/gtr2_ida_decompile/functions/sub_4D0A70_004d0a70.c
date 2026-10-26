int __thiscall sub_4D0A70(int this, int a2, int a3, int a4, int a5)
{
  int v6; // eax
  const CHAR *v7; // eax
  int retaddr; // [esp+4h] [ebp+0h]

  v6 = *(_DWORD *)(this + 244);
  if ( v6 )
  {
    if ( *(_BYTE *)(this + 100) )
      v7 = *(const CHAR **)(v6 + 88);
    else
      v7 = *(const CHAR **)(v6 + 64);
    if ( !v7 )
      v7 = WindowName;
    sub_4DF1B0(*(_DWORD *)(this + 48), v7);
  }
  return sub_4D0610(this, retaddr, a2, a3, a4);
}
