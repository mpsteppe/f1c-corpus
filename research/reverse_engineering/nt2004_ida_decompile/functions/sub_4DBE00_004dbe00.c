int __thiscall sub_4DBE00(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // ebx
  _DWORD **v3; // edi
  char v4; // al
  int *v5; // esi
  int v6; // edx
  void *v7; // ebp
  char *v8; // esi
  int v9; // edi
  int result; // eax
  _DWORD **v11; // [esp+8h] [ebp-Ch]
  int *v12; // [esp+Ch] [ebp-8h]

  v1 = this;
  v2 = *this;
  while ( v2 )
  {
    v3 = (_DWORD **)v2;
    v4 = *(_BYTE *)(v2 + 8);
    v2 = *(_DWORD *)(v2 + 4);
    v11 = v3;
    if ( v4 )
    {
      v5 = *v3;
      v12 = *v3;
      if ( *v3 )
      {
        v6 = *v5;
        if ( *v5 )
        {
          v7 = (void *)(v6 - 4);
          if ( *(_DWORD *)(v6 - 4) - 1 >= 0 )
          {
            v8 = (char *)(v6 + 572 * *(_DWORD *)(v6 - 4) + 148);
            v9 = *(_DWORD *)(v6 - 4);
            do
            {
              v8 -= 572;
              nullsub_6(v8);
              --v9;
            }
            while ( v9 );
            v3 = v11;
            v5 = v12;
          }
          sub_5BE8AE(v7);
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
