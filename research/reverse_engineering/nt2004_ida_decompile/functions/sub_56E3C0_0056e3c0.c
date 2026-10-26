int __thiscall sub_56E3C0(_DWORD *this)
{
  void *v1; // eax
  _DWORD *v2; // edi
  DWORD v3; // eax
  _DWORD *v4; // esi
  _DWORD *v5; // eax
  bool v6; // zf
  int v7; // eax
  _DWORD *v8; // eax
  int result; // eax

  v1 = (void *)this[694];
  v2 = this + 690;
  if ( v1 && ((v3 = WaitForSingleObject(v1, this[695])) == 0 || v3 == 128) )
    v4 = v2;
  else
    v4 = 0;
  v5 = (_DWORD *)*v4;
  v6 = *v4 == 0;
  v4[2] = *v4;
  if ( !v6 && *v5 )
  {
    do
    {
      sub_5772C0(0);
      v7 = v4[2];
      if ( !v7 )
        break;
      v8 = *(_DWORD **)(v7 + 4);
      v4[2] = v8;
      if ( !v8 )
        break;
    }
    while ( *v8 );
  }
  result = v2[4];
  if ( result )
    return ReleaseMutex((HANDLE)v2[4]);
  return result;
}
