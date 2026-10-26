void __cdecl sub_5C1B88(LPVOID lpMem)
{
  int block; // eax
  bool v2; // zf
  int v3; // eax
  int v4; // [esp+Ch] [ebp-28h] BYREF
  int v5; // [esp+10h] [ebp-24h]
  int v6; // [esp+14h] [ebp-20h] BYREF
  int v7; // [esp+18h] [ebp-1Ch]
  CPPEH_RECORD ms_exc; // [esp+1Ch] [ebp-18h]

  if ( lpMem )
  {
    if ( dword_8003C8 == 3 )
    {
      _lock(9);
      ms_exc.registration.TryLevel = 0;
      block = __sbh_find_block(lpMem);
      v7 = block;
      if ( block )
        sub_5CB301(block, lpMem);
      ms_exc.registration.TryLevel = -1;
      _unlock(9);
      v2 = v7 == 0;
    }
    else
    {
      if ( dword_8003C8 != 2 )
      {
LABEL_11:
        HeapFree(hHeap, 0, lpMem);
        return;
      }
      _lock(9);
      ms_exc.registration.TryLevel = 1;
      v3 = sub_5CC031(lpMem, &v4, &v6);
      v5 = v3;
      if ( v3 )
        sub_5CC088(v4, v6, v3);
      ms_exc.registration.TryLevel = -1;
      _unlock(9);
      v2 = v5 == 0;
    }
    if ( !v2 )
      return;
    goto LABEL_11;
  }
}
