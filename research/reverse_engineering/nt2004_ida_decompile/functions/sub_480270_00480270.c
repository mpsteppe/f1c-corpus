int __thiscall sub_480270(_DWORD *this)
{
  int v2; // eax
  int *v3; // esi
  const char *v4; // eax
  int v5; // ebx
  int v6; // eax
  int v7; // edi
  int v9; // [esp+18h] [ebp-8h] BYREF
  int v10; // [esp+1Ch] [ebp-4h] BYREF

  v2 = (*(int (__thiscall **)(int))(*(_DWORD *)dword_76BB24 + 100))(dword_76BB24);
  if ( v2 )
  {
    v3 = *(int **)(v2 + 28);
    if ( v3 )
    {
      if ( dword_600F58 >= 0 )
      {
        LOBYTE(v10) = dword_600F58;
        v4 = (const char *)this[42];
        v9 = 0;
        if ( !v4 )
          v4 = &byte_629120;
        v5 = v10;
        if ( !_strcmpi(v4, aErrorcheck) && (*(unsigned __int8 (__thiscall **)(int *))(*v3 + 144))(v3) == 1 )
        {
          v6 = *v3;
          v10 = 0;
          v7 = (*(int (__thiscall **)(int *))(v6 + 64))(v3);
          (*(void (__thiscall **)(int *, char *, _DWORD, int *))(*v3 + 168))(v3, aHowmuchwillthi, 0, &v10);
          (*(void (__thiscall **)(int *, int, _DWORD, int *))(*v3 + 172))(v3, v5, 0, &v9);
          if ( v9 + v7 < v10 )
          {
            sub_4AD720(a2003CareerRd, 1);
            sub_4AD720(a2003CareerSell, 1);
            return -1;
          }
        }
        (*(void (__thiscall **)(int *, int, int, int *))(*v3 + 172))(v3, v5, 1, &v9);
      }
    }
  }
  return 0;
}
