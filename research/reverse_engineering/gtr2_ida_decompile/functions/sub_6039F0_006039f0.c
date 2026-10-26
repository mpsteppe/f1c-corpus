int __userpurge sub_6039F0@<eax>(_DWORD **a1@<ecx>, int *a2, int a3, int a4, int a5)
{
  int v6; // ebx
  int v7; // ebp
  int v9; // [esp+28h] [ebp-10h]

  v6 = sub_5E7150(a2, a3);
  if ( !v6 )
    goto LABEL_15;
  v7 = sub_5E7150(a2, a4);
  if ( !v7 )
    goto LABEL_15;
  if ( a3 != 4 )
  {
    if ( a3 == 8 && a4 == 4 )
    {
      if ( (*(_BYTE *)a2 & 0x40) == 0 )
      {
        sub_5D8C80(
          (int)(a1 + 1),
          (char *)0xFFFFFFFF,
          "Update texture: Source texture is not a render target - video to system.",
          v9);
        return -1;
      }
      if ( ((int (__thiscall *)(_DWORD **, int *, int *, _DWORD, int, int))(*a1)[3])(a1, a2, &a4, 0, 8, 2)
        || ((int (__thiscall *)(_DWORD **, int *, int *, _DWORD, int, int))(*a1)[3])(a1, a2, &a3, 0, 4, 2) )
      {
        sub_5D8C80(
          (int)(a1 + 1),
          (char *)0xFFFFFFFF,
          "Update texture: Error getting surface ptrs - video to system.",
          v9);
        return -1;
      }
      if ( (*(int (__stdcall **)(_DWORD *, int, int, int))(*a1[2387] + 128))(a1[2387], a4, a3, v9) )
      {
        ((void (__thiscall *)(_DWORD **, int *, int))(*a1)[4])(a1, a2, a5);
        ((void (__thiscall *)(_DWORD **, int *, int, int))(*a1)[4])(a1, a2, a3, 4);
        sub_5D8C80((int)(a1 + 1), (char *)0xFFFFFFFF, "HW error during texture refresh - video to system.", 8);
        return -1;
      }
      ((void (__thiscall *)(_DWORD **, int *, int))(*a1)[4])(a1, a2, a5);
      ((void (__thiscall *)(_DWORD **, int *, int, int))(*a1)[4])(a1, a2, a3, 4);
    }
LABEL_15:
    *a2 |= 0x100u;
    return 0;
  }
  if ( a4 != 8 )
    goto LABEL_15;
  (*(void (__stdcall **)(int, _DWORD))(*(_DWORD *)v6 + 84))(v6, 0);
  if ( !(*(int (__stdcall **)(_DWORD *, int, int))(*a1[2387] + 124))(a1[2387], v6, v7) )
    goto LABEL_15;
  sub_5D8C80((int)(a1 + 1), (char *)0xFFFFFFFF, "HW error during texture refresh - system to video.", v9);
  return -1;
}
