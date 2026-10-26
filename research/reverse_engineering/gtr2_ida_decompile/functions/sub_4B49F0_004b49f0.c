int __usercall sub_4B49F0@<eax>(int *a1@<ecx>, __int32 a2@<ebp>)
{
  int v3; // eax
  int v4; // edi
  int v5; // eax

  if ( !*((_BYTE *)a1 + 276) || *((_BYTE *)a1 + 277) )
    return 0;
  if ( byte_B722E4 )
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 22);
  else
    v3 = (*(int (__thiscall **)(int, int))(*(_DWORD *)dword_B6E090 + 28))(dword_B6E090, 21);
  v4 = v3;
  if ( v3 )
  {
    v5 = *a1;
    *((_BYTE *)a1 + 277) = 1;
    (*(void (__thiscall **)(int *, int))(v5 + 36))(a1, 1);
    sub_4AE810(v4, 0);
    sub_49A6B0(a2, 1);
  }
  return 0;
}
