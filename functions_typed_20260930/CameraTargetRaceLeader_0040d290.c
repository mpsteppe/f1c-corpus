int __thiscall sub_40D290(_DWORD *this, char a2)
{
  int v3; // eax

  v3 = GetTeamIDByFinishPosition(*(_DWORD *)(dword_7C54F0[dword_7C54DC] + 18580), 2 * (a2 != 0) - 1);
  return GameStateDispatchChain(this, v3);
}

