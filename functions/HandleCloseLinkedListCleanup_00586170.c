int __thiscall sub_586170(void *this)
{
  _DWORD *v2; // esi
  _DWORD *v3; // edi
  void *v4; // ebp
  int result; // eax

  if ( *((_BYTE *)this + 24) && CloseHandle(*((HANDLE *)this + 4)) )
    *((_DWORD *)this + 4) = 0;
  v2 = *(_DWORD **)this;
  if ( *(_DWORD *)this )
  {
    do
    {
      v3 = v2;
      v2 = (_DWORD *)v2[1];
      if ( *((_BYTE *)v3 + 8) )
      {
        v4 = (void *)*v3;
        if ( *v3 )
        {
          SEHGuardedFunctionWithExceptionHandling(*v3);
          FreeWrapper_7bcf(v4);
        }
      }
      FreeWrapper_7bcf(v3);
    }
    while ( v2 );
  }
  result = 0;
  *(_DWORD *)this = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  return result;
}
