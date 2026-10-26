int __thiscall sub_480000(void *this)
{
  int v2; // eax
  int *v3; // esi
  unsigned int v4; // ebx
  int v5; // eax
  unsigned int v7; // [esp+Ch] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v2
    && (v3 = *(int **)(v2 + 28)) != 0
    && (v4 = (*(int (__thiscall **)(_DWORD))(*v3 + 64))(*(_DWORD *)(v2 + 28)),
        v5 = *v3,
        v7 = 0,
        (*(unsigned __int8 (__thiscall **)(int *, CHAR *, _DWORD, unsigned int *))(v5 + 168))(v3, &byte_629120, 0, &v7))
    && v7 <= v4 )
  {
    (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)this + 36))(this, 0);
    return 0;
  }
  else
  {
    (*(void (__thiscall **)(void *, int))(*(_DWORD *)this + 36))(this, 1);
    return 0;
  }
}
