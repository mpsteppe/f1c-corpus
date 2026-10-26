int __thiscall sub_59F1D0(_DWORD *this)
{
  void *v1; // eax
  _DWORD *v2; // edi
  DWORD v3; // eax
  _DWORD *v4; // ebx
  _DWORD *v5; // eax
  bool v6; // zf
  int v7; // ebp
  _DWORD *v8; // esi
  _DWORD *v9; // ecx
  void *v10; // eax
  void *v11; // esi
  int result; // eax
  _DWORD *v13; // [esp+8h] [ebp-8h]

  v1 = (void *)this[708];
  v2 = this + 704;
  v13 = this + 704;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[709])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v5 = (_DWORD *)*v4;
  v6 = *v4 == 0;
  v4[2] = *v4;
  if ( !v6 )
  {
    v7 = *v5;
    while ( v7 )
    {
      v8 = v5;
      v9 = 0;
      if ( v5 )
      {
        while ( *v8 != v7 )
        {
          v9 = v8;
          v8 = (_DWORD *)v8[1];
          if ( !v8 )
            goto LABEL_28;
        }
        if ( v8 == (_DWORD *)v4[2] )
          v4[2] = v8[1];
        if ( v9 )
          v9[1] = v8[1];
        else
          *v4 = v8[1];
        if ( (_DWORD *)v4[1] == v8 )
          v4[1] = v9;
        --v4[3];
        if ( *((_BYTE *)v8 + 8) && *v8 )
          (*(void (__thiscall **)(_DWORD, int))(*(_DWORD *)*v8 + 4))(*v8, 1);
        j__free(v8);
        v10 = (void *)this[759];
        if ( v10 )
          WaitForSingleObject(v10, this[760]);
        (*(void (__thiscall **)(int))(*(_DWORD *)v7 + 8))(v7);
        sub_5E5780(v7, 0);
        v11 = (void *)this[759];
        if ( v11 )
          ReleaseMutex(v11);
        v5 = (_DWORD *)*v4;
        v6 = *v4 == 0;
        v2 = v13;
        v4[2] = *v4;
        if ( v6 )
          break;
        v7 = *v5;
      }
LABEL_28:
      ;
    }
  }
  result = v2[4];
  if ( result )
    return ReleaseMutex((HANDLE)v2[4]);
  return result;
}
