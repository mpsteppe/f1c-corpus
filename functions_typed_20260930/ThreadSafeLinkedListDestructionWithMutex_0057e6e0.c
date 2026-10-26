int __thiscall sub_57E6E0(_DWORD *this)
{
  void *v1; // eax
  _DWORD *v2; // ebx
  DWORD v3; // eax
  _DWORD *v4; // ebp
  _DWORD *v5; // esi
  _DWORD *v6; // edi
  int result; // eax

  v1 = (void *)this[694];
  v2 = this + 690;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[695])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v5 = (_DWORD *)*v4;
  if ( *v4 )
  {
    do
    {
      v6 = v5;
      v5 = (_DWORD *)v5[1];
      if ( *((_BYTE *)v6 + 8) && *v6 )
        (**(void (__thiscall ***)(_DWORD, int))*v6)(*v6, 1);
      FreeWrapper_7bcf(v6);
    }
    while ( v5 );
  }
  *v4 = 0;
  v4[1] = 0;
  v4[2] = 0;
  v4[3] = 0;
  result = v2[4];
  if ( result )
    return ReleaseMutex((HANDLE)v2[4]);
  return result;
}

