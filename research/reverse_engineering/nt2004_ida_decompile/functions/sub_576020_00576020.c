int __fastcall sub_576020(_DWORD *a1)
{
  int result; // eax
  _DWORD *v2; // ebp
  int v3; // esi
  int v4; // edi
  int v5; // edi
  int v6; // ebx
  void **v7; // ebp
  _DWORD *v8; // [esp+10h] [ebp-14h]

  v8 = a1;
  result = 0;
  v2 = a1 + 4;
  v3 = a1[4];
  if ( v3 )
  {
    do
    {
      v4 = v3;
      v3 = *(_DWORD *)(v3 + 4);
      if ( *(_BYTE *)(v4 + 8) && *(_DWORD *)v4 )
      {
        nullsub_6(*(void **)v4);
        sub_5BE8AE();
      }
      sub_5BE8AE();
      result = 0;
    }
    while ( v3 );
    a1 = v8;
  }
  *v2 = 0;
  v2[1] = 0;
  v2[2] = 0;
  v2[3] = 0;
  v5 = *a1;
  if ( *a1 )
  {
    do
    {
      v6 = v5;
      v5 = *(_DWORD *)(v5 + 4);
      if ( *(_BYTE *)(v6 + 8) )
      {
        v7 = *(void ***)v6;
        if ( *(_DWORD *)v6 )
        {
          if ( *v7 )
          {
            `eh vector destructor iterator'(*v7, 0x418u, *((_DWORD *)*v7 - 1), nullsub_6);
            sub_5BE8AE();
          }
          sub_5BE8AE();
        }
      }
      sub_5BE8AE();
    }
    while ( v5 );
    a1 = v8;
    result = 0;
  }
  *a1 = 0;
  a1[1] = 0;
  a1[2] = 0;
  a1[3] = 0;
  return result;
}
