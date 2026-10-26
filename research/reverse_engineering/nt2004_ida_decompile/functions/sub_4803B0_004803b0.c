int __thiscall sub_4803B0(void *this)
{
  int v1; // eax
  int *v2; // esi
  unsigned int v3; // ebp
  int v4; // eax
  unsigned __int8 v5; // bl
  unsigned int v6; // edi
  int v7; // eax
  int v8; // eax
  int v10; // edx
  unsigned int v11; // [esp+10h] [ebp-Ch] BYREF
  void *v12; // [esp+14h] [ebp-8h]
  unsigned int v13; // [esp+18h] [ebp-4h]

  v12 = this;
  v1 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( !v1 )
    goto LABEL_7;
  v2 = *(int **)(v1 + 28);
  if ( !v2 )
    goto LABEL_7;
  v3 = 10000000;
  v13 = (*(int (__thiscall **)(_DWORD))(*v2 + 64))(*(_DWORD *)(v1 + 28));
  v4 = *v2;
  v5 = 0;
  LOBYTE(v11) = 0;
  if ( !(*(unsigned __int8 (__thiscall **)(int *))(v4 + 144))(v2) )
    goto LABEL_7;
  while ( 1 )
  {
    v6 = v11;
    v7 = (*(int (__thiscall **)(int *, unsigned int))(*v2 + 148))(v2, v11);
    if ( v7 )
    {
      if ( *(_BYTE *)(v7 + 4) < 0x64u )
        break;
    }
    v8 = *v2;
    LOBYTE(v11) = ++v5;
    if ( v5 >= (*(unsigned __int8 (__thiscall **)(int *))(v8 + 144))(v2) )
      goto LABEL_7;
  }
  v10 = *v2;
  v11 = 10000000;
  (*(void (__thiscall **)(int *, unsigned int, _DWORD, unsigned int *))(v10 + 164))(v2, v6, 0, &v11);
  if ( v11 < 0x989680 )
    v3 = v11;
  if ( v3 <= v13 )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v12 + 36))(v12, 0);
    return 0;
  }
  else
  {
LABEL_7:
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)v12 + 36))(v12, 1);
    return 0;
  }
}
