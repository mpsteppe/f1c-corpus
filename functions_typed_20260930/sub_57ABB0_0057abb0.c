int __stdcall sub_57ABB0(
        int a1,
        int a2,
        int a3,
        int a4,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        int a12,
        _DWORD *a13)
{
  _DWORD *v13; // edi
  _DWORD *v14; // eax
  _DWORD *v15; // esi
  void (__thiscall ***v16)(_DWORD); // eax
  int v17; // eax

  v13 = a13;
  *a13 = 0;
  LOBYTE(a13) = 0;
  v14 = (_DWORD *)OperatorNewNhMallocWrapper(4);
  if ( v14 )
    v15 = NetworkSocketObjectCreate(v14, &a1, &a13);
  else
    v15 = 0;
  if ( (_BYTE)a13 || (*(int (__thiscall **)(_DWORD))(*(_DWORD *)*v15 + 72))(*v15) )
    return 1;
  v16 = (void (__thiscall ***)(_DWORD))FieldGetter_5cc0(*v15);
  (**v16)(v16);
  EmptyStub_0170();
  *v13 = v15;
  v17 = OperatorNewNhMallocWrapper(16);
  if ( v17 )
  {
    *(_DWORD *)v17 = v15;
    *(_DWORD *)(v17 + 4) = 0;
    *(_DWORD *)(v17 + 8) = 0;
    *(_BYTE *)(v17 + 12) = 1;
  }
  else
  {
    v17 = 0;
  }
  if ( dword_8D3BFC )
  {
    *(_DWORD *)(dword_8D3C00 + 4) = v17;
    *(_DWORD *)(v17 + 8) = dword_8D3C00;
  }
  else
  {
    dword_8D3BFC = v17;
    dword_8D3C04 = v17;
  }
  dword_8D3C00 = v17;
  ++dword_8D3C08;
  return 0;
}

