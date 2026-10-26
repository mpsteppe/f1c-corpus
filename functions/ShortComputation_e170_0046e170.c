int sub_46E170()
{
  int v0; // eax
  int result; // eax

  v0 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 36);
  if ( v0 )
    StateCleanupNotification(v0);
  result = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_7CD8C0 + 28))(dword_7CD8C0, 35);
  if ( result )
    return StateCleanupNotification(result);
  return result;
}
