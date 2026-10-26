char __thiscall sub_5853B0(_DWORD *dwData, int a2)
{
  int v3; // edi
  int v5; // [esp+8h] [ebp-4h] BYREF

  (*(void (__thiscall **)(_DWORD *))(*dwData + 60))(dwData);
  QueueUserAPCAsyncProcedureCall((ULONG_PTR)dwData, 0);
  if ( !sub_584E30(dwData, &v5) )
    return 0;
  v3 = v5;
  ShortComputation_6e50(v5);
  (*(void (__thiscall **)(_DWORD *, int))(*dwData + 92))(dwData, v3);
  return 1;
}
