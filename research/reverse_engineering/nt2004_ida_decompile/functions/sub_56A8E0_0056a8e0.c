int __stdcall sub_56A8E0(
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
        void ***a13)
{
  void ***v13; // edi
  _DWORD *v14; // eax
  void **v15; // esi
  void (__thiscall ***v16)(_DWORD); // eax
  void ***v17; // eax

  v13 = a13;
  *a13 = 0;
  LOBYTE(a13) = 0;
  v14 = operator new(4u);
  if ( v14 )
    v15 = (void **)sub_56A150(v14, &a1, &a13);
  else
    v15 = 0;
  if ( (_BYTE)a13 || (*(int (__thiscall **)(void *))(*(_DWORD *)*v15 + 72))(*v15) )
    return 1;
  v16 = (void (__thiscall ***)(_DWORD))sub_575D30(*v15);
  (**v16)(v16);
  nullsub_6(*v15);
  *v13 = v15;
  v17 = (void ***)operator new(0x10u);
  if ( v17 )
  {
    *v17 = v15;
    v17[1] = 0;
    v17[2] = 0;
    *((_BYTE *)v17 + 12) = 1;
  }
  else
  {
    v17 = 0;
  }
  if ( dword_7E05EC )
  {
    *(_DWORD *)(dword_7E05F0 + 4) = v17;
    v17[2] = (void **)dword_7E05F0;
  }
  else
  {
    dword_7E05EC = (int)v17;
    dword_7E05F4 = (int)v17;
  }
  dword_7E05F0 = (int)v17;
  ++dword_7E05F8;
  return 0;
}
