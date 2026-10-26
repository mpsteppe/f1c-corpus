int __userpurge sub_59F010@<eax>(
        int a1@<ecx>,
        int a2@<ebp>,
        int a3@<edi>,
        int a4@<esi>,
        int a5,
        int a6,
        int a7,
        int a8,
        int a9,
        int a10,
        int a11,
        char *cp,
        int a13,
        int a14,
        int a15,
        int a16,
        int a17,
        int a18)
{
  void *v20; // eax
  DWORD v21; // eax
  void *v22; // esi
  int v23; // ebp
  int v24; // esi
  unsigned int v25; // eax
  int v26; // [esp+0h] [ebp-54h]
  _DWORD v27[14]; // [esp+Ch] [ebp-48h] BYREF
  _BYTE v28[16]; // [esp+44h] [ebp-10h] BYREF

  v27[4] = 0;
  sub_5A4030(a1);
  if ( (double)a18 * 0.001 > *(double *)(a1 + 240) )
    return 5;
  (*(void (__thiscall **)(int, int, int, int))(*(_DWORD *)a1 + 48))(a1, a3, a4, a2);
  *(double *)(a1 + 240) = 0.0;
  v20 = *(void **)(a1 + 2832);
  if ( v20 )
  {
    v21 = WaitForSingleObject(v20, *(_DWORD *)(a1 + 2836));
    if ( !v21 || v21 == 128 )
    {
      sub_59EBB0((int *)(a1 + 2816));
      v22 = *(void **)(a1 + 2832);
      if ( v22 )
        ReleaseMutex(v22);
    }
  }
  v23 = (*(int (__thiscall **)(int))(*(_DWORD *)a1 + 88))(a1);
  sub_5A6B10(v23, 0, 1, 0, 2, -1);
  qmemcpy(v27, v28, 0x30u);
  *(float *)&v27[12] = sub_5A3EA0(a1);
  sub_5A6970(v27, 52);
  if ( cp && strlen(cp) )
  {
    if ( operator new(0x10u) )
      v24 = sub_59CFD0();
    else
      v24 = 0;
    v25 = inet_addr(cp);
    if ( v25 == -1 )
    {
      (*(void (__thiscall **)(int, int))(*(_DWORD *)a1 + 92))(a1, v23);
      return 1;
    }
    *(_DWORD *)(v24 + 4) = v25;
    *(_WORD *)(v24 + 2) = *(_WORD *)(a1 + 2348);
    sub_59D660();
  }
  else
  {
    *(_BYTE *)(*(_DWORD *)(v23 + 72) + 4) = 1;
  }
  sub_5A46A0(a1, v23);
  return v26;
}
