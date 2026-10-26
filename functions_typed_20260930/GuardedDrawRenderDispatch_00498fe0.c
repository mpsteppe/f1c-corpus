int __usercall GuardedDrawRenderDispatch@<eax>(int a1@<ecx>, int a2@<edi>)
{
  int **v3; // eax
  _DWORD *i; // edi
  int v6; // [esp-10h] [ebp-14h]
  int v7; // [esp-Ch] [ebp-10h]
  int v8; // [esp-8h] [ebp-Ch]
  int v9; // [esp-4h] [ebp-8h]

  if ( *(_DWORD *)(a1 + 96) )
  {
    if ( (*(unsigned __int8 (__thiscall **)(int, int))(*(_DWORD *)a1 + 40))(a1, a2) )
    {
      v9 = *(_DWORD *)(a1 + 8) - *(_DWORD *)(a1 + 4);
      v8 = *(_DWORD *)(a1 + 16) - *(_DWORD *)(a1 + 12);
      v7 = *(_DWORD *)(a1 + 4);
      v6 = *(_DWORD *)(a1 + 12);
      v3 = (int **)Accessor();
      RenderSurfaceFillCopy(v3, v6, v7, v8, v9);
    }
    RenderDispatchWithIteration(*(_DWORD **)(a1 + 80));
    for ( i = *(_DWORD **)(a1 + 76); i; i = (_DWORD *)StructFieldAccessor(i) )
      (*(void (__thiscall **)(_DWORD *))(*i + 68))(i);
    (*(void (__thiscall **)(int, _DWORD))(*(_DWORD *)a1 + 44))(a1, 0);
  }
  return 0;
}

