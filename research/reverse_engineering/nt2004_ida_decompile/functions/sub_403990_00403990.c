int __thiscall sub_403990(int this)
{
  int v2; // eax
  int v3; // ecx
  int v4; // eax
  void *v5; // eax
  void *v6; // eax
  int v7; // ecx
  int v8; // edx
  _DWORD *v9; // eax
  int v10; // ecx
  int v11; // edx
  _DWORD *v12; // eax
  int v13; // ecx
  int v14; // edx
  _DWORD *v15; // eax
  __int64 v16; // rax
  int i; // ecx
  _DWORD *v18; // eax
  unsigned int v20; // [esp-10h] [ebp-18h]
  unsigned int v21; // [esp-8h] [ebp-10h]

  if ( *(_DWORD *)(this + 388) )
    sub_5BE8AE(*(LPVOID *)(this + 388));
  if ( *(_DWORD *)(this + 392) )
    sub_5BE8AE(*(LPVOID *)(this + 392));
  if ( *(_DWORD *)(this + 396) )
    sub_5BE8AE(*(LPVOID *)(this + 396));
  if ( *(_DWORD *)(this + 400) )
    sub_5BE8AE(*(LPVOID *)(this + 400));
  v2 = *(_DWORD *)(this + 404) + 1;
  v3 = v2 + *(_DWORD *)(this + 408);
  *(_DWORD *)(this + 68) = v2;
  v4 = *(_DWORD *)(this + 412);
  *(_DWORD *)(this + 72) = v3;
  *(_DWORD *)(this + 64) = 1;
  *(_DWORD *)(this + 76) = v4 + v3;
  v5 = operator new(28 * v4);
  v21 = 28 * *(_DWORD *)(this + 408);
  *(_DWORD *)(this + 392) = v5;
  *(_DWORD *)(this + 388) = operator new(v21);
  v6 = operator new(28 * *(_DWORD *)(this + 408));
  v20 = 28 * *(_DWORD *)(this + 412) * *(_DWORD *)(this + 416);
  *(_DWORD *)(this + 400) = v6;
  *(_DWORD *)(this + 396) = operator new(v20);
  v7 = 0;
  if ( *(int *)(this + 412) > 0 )
  {
    v8 = 0;
    do
    {
      v9 = (_DWORD *)(v8 + *(_DWORD *)(this + 392));
      *v9 = 0;
      v9[1] = 0;
      v9[2] = 0;
      v9[3] = 0;
      v9[4] = 0;
      v9[5] = 0;
      v9[6] = 0;
      ++v7;
      v8 += 28;
    }
    while ( v7 < *(_DWORD *)(this + 412) );
  }
  v10 = 0;
  if ( *(int *)(this + 408) > 0 )
  {
    v11 = 0;
    do
    {
      v12 = (_DWORD *)(v11 + *(_DWORD *)(this + 388));
      *v12 = 0;
      v12[1] = 0;
      v12[2] = 0;
      v12[3] = 0;
      v12[4] = 0;
      v12[5] = 0;
      v12[6] = 0;
      ++v10;
      v11 += 28;
    }
    while ( v10 < *(_DWORD *)(this + 408) );
  }
  v13 = 0;
  if ( *(int *)(this + 408) > 0 )
  {
    v14 = 0;
    do
    {
      v15 = (_DWORD *)(v14 + *(_DWORD *)(this + 400));
      *v15 = 0;
      v15[1] = 0;
      v15[2] = 0;
      v15[3] = 0;
      v15[4] = 0;
      v15[5] = 0;
      v15[6] = 0;
      ++v13;
      v14 += 28;
    }
    while ( v13 < *(_DWORD *)(this + 408) );
  }
  v16 = *(unsigned int *)(this + 412);
  if ( (int)v16 > 0 )
  {
    LODWORD(v16) = *(_DWORD *)(this + 416);
    do
    {
      for ( i = 0; i < (int)v16; ++i )
      {
        v18 = (_DWORD *)(*(_DWORD *)(this + 396) + 28 * (HIDWORD(v16) + i * *(_DWORD *)(this + 412)));
        *v18 = 0;
        v18[1] = 0;
        v18[2] = 0;
        v18[3] = 0;
        v18[4] = 0;
        v18[5] = 0;
        v18[6] = 0;
        LODWORD(v16) = *(_DWORD *)(this + 416);
      }
      ++HIDWORD(v16);
    }
    while ( SHIDWORD(v16) < *(_DWORD *)(this + 412) );
  }
  return v16;
}
