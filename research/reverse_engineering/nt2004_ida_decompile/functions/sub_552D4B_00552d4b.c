int __cdecl sub_552D4B(int a1)
{
  int result; // eax

  sub_552B43((int *)a1);
  sub_552CB9(a1);
  (**(void (__cdecl ***)(int))(a1 + 404))(a1);
  (**(void (__cdecl ***)(int))(a1 + 388))(a1);
  result = *(_DWORD *)(*(_DWORD *)(a1 + 388) + 4);
  **(_DWORD **)(a1 + 396) = result;
  return result;
}
