_DWORD *__userpurge sub_5BE617@<eax>(int a1@<ecx>, int a2@<edi>, _DWORD *a3, int a4, _DWORD *a5, int a6)
{
  int v7; // edi
  int v8; // eax
  _DWORD *v9; // esi

  v7 = a6;
  (*(void (__thiscall **)(int, int *, int))(*(_DWORD *)a6 + 4))(a6, &a6, 4);
  v8 = a6;
  if ( a6 > 0 )
  {
    if ( *(_DWORD *)(a1 + 48) < a6 + 1 )
    {
      *(_DWORD *)(a1 + 48) = a6 + 1;
      sub_4F14D0(a2);
      *(_DWORD *)(a1 + 44) = sub_5A8CF0(*(void **)(a1 + 44), *(_DWORD *)(a1 + 48), 500, 16, 0);
      v8 = a6;
    }
    (*(void (__thiscall **)(int, _DWORD, int))(*(_DWORD *)v7 + 4))(v7, *(_DWORD *)(a1 + 44), v8);
    *(_BYTE *)(a4 + *(_DWORD *)(a1 + 44)) = 0;
    sub_4050C0(*(_DWORD *)(a1 + 44));
    v9 = a3;
    sub_5A8A10();
    sub_5A8840();
  }
  else
  {
    v9 = a5;
    *a5 = &off_6F197C;
    a5[1] = 0;
    a5[2] = 0;
    a5[3] = 0;
    sub_5A8860(a5, 0, 0);
  }
  return v9;
}
