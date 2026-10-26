// positive sp value has been detected, the output may be wrong!
int __usercall sub_4A39D2@<eax>(char a1@<cl>, int a2@<ebx>, int a3@<esi>)
{
  _DWORD *v3; // ecx
  int result; // eax
  SOCKET v5; // [esp-14h] [ebp-14h]
  int v6; // [esp-10h] [ebp-10h]
  int v7; // [esp-Ch] [ebp-Ch]
  const char *v8; // [esp-8h] [ebp-8h]
  int v9; // [esp-4h] [ebp-4h]

  *(_BYTE *)(a2 + 743505870) += a1;
  setsockopt(v5, v6, v7, v8, v9);
  (*(void (**)(void))(a3 - 117))();
  __asm { icebp }
  switch ( sub_49D1E0(v3) )
  {
    case 1:
      (*(void (__thiscall **)(int, int))(*(_DWORD *)a3 + 44))(a3, 6);
      (*(void (__thiscall **)(int))(*(_DWORD *)a3 + 148))(a3);
      result = 0;
      break;
    case 2:
    case 5:
      (*(void (__thiscall **)(int))(*(_DWORD *)a3 + 44))(a3);
      goto LABEL_5;
    case 4:
      (*(void (__thiscall **)(int, int))(*(_DWORD *)a3 + 44))(a3, 8);
      (*(void (__thiscall **)(int))(*(_DWORD *)a3 + 148))(a3);
      result = 0;
      break;
    default:
LABEL_5:
      (*(void (__thiscall **)(int))(*(_DWORD *)a3 + 148))(a3);
      result = 0;
      break;
  }
  return result;
}
