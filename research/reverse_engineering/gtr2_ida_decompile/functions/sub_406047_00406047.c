// positive sp value has been detected, the output may be wrong!
void __thiscall sub_406047(void *this)
{
  void **v2; // edi
  _DWORD *v3; // eax
  int j; // ebx
  void (__thiscall ***v5)(_DWORD, int); // ecx
  _DWORD **v6; // ecx
  _DWORD *v7; // eax
  bool v8; // zf
  _DWORD *v9; // edi
  _DWORD **v10; // ecx
  _DWORD *v11; // eax
  _DWORD *v12; // ecx
  _DWORD *v13; // edi
  int i; // [esp+8h] [ebp+0h]

  *(_DWORD *)this = &off_6F1988;
  v2 = (void **)*((_DWORD *)this + 5);
  for ( i = 2; v2 != *((void ***)this + 6); ++v2 )
  {
    v3 = *v2;
    for ( j = 0; j < *(_DWORD *)(*((_DWORD *)*v2 + 1) + 360); ++j )
    {
      j_j__free(*(void **)(v3[5] + 4 * j));
      v3 = *v2;
    }
    j_j__free(*((void **)*v2 + 2));
    j_j__free(*((void **)*v2 + 5));
    j__free(*v2);
  }
  v5 = (void (__thiscall ***)(_DWORD, int))*((_DWORD *)this + 2);
  if ( v5 )
  {
    (**v5)(v5, 1);
    *((_DWORD *)this + 2) = 0;
  }
  v6 = (_DWORD **)*((_DWORD *)this + 12);
  v7 = *v6;
  *v6 = v6;
  *(_DWORD *)(*((_DWORD *)this + 12) + 4) = *((_DWORD *)this + 12);
  v8 = v7 == *((_DWORD **)this + 12);
  *((_DWORD *)this + 13) = 0;
  if ( !v8 )
  {
    do
    {
      v9 = (_DWORD *)*v7;
      j__free(v7);
      v7 = v9;
    }
    while ( v9 != *((_DWORD **)this + 12) );
  }
  j__free(*((void **)this + 12));
  *((_DWORD *)this + 12) = 0;
  v10 = (_DWORD **)*((_DWORD *)this + 9);
  v11 = *v10;
  *v10 = v10;
  *(_DWORD *)(*((_DWORD *)this + 9) + 4) = *((_DWORD *)this + 9);
  v12 = (_DWORD *)*((_DWORD *)this + 9);
  *((_DWORD *)this + 10) = 0;
  if ( v11 != v12 )
  {
    do
    {
      v13 = (_DWORD *)*v11;
      j__free(v11);
      v11 = v13;
    }
    while ( v13 != *((_DWORD **)this + 9) );
  }
  j__free(*((void **)this + 9));
  *((_DWORD *)this + 9) = 0;
  if ( *((_DWORD *)this + 5) )
    j__free(*((void **)this + 5));
  *((_DWORD *)this + 5) = 0;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 0;
}
