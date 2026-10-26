int __thiscall sub_5998D0(void *this, const char *a2, int a3, int a4, _BYTE *a5, _BYTE *a6, int a7)
{
  char *v8; // esi
  int v9; // eax
  _DWORD *v11; // eax
  int v12; // ebp
  int v13; // edx
  int v14; // edi
  _DWORD *v15; // eax
  int v16; // edi
  char *v17; // ebp
  _DWORD *v18; // ebx
  int v19; // edi
  char *v20; // ecx
  int v21; // [esp+10h] [ebp-8h]

  v8 = 0;
  v21 = 0;
  v9 = sub_59A660(a2);
  if ( v9 && (a4 & 0x100) == 0 )
  {
    ++*(_DWORD *)(v9 + 136);
    return 0;
  }
  v11 = operator new(0xC4u);
  if ( v11 )
    v8 = (char *)sub_598460(v11);
  sub_598540(v8, a2, (int)this);
  v12 = (int)a6;
  v13 = *((_DWORD *)v8 + 43) + 1;
  *((_DWORD *)v8 + 43) = v13;
  if ( a6 && *a6 )
  {
    v21 = 1;
    *((_DWORD *)v8 + 43) = v13 + 1;
  }
  v14 = *((_DWORD *)v8 + 43);
  v15 = operator new(148 * v14 + 4);
  if ( v15 )
  {
    *v15 = v14;
    v16 = v14 - 1;
    v17 = (char *)(v15 + 1);
    v18 = v15 + 1;
    if ( v16 >= 0 )
    {
      v19 = v16 + 1;
      do
      {
        sub_5A1B00(v18);
        v18 += 37;
        --v19;
      }
      while ( v19 );
    }
    v20 = v17;
    v12 = (int)a6;
  }
  else
  {
    v20 = 0;
  }
  *((_DWORD *)v8 + 44) = v20;
  if ( a5 && *a5 )
  {
    sub_5A1B80(v20, (int)a5);
    if ( sub_599310(v8, 0) )
      return -1;
  }
  else if ( sub_5994E0(v8, 0) )
  {
    return -1;
  }
  if ( v21 )
  {
    sub_5A1B80((char *)(*((_DWORD *)v8 + 44) + 148), v12);
    if ( sub_599350(v8, 1) )
      return -1;
  }
  *(_DWORD *)(*((_DWORD *)v8 + 44) + 64) = a4;
  *((_DWORD *)v8 + 39) = a3;
  sub_599A70(v8);
  *((_DWORD *)v8 + 39) |= 3u;
  return 0;
}
