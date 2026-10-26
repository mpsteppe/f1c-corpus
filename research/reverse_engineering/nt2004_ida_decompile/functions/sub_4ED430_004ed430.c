int __thiscall sub_4ED430(int **this)
{
  int *v1; // esi
  int v2; // edi
  int v3; // edi
  LPVOID **v4; // ecx
  int v5; // edi
  _BYTE *v6; // ebp
  _DWORD *v7; // edi
  void *v8; // ebp
  _DWORD *v9; // edi
  void *v10; // ebp
  int v11; // edi
  void *v12; // ebp
  int result; // eax

  v1 = *this;
  if ( *this )
  {
    sub_4EA920(v1);
    v2 = v1[20];
    while ( v2 )
    {
      v2 = *(_DWORD *)(v2 + 4);
      sub_4ED960(1);
    }
    v1[20] = 0;
    v1[21] = 0;
    v1[22] = 0;
    v1[23] = 0;
    v3 = v1[16];
    while ( v3 )
    {
      v4 = (LPVOID **)v3;
      v3 = *(_DWORD *)(v3 + 4);
      sub_414480(v4, 1);
    }
    v1[16] = 0;
    v1[17] = 0;
    v1[18] = 0;
    v1[19] = 0;
    v5 = v1[12];
    while ( v5 )
    {
      v6 = (_BYTE *)v5;
      v5 = *(_DWORD *)(v5 + 4);
      sub_4145A0(v6);
      sub_5BE8AE(v6);
    }
    v1[12] = 0;
    v1[13] = 0;
    v1[14] = 0;
    v1[15] = 0;
    v7 = (_DWORD *)v1[8];
    while ( v7 )
    {
      v8 = v7;
      v7 = (_DWORD *)v7[1];
      sub_4EDB70(v8);
      sub_5BE8AE(v8);
    }
    v1[8] = 0;
    v1[9] = 0;
    v1[10] = 0;
    v1[11] = 0;
    v9 = (_DWORD *)v1[4];
    while ( v9 )
    {
      v10 = v9;
      v9 = (_DWORD *)v9[1];
      sub_4EDA70(v10);
      sub_5BE8AE(v10);
    }
    v1[4] = 0;
    v1[5] = 0;
    v1[6] = 0;
    v1[7] = 0;
    v11 = *v1;
    while ( v11 )
    {
      v12 = (void *)v11;
      v11 = *(_DWORD *)(v11 + 4);
      sub_4ED9A0(v12);
      sub_5BE8AE(v12);
    }
    *v1 = 0;
    v1[1] = 0;
    v1[2] = 0;
    v1[3] = 0;
    return sub_5BE8AE(v1);
  }
  return result;
}
