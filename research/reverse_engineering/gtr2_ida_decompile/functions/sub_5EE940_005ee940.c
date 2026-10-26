int __thiscall sub_5EE940(void *this, char **a2, char *ArgList, char a4)
{
  char *v4; // eax
  char *v5; // esi
  int v7; // [esp+0h] [ebp-20h]

  v4 = (char *)operator new(0x13Cu);
  v5 = 0;
  if ( v4 )
    v5 = sub_5EE7D0(v4);
  if ( ArgList )
  {
    if ( sub_5EE330((int)v5, ArgList) )
    {
      if ( v5 )
      {
        sub_5EE840(v5, (__int32)v5, v7);
        j__free(v5);
      }
      sub_5D8C80((int)this, (char *)0xFFFFFFFF, "Error opening MAS file %s", (char)ArgList);
      return -1;
    }
    sub_5FDFB0(v5, 1);
  }
  *(_DWORD *)v5 |= a4 != 0 ? 8 : 0;
  if ( a2 )
    *a2 = v5;
  return 0;
}
