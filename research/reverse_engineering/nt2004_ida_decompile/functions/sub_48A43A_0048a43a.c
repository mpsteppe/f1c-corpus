int __usercall sub_48A43A@<eax>(__int64 a1@<edx:eax>, char a2@<ch>, _DWORD *a3@<edi>)
{
  int v3; // eax
  int v4; // ecx
  int v5; // eax
  char *v6; // eax

  LOBYTE(a1) = a2 + a1;
  *a3 = a1;
  v3 = (*(int (__fastcall **)(int, _DWORD))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24, a1 % (int)(a3 + 1));
  if ( v3 && (v4 = *(_DWORD *)(v3 + 28)) != 0 && (v5 = (*(int (__thiscall **)(int))(*(_DWORD *)v4 + 152))(v4)) != 0 )
  {
    v6 = *(char **)(v5 + 8);
    if ( !v6 )
      v6 = &byte_629120;
    sub_4A1AC0(v6);
    return 0;
  }
  else
  {
    sub_4A1AC0(aNA_1);
    return 0;
  }
}
