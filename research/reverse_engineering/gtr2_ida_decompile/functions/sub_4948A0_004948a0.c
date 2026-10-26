int sub_4948A0()
{
  int result; // eax
  int v1; // ebp
  char *FileName; // eax
  const CHAR *v3; // eax
  int v4; // [esp+0h] [ebp-20h]
  int i; // [esp+8h] [ebp-18h]

  sub_4D0AC0(v4);
  result = CGarageOnline::GetFileCount((CGarageOnline *)dword_B6CBB4);
  v1 = 1;
  for ( i = result; v1 <= i; ++v1 )
  {
    FileName = CGarageOnline::GetFileName((CGarageOnline *)dword_B6CBB4, v1);
    sub_615860(FileName);
    v3 = &WindowName[strlen(WindowName)];
    if ( v3 > WindowName )
    {
      while ( *v3 != 46 )
      {
        if ( --v3 <= WindowName )
          goto LABEL_7;
      }
      *v3 = 0;
    }
LABEL_7:
    sub_4D93B0(WindowName, 0, 0, 0, 0, 0, -1, -1, -1, -1);
    result = i;
  }
  return result;
}
