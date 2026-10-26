int sub_501510()
{
  int result; // eax
  int i; // esi
  _DWORD *v2; // edi
  bool v3; // zf
  int v4; // esi
  _DWORD **v5; // ebp

  result = sub_502280(&dword_7D7978);
  for ( i = dword_7D79C0; i; result = sub_5BE8AE() )
  {
    v2 = (_DWORD *)i;
    v3 = *(_BYTE *)(i + 8) == 0;
    i = *(_DWORD *)(i + 4);
    if ( !v3 && *v2 )
    {
      sub_506920(*v2);
      sub_5BE8AE();
    }
  }
  v4 = dword_7D7978;
  dword_7D79C0 = 0;
  dword_7D79C4 = 0;
  dword_7D79C8 = 0;
  for ( dword_7D79CC = 0; v4; result = sub_5BE8AE() )
  {
    v5 = (_DWORD **)v4;
    v3 = *(_BYTE *)(v4 + 8) == 0;
    v4 = *(_DWORD *)(v4 + 4);
    if ( !v3 && *v5 )
    {
      if ( **v5 )
        sub_5BE8AE();
      sub_5BE8AE();
    }
  }
  dword_7D7978 = 0;
  dword_7D797C = 0;
  dword_7D7980 = 0;
  dword_7D7984 = 0;
  return result;
}
