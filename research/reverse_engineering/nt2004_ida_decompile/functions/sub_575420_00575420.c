char __thiscall sub_575420(_DWORD *dwData, int a2)
{
  int v3; // edi
  int v5; // [esp+8h] [ebp-4h] BYREF

  (*(void (__thiscall **)(_DWORD *))(*dwData + 60))(dwData);
  sub_575E50((ULONG_PTR)dwData, 0);
  if ( !sub_574EA0(dwData, &v5) )
    return 0;
  v3 = v5;
  sub_576EE0(v5);
  (*(void (__thiscall **)(_DWORD *, int))(*dwData + 92))(dwData, v3);
  return 1;
}
