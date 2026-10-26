int __thiscall sub_585040(_DWORD *this)
{
  void *v2; // eax
  _DWORD *v3; // ebp
  DWORD v4; // eax
  _DWORD *v5; // edi
  _DWORD *v6; // esi
  int v7; // ecx
  _DWORD *v8; // eax
  void *v9; // ebx
  int result; // eax
  int v11; // [esp+10h] [ebp-4h] BYREF

  while ( sub_584CD0(this, &v11) )
    (*(void (__thiscall **)(_DWORD *, int))(*this + 92))(this, v11);
  v2 = (void *)this[362];
  v3 = this + 358;
  if ( v2 && ((v4 = WaitForSingleObject(v2, this[363])) == 0 || v4 == 128) )
    v5 = this + 358;
  else
    v5 = 0;
LABEL_8:
  while ( (int)v5[3] > 0 )
  {
    v6 = (_DWORD *)*v5;
    if ( !*v5 )
      break;
    v7 = *v6;
    if ( !*v6 )
      break;
    v8 = 0;
    if ( v6 )
    {
      while ( *v6 != v7 )
      {
        v8 = v6;
        v6 = (_DWORD *)v6[1];
        if ( !v6 )
          goto LABEL_8;
      }
      if ( v6 == (_DWORD *)v5[2] )
        v5[2] = v6[1];
      if ( v8 )
        v8[1] = v6[1];
      else
        *v5 = v6[1];
      if ( (_DWORD *)v5[1] == v6 )
        v5[1] = v8;
      --v5[3];
      if ( *((_BYTE *)v6 + 8) )
      {
        v9 = (void *)*v6;
        if ( *v6 )
        {
          SEHGuardedFunctionWithExceptionHandling(*v6);
          FreeWrapper_7bcf(v9);
        }
      }
      FreeWrapper_7bcf(v6);
    }
  }
  result = v3[4];
  if ( result )
    return ReleaseMutex((HANDLE)v3[4]);
  return result;
}

