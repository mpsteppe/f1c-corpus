int __userpurge sub_585270@<eax>(_DWORD *a1@<ecx>, int a2@<edi>, int a3)
{
  _BYTE *v5; // ecx
  int v6; // ebp
  int i; // edi
  int v8; // eax
  int v9; // eax
  int v10; // ebp
  int j; // edi
  int v12; // eax

  if ( (unsigned __int8)sub_586CA0(a3) )
    return sub_585380(a3);
  v5 = *(_BYTE **)(a3 + 72);
  if ( v5[4] )
  {
    v6 = (*(int (__thiscall **)(_DWORD *, int))(*a1 + 164))(a1, a2);
    for ( i = 0; i < v6; ++i )
    {
      v8 = (*(int (__thiscall **)(_DWORD *, int))(*a1 + 168))(a1, i);
      if ( v8 )
      {
        v9 = sub_5871F0(v8);
        sub_584130(a1, a3, v9);
      }
    }
  }
  else
  {
    v10 = (*(int (__thiscall **)(_BYTE *, int))(*(_DWORD *)v5 + 20))(v5, a2);
    for ( j = 0; j < v10; ++j )
    {
      v12 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a3 + 72) + 24))(*(_DWORD *)(a3 + 72), j);
      sub_584130(a1, a3, v12);
    }
  }
  (*(void (__thiscall **)(_DWORD *, int))(*a1 + 92))(a1, a3);
  return 1;
}
