void __usercall sub_5BD6E0(int a1@<ecx>, int a2@<edi>)
{
  int v3; // ebp
  int v4; // esi
  int v5; // eax
  int v6; // esi
  int v7; // edi
  int v8; // [esp-8h] [ebp-14h]
  int v9; // [esp+0h] [ebp-Ch]
  int v10; // [esp+8h] [ebp-4h]

  v3 = 0;
  v10 = 0;
  if ( *(int *)a1 > 0 )
  {
    v8 = a2;
    do
    {
      v4 = *(_DWORD *)(a1 + 8);
      v5 = *(_DWORD *)(v4 + v3);
      v6 = v3 + v4;
      v7 = 0;
      if ( v5 > 0 )
      {
        do
        {
          (**(void (__thiscall ***)(int, _DWORD))(*(_DWORD *)(v6 + 8) + 8 * v7))(*(_DWORD *)(v6 + 8) + 8 * v7, 0);
          ++v7;
        }
        while ( v7 < *(_DWORD *)v6 );
      }
      sub_4F14D0(v8);
      sub_5A8D10(*(void **)(v6 + 8));
      v3 += 12;
      ++v10;
    }
    while ( v10 < *(_DWORD *)a1 );
  }
  sub_4F14D0(v9);
  sub_5A8D10(*(void **)(a1 + 8));
}
