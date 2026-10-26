int __thiscall sub_480070(_DWORD *this)
{
  int v2; // eax
  int v3; // esi
  const char *v4; // eax
  void *v6; // [esp+Ch] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 28);
    if ( v3 )
    {
      v4 = (const char *)this[42];
      v6 = 0;
      if ( !v4 )
        v4 = &byte_629120;
      if ( !_strcmpi(v4, aErrorcheck) )
      {
        (*(void (__thiscall **)(int, char *, _DWORD, void **))(*(_DWORD *)v3 + 168))(v3, &byte_765578, 0, &v6);
        if ( sub_46DFC0(v6) )
        {
          sub_4AD720(a2003CareerRd, 1);
          sub_4AD720(a2003CareerBuil, 1);
          return -1;
        }
      }
      (*(void (__thiscall **)(int, char *, int, void **))(*(_DWORD *)v3 + 168))(v3, &byte_765578, 1, &v6);
    }
  }
  return 0;
}
