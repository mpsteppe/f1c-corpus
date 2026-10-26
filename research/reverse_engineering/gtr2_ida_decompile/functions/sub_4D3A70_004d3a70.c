int __thiscall sub_4D3A70(_DWORD *this)
{
  _DWORD *v2; // esi
  void *v3; // ebx
  _DWORD *v4; // esi
  void *v5; // ebx
  _DWORD *v6; // esi
  void *v7; // ebx
  _DWORD *v8; // esi
  void *v9; // ebx
  int v10; // ecx

  v2 = (_DWORD *)this[62];
  while ( v2 )
  {
    v3 = v2;
    v2 = (_DWORD *)v2[6];
    sub_501700(v3);
    j__free(v3);
  }
  v4 = (_DWORD *)this[63];
  while ( v4 )
  {
    v5 = v4;
    v4 = (_DWORD *)v4[6];
    sub_501700(v5);
    j__free(v5);
  }
  v6 = (_DWORD *)this[64];
  while ( v6 )
  {
    v7 = v6;
    v6 = (_DWORD *)v6[6];
    sub_501700(v7);
    j__free(v7);
  }
  v8 = (_DWORD *)this[65];
  while ( v8 )
  {
    v9 = v8;
    v8 = (_DWORD *)v8[6];
    sub_501700(v9);
    j__free(v9);
  }
  while ( this[36] )
  {
    v10 = this[36];
    this[36] = *(_DWORD *)(v10 + 140);
    if ( v10 )
      (**(void (__thiscall ***)(int, int))v10)(v10, 1);
  }
  this[36] = 0;
  return sub_409FB0(this + 17);
}
