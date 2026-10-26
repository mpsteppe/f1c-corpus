char __cdecl sub_5016E0(_DWORD *a1)
{
  _DWORD *v1; // eax

  (*(void (__cdecl **)(_DWORD *))(*a1 + 8))(a1);
  LongjmpMSVCCRT(*a1 + 132, 1);
  v1 = (_DWORD *)a1[5];
  *v1 = v1[7];
  v1[1] = v1[8];
  return 1;
}

