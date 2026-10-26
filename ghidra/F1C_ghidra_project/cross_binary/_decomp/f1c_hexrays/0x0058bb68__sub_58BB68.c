// f1c  0x0058bb68  size=238
SIZE_T __cdecl sub_58BB68(_DWORD *lpMem)
{
  int v1; // esi
  bool v2; // zf
  unsigned __int8 *v3; // eax
  _BYTE v5[4]; // [esp+Ch] [ebp-2Ch] BYREF
  unsigned __int8 *v6; // [esp+10h] [ebp-28h]
  _BYTE v7[4]; // [esp+14h] [ebp-24h] BYREF
  int v8; // [esp+18h] [ebp-20h]
  int v9; // [esp+1Ch] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+20h] [ebp-18h]

  if ( dword_8D4908 == 3 )
  {
    sub_58DFEA(9);
    ms_exc.registration.TryLevel = 0;
    v9 = sub_593E1B(lpMem);
    if ( v9 )
    {
      v1 = *(lpMem - 1) - 9;
      v8 = v1;
    }
    else
    {
      v1 = v8;
    }
    ms_exc.registration.TryLevel = -1;
    sub_58E04B(9);
    v2 = v9 == 0;
  }
  else
  {
    if ( dword_8D4908 != 2 )
      return HeapSize(hHeap, 0, lpMem);
    sub_58DFEA(9);
    ms_exc.registration.TryLevel = 1;
    v3 = (unsigned __int8 *)sub_594B76(lpMem, v5, v7);
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
    sub_58E04B(9);
    v2 = v6 == 0;
  }
  if ( v2 )
    return HeapSize(hHeap, 0, lpMem);
  return v1;
}
