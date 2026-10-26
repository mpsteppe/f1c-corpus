int __thiscall sub_4BB5A0(_DWORD *this)
{
  _DWORD *v1; // ebp
  int v2; // ebx
  _DWORD **v3; // edi
  char v4; // al
  int *v5; // esi
  int v6; // edx
  void *v7; // ebp
  int v8; // esi
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
            v8 = v6 + 1016 * *(_DWORD *)(v6 - 4) + 144;
            v9 = *(_DWORD *)(v6 - 4);
            do
            {
              v8 -= 1016;
              nullsub_3();
              --v9;
            }
            while ( v9 );
            v3 = v11;
            v5 = v12;
          }
          sub_587BCF(v7);
          v1 = this;
        }
        sub_587BCF(v5);
      }
    }
    sub_587BCF(v3);
  }
  result = 0;
  *v1 = 0;
  v1[1] = 0;
  v1[2] = 0;
  v1[3] = 0;
  return result;
}
