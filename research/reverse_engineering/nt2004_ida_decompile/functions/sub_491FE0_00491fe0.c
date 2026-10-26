int sub_491FE0()
{
  int v0; // eax
  int *v1; // esi
  int v2; // ecx
  int v3; // edx
  int v5; // [esp+Ch] [ebp-44h] BYREF
  char v6[61]; // [esp+10h] [ebp-40h] BYREF
  __int16 v7; // [esp+4Dh] [ebp-3h]
  char v8; // [esp+4Fh] [ebp-1h]

  v0 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v0
    && (v1 = *(int **)(v0 + 28)) != 0
    && (v2 = (*(unsigned __int8 (__thiscall **)(_DWORD))(*v1 + 144))(*(_DWORD *)(v0 + 28))) != 0
    && dword_600F58 >= 0
    && dword_600F58 < v2
    && (v3 = *v1,
        v5 = 0,
        (*(unsigned __int8 (__thiscall **)(int *, int, _DWORD, int *))(v3 + 172))(v1, dword_600F58, 0, &v5)) )
  {
    v6[0] = byte_629120;
    memset(&v6[1], 0, 0x3Cu);
    v7 = 0;
    v8 = 0;
    sub_40FF80(v5, v6, 63);
    sub_49EC60(v6);
    return 0;
  }
  else
  {
    sub_49EC60(aNA_1);
    return 0;
  }
}
