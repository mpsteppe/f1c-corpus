int __thiscall sub_47FF30(void *this)
{
  void *v1; // edi
  int v2; // eax
  int *v3; // esi
  int v4; // edi
  unsigned __int8 v5; // al
  int v6; // edx
  unsigned int v7; // eax
  unsigned int v9; // [esp+1Ch] [ebp-Ch] BYREF
  void *v10; // [esp+20h] [ebp-8h]
  int v11; // [esp+24h] [ebp-4h] BYREF

  v1 = this;
  v10 = this;
  if ( (unsigned int)dword_600F50 < 4 && (unsigned int)dword_600F54 <= 2 )
  {
    v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
    if ( v2 )
    {
      v3 = *(int **)(v2 + 28);
      if ( v3 )
      {
        v4 = dword_600F50;
        v5 = (*(int (__thiscall **)(int *, int))(*v3 + 92))(v3, dword_600F50);
        v6 = *v3;
        v11 = 0;
        v9 = 0;
        if ( (*(unsigned __int8 (__thiscall **)(int *, int, int, int, _DWORD, int *, unsigned int *))(v6 + 88))(
               v3,
               v4,
               v5 + 1,
               dword_600F54,
               0,
               &v11,
               &v9) )
        {
          v7 = (*(int (__thiscall **)(int *))(*v3 + 64))(v3);
          if ( v9 <= v7 )
          {
            (*(void (__thiscall **)(void *, _DWORD))(*(_DWORD *)v10 + 36))(v10, 0);
            return 0;
          }
        }
        v1 = v10;
      }
    }
  }
  (*(void (__thiscall **)(void *, int))(*(_DWORD *)v1 + 36))(v1, 1);
  return 0;
}
