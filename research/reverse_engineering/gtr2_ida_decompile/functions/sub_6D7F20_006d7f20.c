int __userpurge sub_6D7F20@<eax>(int a1@<ebx>, int *a2, int a3, _BYTE *a4, int a5)
{
  int v5; // eax
  int v6; // eax

  if ( (*a4 & 7) != 0 )
  {
    v5 = *a2;
    *(_DWORD *)(v5 + 20) = 2;
    (*(void (__stdcall **)(int *, int))(v5 + 4))(a2, -1);
    return sub_6D7850((int)a2, a3, (int)a4, a5);
  }
  v6 = a2[49];
  if ( v6 != 5 && v6 != 6 )
    return sub_6D7850((int)a2, a3, (int)a4, a5);
  return sub_6D78E0((int)a2, a3, a1, (int)a4, a5);
}
