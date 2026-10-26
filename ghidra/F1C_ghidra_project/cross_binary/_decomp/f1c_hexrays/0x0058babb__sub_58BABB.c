// f1c  0x0058babb  size=78
int __cdecl sub_58BABB(char *a1, int a2)
{
  int v2; // edi
  int v3; // ebx
  unsigned int v5; // [esp+14h] [ebp+8h]

  v2 = sub_58E1B0(a1);
  sub_58C1B1(a2);
  v3 = sub_58E41B(a2);
  v5 = sub_5886A7(a1, 1u, v2, a2);
  sub_58E4A8(v3, a2);
  sub_58C203(a2);
  return (v5 == v2) - 1;
}
