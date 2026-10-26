// positive sp value has been detected, the output may be wrong!
int __usercall sub_4BD5C6@<eax>(int a1@<ebp>, int a2)
{
  const char *v2; // eax
  int v3; // ebp
  int v4; // edi
  _DWORD *v5; // eax
  _DWORD *v6; // esi
  _DWORD *v7; // eax
  unsigned int v9; // kr00_4
  __int32 v10; // ebx
  __int32 v11; // ebx
  __int32 v12; // [esp-10h] [ebp-14h] BYREF
  _DWORD *retaddr; // [esp+4h] [ebp+0h] BYREF

  v9 = __readeflags();
  v10 = dword_16C6EA4 - 379059860;
  __writeeflags(v9);
  v11 = _InterlockedExchange(&v12, v10);
  if ( sub_613DE0((char *)&STACK[0x59C], v12) )
    JUMPOUT(0x483032);
  sub_613C30(&STACK[0x124]);
  v2 = *(const char **)dword_759ED8;
  if ( *(_DWORD *)dword_759ED8 == v11 )
    v2 = WindowName;
  if ( !strlen(v2) )
  {
    UuidCreate((UUID *)&STACK[0x114]);
    UuidToStringA((const UUID *)&STACK[0x114], (RPC_CSTR *)&retaddr);
    sub_615860(retaddr);
    sub_615860(retaddr);
    RpcStringFreeA((RPC_CSTR *)&retaddr);
  }
  if ( *(_DWORD *)(a1 + 12) <= v11 )
  {
    v3 = 0;
    if ( sub_5A6E90(a2 + 1584) > 0 )
    {
      do
      {
        v4 = sub_53A9E0(a2 + 1584, v3);
        v5 = operator new(8u);
        v6 = v5;
        LOBYTE(STACK[0x7A4]) = 2;
        if ( v5 )
        {
          *v5 = 0;
          v5[1] = -1;
          sub_615860(v4 + 260);
        }
        else
        {
          v6 = 0;
        }
        LOBYTE(STACK[0x7A4]) = 0;
        if ( v6 )
        {
          v7 = operator new(0xCu);
          if ( v7 )
          {
            *v7 = v6;
            v7[1] = 0;
            *((_BYTE *)v7 + 8) = 1;
          }
          else
          {
            v7 = 0;
          }
          if ( *retaddr )
          {
            *(_DWORD *)(retaddr[1] + 4) = v7;
          }
          else
          {
            *retaddr = v7;
            retaddr[2] = v7;
          }
          retaddr[1] = v7;
          ++retaddr[3];
        }
        ++v3;
      }
      while ( v3 < a2 );
    }
  }
  retaddr[2] = *retaddr;
  STACK[0x7A4] = -1;
  return sub_614140(&STACK[0x120]);
}
