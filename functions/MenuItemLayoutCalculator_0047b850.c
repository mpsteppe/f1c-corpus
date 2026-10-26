int __thiscall sub_47B850(_DWORD *this, int a2, int a3)
{
  int v4; // ecx
  int v6; // ebp
  int v7; // edi
  int v8; // edi
  int i; // ebx
  int v10; // eax
  int v11; // ecx
  char *v12; // ecx
  int v13; // [esp+14h] [ebp+4h]

  v4 = this[61];
  if ( v4 <= 0 )
    return 0;
  v6 = a2 - this[62] - this[3];
  v7 = (a3 - this[63] - this[1]) / v4;
  if ( v7 >= 0 )
  {
    if ( v7 > this[60] - 1 )
      v7 = this[60] - 1;
  }
  else
  {
    v7 = 0;
  }
  v8 = this[59] + v7;
  for ( i = 0; ; i = v10 )
  {
    v10 = MenuCursorNavigationHelper((int)this, i);
    v13 = v10;
    if ( i == v10 )
      return i;
    if ( !v8 )
      break;
    --v8;
  }
  v11 = this[50];
  if ( v11 )
  {
    v12 = *(char **)(v11 + 64);
    if ( !v12 )
      v12 = byte_5EA438;
    sub_498560(v12);
    v10 = v13;
  }
  return MenuItemRenderHelper(v6, i, v10);
}
