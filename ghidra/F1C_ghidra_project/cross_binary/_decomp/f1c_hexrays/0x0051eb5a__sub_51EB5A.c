// f1c  0x0051eb5a  size=20
int __cdecl sub_51EB5A(int a1)
{
  *(_DWORD *)(*(_DWORD *)a1 + 20) = 45;
  return (**(int (__cdecl ***)(int))a1)(a1);
}
