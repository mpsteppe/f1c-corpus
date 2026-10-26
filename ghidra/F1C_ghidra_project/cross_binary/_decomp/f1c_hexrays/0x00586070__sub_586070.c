// f1c  0x00586070  size=251
int __fastcall sub_586070(_DWORD *a1)
{
  int result; // eax
  _DWORD *v2; // ebp
  _DWORD *v3; // esi
  _BYTE *v4; // edi
  void *v5; // ebx
  _DWORD *v6; // edi
  _BYTE *v7; // ebx
  int *v8; // ebp
  int v9; // eax
  void *v10; // esi
  _DWORD *v11; // [esp+10h] [ebp-14h]

  v11 = a1;
  result = 0;
  v2 = a1 + 4;
  v3 = (_DWORD *)a1[4];
  if ( v3 )
  {
    do
    {
      v4 = v3;
      v3 = (_DWORD *)v3[1];
      if ( v4[8] )
      {
        v5 = *(void **)v4;
        if ( *(_DWORD *)v4 )
        {
          nullsub_3();
          sub_587BCF(v5);
        }
      }
      sub_587BCF(v4);
      result = 0;
    }
    while ( v3 );
    a1 = v11;
  }
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v6 = (_DWORD *)*a1;
  if ( *a1 )
  {
    do
    {
      v7 = v6;
      v6 = (_DWORD *)v6[1];
      if ( v7[8] )
      {
        v8 = *(int **)v7;
        if ( *(_DWORD *)v7 )
        {
          v9 = *v8;
          if ( *v8 )
          {
            v10 = (void *)(v9 - 4);
            sub_58A5F7(v9, 1048, *(_DWORD *)(v9 - 4), nullsub_3);
            sub_587BCF(v10);
          }
          sub_587BCF(v8);
        }
      }
      sub_587BCF(v7);
    }
    while ( v6 );
    a1 = v11;
    result = 0;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
