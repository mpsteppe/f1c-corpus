int __thiscall sub_4DBD50(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // ebx
  _DWORD **v3; // esi
  char v4; // al
  int *v5; // edi
  int v6; // ecx
  void *v7; // ebp
  char *v8; // esi
  int v9; // edi
  int result; // eax
  int *v11; // [esp+8h] [ebp-Ch]
  _DWORD **v12; // [esp+Ch] [ebp-8h]

  v1 = this;
  v2 = *this;
  while ( v2 )
  {
    v3 = (_DWORD **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    v12 = v3;
    if ( v4 )
    {
      v5 = *v3;
      v11 = *v3;
      if ( *v3 )
      {
        v6 = *v5;
        if ( *v5 )
        {
          v7 = (void *)(v6 - 4);
          v8 = (char *)(v6 + 436 * *(_DWORD *)(v6 - 4));
          if ( *(_DWORD *)(v6 - 4) - 1 >= 0 )
          {
            v9 = *(_DWORD *)(v6 - 4);
            do
            {
              v8 -= 436;
              nullsub_6(v8);
              --v9;
            }
            while ( v9 );
            v5 = v11;
          }
          sub_5BE8AE(v7);
          v3 = v12;
          v1 = this;
        }
        sub_5BE8AE(v5);
      }
    }
    sub_5BE8AE(v3);
  }
  result = 0;
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}
