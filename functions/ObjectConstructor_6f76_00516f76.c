int __cdecl sub_516F76(int a1)
{
  int v1; // eax

  v1 = (**(int (__cdecl ***)(int, int, int))(a1 + 4))(a1, 1, 28);
  *(_DWORD *)(a1 + 380) = v1;
  *(_BYTE *)(v1 + 8) = 0;
  *(_DWORD *)v1 = UIControlStateMachine;
  *(_DWORD *)(v1 + 4) = PhysicsStepCounterIncrement;
  return sub_516C7B(a1);
}
