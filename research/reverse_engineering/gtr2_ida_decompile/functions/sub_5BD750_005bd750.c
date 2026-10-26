void __userpurge sub_5BD750(int a1@<ecx>, int a2@<edi>, int a3)
{
  int v5; // esi
  bool v6; // cc
  int v7; // eax
  int v8; // esi
  int j; // edi
  int v10; // [esp-4h] [ebp-14h]
  int v11; // [esp+0h] [ebp-10h]
  int v12; // [esp+Ch] [ebp-4h]
  int i; // [esp+14h] [ebp+4h]

  v5 = *(_DWORD *)a1;
  if ( a3 <= *(_DWORD *)a1 )
  {
    v12 = a3;
    if ( a3 < v5 )
    {
      v7 = 12 * a3;
      v10 = a2;
      for ( i = 12 * a3; ; v7 = i )
      {
        v8 = v7 + *(_DWORD *)(a1 + 8);
        for ( j = 0; j < *(_DWORD *)v8; ++j )
          (**(void (__thiscall ***)(int, _DWORD))(*(_DWORD *)(v8 + 8) + 8 * j))(*(_DWORD *)(v8 + 8) + 8 * j, 0);
        sub_4F14D0(v10);
        sub_5A8D10(*(void **)(v8 + 8));
        v6 = ++v12 < *(_DWORD *)a1;
        i += 12;
        if ( !v6 )
          break;
      }
    }
    *(_DWORD *)a1 = a3;
  }
  else
  {
    v6 = *(_DWORD *)(a1 + 4) < a3;
    *(_DWORD *)a1 = a3;
    if ( v6 )
    {
      sub_4F14D0(v11);
      *(_DWORD *)(a1 + 8) = sub_5A8CF0(*(void **)(a1 + 8), 12 * a3, 2, 16, 2);
      *(_DWORD *)(a1 + 4) = a3;
    }
    for ( ; v5 < a3; ++v5 )
      sub_5BC520((_DWORD *)a1, v5);
  }
}
