int __thiscall sub_480550(void *this)
{
  int v2; // eax
  int *v3; // esi
  int v4; // edx
  unsigned int v5; // edi
  int v6; // eax
  int v7; // eax
  unsigned int v8; // eax
  unsigned int v10; // [esp+10h] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( !v2 )
    goto LABEL_8;
  v3 = *(int **)(v2 + 28);
  if ( !v3 )
    goto LABEL_8;
  if ( dword_600F58 < 0 )
    goto LABEL_8;
  v4 = *v3;
  LOBYTE(v10) = dword_600F58;
  v5 = v10;
  v6 = (*(int (__thiscall **)(int *, unsigned int))(v4 + 148))(v3, v10);
  if ( !v6 )
    goto LABEL_8;
  if ( *(_BYTE *)(v6 + 4) < 0x64u
    && (v7 = *v3,
        v10 = 0,
        (*(void (__thiscall **)(int *, unsigned int, _DWORD, unsigned int *))(v7 + 164))(v3, v5, 0, &v10),
        v8 = (*(int (__thiscall **)(int *))(*v3 + 64))(v3),
        v10 <= v8) )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
    return 0;
  }
  else
  {
LABEL_8:
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    return 0;
  }
}
