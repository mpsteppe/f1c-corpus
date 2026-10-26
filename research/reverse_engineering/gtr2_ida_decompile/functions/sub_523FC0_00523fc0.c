char sub_523FC0()
{
  const CHAR *v0; // eax
  int v1; // edi
  int v2; // ebp
  char *v3; // esi
  char *v4; // eax
  _DWORD *v5; // eax
  char *v6; // edx
  char v7; // cl
  const char *v8; // edx
  char *v9; // eax
  unsigned int v11; // [esp+Ch] [ebp-210h]
  char v12[256]; // [esp+10h] [ebp-20Ch] BYREF
  char v13[256]; // [esp+110h] [ebp-10Ch] BYREF
  int v14; // [esp+218h] [ebp-4h]

  v0 = (const CHAR *)dword_91CAC0;
  if ( !dword_91CAC0 )
    v0 = WindowName;
  sub_615860(v0);
  v14 = 0;
  v11 = strlen(WindowName);
  _mkdir(WindowName);
  if ( dword_BE1CD0 > 0 )
  {
    v1 = 0;
    v2 = dword_BE1CD0;
    do
    {
      v3 = (char *)(v1 + dword_BE1CD8 + 260);
      sub_53A250(v3);
      if ( sub_53A250(v3) )
      {
        v5 = (_DWORD *)sub_616630(off_9034CC);
        if ( v5 )
          v4 = sub_48D380(v5);
        else
          v4 = v3;
      }
      else
      {
        v4 = v3;
      }
      v6 = (char *)(v12 - v4);
      do
      {
        v7 = *v4;
        v4[(_DWORD)v6] = *v4;
        ++v4;
      }
      while ( v7 );
      sub_521240(v12);
      v9 = sub_41D840(&byte_91CC38, v8);
      sub_615A50(v9);
      sub_617930(255);
      _mkdir(v13);
      v1 += 396;
      --v2;
      WindowName[v11] = 0;
    }
    while ( v2 );
  }
  return 0;
}
