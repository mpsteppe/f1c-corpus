int __cdecl sub_54E581(int a1)
{
  _DWORD *v1; // eax
  int i; // eax

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 92);
  *(_DWORD *)(a1 + 400) = v1;
  *v1 = sub_54E557;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 4) = sub_54E1FD;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 8) = sub_54E3EA;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 12) = sub_54DFF3;
  for ( i = 16; i < 80; i += 4 )
    *(_DWORD *)(i + *(_DWORD *)(a1 + 400)) = sub_54DFF3;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 16) = sub_54D552;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 72) = sub_54D78E;
  return sub_54E557((_DWORD *)a1);
}
