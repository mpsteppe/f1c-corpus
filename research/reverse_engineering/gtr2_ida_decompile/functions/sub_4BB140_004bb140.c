int __usercall sub_4BB140@<eax>(int a1@<ecx>, int a2@<ebx>, int a3@<edi>)
{
  int result; // eax
  int v5; // edi
  int v6; // ebx
  _BYTE v7[172]; // [esp+4h] [ebp-C8h] BYREF
  int v8; // [esp+C8h] [ebp-4h]

  switch ( *(_DWORD *)dword_B72314 )
  {
    case 1:
    case 2:
    case 3:
      sub_4CD6D0("CIRCUIT_SELECT");
      result = -1;
      break;
    case 4:
      sub_4EBFF0(&unk_B6F135, a3, a2);
      v5 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 42);
      v6 = (*(int (__thiscall **)(_DWORD, int))(**(_DWORD **)(a1 + 48) + 28))(*(_DWORD *)(a1 + 48), 44);
      if ( v5 )
        sub_4B8110();
      if ( v6 )
        sub_4B8110();
      sub_4CD6D0("NEXTROUND_CHAMP");
      result = -1;
      break;
    case 5:
      if ( sub_473550() == 3 )
      {
        sub_4E1810("MONITOR_MPCLIENT", 0);
        sub_4744E0(v7);
        v8 = 0;
        sub_4747D0(&dword_B6CBA8, (int)v7, 0);
        sub_4781A0((int)v7, a1);
        dword_75B17C = 1;
        v8 = -1;
        nullsub_7(v7);
      }
      result = -1;
      break;
    default:
      result = 0;
      break;
  }
  return result;
}
