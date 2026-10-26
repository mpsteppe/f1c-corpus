int __stdcall sub_59B880(
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
        int **a13)
{
  int **v13; // edi
  int *v14; // eax
  int *v15; // esi
  void (__thiscall ***v16)(_DWORD); // eax

  v13 = a13;
  *a13 = 0;
  LOBYTE(a13) = 0;
  v14 = (int *)operator new(4u);
  if ( v14 )
    v15 = sub_59B310(v14, &a1, &a13);
  else
    v15 = 0;
  if ( (_BYTE)a13 || (*(int (__thiscall **)(int))(*(_DWORD *)*v15 + 72))(*v15) )
    return 1;
  v16 = (void (__thiscall ***)(_DWORD))sub_5A3CE0(*v15);
  (**v16)(v16);
  nullsub_7((void *)*v15);
  *v13 = v15;
  sub_524350(dword_FB22B8, (int)v15, 1);
  return 0;
}
