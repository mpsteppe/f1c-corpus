int __thiscall sub_416B70(void *this)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  void *v7; // edx
  int v8; // edi
  int v9; // ebp
  int v10; // eax
  int v11; // eax
  void *v12; // edx
  int v13; // edi
  int v14; // ebp
  int v15; // eax
  void *v16; // edi
  int v17; // eax
  void *v18; // edi
  int v19; // eax
  void *v20; // edi
  int v21; // eax
  void *v22; // edi
  int result; // eax
  void *v24; // edi
  int v25; // ecx
  void *v26; // [esp+8h] [ebp-4h]
  void *v27; // [esp+8h] [ebp-4h]

  if ( *((_DWORD *)this + 2) )
    sub_5BE8AE(*((LPVOID *)this + 2));
  v2 = *((_DWORD *)this + 4);
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  if ( v2 )
    sub_5BE8AE((LPVOID)(v2 - 4));
  v3 = *((_DWORD *)this + 6);
  *((_DWORD *)this + 3) = 0;
  *((_DWORD *)this + 4) = 0;
  if ( v3 )
    sub_5BE8AE((LPVOID)(v3 - 4));
  v4 = *((_DWORD *)this + 8);
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  if ( v4 )
    sub_5BE8AE((LPVOID)(v4 - 4));
  v5 = *((_DWORD *)this + 10);
  *((_DWORD *)this + 7) = 0;
  *((_DWORD *)this + 8) = 0;
  if ( v5 )
    sub_5BE8AE((LPVOID)(v5 - 4));
  v6 = *((_DWORD *)this + 11);
  if ( v6 )
  {
    v7 = (void *)(v6 - 4);
    v8 = v6 + 796 * *(_DWORD *)(v6 - 4);
    v26 = (void *)(v6 - 4);
    if ( *(_DWORD *)(v6 - 4) - 1 >= 0 )
    {
      v9 = *(_DWORD *)(v6 - 4);
      do
      {
        v8 -= 796;
        sub_416E70(v8);
        --v9;
      }
      while ( v9 );
      v7 = v26;
    }
    sub_5BE8AE(v7);
  }
  v10 = *((_DWORD *)this + 13);
  *((_DWORD *)this + 11) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 9) = 0;
  if ( v10 )
    sub_5BE8AE((LPVOID)(v10 - 4));
  v11 = *((_DWORD *)this + 14);
  if ( v11 )
  {
    v12 = (void *)(v11 - 4);
    v13 = v11 + 796 * *(_DWORD *)(v11 - 4);
    v27 = (void *)(v11 - 4);
    if ( *(_DWORD *)(v11 - 4) - 1 >= 0 )
    {
      v14 = *(_DWORD *)(v11 - 4);
      do
      {
        v13 -= 796;
        sub_416E70(v13);
        --v14;
      }
      while ( v14 );
      v12 = v27;
    }
    sub_5BE8AE(v12);
  }
  v15 = *((_DWORD *)this + 16);
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 12) = 0;
  if ( v15 )
  {
    v16 = (void *)(v15 - 4);
    sub_401030(v15, 40, *(_DWORD *)(v15 - 4), (int (__thiscall *)(int))nullsub_5);
    sub_5BE8AE(v16);
  }
  v17 = *((_DWORD *)this + 17);
  if ( v17 )
  {
    v18 = (void *)(v17 - 4);
    sub_401030(v17, 796, *(_DWORD *)(v17 - 4), sub_416E70);
    sub_5BE8AE(v18);
  }
  v19 = *((_DWORD *)this + 19);
  *((_DWORD *)this + 17) = 0;
  *((_DWORD *)this + 16) = 0;
  *((_DWORD *)this + 15) = 0;
  if ( v19 )
  {
    v20 = (void *)(v19 - 4);
    sub_401030(v19, 40, *(_DWORD *)(v19 - 4), (int (__thiscall *)(int))nullsub_5);
    sub_5BE8AE(v20);
  }
  v21 = *((_DWORD *)this + 20);
  if ( v21 )
  {
    v22 = (void *)(v21 - 4);
    sub_401030(v21, 812, *(_DWORD *)(v21 - 4), sub_416E70);
    sub_5BE8AE(v22);
  }
  result = *((_DWORD *)this + 22);
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 19) = 0;
  *((_DWORD *)this + 18) = 0;
  if ( result )
  {
    v24 = (void *)(result - 4);
    sub_401030(result, 40, *(_DWORD *)(result - 4), (int (__thiscall *)(int))nullsub_5);
    result = sub_5BE8AE(v24);
  }
  if ( *((_DWORD *)this + 23) )
    result = sub_416DF0(3);
  v25 = *((_DWORD *)this + 25);
  *((_DWORD *)this + 23) = 0;
  *((_DWORD *)this + 22) = 0;
  *((_DWORD *)this + 21) = 0;
  if ( v25 )
    result = sub_416DC0(3);
  if ( *((_DWORD *)this + 26) )
    result = sub_416DF0(3);
  *((_DWORD *)this + 26) = 0;
  *((_DWORD *)this + 25) = 0;
  *((_DWORD *)this + 24) = 0;
  return result;
}
