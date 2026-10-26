int __thiscall sub_5750B0(_DWORD *this)
{
  void *v2; // eax
  _DWORD *v3; // ebp
  DWORD v4; // eax
  int *v5; // edi
  int v6; // esi
  void *v7; // ecx
  int v8; // eax
  int result; // eax
  int v10; // [esp+10h] [ebp-4h] BYREF

  while ( sub_574D40(this, &v10) )
    (*(void (__thiscall **)(_DWORD *, int))(*this + 92))(this, v10);
  v2 = (void *)this[362];
  v3 = this + 358;
  if ( v2 && ((v4 = WaitForSingleObject(v2, this[363])) == 0 || v4 == 128) )
    v5 = this + 358;
  else
    v5 = 0;
LABEL_8:
  while ( v5[3] > 0 )
  {
    v6 = *v5;
    if ( !*v5 )
      break;
    v7 = *(void **)v6;
    if ( !*(_DWORD *)v6 )
      break;
    v8 = 0;
    if ( v6 )
    {
      while ( *(void **)v6 != v7 )
      {
        v8 = v6;
        v6 = *(_DWORD *)(v6 + 4);
        if ( !v6 )
          goto LABEL_8;
      }
      if ( v6 == v5[2] )
        v5[2] = *(_DWORD *)(v6 + 4);
      if ( v8 )
        *(_DWORD *)(v8 + 4) = *(_DWORD *)(v6 + 4);
      else
        *v5 = *(_DWORD *)(v6 + 4);
      if ( v5[1] == v6 )
        v5[1] = v8;
      --v5[3];
      if ( *(_BYTE *)(v6 + 8) )
      {
        if ( *(_DWORD *)v6 )
        {
          sub_576830(*(void **)v6);
          sub_5BE8AE();
        }
      }
      sub_5BE8AE();
    }
  }
  result = v3[4];
  if ( result )
    return ReleaseMutex((HANDLE)v3[4]);
  return result;
}
