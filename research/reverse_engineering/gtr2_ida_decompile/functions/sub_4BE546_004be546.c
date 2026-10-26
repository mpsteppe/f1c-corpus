// positive sp value has been detected, the output may be wrong!
char __userpurge sub_4BE546@<al>(int a1@<eax>, int a2@<ebp>, int a3@<edi>, int a4)
{
  unsigned int v4; // kr00_4
  __int32 v5; // ebx
  char v6; // bl
  int v7; // eax
  int v8; // eax
  char *v10; // eax
  int v11; // esi
  __int32 v12; // [esp-8h] [ebp-Ch] BYREF

  v4 = __readeflags();
  v5 = dword_16C6F18 + 1525406209;
  __writeeflags(v4);
  v6 = _InterlockedExchange(&v12, v5);
  if ( (*(int (__thiscall **)(int, char *))(a1 + 36))(a2, byte_903710) )
  {
    v6 = 1;
    v7 = sub_612EB0(&unk_9034F8);
    if ( v7 )
    {
      v8 = v7 - 1;
      if ( !v8 || v8 == 3 )
        return v6;
    }
    else
    {
      v10 = strstr(byte_903710, "[OPPONENT");
      if ( v10 )
      {
        v11 = 920 * atol(&v10[strlen("[OPPONENT")]) + a3;
        sub_531650(a2);
        ((void (__thiscall *)(int, _DWORD))sub_5305B0)(v11, 0);
      }
      else if ( strstr(byte_903710, "[PLAYER]") )
      {
        sub_531650(a2);
        ((void (__thiscall *)(int, int))sub_5305B0)(a3 + 94760, 1);
      }
      else if ( sub_6133A0("SEASONSTATUS", (int)&a4, 0, 0, 0) )
      {
        *(_DWORD *)(a3 + 95732) = a4;
      }
      else
      {
        sub_6133A0("RACESESSION", a3 + 95740, 0, 0, 0);
        sub_6133A0("RACEQUARTER", a3 + 95760, 0, 0, 0);
        if ( sub_6133A0("RACEOVER", (int)&a4, 0, 0, 0) )
          *(_BYTE *)(a3 + 95744) = a4 != 0;
        sub_6133A0("CURRENTRACE", a3 + 95736, 0, 0, 0);
      }
    }
    JUMPOUT(0x532456);
  }
  return v6;
}
