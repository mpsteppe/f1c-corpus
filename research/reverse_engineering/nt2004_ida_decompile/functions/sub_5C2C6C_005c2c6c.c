SIZE_T __cdecl sub_5C2C6C(_DWORD *lpMem)
{
  int v1; // esi
  bool v2; // zf
  unsigned __int8 *v3; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int8 *v6; // [esp+10h] [ebp-28h]
  _BYTE v7[4]; // [esp+14h] [ebp-24h] BYREF
  int v8; // [esp+18h] [ebp-20h]
  int block; // [esp+1Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  if ( dword_8003C8 == 3 )
  {
    _lock(9);
    ms_exc.registration.TryLevel = 0;
    block = __sbh_find_block(lpMem);
    if ( block )
    {
      v1 = *(lpMem - 1) - 9;
      v8 = v1;
    }
    else
    {
      v1 = v8;
    }
    ms_exc.registration.TryLevel = -1;
    _unlock(9);
    v2 = block == 0;
  }
  else
  {
    if ( dword_8003C8 != 2 )
      return HeapSize(hHeap, 0, lpMem);
    _lock(9);
    ms_exc.registration.TryLevel = 1;
    v3 = (unsigned __int8 *)sub_5CC031(lpMem, v5, v7);
    v6 = v3;
    if ( v3 )
    {
      v1 = 16 * *v3;
      v8 = v1;
    }
    else
    {
      v1 = v8;
    }
    ms_exc.registration.TryLevel = -1;
    _unlock(9);
    v2 = v6 == 0;
  }
  if ( v2 )
    return HeapSize(hHeap, 0, lpMem);
  return v1;
}
