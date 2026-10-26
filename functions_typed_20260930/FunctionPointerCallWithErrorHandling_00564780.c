int __fastcall sub_564780(int a1, int a2)
{
  int v4; // ebx
  int v5; // eax

  v4 = (*(int (__fastcall **)(int, _DWORD))(a1 + 12))(a2, *(_DWORD *)(a1 + 4));
  v5 = BufferIndexComputation(*(_DWORD *)(a1 + 16), 0, 0);
  if ( v5 == -1 )
    return SingleFunctionCallWrapper_48c0(*(_DWORD *)(*(_DWORD *)a1 + 4 * v4), a2);
  else
    return CallChainWrapper(v5);
}

