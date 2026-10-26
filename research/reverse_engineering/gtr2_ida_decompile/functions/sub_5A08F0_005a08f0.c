int __thiscall sub_5A08F0(_DWORD *this)
{
  unsigned int v1; // kr00_4
  __int32 v2; // ebp
  _DWORD *v3; // esi
  int v4; // edi
  bool v5; // zf
  void (__thiscall **v6)(void *); // ebx
  char v7; // al
  void (__thiscall *v8)(void *); // ebp
  _DWORD *v9; // eax
  int v10; // ecx
  char *v11; // esi
  int result; // eax
  void (__thiscall *v13[5])(void *); // [esp+0h] [ebp-18h] BYREF
  _DWORD *v14; // [esp+14h] [ebp-4h]

  v3 = this;
  v4 = *this;
  v5 = *this == 0;
  v14 = this;
  if ( !v5 )
  {
    do
    {
      v6 = (void (__thiscall **)(void *))v4;
      v7 = *(_BYTE *)(v4 + 8);
      v4 = *(_DWORD *)(v4 + 4);
      if ( v7 )
      {
        v8 = *v6;
        if ( *v6 )
        {
          v9 = *(_DWORD **)v8;
          if ( *(_DWORD *)v8 )
          {
            v10 = *(v9 - 1);
            v11 = (char *)(v9 - 1);
            v13[0] = *v6;
            v1 = __readeflags();
            v2 = dword_16C6CEC - (*(_DWORD *)sub_41FCD0 + 1);
            __writeeflags(v1);
            v8 = (void (__thiscall *)(void *))_InterlockedExchange((volatile __int32 *)v13, v2);
            `eh vector destructor iterator'(v9, 0x20848u, v10, v13[0]);
            j_j__free(v11);
            v3 = v14;
          }
          j__free(v8);
        }
      }
      j__free(v6);
    }
    while ( v4 );
  }
  result = 0;
  *v3 = 0;
  v3[1] = 0;
  v3[2] = 0;
  v3[3] = 0;
  return result;
}
