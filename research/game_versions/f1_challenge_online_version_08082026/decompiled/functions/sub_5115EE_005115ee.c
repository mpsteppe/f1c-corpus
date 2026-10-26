int __cdecl sub_5115EE(int a1)
{
  _DWORD *v1; // eax
  int i; // eax

  v1 = (_DWORD *)(**(int (__cdecl ***)(int, _DWORD, int))(a1 + 4))(a1, 0, 92);
  *(_DWORD *)(a1 + 400) = v1;
  *v1 = sub_5115C4;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 4) = sub_51126A;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 8) = sub_511457;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 12) = sub_511060;
  for ( i = 16; i < 80; i += 4 )
    *(_DWORD *)(i + *(_DWORD *)(a1 + 400)) = sub_511060;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 16) = sub_5105BF;
  *(_DWORD *)(*(_DWORD *)(a1 + 400) + 72) = sub_5107FB;
  return sub_5115C4((_DWORD *)a1);
}
