int __thiscall sub_47BC90(_DWORD **this)
{
  const char *v2; // ebp
  unsigned int v3; // kr04_4
  int v4; // edi
  int i; // esi
  int v6; // eax

  v2 = (const char *)*this[56];
  if ( !v2 )
    v2 = byte_5EA438;
  v3 = strlen(v2) + 1;
  v4 = 1;
  for ( i = 0; ; i = v6 )
  {
    v6 = MenuCursorNavigationHelper((int)this, i);
    if ( i == v6 || v6 == v3 - 1 && v2[v6 - 1] != -1 )
      break;
    ++v4;
  }
  return v4;
}
