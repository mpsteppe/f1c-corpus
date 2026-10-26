int __thiscall sub_47FE40(void *this)
{
  int v1; // eax
  int v2; // esi
  int v3; // ebx
  unsigned __int8 v4; // al
  int v5; // ebp
  int v6; // edi
  const char *v7; // eax
  int v8; // edi
  void *v10; // [esp+1Ch] [ebp-10h] BYREF
  void *v11; // [esp+20h] [ebp-Ch]
  int v12; // [esp+24h] [ebp-8h] BYREF
  int v13; // [esp+28h] [ebp-4h]

  v11 = this;
  v1 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v1 )
  {
    v2 = *(_DWORD *)(v1 + 28);
    if ( v2 )
    {
      v3 = dword_600F50;
      v4 = (*(int (__thiscall **)(int, int))(*(_DWORD *)v2 + 92))(v2, dword_600F50);
      v5 = dword_600F54;
      v6 = v4;
      v7 = (const char *)*((_DWORD *)v11 + 42);
      v8 = v6 + 1;
      v13 = dword_600F54;
      v12 = 0;
      v10 = 0;
      if ( !v7 )
        v7 = &byte_629120;
      if ( !_strcmpi(v7, aErrorcheck) )
      {
        (*(void (__thiscall **)(int, int, int, int, _DWORD, int *, void **))(*(_DWORD *)v2 + 88))(
          v2,
          v3,
          v8,
          v5,
          0,
          &v12,
          &v10);
        if ( sub_46DFC0(v10) )
        {
          sub_4AD720(a2003CareerRd, 1);
          sub_4AD720(a2003CareerStar, 1);
          return -1;
        }
        v5 = v13;
      }
      (*(void (__thiscall **)(int, int, int, int, int, int *, void **))(*(_DWORD *)v2 + 88))(
        v2,
        v3,
        v8,
        v5,
        1,
        &v12,
        &v10);
    }
  }
  return 0;
}
