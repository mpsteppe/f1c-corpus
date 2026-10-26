int __userpurge sub_5A6190@<eax>(void *a1@<ecx>, int a2@<ebp>, int a3)
{
  int v4; // edi
  int v6; // ebp
  int i; // edi
  int v8; // eax
  int v9; // ebp
  int j; // edi

  if ( (unsigned __int8)sub_5A6BF0(a3) )
  {
    v4 = 2;
    if ( a3 )
    {
      sub_5A46A0(a1, a3);
      v4 = 0;
    }
    (*(void (__thiscall **)(void *))(*(_DWORD *)a1 + 56))(a1);
    return v4;
  }
  else
  {
    if ( *(_BYTE *)(*(_DWORD *)(a3 + 72) + 4) )
    {
      v6 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)a1 + 164))(a1, a2);
      for ( i = 0; i < v6; ++i )
      {
        v8 = (*(int (__thiscall **)(void *, int))(*(_DWORD *)a1 + 172))(a1, i);
        if ( v8 )
        {
          sub_5A6E90(v8);
          sub_5A60F0();
        }
      }
    }
    else
    {
      v9 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a3 + 72) + 20))(*(_DWORD *)(a3 + 72), a2);
      for ( j = 0; j < v9; ++j )
      {
        (*(void (__thiscall **)(_DWORD, int))(**(_DWORD **)(a3 + 72) + 24))(*(_DWORD *)(a3 + 72), j);
        sub_5A60F0();
      }
    }
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)a1 + 92))(a1, a3);
    return 1;
  }
}
