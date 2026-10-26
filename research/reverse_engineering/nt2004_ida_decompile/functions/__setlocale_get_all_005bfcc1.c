char *_setlocale_get_all()
{
  char *v0; // eax
  int v1; // ebp
  const char **v2; // esi
  const char **v3; // ebx
  const char *v5; // [esp-Ch] [ebp-1Ch]

  v0 = dword_6251B4;
  v1 = 1;
  if ( !dword_6251B4 )
  {
    v0 = (char *)malloc(0x351u);
    dword_6251B4 = v0;
  }
  *v0 = 0;
  _strcats(dword_6251B4, 3);
  v2 = (const char **)&off_6251C0;
  v3 = (const char **)&off_6251C0;
  do
  {
    strcat(dword_6251B4, ";");
    v5 = v2[3];
    v2 += 3;
    if ( strcmp(*v3, v5) )
      v1 = 0;
    v3 = v2;
    _strcats(dword_6251B4, 3);
  }
  while ( (int)v2 < (int)&off_6251F0 );
  if ( !v1 )
    return dword_6251B4;
  sub_5C1B88(dword_6251B4);
  dword_6251B4 = 0;
  return (char *)off_6251CC;
}
